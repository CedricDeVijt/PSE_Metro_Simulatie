#include "mainwindow.h"
#include "SimThread.h"
#include "./ui_mainwindow.h"
#include "../src/MetroSimStatistics.h"

const std::string INPUTPATH = "../xmlFiles/sims/input/";
const std::string OUTPUTPATH = "../xmlFiles/sims/output/";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Metro simulation for GUI
    sim = new GUI_MetroSimulation(filename, &ss,100, true);

    systemStarted = false;
    systemStopped = false;
    streamStackIndex = 0;

    // Connect signals to slots
    connect(sim, &GUI_MetroSimulation::simulationProgressed, this, &MainWindow::updateGUIAuto);
    connect(ui->pushButton_Start, SIGNAL(clicked()), this, SLOT(onPushButton_StartClicked()));
    connect(ui->pushButton_Stop, SIGNAL(clicked()), this, SLOT(onPushButton_StopClicked()));
    connect(ui->pushButton_Previous, SIGNAL(clicked()), this, SLOT(onPushButton_PreviousClicked()));
    connect(ui->pushButton_Next, SIGNAL(clicked()), this, SLOT(onPushButton_NextClicked()));
    connect(ui->pushButton_FindRoute, SIGNAL(clicked()), this, SLOT(onPushButton_FindRouteClicked()));

    // Add stations to comboxes in navigation
    std::vector<TramStop *> stations = sim->getSystem()->getStations();
    for (int i = 0; i < (int)stations.size(); ++i) {
        QString name = QString::fromStdString(stations[i]->getName());
        ui->comboBox->addItem(name);
        ui->comboBox_2->addItem(name);
    }

    // Set stat labels
    ui->label_6->setText("/");
    ui->label_7->setText("/");
    ui->label_9->setText("/");
    ui->label_10->setText("/");
    ui->label_16->setText("/");

    streamStack.push_back(ss.str());
    statStack.push_back(getSystemStats());
}

MainWindow::~MainWindow(){
    delete ui;
    delete sim;
}

void MainWindow::onPushButton_StartClicked() {
    if (not systemStarted) {
        ui->textBrowser_Simulation->append("Started simulation");
        SimThread *thread = new SimThread(sim, &ss);
        thread->start();  //start the thread
        systemStarted = true;
    } else {
        ui->textBrowser_Simulation->append("Simulation already started.");
    }
}

void MainWindow::onPushButton_StopClicked(){
    if (not systemStarted) {
        ui->textBrowser_Simulation->append("System hasn't been started yet");
    } else if (not systemStopped){
        sim->stopSystem();
        ui->textBrowser_Simulation->append("Stopped simulation");
        systemStopped = true;
    } else {
        ui->textBrowser_Simulation->append("Simulation is already stopped");
    }
}

void MainWindow::onPushButton_NextClicked(){
    systemStarted = true;
    if (not systemStopped){
        if (streamStackIndex == (int)streamStack.size()-1){
            streamStackIndex++;
            sim->updateTime();
            ss.str("");
            sim->getSystem()->updateSystem();
            // Push new data
            statStack.push_back(getSystemStats());
            streamStack.push_back(ss.str());

        } else {
            streamStackIndex++;
        }
        ss.str("");
        for (int i = 0; i < streamStackIndex+1; ++i) {
            ss << streamStack[i];
        }
        updateGUI();
    }
}

void MainWindow::onPushButton_PreviousClicked(){
    if (not systemStopped){
        if (streamStackIndex >= 0){
            streamStackIndex--;
            ss.str("");
            for (int i = 0; i < streamStackIndex+1; ++i) {
                ss << streamStack[i];
            }
            updateGUI();
        } else {
            ss.str("");
        }
        updateGUI();
    }
}

void MainWindow::onPushButton_FindRouteClicked() {
    ui->textBrowser_2->clear();
    if (ui->comboBox->currentText() == ui->comboBox_2->currentText()){
        ui->textBrowser_2->append("You are already at your destination.");
    } else {
        std::string from = ui->comboBox->currentText().toStdString();
        std::string to = ui->comboBox_2->currentText().toStdString();
        std::pair<std::vector<TramStop *>, std::vector<Line *>> route = sim->getSystem()->getRoute(from, to);
        if (route.second.empty()){
            // No route
            ui->textBrowser_2->append("No possible route to your destination.");
        } else if ((int)route.first.size() == 2) {
            // Route on one track
            TramStop* beginStop = route.first[0];
            TramStop* endStop = route.first[1];
            Line* line = route.second[0];

            ui->textBrowser_2->append("Route from station " + QString::fromStdString(beginStop->getName()) + " to " + QString::fromStdString(endStop->getName()));
            ui->textBrowser_2->append("Line " + QString::number(line->getLineNumber()) + ":");
            ui->textBrowser_2->append("Station " + QString::fromStdString(beginStop->getName()));

            TramStop* currentStop = beginStop;
            while (currentStop != endStop){
                currentStop = line->getNext(currentStop);
                ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
            }
        } else {
            // Route with connection
            TramStop* beginStop = route.first[0];
            TramStop* connectionStop = route.first[1];
            TramStop* endStop = route.first[2];
            Line* beginLine = route.second[0];
            Line* endLine = route.second[1];

            ui->textBrowser_2->append("Route from station " + QString::fromStdString(beginStop->getName()) + " to " + QString::fromStdString(endStop->getName()));
            ui->textBrowser_2->append("Line " + QString::number(beginLine->getLineNumber()) + ":");

            TramStop* currentStop = beginStop;
            while (currentStop != connectionStop) {
                ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
                currentStop = beginLine->getNext(currentStop);
            }
            ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
            ui->textBrowser_2->append("Line " + QString::number(endLine->getLineNumber()) + ":");
            while (currentStop != endStop){
                ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
                currentStop = endLine->getNext(currentStop);
            }
            ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
        }
    }
}

void MainWindow::updateGUI() {

    std::vector<int> stats = statStack[streamStackIndex];

    // Time label
    ui->label_6->setText(QString::number(stats[0]));
    // Total Trams  label
    ui->label_7->setText(QString::number(stats[1] + stats[2]));
    // Working trams
    ui->label_9->setText(QString::number(stats[1]));
    // Broken trams
    ui->label_10->setText(QString::number(stats[2]));
    // Total cost
    ui->label_16->setText(QString::number(stats[3]));

    ui->textBrowser_Simulation->clear();

    ui->textBrowser_Simulation->append("Started simulation");
    ui->textBrowser_Simulation->append(QString::fromStdString(ss.str()));


}

void MainWindow::updateGUIAuto() {
    std::vector<int> stats= getSystemStats();
    // Time label
    ui->label_6->setText(QString::number(stats[0]));
    // Total Trams  label
    ui->label_7->setText(QString::number(stats[1] + stats[2]));
    // Working trams
    ui->label_9->setText(QString::number(stats[1]));
    // Broken trams
    ui->label_10->setText(QString::number(stats[2]));
    // Total cost
    ui->label_16->setText(QString::number(stats[3]));

    ui->textBrowser_Simulation->clear();

    ui->textBrowser_Simulation->append("Started simulation");
    ui->textBrowser_Simulation->append(QString::fromStdString(ss.str()));
}

std::vector<int> MainWindow::getSystemStats() {
    MetroSimStatistics *stats = new MetroSimStatistics(sim);
    return {
            stats->getTime(),
            stats->getWorkingTrams(),
            stats->getDefectTrams(),
            stats->getTotalCost()
    };
}
