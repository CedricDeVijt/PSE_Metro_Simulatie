#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>
#include "GUI_MetroSimulation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateGUI();

private slots:
    void onPushButton_StartClicked();
    void onPushButton_StopClicked();
    void onPushButton_PreviousClicked();
    void onPushButton_NextClicked();
    void onPushButton_FindRouteClicked();

private:
    Ui::MainWindow *ui;

    std::ostringstream ss;

    std::string filename = "./xmlFiles/sims/input/simAdvanced.xml.xml";
    GUI_MetroSimulation *sim;

    std::vector<std::string> streamStack;
    std::vector<std::vector<int>> statStack;
    int streamStackIndex;


    bool systemStarted;
    bool systemStopped;

    std::vector<int> getSystemStats();
};
#endif // MAINWINDOW_H
