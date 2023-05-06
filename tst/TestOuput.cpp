#include "TestFuncs.h"
#include "gtest/gtest.h"
#include "../src/MetroSystem.h"
#include "../src/MetroXMLParser.h"
#include "../src/MetroSystemOutput.h"

class TestOutput: public ::testing::Test{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(TestOutput, simpleSystemOutput){
    const std::string INPUTFOLDER = "xmlFiles/tests/OutputTests/Input/";
    const std::string OUTPUTFOLDER = "xmlFiles/tests/OutputTests/Output/";
    const std::string COMPAREFOLDER = "xmlFiles/tests/OutputTests/Compare/";
    // create metro-system
    MetroSystem system1;
    MetroXMLParser::loadMetroSystem(system1, INPUTFOLDER + "simAdvanced.xml", std::cout);
//    MetroSystem system2;
//    MetroXMLParser::loadMetroSystem(system2, INPUTFOLDER + "simFile3.xml", std::cout);

    //output streams to files
    std::ofstream system1Output((OUTPUTFOLDER + "simpleSimFileOutput.txt").c_str());
//    std::ofstream system2Output((OUTPUTFOLDER + "simFileOutput3.txt").c_str());

    // output metro-systeem
    MetroSystemOutput::simpleSystemOutput(&system1,system1Output);
    system1Output.close();
//    MetroSystemOutput::simpleSystemOutput(&system2,system2Output);
//    system1Output.close();

    EXPECT_TRUE(FileCompare(OUTPUTFOLDER+"simFileOutput.txt", OUTPUTFOLDER+"simFileOutput.txt"));
//    EXPECT_FALSE(FileCompare(OUTPUTFOLDER+"simFileOutput3.txt", COMPAREFOLDER+"simFileOutput3.txt"));
}

TEST(TestOutput, advancedSystemOutput){
    const std::string INPUTFOLDER = "xmlFiles/tests/OutputTests/Input/";
    const std::string OUTPUTFOLDER = "xmlFiles/tests/OutputTests/Output/";
    const std::string COMPAREFOLDER = "xmlFiles/tests/OutputTests/Compare/";
    // create metro-system
    MetroSystem system1;
    MetroXMLParser::loadMetroSystem(system1, INPUTFOLDER + "simAdvanced.xml", std::cout);
//    MetroSystem system2;
//    MetroXMLParser::loadMetroSystem(system2, INPUTFOLDER + "simFile3.xml", std::cout);

    //output streams to files
    std::ofstream system1Output((OUTPUTFOLDER + "advancedSimFileOutput.txt").c_str());
//    std::ofstream system2Output((OUTPUTFOLDER + "simFileOutput3.txt").c_str());

    // output metro-systeem
    MetroSystemOutput::advancedSystemOutput(&system1,system1Output);
    system1Output.close();
//    MetroSystemOutput::advancedSystemOutput(&system2,system2Output);
//    system1Output.close();

    EXPECT_TRUE(FileCompare(OUTPUTFOLDER+"simFileOutput.txt", COMPAREFOLDER+"simFileOutput.txt"));
//    EXPECT_FALSE(FileCompare(OUTPUTFOLDER+"simFileOutput3.txt", COMPAREFOLDER+"simFileOutput3.txt"));
}