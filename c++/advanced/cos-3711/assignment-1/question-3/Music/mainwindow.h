// Interface file for class 'MainWindow' which represents the view for capturing music
// item information to a model which is viewed in a QTableView. There is a:
//  - Constructor which calls buildGUI(),
//  - addEntry slot to capture the input data from the GUI,
//  - clearForm slot to clear the form after adding an entry,
//  - buildGUI function which initialises/creates all the GUI elements required.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QPushButton>
#include <QTableView>
#include <QDebug>
#include "musicmodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void addEntry();
    void clearForm();

private:
    void buildGUI();
    QLineEdit* m_Composer;
    QLineEdit* m_Title;
    QDoubleSpinBox* m_Cost;
    QSpinBox* m_Rating;
    QPushButton* m_AddButton;
    QTableView* m_TableView;
    MusicModel m_MusicData;
};

#endif // MAINWINDOW_H
