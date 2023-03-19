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

    std::string filename = "test1.xml";

    std::ofstream file;
    file.open((OUTPUTFOLDERPATH+filename).c_str(), std::ios::out);
    EXPECT_TRUE(file);

    MetroSimulation sim(INPUTFOLDERPATH+filename, file, 10);

    if (file) {
        sim.startSystem(file);
        file.close();

        EXPECT_TRUE(FileCompare(COMPAREFOLDERPATH+filename, OUTPUTFOLDERPATH+filename));
    }
}