#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>
#include "GUI_MetroSimulation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/**
 * @brief The main window of the Metro Simulation GUI.
 *
 * This class is responsible for creating and managing the Metro Simulation GUI.
 */
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object.
     *
     * @param parent The parent widget of the MainWindow.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys a MainWindow object.
     */
    ~MainWindow();

    /**
     * @brief Updates the GUI with when next or previous buttons have been pressed.
     */
    void updateGUI();

    /**
     * @brief Updates the GUI with when start button has been pressed.
     */
    void updateGUIAuto();

private slots:
    void onPushButton_StartClicked();
    void onPushButton_StopClicked();
    void onPushButton_PreviousClicked();
    void onPushButton_NextClicked();
    void onPushButton_FindRouteClicked();

private:
    Ui::MainWindow *ui;

    std::ostringstream ss;

    std::string filename = "./xmlFiles/sims/input/simAdvanced.xml";
    GUI_MetroSimulation *sim;

    std::vector<std::string> streamStack;
    std::vector<std::vector<int>> statStack;
    int streamStackIndex;


    bool systemStarted;
    bool systemStopped;

    std::vector<int> getSystemStats();
};
#endif // MAINWINDOW_H
