#include "gtest/gtest.h"
#include "../src/MetroSimStatistics.h"

class StatisticsTest: public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(StatisticsTest, test1) {
    std::string filename = "xmlFiles/tests/StatisticsTest/test1.xml";
    std::stringstream  errorStream;
    Logger::setErrorStream(&errorStream);
    MetroSimulation sim(filename, 10, false);
    //No error should occur
    EXPECT_TRUE(errorStream.str().empty());

    //Before the simulation
    MetroSimStatistics statisticsB4(&sim);
    EXPECT_EQ(statisticsB4.getTime(),0);
    EXPECT_EQ(statisticsB4.getTotalCost(),0);
    EXPECT_EQ(statisticsB4.getWorkingTrams(),2);
    EXPECT_EQ(statisticsB4.getDefectTrams(),0);

    //run the sim
    std::stringstream ignoreStream;
    Logger::setOutputStream(&ignoreStream);
    sim.run();

    //After the simulation
    MetroSimStatistics statisticsAft(&sim);
    EXPECT_EQ(statisticsAft.getTime(),10);
    EXPECT_EQ(statisticsAft.getTotalCost(),15);
    EXPECT_EQ(statisticsAft.getWorkingTrams(),1);
    EXPECT_EQ(statisticsAft.getDefectTrams(),1);
}

TEST(StatisticsTest, test2) {
    std::string filename = "xmlFiles/tests/StatisticsTest/test1.xml";
    std::stringstream  errorStream;
    Logger::setErrorStream(&errorStream);
    MetroSimulation sim(filename, 24, false);
    //No error should occur
    EXPECT_TRUE(errorStream.str().empty());

    //Before the simulation
    MetroSimStatistics statisticsB4(&sim);
    EXPECT_EQ(statisticsB4.getTime(),0);
    EXPECT_EQ(statisticsB4.getTotalCost(),0);
    EXPECT_EQ(statisticsB4.getWorkingTrams(),2);
    EXPECT_EQ(statisticsB4.getDefectTrams(),0);

    //run the sim
    std::stringstream ignoreStream;
    Logger::setOutputStream(&ignoreStream);
    sim.run();

    //After the simulation
    MetroSimStatistics statisticsAft(&sim);
    EXPECT_EQ(statisticsAft.getTime(),24);
    EXPECT_EQ(statisticsAft.getTotalCost(),30);
    EXPECT_EQ(statisticsAft.getWorkingTrams(),2);
    EXPECT_EQ(statisticsAft.getDefectTrams(),0);
}