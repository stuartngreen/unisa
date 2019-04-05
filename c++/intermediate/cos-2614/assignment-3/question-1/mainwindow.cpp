// Implementation file for class 'MainWindow'.

#include "mainwindow.h"

// Constructor.
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    // Create application 'pages' and add to stacked widget.
    QWidget* startPage = new QWidget;
    QWidget* formPage = new QWidget;
    QWidget* viewPage = new QWidget;
    m_StackedWidget = new QStackedWidget;
    m_StackedWidget->addWidget(startPage);
    m_StackedWidget->addWidget(formPage);
    m_StackedWidget->addWidget(viewPage);

    // Create layout for start page.
    QVBoxLayout* startLayout = new QVBoxLayout;
    QLabel* startLabel = new QLabel("Select a menu option.");
    startLabel->setAlignment(Qt::AlignCenter);
    startLayout->addWidget(startLabel);
    startPage->setLayout(startLayout);


    // Create layout for form page ('Add Order').
    QVBoxLayout* formLayout = createFormLayout();
    formPage->setLayout(formLayout);


    // Create layout for view page ('View Order List').
    QVBoxLayout* viewLayout = new QVBoxLayout;
    m_TextEdit = new QTextEdit;
    m_TextEdit->setReadOnly(true);
    viewLayout->addWidget(m_TextEdit);
    viewLayout->setContentsMargins(10,10,10,3);
    viewPage->setLayout(viewLayout);


    // Add menu and status bar.
    QMenu* menu = createMenu();
    this->menuBar()->addMenu(menu);
    statusBar();


    //QDialog* test = new QDialog;
    //test->setLayout(formLayout);


    // Setup main window.
    this->resize(300,250);
    this->setWindowTitle("Orders");
    //this->setCentralWidget(test);
    this->setCentralWidget(m_StackedWidget);


    // Connect SIGNALS and SLOTS.
    connect(m_AddOrderAction, SIGNAL(triggered()), SLOT(goToPageTwo()));
    connect(m_ViewOrdersAction, SIGNAL(triggered()), SLOT(goToPageThree()));
    connect(m_QuantityInput, SIGNAL(valueChanged(int)), SLOT(setTotalPrice()));
    connect(m_PriceInput, SIGNAL(valueChanged(double)), SLOT(setTotalPrice()));
    connect(m_OkButton, SIGNAL(clicked()), SLOT(addOrder()));
    connect(m_CancelButton, SIGNAL(clicked()), SLOT(goToPageOne()));
}


// Destructor.
MainWindow::~MainWindow()
{
    qDebug() << "Destroying MainWindow...";
}


// Function to create the main menu.
QMenu* MainWindow::createMenu()
{
    QMenu* menu = new QMenu("&Orders");


    // Configure menu items.
    m_AddOrderAction = new QAction(QIcon(":/icons/add.png"), "&Add Order", this);
    m_AddOrderAction->setStatusTip("Add new order details");

    m_ViewOrdersAction = new QAction(QIcon(":/icons/view.png"), "&View Order List", this);
    m_ViewOrdersAction->setStatusTip("View complete order list and order details");
    m_ViewOrdersAction->setEnabled(false);


    // Add items to menu.
    menu->addAction(m_AddOrderAction);
    menu->addAction(m_ViewOrdersAction);

    return menu;
}


