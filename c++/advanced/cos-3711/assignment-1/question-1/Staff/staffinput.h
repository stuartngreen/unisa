// Interface file for class 'StaffInput' which builds the GUI and enables the user
// to capture staff member information. There is a:
//  - constructor and destructor,
//  - captureInfo function to capture user entered information from the GUI and save it to a file/list,
//  - buildGUI function to build and setup the GUI elements.

#ifndef STAFFINPUT_H
#define STAFFINPUT_H

#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include "staffmember.h"
#include "stafflist.h"
#include "staffoutput.h"

class StaffInput: public QWidget
{
    Q_OBJECT

public:
    StaffInput();
    ~StaffInput();

public slots:
    void captureInfo();

private:
    void buildGUI();
    QLineEdit* m_NameInput;
    QDateEdit* m_BirthDateInput;
    QComboBox* m_ApptTypeSelect;
    QPushButton* m_SaveButton;
    StaffList m_StaffList;
};

#endif // STAFFINPUT_H
