#include "gtest/gtest.h"
#include "../src/MetroSimStatistics.h"

class StatisticsTest: public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(StatisticsTest, test1) {
    std::string filename = "xmlFiles/tests/StatisticsTest/test1.xml";
    std::stringstream  errorStream;
    MetroSimulation sim(filename, errorStream, 10, false);
    //No error should occur
    EXPECT_TRUE(errorStream.str().empty());

    //Before the simulation
    MetroSimStatistics statisticsB4(&sim);
    EXPECT_TRUE(statisticsB4.getTime()==0);
    EXPECT_TRUE(statisticsB4.getTotalCost()==0);
    EXPECT_TRUE(statisticsB4.getWorkingTrams()==2);
    EXPECT_TRUE(statisticsB4.getDefectTrams()==0);

    //run the sim
    std::stringstream ignoreStream;
    sim.run(ignoreStream);

    //After the simulation
    MetroSimStatistics statisticsAft(&sim);
    EXPECT_TRUE(statisticsAft.getTime()==10);
    EXPECT_TRUE(statisticsAft.getTotalCost()==15);
    EXPECT_TRUE(statisticsAft.getWorkingTrams()==0);
    EXPECT_TRUE(statisticsAft.getDefectTrams()==2);
}

TEST(StatisticsTest, test2) {
    std::string filename = "xmlFiles/tests/StatisticsTest/test1.xml";
    std::stringstream  errorStream;
    MetroSimulation sim(filename, errorStream, 24, false);
    //No error should occur
    EXPECT_TRUE(errorStream.str().empty());

    //Before the simulation
    MetroSimStatistics statisticsB4(&sim);
    EXPECT_TRUE(statisticsB4.getTime()==0);
    EXPECT_TRUE(statisticsB4.getTotalCost()==0);
    EXPECT_TRUE(statisticsB4.getWorkingTrams()==2);
    EXPECT_TRUE(statisticsB4.getDefectTrams()==0);

    //run the sim
    std::stringstream ignoreStream;
    sim.run(ignoreStream);

    //After the simulation
    MetroSimStatistics statisticsAft(&sim);
    EXPECT_TRUE(statisticsAft.getTime()==24);
    EXPECT_TRUE(statisticsAft.getTotalCost()==30);
    EXPECT_TRUE(statisticsAft.getWorkingTrams()==2);
    EXPECT_TRUE(statisticsAft.getDefectTrams()==0);
}