// Function to create the 'Add Order' form layout.
QVBoxLayout* MainWindow::createFormLayout()
{
    // Initialise members related to the form.
    m_NameInput = new QLineEdit;
    m_DateAddedInput = new QDateEdit(QDate::currentDate());
    m_QuantityInput = new QSpinBox;
    m_PriceInput = new QDoubleSpinBox;
    m_TotalPriceInput = new QLineEdit;
    m_OkButton = new QPushButton("&OK");
    m_CancelButton = new QPushButton("&Cancel");


    // Create additional required elements for form.
    QLabel* nameLabel = new QLabel("Name:");
    QLabel* dateAddedLabel = new QLabel("Date Added:");
    QLabel* quantityLabel = new QLabel("Quantity:");
    QLabel* priceLabel = new QLabel("Unit Price:");
    QLabel* totalPriceLabel = new QLabel("Total Price:");


    // Additional settings for fields.
    nameLabel->setMinimumWidth(100);
    m_QuantityInput->setValue(1);
    m_QuantityInput->setMinimum(1);
    m_PriceInput->setValue(0.00);
    m_TotalPriceInput->setStyleSheet("background-color: #eee");
    m_TotalPriceInput->setReadOnly(true);
    setTotalPrice();


    // Create layouts.
    QVBoxLayout* formPageLayout = new QVBoxLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QFormLayout* formLayout = new QFormLayout;


    // Set some margins on the layouts.
    formLayout->setContentsMargins(8,8,8,0);
    formLayout->setSpacing(10);
    buttonLayout->setContentsMargins(8,8,8,0);
    buttonLayout->setSpacing(10);


    // Build the form layout.
    formLayout->setWidget(1, QFormLayout::LabelRole, nameLabel);
    formLayout->setWidget(1, QFormLayout::FieldRole, m_NameInput);
    formLayout->setWidget(2, QFormLayout::LabelRole, dateAddedLabel);
    formLayout->setWidget(2, QFormLayout::FieldRole, m_DateAddedInput);
    formLayout->setWidget(3, QFormLayout::LabelRole, quantityLabel);
    formLayout->setWidget(3, QFormLayout::FieldRole, m_QuantityInput);
    formLayout->setWidget(4, QFormLayout::LabelRole, priceLabel);
    formLayout->setWidget(4, QFormLayout::FieldRole, m_PriceInput);
    formLayout->setWidget(5, QFormLayout::LabelRole, totalPriceLabel);
    formLayout->setWidget(5, QFormLayout::FieldRole, m_TotalPriceInput);

    buttonLayout->addWidget(m_OkButton);
    buttonLayout->addWidget(m_CancelButton);

    formPageLayout->addLayout(formLayout);
    formPageLayout->addLayout(buttonLayout);

    return formPageLayout;
}


// Set the total price when modifying price or quantity.
void MainWindow::setTotalPrice()
{
    m_TotalPriceInput->setText(QString::number(m_QuantityInput->value() * m_PriceInput->value(), 'f', 2));
}


// Capture new order information.
void MainWindow::addOrder()
{
    if (m_NameInput->text() != "")
    {
        // Get all the values from the form.
        QString name = m_NameInput->text();
        QDate date = m_DateAddedInput->date();
        int quantity = m_QuantityInput->value();
        double price = m_PriceInput->value();
        double totalPrice = m_TotalPriceInput->text().toDouble();


        // Create an Order and append to OrderList.
        Order* o = new Order(name, date, quantity, price, totalPrice);
        m_OrderList.addOrder(o);


        // Append order to TextEdit display.
        m_TextEdit->append(o->toString());


        // Enable the 'View Order List' menu item.
        if (!m_ViewOrdersAction->isEnabled())
            m_ViewOrdersAction->setEnabled(true);


        // Show success message.
        QMessageBox::information(0, "Order Added", "Order added to the list.", QMessageBox::Ok);
    }
    else
    {
        // Show warning.
        QMessageBox::warning(0, "Oops", "Please type in a name.", QMessageBox::Ok);
    }
}


// Function to set the index of the QStackedWidget.
void MainWindow::setStackedIndex(int i) const
{
    m_StackedWidget->setCurrentIndex(i);
}


// SLOTS for navigating between pages.
void MainWindow::goToPageOne()
{
    emit setStackedIndex(0);
}

void MainWindow::goToPageTwo()
{
    emit setStackedIndex(1);
}

void MainWindow::goToPageThree()
{
    emit setStackedIndex(2);
}
