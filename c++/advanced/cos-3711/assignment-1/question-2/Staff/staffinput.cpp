// Implementation file for class 'StaffInput'.

#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>
#include "staffinput.h"

// Constructor.
StaffInput::StaffInput()
{
    buildGUI();
}

// Destructor.
StaffInput::~StaffInput()
{
}

// Function to build and setup the GUI elements.
void StaffInput::buildGUI()
{
    setWindowTitle("Staff Members");

    // Initialise members for the form.
    m_NameInput = new QLineEdit;
    m_BirthDateInput = new QDateEdit;
    m_ApptTypeSelect = new QComboBox;
    m_SaveButton = new QPushButton("Save to File");

    // Create other elements for input form.
    QGridLayout* layout = new QGridLayout;
    QLabel* nameLabel = new QLabel("Name: ");
    QLabel* birthDateLabel = new QLabel("Birth Date: ");
    QLabel* apptTypeLabel = new QLabel("Appointment Type: ");

    // Setup layout.
    layout->setSpacing(10);
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(m_NameInput, 0, 1);
    layout->addWidget(birthDateLabel, 1, 0);
    layout->addWidget(m_BirthDateInput, 1, 1);
    layout->addWidget(apptTypeLabel, 2, 0);
    layout->addWidget(m_ApptTypeSelect, 2, 1);
    layout->addWidget(m_SaveButton, 3, 1);
    nameLabel->setMinimumWidth(120);
    this->resize(300, 135);
    this->setLayout(layout);

    // Add items to combobox.
    m_ApptTypeSelect->insertItem(m_ApptTypeSelect->count(), "Permanent", StaffMember::Permanent);
    m_ApptTypeSelect->insertItem(m_ApptTypeSelect->count(), "Part Time", StaffMember::PartTime);
    m_ApptTypeSelect->insertItem(m_ApptTypeSelect->count(), "Contract", StaffMember::Contract);

    // Connect button to slot.
    connect(m_SaveButton, SIGNAL(clicked()), this, SLOT(captureInfo()));
}

// Function to capture user entered information from the GUI and save to file/list.
void StaffInput::captureInfo()
{
    // Get the values from the GUI.
    QString name = m_NameInput->text();
    QDate birthDate = m_BirthDateInput->date();
    int enumVal = m_ApptTypeSelect->itemData(m_ApptTypeSelect->currentIndex()).toInt();

    if (!name.isEmpty() && birthDate.isValid())
    {
        // Create StaffMember object to save.
        StaffMember* staff = new StaffMember(name, birthDate, (StaffMember::ApptType)enumVal);

        // Appending to list.
        m_StaffList.addStaffMember(staff);
        qDebug() << "\nOutputting Staff List:" << endl;
        qDebug() << m_StaffList.toString();

        // Appending to file.
        ObjectOutput output("stafflist.txt");

        if (output.saveToFile(staff))
            QMessageBox::information(this, "Success", "Staff member written to file successfully. Check the build folder.");
        else
            QMessageBox::critical(this, "Oh no...", "Something went wrong... file NOT updated.");
    }
    else
    {
        QMessageBox::warning(this, "Oops", "Please enter all the information.");
    }
}
