#include "TestFuncs.h"
#include "gtest/gtest.h"
#include "../src/MetroSimulation.h"

std::string INPUTFOLDERPATH   = "xmlFiles/tests/simTest/input/";
std::string OUTPUTFOLDERPATH  = "xmlFiles/tests/simTest/output/";
std::string COMPAREFOLDERPATH = "xmlFiles/tests/simTest/compare/";

class SimTest : public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

void testFile(std::string filename) {
    //WERKT NOG NIET
//    ASSERT_TRUE(DirectoryExists(OUTPUTFOLDERPATH));
//    ASSERT_TRUE(DirectoryExists(INPUTFOLDERPATH));

    MetroSimulation sim(INPUTFOLDERPATH+filename, 10);

    std::ofstream file;
    file.open((OUTPUTFOLDERPATH+filename).c_str(), std::ios::out);
    EXPECT_TRUE(file);

    if (file) {
        sim.start(file);
        file.close();

        EXPECT_TRUE(FileCompare(COMPAREFOLDERPATH+filename, OUTPUTFOLDERPATH+filename));
    }
}

TEST(SimTest, test1) {
    testFile("test1.xml");
}

//TEST(SimTest, test2) {
//    testFile("test2.xml");
//}
