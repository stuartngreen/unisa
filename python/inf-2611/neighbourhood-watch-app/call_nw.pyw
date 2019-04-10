import sys
from nw import *
from functools import partial
from PyQt4 import QtSql, QtCore, QtGui
from PyQt4.QtGui import QMessageBox
from PyQt4.QtSql import QSqlRelation
from datetime import date, datetime, timedelta, time


# Open db connection
def createConnection():
    db = QtSql.QSqlDatabase.addDatabase('QMYSQL')
    db.setHostName('localhost')
    db.setDatabaseName('tvnw')
    db.setUserName('root')
    db.setPassword('1qaz.;[=')
    if db.open():
        print ("Database opened successfully.")
        return True
    else:
        print (db.lastError().text())
        return False


# Main application
class MyApp(QtGui.QMainWindow):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        if not createConnection():
            sys.exit(1)
        

        # Add UI subwindows
        self.ui.mdiArea.addSubWindow(self.ui.subWindowIncidents)
        self.ui.mdiArea.addSubWindow(self.ui.subWindowManageMembers)
        self.ui.mdiArea.addSubWindow(self.ui.subWindowAddNewMember)
        self.ui.mdiArea.addSubWindow(self.ui.subWindowManagePatrolTimeSlots)

        # Window actions for navigation via menu and toolbar
        self.ui.actionIncidents.triggered.connect(partial(self.switchWindow, self.ui.subWindowIncidents))
        self.ui.actionManageMembers.triggered.connect(partial(self.switchWindow, self.ui.subWindowManageMembers))
        self.ui.actionAddNewMember.triggered.connect(partial(self.switchWindow, self.ui.subWindowAddNewMember))
        self.ui.actionManagePatrolTimeSlots.triggered.connect(partial(self.switchWindow, self.ui.subWindowManagePatrolTimeSlots))
        
        # Init UI elements (maximise window, load data from db and populate date fields)
        self.ui.subWindowIncidents.showMaximized()
        self.initAppData()
        self.initFieldStates()

        # Start timer for LCD time
        timer = QtCore.QTimer(self)
        timer.timeout.connect(self.showLcd)
        timer.start(1000)
        self.showLcd()

        # Start timer for list of patrolling members (updated every min)
        timerUpdateList = QtCore.QTimer(self)
        timerUpdateList.timeout.connect(self.populateCurrentlyPatrollingList)
        timerUpdateList.start(60000)
        self.populateCurrentlyPatrollingList()
        
        # Manage members
        self.ui.buttonNewSave.clicked.connect(self.addNewMember)
        self.ui.tableMembers.clicked.connect(self.populateUpdateMemberForms)
        self.ui.buttonManageSave.clicked.connect(self.updateMemberDetails)
        #self.connect(self.ui.buttonFindMember, QtCore.SIGNAL('clicked()'), self.findMember)
        self.ui.buttonFindMember.clicked.connect(self.findMember)
        self.ui.buttonClearMemberFilter.clicked.connect(self.clearMemberFilter)
        self.ui.buttonChangeMemberPhoto.clicked.connect(self.changeMemberPhoto)
        self.ui.buttonAddMemberPhoto.clicked.connect(self.addMemberPhoto)

        # Manage patrol time slots
        self.ui.buttonAddTime.clicked.connect(self.addNewTimeSlot)
        self.ui.buttonRemoveTime.clicked.connect(self.removeTimeSlot)
        self.ui.buttonAddPatrolLink.clicked.connect(self.addPatrolLink)
        self.ui.buttonRemovePatrolLink.clicked.connect(self.removePatrolLink)
        self.ui.comboAddPatrolWeekDay.currentIndexChanged.connect(self.populatePatrolTimeSlotsCombo)

        # Manage incidents
        self.ui.buttonNewIncidentSave.clicked.connect(self.addNewIncident)
        self.ui.tableIncidents.clicked.connect(self.populateUpdateIncidentForm)
        self.ui.buttonUpdateIncident.clicked.connect(self.updateIncident)
        self.ui.buttonDeleteIncident.clicked.connect(self.deleteIncident)
        self.ui.buttonIncidentClearFilter.clicked.connect(self.clearIncidentFilter)
        self.ui.buttonIncidentFilter.clicked.connect(self.filterIncidents)






    # Startup functions
    def switchWindow(self, subWindow):
        subWindow.showMaximized()

        
    def initAppData(self):
        self.populateIncidentTableView()
        self.populateIncidentTypesCombo()
        self.populateMembersCombo()
        self.populateMemberTableView()
        self.populatePatrolTimesTableView()
        self.populatePatrolTimeSlotsCombo()
        self.populatePatrolAreaCombo()

        
    def initFieldStates(self):
        # Set date fields to current date/time
        self.ui.dateNewDateJoined.setDateTime(QtCore.QDateTime.currentDateTime())
        self.ui.dateManageDateJoined.setDateTime(QtCore.QDateTime.currentDateTime())
        self.ui.dateNewIncidentDateTime.setDateTime(QtCore.QDateTime.currentDateTime())
        self.setIncidentFilterRangeDates()

        # Disable tab contents before a selection is made
        self.ui.tabWidgetMembers.setEnabled(False)
        self.ui.tabWidgetIncidents.setTabEnabled(1, False)

        # Set a filename attribute on the member photo labels for later use
        self.ui.labelChangeMemberPhoto.filename = ""
        self.ui.labelAddMemberPhoto.filename = ""
        

    def showLcd(self):
        time = QtCore.QTime.currentTime()
        self.ui.lcdNumber.display(time.toString('hh:mm'))


    def populateCurrentlyPatrollingList(self):
        self.ui.listPatrollingMembers.clear()
        
        # Get week day and current time
        time = QtCore.QTime.currentTime()
        day_int = QtCore.QDate.dayOfWeek(QtCore.QDate.currentDate())
        week_day = QtCore.QDate.longDayName(day_int)

        # Select members where the patrol time slot intersects with current time
        query = QtSql.QSqlQuery()
        query.prepare("SELECT member.name, member.surname, member.callsign, member.contact_number, patrol_area.description "
            "FROM patrol INNER JOIN member ON patrol.member_id=member.member_id INNER JOIN patrol_time ON patrol.time_id=patrol_time.time_id INNER JOIN patrol_area ON patrol.area_id=patrol_area.area_id "
            "WHERE patrol_time.time_start < ? AND patrol_time.time_end > ? AND patrol_time.week_day = ?")
        query.addBindValue(time)
        query.addBindValue(time)
        query.addBindValue(week_day)
        query.exec_()
        while query.next():
            name = query.value(0)
            surname = query.value(1)
            callsign = query.value(2)
            contact_number = str(query.value(3))
            area = query.value(4)
            patrolling_member = name + " \"" + callsign + "\" " + surname + " (0" + contact_number + ") patrolling in " + area
            self.ui.listPatrollingMembers.addItem(patrolling_member)


        



    # Incident related functions
    def populateIncidentTableView(self):
        self.model = QtSql.QSqlRelationalTableModel(self)
        self.model.setTable("incident")
        self.model.setEditStrategy(QtSql.QSqlTableModel.OnManualSubmit)

        # Sort results by date_time descending
        self.model.setSort(1, QtCore.Qt.SortOrder(1))

        # Get columns from related tables
        self.model.setRelation(2, QtSql.QSqlRelation("incident_type", "type_id", "description"))
        self.model.setRelation(7, QtSql.QSqlRelation("member", "member_id", "callsign"))
        
        self.model.select()

        # Change display names of column headers
        self.model.setHeaderData(1, QtCore.Qt.Horizontal, "Date/time")
        self.model.setHeaderData(2, QtCore.Qt.Horizontal, "Type")
        self.model.setHeaderData(3, QtCore.Qt.Horizontal, "Street")
        self.model.setHeaderData(4, QtCore.Qt.Horizontal, "Street no.")
        self.model.setHeaderData(7, QtCore.Qt.Horizontal, "Reported by")

        # Hide columns I don't want to see on the table view
        self.ui.tableIncidents.setModel(self.model)
        self.ui.tableIncidents.hideColumn(0)
        self.ui.tableIncidents.hideColumn(5)
        self.ui.tableIncidents.hideColumn(6)
        self.ui.tableIncidents.hideColumn(8)


    def setIncidentFilterRangeDates(self):
        # Set 'to' value in range to current date
        self.ui.dateIncidentFilterTo.setDateTime(QtCore.QDateTime.currentDateTime())
        
        # Set 'from' value in range to one week ago
        one_week_ago = datetime.today() - timedelta(days=7)
        self.ui.dateIncidentFilterFrom.setDateTime(one_week_ago)

        # Reload the incidents table view
        self.populateIncidentTableView()


    def filterIncidents(self):
        # Disable the update tab because incident is not selected anymore
        self.ui.tabWidgetIncidents.setCurrentIndex(0)
        self.ui.tabWidgetIncidents.setTabEnabled(1, False)

        # Convoluted way to get date and time for sql statement :/
        from_date = self.ui.dateIncidentFilterFrom.date().toPyDate()
        to_date = self.ui.dateIncidentFilterTo.date().toPyDate()
        from_time = datetime.time(datetime(2000, 1, 1, 0, 0) - timedelta(seconds=1))
        to_time = datetime.time(datetime(2000, 1, 1, 0, 0) + timedelta(seconds=1))
        from_date_time = datetime.combine(from_date, from_time)
        to_date_time = datetime.combine(to_date, to_time)
        
        # Reload table with incidents matching provided date range        
        if to_date < from_date:
            showMessageBox(QMessageBox.Warning, "'To' date cannot be before 'From' date.", "", "Oops!")
            return False

        self.model = QtSql.QSqlRelationalTableModel(self)
        self.model.setTable("incident")
        self.model.setEditStrategy(QtSql.QSqlTableModel.OnManualSubmit)

        # Find the incidents that match the date range and set the sort order
        self.model.setFilter("date_time > '" + str(from_date) + "'AND date_time < '" + str(to_date) + "'")
        self.model.setSort(1, QtCore.Qt.SortOrder(1))

        # Get real values for display via relations
        self.model.setRelation(2, QtSql.QSqlRelation("incident_type", "type_id", "description"))
        self.model.setRelation(7, QtSql.QSqlRelation("member", "member_id", "callsign"))
        self.model.select()

        # Change display name of column headers
        self.model.setHeaderData(1, QtCore.Qt.Horizontal, "Date/time")
        self.model.setHeaderData(2, QtCore.Qt.Horizontal, "Type")
        self.model.setHeaderData(3, QtCore.Qt.Horizontal, "Street")
        self.model.setHeaderData(4, QtCore.Qt.Horizontal, "Street no.")
        self.model.setHeaderData(7, QtCore.Qt.Horizontal, "Reported by")

        # Hide the columns I don't want to see on the table view
        self.ui.tableIncidents.setModel(self.model)
        self.ui.tableIncidents.hideColumn(0)
        self.ui.tableIncidents.hideColumn(5)
        self.ui.tableIncidents.hideColumn(6)
        self.ui.tableIncidents.hideColumn(8)


    def clearIncidentFilter(self):
        # Disable the update tab because incident is not selected anymore
        self.ui.tabWidgetIncidents.setCurrentIndex(0)
        self.ui.tabWidgetIncidents.setTabEnabled(1, False)

        # Call function to reset the date range and reload the incidents table
        self.setIncidentFilterRangeDates()


    def populateIncidentTypesCombo(self):
        # Prepare and execute the query to get incident_type descriptions
        query = QtSql.QSqlQuery()
        query.prepare("SELECT description FROM incident_type")
        query.exec_()
        while query.next():
            # Append each to the combobox
            incident_type = query.value(0)
            self.ui.comboNewIncidentType.addItem(incident_type)
            self.ui.comboUpdateIncidentType.addItem(incident_type)


    def populateMembersCombo(self):
        # Prepare and execure the the query to get member details
        query = QtSql.QSqlQuery()
        query.prepare("SELECT member_id, name, surname, callsign FROM member")
        query.exec_()
        while query.next():
            # For each member, create a string containing member_id, name, callsign, surname, contact_number
            member_id = str(query.value(0))
            name = query.value(1)
            surname = query.value(2)
            callsign = query.value(3)
            full_name = member_id + " - " + name + " \"" + callsign + "\" " + surname
            # Add string to 'add new' tab and 'update' tab comboboxes
            self.ui.comboNewIncidentReportedBy.addItem(full_name)
            self.ui.comboUpdateIncidentReportedBy.addItem(full_name)


    def addNewIncident(self):
        # Get field values from the GUI elements
        date_time = self.ui.dateNewIncidentDateTime.dateTime()
        location_street = self.ui.editNewIncidentStreetName.text()
        location_number = self.ui.editNewIncidentStreetNo.text()
        gps_x = self.ui.editNewIncidentGpsX.text()
        gps_y = self.ui.editNewIncidentGpsY.text()
        notes = self.ui.textNewIncidentNotes.toPlainText()

        # Get type id of incident by matching type description to db
        type_description = self.ui.comboNewIncidentType.currentText()
        query = QtSql.QSqlQuery()
        query.prepare("SELECT type_id FROM incident_type WHERE description = ?")
        query.addBindValue(type_description)
        query.exec_()
        while query.next():
            type_id = query.value(0)
        
        # Get the member id from combo box text
        member_full_name = self.ui.comboNewIncidentReportedBy.currentText()
        reported_by_member_id = member_full_name.split()[0]

        # Validation
        validation_message = ""
        if location_street == "":
            validation_message += "Street name cannot be empty.\n"
        if location_number == "":
            validation_message += "Street number cannot be empty.\n"
        if gps_x == "" or gps_y == "":
            validation_message += "GPS coordinates cannot be empty.\n"
        if not (validation_message == ""):
            showMessageBox(QMessageBox.Warning, "There are some problems with the data.", validation_message, "Oops!")
            return False

        # Prepare query for inserting new incident into db
        query.prepare("INSERT INTO incident "
            "(date_time, type_id, location_street, location_number, gps_x, gps_y, reported_by_member_id, notes) VALUES "
            "(?, ?, ?, ?, ?, ?, ?, ?)")
        query.addBindValue(date_time)
        query.addBindValue(type_id)
        query.addBindValue(location_street)
        query.addBindValue(location_number)
        query.addBindValue(gps_x)
        query.addBindValue(gps_y)
        query.addBindValue(reported_by_member_id)
        query.addBindValue(notes)
        # Execute query
        if not query.exec_():
            print(query.lastError().text())
        else:
            print("Row added successfully")
            # Refresh table view with latest incidents
            self.populateIncidentTableView()
            showMessageBox(QMessageBox.Information, "New incident added successfully.", "", "Information")

        # Reset fields
        self.ui.editNewIncidentStreetName.setText("")
        self.ui.editNewIncidentStreetNo.setText("")
        self.ui.editNewIncidentGpsX.setText("")
        self.ui.editNewIncidentGpsY.setText("")
        self.ui.textNewIncidentNotes.clear()


    def populateUpdateIncidentForm(self):
        # Get the incident_id of the selected row
        selected_row = self.ui.tableIncidents.selectionModel().selectedRows()[0]
        incident_id = self.ui.tableIncidents.model().data(selected_row)

        # Enable and focus the update tab
        self.ui.tabWidgetIncidents.setTabEnabled(1, True)
        self.ui.tabWidgetIncidents.setCurrentIndex(1)

        # Get the incident data
        query = QtSql.QSqlQuery()
        query.prepare("SELECT * FROM incident WHERE incident_id = ?")
        query.addBindValue(incident_id)
        query.exec_()
        while query.next():
            self.ui.dateUpdateIncidentDateTime.setDateTime(query.value(1))
            type_id = query.value(2)
            self.ui.editUpdateIncidentStreetNo.setText(str(query.value(4)))
            self.ui.editUpdateIncidentStreetName.setText(query.value(3))
            self.ui.editUpdateIncidentGpsX.setText(str(query.value(5)))
            self.ui.editUpdateIncidentGpsY.setText(str(query.value(6)))
            reported_by_member_id = query.value(7)
            self.ui.textUpdateIncidentNotes.clear()
            self.ui.textUpdateIncidentNotes.insertPlainText(query.value(8))

        # Get the incident description from type_id
        query.prepare("SELECT description FROM incident_type WHERE type_id = ?")
        query.addBindValue(type_id)
        query.exec_()
        while query.next():
            type_description = query.value(0)
            
        # Set the 'incident type' combo box to the correct index
        incident_type_index = self.ui.comboUpdateIncidentType.findText(type_description, QtCore.Qt.MatchFixedString)
        self.ui.comboUpdateIncidentType.setCurrentIndex(incident_type_index)

        # Set the 'reported by member' combo box to the correct index
        member_index = self.ui.comboUpdateIncidentReportedBy.findText(str(reported_by_member_id) + " ", QtCore.Qt.MatchStartsWith)
        self.ui.comboUpdateIncidentReportedBy.setCurrentIndex(member_index)


    def updateIncident(self):
        # Get incident id from selected row
        selected_incident_row = self.ui.tableIncidents.selectionModel().selectedRows()[0]
        incident_id = self.ui.tableIncidents.model().data(selected_incident_row)

        # Get field values from GUI elements
        date_time = self.ui.dateUpdateIncidentDateTime.dateTime()
        location_street = self.ui.editUpdateIncidentStreetName.text()
        location_number = self.ui.editUpdateIncidentStreetNo.text()
        gps_x = self.ui.editUpdateIncidentGpsX.text()
        gps_y = self.ui.editUpdateIncidentGpsY.text()
        notes = self.ui.textUpdateIncidentNotes.toPlainText()

        # Get type id of incident
        type_description = self.ui.comboUpdateIncidentType.currentText()
        query = QtSql.QSqlQuery()
        query.prepare("SELECT type_id FROM incident_type WHERE description = ?")
        query.addBindValue(type_description)
        query.exec_()
        while query.next():
            type_id = query.value(0)
        
        # Get member id from combo box text
        member_full_name = self.ui.comboUpdateIncidentReportedBy.currentText()
        reported_by_member_id = member_full_name.split()[0]

        # Validation
        validation_message = ""
        if location_street == "":
            validation_message += "Street name cannot be empty.\n"
        if location_number == "":
            validation_message += "Street number cannot be empty.\n"
        if gps_x == "" or gps_y == "":
            validation_message += "GPS coordinates cannot be empty.\n"
        if not (validation_message == ""):
            showMessageBox(QMessageBox.Warning, "There are some problems with the data.", validation_message, "Oops!")
            return False

        # Update incident in db with new values
        query.prepare("UPDATE incident SET "
            "date_time = ?, type_id = ?, location_street = ?, location_number = ?, gps_x = ?, gps_y = ?, "
            "reported_by_member_id = ?, notes = ? WHERE incident_id = ?")
        query.addBindValue(date_time)
        query.addBindValue(type_id)
        query.addBindValue(location_street)
        query.addBindValue(location_number)
        query.addBindValue(gps_x)
        query.addBindValue(gps_y)
        query.addBindValue(reported_by_member_id)
        query.addBindValue(notes)
        query.addBindValue(incident_id)
        if not query.exec_():
            print(query.lastError().text())
        else:
            print("Row updated successfully")
            self.populateIncidentTableView()
            showMessageBox(QMessageBox.Information, "Incident details updated successfully.", "", "Information")

    def deleteIncident(self):
        # Ask for confirmation of deletion
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Question)
        msg.setText("Are you sure you want to delete this incident?")
        msg.setWindowTitle("Confirm")
        msg.setStandardButtons(QMessageBox.Yes | QMessageBox.No)
        ret = msg.exec_()
        if (ret == QMessageBox.Yes):
            # Get the currently selected incident_id
            selected_row = self.ui.tableIncidents.selectionModel().selectedRows()[0]
            incident_id = self.ui.tableIncidents.model().index(selected_row.row(), 0).data()

            # Delete from db
            query = QtSql.QSqlQuery()
            query.prepare("DELETE FROM incident WHERE incident_id = ?")
            query.addBindValue(incident_id)
            if not query.exec_():
                print(query.lastError().text())
                return False

            # Reload the incidents table            
            self.populateIncidentTableView()

            # Disable the update tab because incident is not there anymore
            self.ui.tabWidgetIncidents.setCurrentIndex(0)
            self.ui.tabWidgetIncidents.setTabEnabled(1, False)
            
            showMessageBox(QMessageBox.Information, "Incident removed.", "", "Information")
        else:
            return False






    # Member related functions
    def populateMemberTableView(self):
        # Set the model of the table to the member table from the db
        self.model = QtSql.QSqlTableModel(self)
        self.model.setTable("member")
        self.model.setEditStrategy(QtSql.QSqlTableModel.OnManualSubmit)
        self.model.select()

        # Set custom names for headers
        self.model.setHeaderData(1, QtCore.Qt.Horizontal, "Name")
        self.model.setHeaderData(2, QtCore.Qt.Horizontal, "Surname")
        self.model.setHeaderData(3, QtCore.Qt.Horizontal, "Callsign")
        self.model.setHeaderData(4, QtCore.Qt.Horizontal, "Contact no.")

        # Hide columns I don't want to show in the table view
        self.ui.tableMembers.setModel(self.model)
        self.ui.tableMembers.hideColumn(0)
        self.ui.tableMembers.hideColumn(5)
        self.ui.tableMembers.hideColumn(6)
        self.ui.tableMembers.hideColumn(7)
        self.ui.tableMembers.hideColumn(8)
        self.ui.tableMembers.hideColumn(9)

        
    def addNewMember(self):
        # Get the values from the GUI elements
        name = self.ui.editNewName.text()
        surname = self.ui.editNewSurname.text()
        callsign = self.ui.editNewCallsign.text()
        contact_number = self.ui.editNewContactNo.text()
        address = self.ui.editNewAddress.text()
        date_joined = self.ui.dateNewDateJoined.date()
        photo = self.ui.labelAddMemberPhoto.filename
        id_number = self.ui.editNewIdNo.text()
        status = 0
        if (self.ui.checkNewStatus.isChecked()):
            status = 1

        # Validation
        validation_message = ""
        if name == "":
            validation_message += "Name field cannot be empty.\n"
        if surname == "":
            validation_message += "Surname field cannot be empty.\n"
        if callsign == "":
            validation_message += "Callsign field cannot be empty.\n"
        if contact_number == "":
            validation_message += "Contact number field cannot be empty.\n"
        if id_number == "":
            validation_message += "ID number field cannot be empty.\n"
        if name.isdigit():
            validation_message += "Please enter a proper name.\n"
        if surname.isdigit():
            validation_message += "Please enter a proper surname.\n"
        if not str(contact_number).isdigit():
            validation_message += "Please enter a proper contact number.\n"
        if (not str(id_number).isdigit()) or (not len(str(id_number)) == 13):
            validation_message += "Please enter a proper ID number.\n"
        if (not len(str(contact_number)) < 11):
            validation_message += "Contact number is too long.\n"
        if not (validation_message == ""):
            showMessageBox(QMessageBox.Warning, "There are some problems with the data.", validation_message, "Oops!")
            return False

        # Prepare sql query for insert
        query = QtSql.QSqlQuery()
        query.prepare("INSERT INTO member "
            "(name, surname, callsign, contact_number, address, date_joined, photo, id_number, status) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)")
        query.addBindValue(name)
        query.addBindValue(surname)
        query.addBindValue(callsign)
        query.addBindValue(contact_number)
        query.addBindValue(address)
        query.addBindValue(date_joined)
        query.addBindValue(photo)
        query.addBindValue(id_number)
        query.addBindValue(status)

        # Insert new row into member table of db
        if query.exec_():
            print ("Row added successfully")
        else:
            print (query.lastError().text())
            return False

        # Show confirmation message
        showMessageBox(QMessageBox.Information, "New member added successfully.", "", "Information")

        # Update member table view
        self.populateMemberTableView()

        # Reset fields to empty values
        self.ui.editNewName.setText("")
        self.ui.editNewName.setFocus()
        self.ui.editNewSurname.setText("")
        self.ui.editNewCallsign.setText("")
        self.ui.editNewContactNo.setText("")
        self.ui.editNewAddress.setText("")
        self.ui.editNewIdNo.setText("")

        # Remove the pixmap from the photo label
        pixmap = QtGui.QPixmap("")
        self.ui.labelAddMemberPhoto.setPixmap(pixmap)


    def populateUpdateMemberForms(self):
        # Get the member_id of the selected row
        selected_row = self.ui.tableMembers.selectionModel().selectedRows()[0]
        member_id = self.ui.tableMembers.model().data(selected_row)

        # Enable tab widget
        self.ui.tabWidgetMembers.setEnabled(True)

        # Get the row of data for the member
        query = QtSql.QSqlQuery()
        query.prepare("SELECT * FROM member WHERE member_id = ?")
        query.addBindValue(member_id)
        query.exec_()
        while(query.next()):
            # Populate all the GUI fields with the data
            self.ui.editManageName.setText(query.value(1))
            self.ui.editManageSurname.setText(query.value(2))
            self.ui.editManageCallsign.setText(query.value(3))
            self.ui.editManageIdNo.setText(str(query.value(8)))
            self.ui.editManageContactNo.setText(str(query.value(4)))
            self.ui.editManageAddress.setText(query.value(5))
            self.ui.dateManageDateJoined.setDate(query.value(6))
            if (query.value(9) == 1):
                self.ui.checkManageStatus.setChecked(True)
            else:
                self.ui.checkManageStatus.setChecked(False)

            # Retrieve path and show image
            #image_data = QtGui.QImage.fromData(query.value(7))
            #pixmap = QtGui.QPixmap.fromImage(image_data)
            #self.ui.labelChangeMemberPhoto.setPixmap(pixmap)

            # Use the photo file path to load a pixmap into a label
            file_path = query.value(7)

            if str(type(file_path)) == "<class 'str'>":
                pixmap = QtGui.QPixmap(file_path)
                self.ui.labelChangeMemberPhoto.setPixmap(pixmap)
                self.ui.labelChangeMemberPhoto.setScaledContents(True)
            else:
                pixmap = QtGui.QPixmap("")
                self.ui.labelChangeMemberPhoto.setPixmap(pixmap)

            # Call function to populate Patrols table view
            self.populateLinkedPatrolsTableView(member_id)


    def updateMemberDetails(self):
        # Get the member_id from the selected table row
        selected_member_row = self.ui.tableMembers.selectionModel().selectedRows()[0]
        member_id = self.ui.tableMembers.model().data(selected_member_row)
        
        # Grab the values from all the GUI fields
        name = self.ui.editManageName.text()
        surname = self.ui.editManageSurname.text()
        callsign = self.ui.editManageCallsign.text()
        id_number = self.ui.editManageIdNo.text()
        contact_number = self.ui.editManageContactNo.text()
        address = self.ui.editManageAddress.text()
        date_joined = self.ui.dateManageDateJoined.date()
        status = 0
        if (self.ui.checkManageStatus.isChecked()):
            status = 1
        photo = self.ui.labelChangeMemberPhoto.filename
        
        #photo = "LOAD_FILE('" + photo_filename + "')"

        # Validation
        validation_message = ""
        if name == "":
            validation_message += "Name field cannot be empty.\n"
        if surname == "":
            validation_message += "Surname field cannot be empty.\n"
        if callsign == "":
            validation_message += "Callsign field cannot be empty.\n"
        if contact_number == "":
            validation_message += "Contact number field cannot be empty.\n"
        if id_number == "":
            validation_message += "ID number field cannot be empty.\n"
        if name.isdigit():
            validation_message += "Please enter a proper name.\n"
        if surname.isdigit():
            validation_message += "Please enter a proper surname.\n"
        if not str(contact_number).isdigit():
            validation_message += "Please enter a proper contact number.\n"
        if (not str(id_number).isdigit()) or (not len(str(id_number)) == 13):
            validation_message += "Please enter a proper ID number.\n"
        if (not len(str(contact_number)) < 11):
            validation_message += "Contact number is too long.\n"
        if not (validation_message == ""):
            showMessageBox(QMessageBox.Warning, "There are some problems with the data.", validation_message, "Oops!")
            return False

        # Prepare query to update member details in db
        query = QtSql.QSqlQuery()
        query.prepare("UPDATE member SET "
            "name = ?, surname = ?, callsign = ?, contact_number = ?, address = ?, date_joined = ?, photo = ?, "
            "id_number = ?, status = ? WHERE member_id = ?")
        query.addBindValue(name)
        query.addBindValue(surname)
        query.addBindValue(callsign)
        query.addBindValue(contact_number)
        query.addBindValue(address)
        query.addBindValue(date_joined)
        query.addBindValue(photo)
        query.addBindValue(id_number)
        query.addBindValue(status)
        query.addBindValue(member_id)

        # Execute query
        if query.exec_():
            print ("Row added successfully")
            self.populateMemberTableView()
            showMessageBox(QMessageBox.Information, "Member details updated successfully.", "", "Information")
        else:
            print (query.lastError().text())


    def findMember(self):
        # Disable the tabs because member is not selected anymore
        self.ui.tabWidgetMembers.setEnabled(False)

        # Reload table with members matching provided term
        search_term = self.ui.editMemberFilterValue.text()
        if search_term == "":
            showMessageBox(QMessageBox.Warning, "Please type in a member's name", "", "Oops!")
            return False
        
        self.model = QtSql.QSqlTableModel(self)
        self.model.setTable("member")
        self.model.setFilter("name like '%" + str(search_term) + "%'")
        self.model.setEditStrategy(QtSql.QSqlTableModel.OnManualSubmit)

        self.model.select()
        self.model.setHeaderData(3, QtCore.Qt.Horizontal, "Week day")
        self.model.setHeaderData(4, QtCore.Qt.Horizontal, "Start time")
        self.model.setHeaderData(5, QtCore.Qt.Horizontal, "End time")
        self.model.setHeaderData(6, QtCore.Qt.Horizontal, "Patrol area")

        self.ui.tableMembers.setModel(self.model)


    def clearMemberFilter(self):
        # Disable the tabs because member is not selected anymore
        self.ui.tabWidgetMembers.setEnabled(False)

        # Clear field contents and reload table
        self.ui.editMemberFilterValue.setText("")
        self.populateMemberTableView()


    def changeMemberPhoto(self):
        filename = self.getPhotoPath()

        # Set the label's pixmap to the file path
        if str(type(filename)) == "<class 'str'>":
            self.ui.labelChangeMemberPhoto.setPixmap(QtGui.QPixmap(filename))
            self.ui.labelChangeMemberPhoto.setScaledContents(True)
            self.ui.labelChangeMemberPhoto.filename = filename
        
        #pixmap = QtGui.QPixmap(self.ui.labelChangeMemberPhoto.filename)
        #byte_array = QtCore.QByteArray()
        #buffer = QtCore.QBuffer(byte_array)
        #buffer.open(QtCore.QIODevice.WriteOnly)
        #pixmap.save(buffer, 'JPG')


    def addMemberPhoto(self):
        # Call function to get the file path
        filename = self.getPhotoPath()

        # Set the label's pixmap to the file path
        if str(type(filename)) == "<class 'str'>":
            self.ui.labelAddMemberPhoto.setPixmap(QtGui.QPixmap(filename))
            self.ui.labelAddMemberPhoto.setScaledContents(True)
            self.ui.labelAddMemberPhoto.filename = filename


    def getPhotoPath(self):
        # Open file dialog to get photo file
        file_dialog = QtGui.QFileDialog()
        file_dialog.setWindowTitle('Open photo file')
        file_dialog.setNameFilter('Images (*.png *.gif *.jpg)')
        #file_dialog.setFileMode(QtGui.QFileDialog.ExistingFile)
        #if file_dialog.exec_() == QtGui.QDialog.Accepted:
        if file_dialog.exec_():
            filename = file_dialog.selectedFiles()[0]
            return filename
        else:
            return False






    # Patrol related functions  
    def populatePatrolTimesTableView(self):
        self.model = QtSql.QSqlTableModel(self)
        self.model.setTable("patrol_time")
        self.model.setEditStrategy(QtSql.QSqlTableModel.OnManualSubmit)
        self.model.select()
        self.model.setHeaderData(1, QtCore.Qt.Horizontal, "Week day")
        self.model.setHeaderData(2, QtCore.Qt.Horizontal, "Start time")
        self.model.setHeaderData(3, QtCore.Qt.Horizontal, "End time")
        self.ui.tablePatrolTimes.setModel(self.model)
        self.ui.tablePatrolTimes.hideColumn(0)

        
    def addNewTimeSlot(self):
        # Get the values from the GUI elements
        week_day = str(self.ui.comboWeekDay.currentText())
        start_hour = str(self.ui.comboStartHour.currentText())
        start_min = str(self.ui.comboStartMin.currentText())
        end_hour = str(self.ui.comboEndHour.currentText())
        end_min = str(self.ui.comboEndMin.currentText())

        # Concatenate hours and minutes to get strings to compare to in the db
        time_start = str(start_hour + ":" + start_min)
        time_end = str(end_hour + ":" + end_min)

        # Validation
        validation_message = ""
        if start_hour == end_hour:
            validation_message = "A patrol must be at least one\nhour in length."
        if not (validation_message == ""):
            showMessageBox(QMessageBox.Warning, validation_message, "", "Oops!")
            return False

        # Check if the record already exists
        query = QtSql.QSqlQuery()
        query.prepare("SELECT (1) FROM patrol_time WHERE week_day = ? AND time_start = ? AND time_end = ?")
        query.addBindValue(week_day)
        query.addBindValue(time_start)
        query.addBindValue(time_end)
        query.exec_()
        if query.size() > 0:
            showMessageBox(QMessageBox.Warning, "That patrol time slot already exists!\nHint: You can order the table by day or time to find it.", "", "Oops!")
            return False

        # Insert new row into patrol_time table of db
        query.prepare("INSERT INTO patrol_time "
            "(week_day, time_start, time_end) "
            "VALUES (?, ?, ?)")
        query.addBindValue(week_day)
        query.addBindValue(time_start)
        query.addBindValue(time_end)
        if query.exec_():
            print ("Row added successfully")
        else:
            print (query.lastError().text())
        
        # Update patrol time table view
        self.populatePatrolTimesTableView()

        showMessageBox(QMessageBox.Information, "New patrol time slot added successfully.", "", "Information")

        
    def removeTimeSlot(self):
        # Check if a table row is selected
        if (self.ui.tablePatrolTimes.currentIndex().row() == -1):
            msg = QMessageBox()
            msg.setIcon(QMessageBox.Information)
            msg.setText("You need to select a patrol time slot first.")
            msg.setWindowTitle("Information")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.exec_()
            return False
        # Ask for confirmation of deletion
        else:
            msg = QMessageBox()
            msg.setIcon(QMessageBox.Question)
            msg.setText("Are you sure you want to remove\nthis time slot?")
            msg.setWindowTitle("Confirm")
            msg.setStandardButtons(QMessageBox.Yes | QMessageBox.No)
            ret = msg.exec_()
            if (ret == QMessageBox.Yes):
                # Remove the row from the table and submit the changes
                self.model.removeRow(self.ui.tablePatrolTimes.currentIndex().row())
                self.model.submitAll()
                # Check if there is an error from the db
                if self.model.lastError():
                    showMessageBox(QMessageBox.Information, "A member patrol is linked to that time slot.\nIt cannot be removed until the patrol is unlinked.", "", "Information")
                else:
                    print ("Row removed.")
                    showMessageBox(QMessageBox.Information, "Patrol time slot removed.", "", "Information")
            else:
                return False


    def populateLinkedPatrolsTableView(self, member_id):
        # Set the model of the table view to the linked_patrols view in the db
        self.model = QtSql.QSqlTableModel(self)
        self.model.setTable("linked_patrols")
        self.model.setFilter("member_id like '" + str(member_id) + "'")
        self.model.setEditStrategy(QtSql.QSqlTableModel.OnManualSubmit)
        self.model.select()

        # Change column headers to custom names
        self.model.setHeaderData(3, QtCore.Qt.Horizontal, "Week day")
        self.model.setHeaderData(4, QtCore.Qt.Horizontal, "Start time")
        self.model.setHeaderData(5, QtCore.Qt.Horizontal, "End time")
        self.model.setHeaderData(6, QtCore.Qt.Horizontal, "Patrol area")

        # Hide columns I don't want to see on the table view
        self.ui.tableLinkedPatrols.setModel(self.model)
        self.ui.tableLinkedPatrols.hideColumn(0)
        self.ui.tableLinkedPatrols.hideColumn(1)
        self.ui.tableLinkedPatrols.hideColumn(2)
        self.ui.tableLinkedPatrols.resizeColumnsToContents()


    def populatePatrolTimeSlotsCombo(self):
        # Get the selected week day
        week_day = str(self.ui.comboAddPatrolWeekDay.currentText())

        # Clear the time slots in the combo in preparation for new list
        self.ui.comboAddPatrolTimeSlot.clear()

        # Prepare query to fetch time slots based on week day
        query = QtSql.QSqlQuery()
        query.prepare("SELECT time_start, time_end FROM patrol_time WHERE week_day = ?")
        query.addBindValue(week_day)

        # Execute the query and build the string to append to the combobox
        query.exec_()
        while query.next():
            time_start = str(query.value(0).toString("hh:mm"))
            time_end = str(query.value(1).toString("hh:mm"))
            time_slot = time_start + " - " + time_end
            self.ui.comboAddPatrolTimeSlot.addItem(time_slot)


    def populatePatrolAreaCombo(self):
        # Prepare and execute query to get descriptions from patrol_area
        query = QtSql.QSqlQuery()
        query.prepare("SELECT description FROM patrol_area")
        query.exec_()
        while query.next():
            area = query.value(0)
            # Append to combo box
            self.ui.comboAddPatrolArea.addItem(area)


    def addPatrolLink(self):
        # Get the member_id from the selected table row
        selected_member_row = self.ui.tableMembers.selectionModel().selectedRows()[0]
        member_id = self.ui.tableMembers.model().data(selected_member_row)

        # Grab the selected values from the comboboxes
        week_day = str(self.ui.comboAddPatrolWeekDay.currentText())
        time_slot = str(self.ui.comboAddPatrolTimeSlot.currentText())
        time_start, x, time_end = time_slot.split()
        area = str(self.ui.comboAddPatrolArea.currentText())

        # Prepare and execute the sql query to get the time_id of the selected time slot
        query = QtSql.QSqlQuery()
        query.prepare("SELECT time_id FROM patrol_time WHERE week_day = ? AND time_start = ? AND time_end = ?")
        query.addBindValue(week_day)
        query.addBindValue(time_start)
        query.addBindValue(time_end)
        if not query.exec_():
            print(query.lastError().text())
        while query.next():
            time_id = query.value(0)

        # Prepare and execute the sql query to get the area_id of the selected area
        query.prepare("SELECT area_id FROM patrol_area WHERE description = ?")
        query.addBindValue(area)
        if not query.exec_():
            print(query.lastError().text())
        while query.next():
            area_id = query.value(0)

        # Prepare and execute the sql queries to check whether the member is already patrolling at those times and if not, insert the row
        query.prepare("SELECT * FROM patrol WHERE member_id = ? AND time_id = ? AND area_id = ?")
        query.addBindValue(member_id)
        query.addBindValue(time_id)
        query.addBindValue(area_id)
        if not query.exec_():
            print(query.lastError().text())
        if query.size() > 0:
            # If a row exists, the member is already patrolling that time
            showMessageBox(QMessageBox.Warning, "Member already linked to that patrol.", "", "Oops!")
        else:
            # If there is no row, insert the new patrol for the member
            query.prepare("INSERT INTO patrol (member_id, time_id, area_id) VALUES (?, ?, ?)")
            query.addBindValue(member_id)
            query.addBindValue(time_id)
            query.addBindValue(area_id)
            if not query.exec_():
                print(query.lastError().text())
            else:
                print("Row added successfully")

            # Refresh the member's patrol table view and the currently patrolling list
            self.populateLinkedPatrolsTableView(member_id)
            self.populateCurrentlyPatrollingList()
            showMessageBox(QMessageBox.Information, "New patrol linked successfully.", "", "Information")


    def removePatrolLink(self):
        # Check that a table row has been selected
        if (self.ui.tableLinkedPatrols.currentIndex().row() == -1):
            msg = QMessageBox()
            msg.setIcon(QMessageBox.Information)
            msg.setText("You need to select a linked patrol first.")
            msg.setWindowTitle("Information")
            msg.setStandardButtons(QMessageBox.Ok)
            msg.exec_()
            return False
        # Ask for confirmation and delete the db row
        else:
            msg = QMessageBox()
            msg.setIcon(QMessageBox.Question)
            msg.setText("Are you sure you want to remove\nthis linked patrol?")
            msg.setWindowTitle("Confirm")
            msg.setStandardButtons(QMessageBox.Yes | QMessageBox.No)
            ret = msg.exec_()
            if (ret == QMessageBox.Yes):
                # Get the selected row
                selected_row = self.ui.tableLinkedPatrols.selectionModel().selectedRows()[0]

                # Get the required values from the selected row
                member_id = self.ui.tableLinkedPatrols.model().index(selected_row.row(), 0).data()
                time_id = self.ui.tableLinkedPatrols.model().index(selected_row.row(), 1).data()
                area_id = self.ui.tableLinkedPatrols.model().index(selected_row.row(), 2).data()

                # Prepare and execute query to delete matching patrol from the db
                query = QtSql.QSqlQuery()
                query.prepare("DELETE FROM patrol WHERE member_id = ? AND time_id = ? AND area_id = ?")
                query.addBindValue(member_id)
                query.addBindValue(time_id)
                query.addBindValue(area_id)
                if not query.exec_():
                    print(query.lastError().text())
                    return False

                # Reload the member's patrol table view
                self.populateLinkedPatrolsTableView(member_id)
                showMessageBox(QMessageBox.Information, "Linked patrol time removed.", "", "Information")
            else:
                return False


    
  

        
def showMessageBox(message_type, msg_text, msg_body, msg_title):
    msg = QMessageBox()
    msg.setIcon(message_type)
    msg.setText(msg_text)
    msg.setInformativeText(msg_body)
    msg.setWindowTitle(msg_title)
    msg.setStandardButtons(QMessageBox.Ok)
    msg.exec_()
	

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    myapp = MyApp()
    myapp.show()
    sys.exit(app.exec_())
