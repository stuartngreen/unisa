// Implementation file for class 'Widget'.

#include "widget.h"

// Constructor.
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    buildGui();

    // Initialise the process and connect the SIGNAL for the process output.
    m_Process = new QProcess(0);
    connect(m_Process, SIGNAL(readyReadStandardOutput()), this, SLOT(readFromProcess()));
}

// Destructor.
Widget::~Widget()
{
}

// Function to build and setup the GUI elements.
void Widget::buildGui()
{
    setWindowTitle("Process Student");

    // Initialise members for the form.
    m_AddModuleButton = new QPushButton("Add Module");
    m_TextEdit = new QTextEdit;

    // Setup layout.
    QGridLayout* layout = new QGridLayout;
    layout->setSpacing(10);
    layout->addWidget(m_AddModuleButton, 0, 0);
    layout->addWidget(m_TextEdit, 1, 0);
    this->resize(300, 250);
    this->setLayout(layout);

    // Connect button to slot.
    connect(m_AddModuleButton, SIGNAL(clicked()), this, SLOT(startGetStudent()));
}

// Function to start the GetStudent process.
void Widget::startGetStudent()
{
    m_Process->start("GetStudent.exe");
}

// Function to read output from the GetStudent process.
void Widget::readFromProcess()
{
    // Get the contents of the process output.
    QString output = QString(m_Process->readAllStandardOutput());

    // Append output from the process to the text edit.
    m_TextEdit->append(output);
}
