// Interface file for class 'Widget' which builds a GUI for the GetStudent app to capture
// student code, module code, and student mark. There is a:
// - constructor and destructor,
// - captureInfo function to capture entered information and output to the console,
// - validateInput function to validate the input using regular expressions,
// - buildGui function to build and setup the GUI elements.

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGridLayout>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QRegExp>
#include "widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void captureInfo();
    bool validateInput(QString input, QRegExp regex);

private:
    void buildGui();
    QLineEdit* m_StudentNumberInput;
    QLineEdit* m_ModuleCodeInput;
    QSpinBox* m_MarkInput;
    QPushButton* m_AddButton;
};

#endif // WIDGET_H
