#include "TestFuncs.h"
#include "gtest/gtest.h"
#include "../src/MetroSystem.h"

class TestOutput: public ::testing::Test{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(TestOutput, testTextOutput){
    const std::string INPUTFOLDER = "xmlFiles/tests/OutputTests/Input/";
    const std::string OUTPUTFOLDER = "xmlFiles/tests/OutputTests/Output/";
    const std::string COMPAREFOLDER = "xmlFiles/tests/OutputTests/Compare/";
    // create metro-system
    MetroSystem system1 = MetroSystem(INPUTFOLDER + "simFile.xml", std::cout);
    MetroSystem system2 = MetroSystem(INPUTFOLDER + "simFile2.xml", std::cout);

    // output streams to files
    std::ofstream system1Output = std::ofstream("simFileOutput.txt");
    std::ofstream system2Output = std::ofstream("simFileOutput2.txt");

    // output metro-systeem
    system1.outputSystem(system1Output);
    system1Output.close();
    system2.outputSystem(system2Output);
    system1Output.close();

//    // vergelijk output van metro-systeem met verwachte output
//    EXPECT_TRUE(FileCompare(OUTPUTFOLDER+"simFileOutput.txt", COMPAREFOLDER+"simFileOutput.txt"));
//    EXPECT_TRUE(FileCompare(OUTPUTFOLDER+"simFileOutput2.txt", COMPAREFOLDER+"simFileOutput2.txt"));

}