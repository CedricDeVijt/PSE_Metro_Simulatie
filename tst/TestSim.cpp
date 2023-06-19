#include "TestFuncs.h"
#include "gtest/gtest.h"
#include "../src/MetroSimulation.h"

class SimTest : public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(SimTest, automaticDriving) {
    std::string INPUTFOLDERPATH   = "xmlFiles/tests/simTest/input/";
    std::string OUTPUTFOLDERPATH  = "xmlFiles/tests/simTest/output/";
    std::string COMPAREFOLDERPATH = "xmlFiles/tests/simTest/compare/";

    std::string filename = "simFile";

    std::ofstream file;
    file.open((OUTPUTFOLDERPATH+filename+".txt").c_str());
    EXPECT_TRUE(file.is_open());

    Logger::setErrorStream(&file);
    Logger::setOutputStream(&file);

    MetroSimulation sim(INPUTFOLDERPATH+filename+".xml", 10, false);

    sim.run();
    file.close();

    EXPECT_TRUE(FileCompare(COMPAREFOLDERPATH+filename+".txt", OUTPUTFOLDERPATH+filename+".txt"));
}