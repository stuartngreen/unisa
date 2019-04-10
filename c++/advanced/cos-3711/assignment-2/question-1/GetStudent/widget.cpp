// Implementation file for class 'Widget'.

#include "widget.h"

// Constructor.
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    buildGui();
}

// Destructor
Widget::~Widget()
{
}

// Function to build and setup the GUI elements.
void Widget::buildGui()
{
    setWindowTitle("Get Student");

    // Initialise members for the form.
    m_StudentNumberInput = new QLineEdit;
    m_ModuleCodeInput = new QLineEdit;
    m_MarkInput = new QSpinBox;
    m_AddButton = new QPushButton("Add");

    // Create other elements for input form.
    QGridLayout* layout = new QGridLayout;
    QLabel* studentNumberLabel = new QLabel("Student number: ");
    QLabel* addModuleLabel = new QLabel("Add module:");
    addModuleLabel->setStyleSheet("font-weight: bold");
    QLabel* moduleCode = new QLabel("Module code:");
    QLabel* markLabel = new QLabel("Mark (%): ");

    // Set input masks and limits.
    // Assumptions:
    // - Student numbers start at 1000 (4 digits).
    // - Letters in module codes should be uppercase.
    m_StudentNumberInput->setInputMask("D999");
    m_ModuleCodeInput->setInputMask(">AAAD99N");
    m_MarkInput->setMinimum(0);
    m_MarkInput->setMaximum(100);

    // Setup layout.
    layout->setSpacing(10);
    layout->addWidget(studentNumberLabel, 0, 0);
    layout->addWidget(m_StudentNumberInput, 0, 1);
    layout->addWidget(addModuleLabel, 1, 0);
    layout->addWidget(moduleCode, 2, 0);
    layout->addWidget(m_ModuleCodeInput, 2, 1);
    layout->addWidget(markLabel, 3, 0);
    layout->addWidget(m_MarkInput, 3, 1);
    layout->addWidget(m_AddButton, 4, 1);
    this->resize(250, 155);
    this->setLayout(layout);

    // Connect button to slot.
    connect(m_AddButton, SIGNAL(clicked()), this, SLOT(captureInfo()));
}

// Function to capture entered information and output to the console.
void Widget::captureInfo()
{
    // Get the values from the GUI.
    QString studentNumber = m_StudentNumberInput->text();
    QString moduleCode = m_ModuleCodeInput->text();
    QString mark = QString::number(m_MarkInput->value());

    // Validate the inputs with regular expressions.
    if (validateInput(studentNumber, QRegExp("^[1-9]\\d{3}$")) &&
        validateInput(moduleCode, QRegExp("^[A-Z]{3}[123]\\d{2}[A-Z0-9]$")) &&
        validateInput(mark, QRegExp("^[0-9]$|^[1-9][0-9]$|^(100)$")))
    {
        // Output the values
        QTextStream cout(stdout);
        QString output = studentNumber + " " + moduleCode + " " + mark;
        cout << output << endl;

        QMessageBox::information(this, "Added", "Student/modules information added.");
    }
    else
    {
        QString error = "Incorrect format.\n\nStudent number should be in the format: 4 digits (0-9), e.g. 1234\n\nModule code should be in the format: 3 uppercase letters, then a 1, 2 or 3, then 2 more digits (0-9), then another alpha-numeric character, e.g. COS3711 or COS371X.\n\nMark should be between 0 and 100.";
        QMessageBox::warning(this, "Oops", error);
    }
}

// Function to validate the input using regular expressions.
bool Widget::validateInput(QString input, QRegExp regex)
{
    return regex.exactMatch(input);
}
