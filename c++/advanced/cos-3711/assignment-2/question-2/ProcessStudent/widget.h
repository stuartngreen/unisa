// Interface file for class 'Widget' which builds a GUI for the ProcessStudent app to start
// the GetStudent process and receive data. There is a:
// - constructor and destructor,
// - startGetStudent function to start the GetStudent process,
// - readFromProcess function to read output from the GetStudent process,
// - buildGui function to build and setup the GUI elements.

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QProcess>
#include "widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void startGetStudent();
    void readFromProcess();

private:
    void buildGui();
    QPushButton* m_AddModuleButton;
    QTextEdit* m_TextEdit;
    QProcess* m_Process;
};

#endif // WIDGET_H
