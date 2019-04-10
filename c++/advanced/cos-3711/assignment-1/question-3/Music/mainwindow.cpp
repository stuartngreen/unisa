// Implementation file for class 'MainWindow'.

#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include "mainwindow.h"
#include "currencydelegate.h"

// Constructor.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Add a music item to the model for fun.
    MusicItem acdc;
    acdc.composer = "AC/DC";
    acdc.title = "Back in Black";
    acdc.cost = 85.49;
    acdc.rating = 90;
    m_MusicData.insertData(acdc);

    buildGUI();
}

// Destructor.
MainWindow::~MainWindow()
{
}

// Function to build and setup the GUI elements.
void MainWindow::buildGUI()
{
    setWindowTitle("Music Collection");
    QWidget* widget = new QWidget;

    // Initialise and setup data members for the input form.
    m_Composer = new QLineEdit;
    m_Title = new QLineEdit;
    m_Cost = new QDoubleSpinBox;
    m_Cost->setDecimals(2);
    m_Cost->setAlignment(Qt::AlignRight);
    m_Cost->setMinimum(0);
    m_Cost->setMaximum(9999);
    m_Rating = new QSpinBox;
    m_Rating->setAlignment(Qt::AlignRight);
    m_Rating->setMinimum(0);
    m_Rating->setMaximum(100);
    m_AddButton = new QPushButton("Add Entry");
    m_TableView = new QTableView;

    // Create other visual elements for GUI.
    QGridLayout* grid = new QGridLayout;
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel* composerLabel = new QLabel("Composer");
    QLabel* titleLabel = new QLabel("Album Title");
    QLabel* costLabel = new QLabel("Replacement Cost (R)");
    QLabel* ratingLabel = new QLabel("Rating");

    // Set the model of the table view.
    m_TableView->setModel(&m_MusicData);
    m_TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set custom formats for the "Replacement Cost" column.
    CurrencyDelegate* currencyDel = new CurrencyDelegate;
    m_TableView->setItemDelegateForColumn(2, currencyDel);

    // Setup layout.
    grid->setSpacing(10);
    grid->addWidget(composerLabel, 0, 0);
    grid->addWidget(titleLabel, 0, 1);
    grid->addWidget(costLabel, 0, 2);
    grid->addWidget(ratingLabel, 0, 3);
    grid->addWidget(m_Composer, 1, 0);
    grid->addWidget(m_Title, 1, 1);
    grid->addWidget(m_Cost, 1, 2);
    grid->addWidget(m_Rating, 1, 3);
    grid->addWidget(m_AddButton, 1, 4);

    layout->addLayout(grid);
    layout->addWidget(m_TableView);

    widget->setLayout(layout);
    this->setCentralWidget(widget);

    // Connect button to slot.
    connect(m_AddButton, SIGNAL(clicked()), this, SLOT(addEntry()));
}

// Function to add an entry to the table view.
void MainWindow::addEntry()
{
    if (m_Composer->text() == "" || m_Title->text() == "")
        QMessageBox::warning(this, "Oops", "Please supply all the necessary information.");
    else
    {
        // Create a MusicItem and insert it into the model.
        MusicItem musicItem;
        musicItem.composer = m_Composer->text();
        musicItem.title = m_Title->text();
        musicItem.cost = m_Cost->value();
        musicItem.rating = m_Rating->value();

        m_MusicData.insertData(musicItem);
        clearForm();
    }
}

// Function to clear the form after adding an entry.
void MainWindow::clearForm()
{
    m_Composer->setText("");
    m_Title->setText("");
    m_Cost->setValue(0);
    m_Rating->setValue(0);
}
