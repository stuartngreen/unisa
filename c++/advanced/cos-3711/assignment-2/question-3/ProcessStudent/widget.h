// Interface file for class 'Widget' which provides a GUI for checking students' details,
// average mark, whether they qualify for graduation, and to add student and module information
// to a list. There is a:
// - constructor and destructor,
// - buildGui() function to build and setup the GUI elements,
// - startGetStudent() slot to start the GetStudent process,
// - readFromProcess() slot to read output from the GetStudent process,
// - validateStudentNum() function to validate the student number format,
// - displayDetails() slot to display the details associated with the student number,
// - displayAverage() function to show the student's average marks,
// - displayGraduateEval() function to display whether the student has qualified for graduation.

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QProcess>
#include <QMessageBox>
#include <QRegExp>
#include "widget.h"
#include "student.h"
#include "studentlist.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void startGetStudent();
    void readFromProcess();
    void displayDetails();
    void displayAverage();
    void displayGraduateEval();

private:
    void buildGui();
    bool validateStudentNum(QString studentNum);

    QLineEdit* m_StudentNumInput;
    QPushButton* m_DisplayDetailsButton;
    QPushButton* m_CalculateAverageButton;
    QPushButton* m_GraduateButton;
    QPushButton* m_AddModuleButton;
    QTextEdit* m_TextEdit;
    QProcess* m_Process;
};

#endif // WIDGET_H
