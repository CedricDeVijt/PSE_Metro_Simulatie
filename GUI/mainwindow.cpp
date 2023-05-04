#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../src/MetroSimulation.h"
#include "../src/MetroSimStatistics.h"
#include "SimThread.h"

const std::string INPUTPATH = "../xmlFiles/sims/input/";
const std::string OUTPUTPATH = "../xmlFiles/sims/output/";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    sim = new GUI_MetroSimulation(filename, ss,10, true);

    ui->setupUi(this);

    connect(sim, &GUI_MetroSimulation::simulationProgressed, this, &MainWindow::updateGUI);

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

    ui->label_6->setText("/");
    ui->label_7->setText("/");
    ui->label_9->setText("/");
    ui->label_10->setText("/");
    ui->label_16->setText("/");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::onPushButton_StartClicked() {
    ui->textBrowser_Simulation->append("Started simulation");
    SimThread *thread = new SimThread(sim, ss);
    thread->start();  //start the thread
    sim->stopSystem();
}

void MainWindow::onPushButton_StopClicked(){
    sim->stopSystem();
    ui->textBrowser_Simulation->append("Stopped simulation");
}

void MainWindow::onPushButton_PreviousClicked(){
    ui->textBrowser_Simulation->append("Previous step");
//    sim = std::move(simStack.pop());
//    sim.getSystem()->updateSystem(ss);
//    updateGUI();
}

void MainWindow::onPushButton_NextClicked(){
//    ui->textBrowser_Simulation->append("Next step");
//    simStack.push(new MetroSimulation(sim));
    sim->getSystem()->updateSystem(ss);
    sim->updateTime();
    updateGUI();
}

void MainWindow::onPushButton_FindRouteClicked() {
    ui->textBrowser_2->clear();
    if (ui->comboBox->currentText() == ui->comboBox_2->currentText()){
        ui->textBrowser_2->append("You are already at your destination.");
    } else {
        std::pair<std::vector<TramStop *>, std::vector<Line *>> route = sim->getSystem()->getRoute(ui->comboBox->currentText().toStdString(), ui->comboBox_2->currentText().toStdString());
        if (route.second.empty()){
            // No route
            ui->textBrowser_2->append("No possible route to your destination.");
        } else if (route.second.size() == 1) {
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
        } else{
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
                currentStop = beginLine->getNext(currentStop);
                ui->textBrowser_2->append("Line " + QString::number(endLine->getLineNumber()) + ":");
            }

            ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
            while (currentStop != endStop){
                currentStop = endLine->getNext(currentStop);
                ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
            }
            ui->textBrowser_2->append("Station " + QString::fromStdString(currentStop->getName()));
        }
    }
}

void MainWindow::updateGUI(){
    MetroSimStatistics *stats = new MetroSimStatistics(sim);

    // Time label
    ui->label_6->setText(QString::number(stats->getTime()));
    // Total Trams  label
    ui->label_7->setText(QString::number(stats->getWorkingTrams() + stats->getDefectTrams()));
    // Working trams
    ui->label_9->setText(QString::number(stats->getWorkingTrams()));
    // Broken trams
    ui->label_10->setText(QString::number(stats->getDefectTrams()));
    // Total cost
    ui->label_16->setText(QString::number(stats->getTotalCost()));

    ui->textBrowser_Simulation->clear();
    ui->textBrowser_Simulation->append("Started simulation");
    ui->textBrowser_Simulation->append(QString::fromStdString(ss.str()));

    delete stats;
}
