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
    m_StudentNumInput = new QLineEdit;
    m_StudentNumInput->setInputMask("D999");
    m_DisplayDetailsButton = new QPushButton("Display Details");
    m_CalculateAverageButton = new QPushButton("Calculate Average");
    m_GraduateButton = new QPushButton("Graduate?");
    m_AddModuleButton = new QPushButton("Add Module");
    m_TextEdit = new QTextEdit;

    // Setup additional layout elements.
    QGridLayout* grid = new QGridLayout;
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel* studentNumLabel = new QLabel("Student number: ");

    // Setup layout.
    grid->setSpacing(10);
    grid->addWidget(studentNumLabel, 0, 0);
    grid->addWidget(m_StudentNumInput, 0, 1);
    grid->addWidget(m_DisplayDetailsButton, 2, 0);
    grid->addWidget(m_CalculateAverageButton, 2, 1);
    grid->addWidget(m_GraduateButton, 2, 2);
    grid->addWidget(m_AddModuleButton, 2, 3);
    layout->setSpacing(10);
    layout->addLayout(grid);
    layout->addWidget(m_TextEdit);
    this->resize(400, 300);
    this->setLayout(layout);

    // Connect buttons to slots.
    connect(m_DisplayDetailsButton, SIGNAL(clicked()), this, SLOT(displayDetails()));
    connect(m_CalculateAverageButton, SIGNAL(clicked()), this, SLOT(displayAverage()));
    connect(m_GraduateButton, SIGNAL(clicked()), this, SLOT(displayGraduateEval()));
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

    // Process the string.
    QStringList splitOutput = output.split(" ");
    QString studentNum = splitOutput[0];
    QString moduleCode = splitOutput[1];
    double mark = splitOutput[2].toDouble();

    // Create a student object.
    Student* student = new Student;
    student->setNumber(studentNum);
    student->addModule(moduleCode, mark);

    // Add student to the list.
    StudentList* studentList = StudentList::instance();
    studentList->addStudent(student);
}

// Function to validate the student number format.
bool Widget::validateStudentNum(QString studentNum)
{
    QRegExp regex("^[1-9]\\d{3}$");
    if (regex.exactMatch(studentNum))
        return true;
    else
    {
        QMessageBox::warning(this, "Oops", "Please enter a valid student number (e.g. 1234).");
        return false;
    }
}

// Function to display the details associated with the student number.
void Widget::displayDetails()
{
    m_TextEdit->clear();
    QString studentNum = m_StudentNumInput->text();

    // Get the index of the student in the list.
    StudentList* studentList = StudentList::instance();
    int index = studentList->getStudentIndex(studentNum);

    if (validateStudentNum(studentNum))
    {
        if (index != -1)
            m_TextEdit->append(studentList->at(index)->toString());
        else
            QMessageBox::information(this, "Not found", "Student with number " + studentNum + " not found.");
    }
}

// Function to show the student's average marks.
void Widget::displayAverage()
{
    m_TextEdit->clear();
    QString studentNum = m_StudentNumInput->text();

    // Get the index of the student in the list.
    StudentList* studentList = StudentList::instance();
    int index = studentList->getStudentIndex(studentNum);

    if (validateStudentNum(studentNum))
    {
        if (index != -1)
        {
            m_TextEdit->append("Student number: " + studentNum);
            m_TextEdit->append("Average mark: " + QString::number(studentList->at(index)->average()) + "%");
        }
        else
            QMessageBox::information(this, "Not found", "Student with number " + studentNum + " not found.");
    }
}

// Function to display whether the student has qualified for graduation.
void Widget::displayGraduateEval()
{
    m_TextEdit->clear();
    QString studentNum = m_StudentNumInput->text();

    // Get the index of the student in the list.
    StudentList* studentList = StudentList::instance();
    int index = studentList->getStudentIndex(studentNum);

    if (validateStudentNum(studentNum))
    {
        if (index != -1)
        {
            m_TextEdit->append("Student number: " + studentNum);

            if (studentList->at(index)->graduate())
                m_TextEdit->append("This student qualifies for graduation.");
            else
                m_TextEdit->append("Unfortunately, this student does not qualify for graduation.");
        }
        else
            QMessageBox::information(this, "Not found", "Student with number " + studentNum + " not found.");
    }
}
