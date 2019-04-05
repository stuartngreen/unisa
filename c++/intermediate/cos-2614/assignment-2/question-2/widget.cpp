// Implementation file for class 'Widget'.
#include "widget.h"

// Constructor which builds the GUI and connects SIGNALS to SLOTS.
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    // Initialise or create all the elements for the GUI.
    m_StartButton = new QPushButton("Start", this);
    m_StopButton = new QPushButton("Stop", this);
    m_TimeInput = new QLineEdit(this);
    m_MessageOutput = new QLabel(this);

    QLabel* instrText = new QLabel(this);
    QLabel* msText = new QLabel(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* inputFormLayout = new QHBoxLayout();

    // Style the message output box.
    QFont font("Calisto MT", 11);
    m_MessageOutput->setFont(font);
    m_MessageOutput->setFrameStyle(QFrame::Box | QFrame::Sunken);
    m_MessageOutput->setLineWidth(0);
    m_MessageOutput->setMidLineWidth(1);
    m_MessageOutput->setStyleSheet("QLabel { background-color: #fff; }");
    m_MessageOutput->setWordWrap(true);
    m_MessageOutput->setAlignment(Qt::AlignCenter);
    m_MessageOutput->setMargin(10);
    m_MessageOutput->setMinimumHeight(100);

    // Set labels text and style.
    instrText->setText("Enter a time interval between 5000 and 20000 milliseconds.");
    instrText->setAlignment(Qt::AlignHCenter);
    msText->setText("ms");

    // Set validation and style the milliseconds input field.
    QValidator* validator = new QIntValidator(5000, 20000, this);
    m_TimeInput->setValidator(validator);
    m_TimeInput->setAlignment(Qt::AlignRight);
    m_TimeInput->setMaximumWidth(75);
    m_TimeInput->setText("5000");

    // Disable the stop button initially.
    m_StopButton->setDisabled(true);

    // Connect the SIGNALS to SLOTS.
    connect(m_StartButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(m_StopButton, SIGNAL(clicked()), this, SLOT(stop()));

    // Build the layout.
    inputFormLayout->addWidget(m_TimeInput);
    inputFormLayout->addWidget(msText);
    inputFormLayout->addWidget(m_StartButton);
    inputFormLayout->addWidget(m_StopButton);
    layout->addWidget(instrText);
    layout->addLayout(inputFormLayout);
    layout->addWidget(m_MessageOutput);

    // Set the widget size and title.
    this->resize(350,175);
    setWindowTitle("Timed Messages");

    this->setLayout(layout);
}

// Destructor.
Widget::~Widget()
{
}

// Initialises the private member list with content.
void Widget::init(MessageList *messageList)
{
    m_MessageList = messageList;
}

// Validates input and starts a timer to call update().
void Widget::start()
{
    //qDebug() << m_TimeInput->text();
    if (m_TimeInput->hasAcceptableInput())
    {
        bool ok = true;
        int time = m_TimeInput->text().toInt(&ok, 10);

        m_Timer = new QTimer(this);
        connect(m_Timer, SIGNAL(timeout()), this, SLOT(update()));
        m_Timer->start(time);

        // Enable/disable buttons appropriately.
        m_TimeInput->setDisabled(true);
        m_StartButton->setDisabled(true);
        m_StopButton->setDisabled(false);
    }
    else
    {
        QMessageBox::warning(0, "Oops", "Please enter a number between 5000 and 20000.", QMessageBox::Ok);
    }
}

// Stops the timer function and enables/disables buttons appropriately.
void Widget::stop()
{
    m_Timer->stop();
    m_TimeInput->setDisabled(false);
    m_StartButton->setDisabled(false);
    m_StopButton->setDisabled(true);
}

// Displays a random message returned from the MessageList member function.
void Widget::update()
{
    m_MessageOutput->setText(m_MessageList->getMessage());
}
