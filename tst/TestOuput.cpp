#include "TestFuncs.h"
#include "gtest/gtest.h"
#include "../src/MetroSystem.h"
#include "../src/MetroXMLParser.h"
#include "../src/MetroSystemOutput.h"

class TestOutput: public ::testing::Test{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(TestOutput, simpleSystemOutput_1){
    const std::string INPUTFOLDER = "xmlFiles/tests/OutputTests/Input/";
    const std::string OUTPUTFOLDER = "xmlFiles/tests/OutputTests/Output/";
    const std::string COMPAREFOLDER = "xmlFiles/tests/OutputTests/Compare/";

    // create metro-system
    MetroSystem system;
    MetroXMLParser::loadMetroSystem(system, INPUTFOLDER + "simFile.xml");

    //output streams to files
    std::ofstream systemOutput((OUTPUTFOLDER + "simpleSystemOutput_1.txt").c_str());

    // output metro-systeem
    MetroSystemOutput::simpleSystemOutput(system, systemOutput);
    systemOutput.close();

    EXPECT_TRUE(FileCompare(COMPAREFOLDER+"simpleSystemOutput_1.txt", OUTPUTFOLDER+"simpleSystemOutput_1.txt"));
}

TEST(TestOutput, simpleSystemOutput_2){
    const std::string INPUTFOLDER = "xmlFiles/tests/OutputTests/Input/";
    const std::string OUTPUTFOLDER = "xmlFiles/tests/OutputTests/Output/";
    const std::string COMPAREFOLDER = "xmlFiles/tests/OutputTests/Compare/";

    // create metro-system
    MetroSystem system;
    MetroXMLParser::loadMetroSystem(system, INPUTFOLDER + "simAdvanced.xml");

    //output streams to files
    std::ofstream systemOutput((OUTPUTFOLDER + "simpleSystemOutput_2.txt").c_str());

    // output metro-systeem
    MetroSystemOutput::simpleSystemOutput(system,systemOutput);
    systemOutput.close();

    EXPECT_TRUE(FileCompare(COMPAREFOLDER+"simpleSystemOutput_2.txt", OUTPUTFOLDER+"simpleSystemOutput_2.txt"));
}

TEST(TestOutput, advancedSystemOutput_1){
    const std::string INPUTFOLDER = "xmlFiles/tests/OutputTests/Input/";
    const std::string OUTPUTFOLDER = "xmlFiles/tests/OutputTests/Output/";
    const std::string COMPAREFOLDER = "xmlFiles/tests/OutputTests/Compare/";

    // create metro-system
    MetroSystem system;
    MetroXMLParser::loadMetroSystem(system, INPUTFOLDER + "simFile.xml");

    //output streams to files
    std::ofstream systemOutput((OUTPUTFOLDER + "advancedSystemOutput_1.txt").c_str());

    // output metro-systeem
    MetroSystemOutput::advancedSystemOutput(system, systemOutput);
    systemOutput.close();

    EXPECT_TRUE(FileCompare(COMPAREFOLDER+"advancedSystemOutput_1.txt", OUTPUTFOLDER+"advancedSystemOutput_1.txt"));
}

TEST(TestOutput, advancedSystemOutput_2){
    const std::string INPUTFOLDER = "xmlFiles/tests/OutputTests/Input/";
    const std::string OUTPUTFOLDER = "xmlFiles/tests/OutputTests/Output/";
    const std::string COMPAREFOLDER = "xmlFiles/tests/OutputTests/Compare/";

    // create metro-system
    MetroSystem system;
    MetroXMLParser::loadMetroSystem(system, INPUTFOLDER + "simAdvanced.xml");

    //output streams to files
    std::ofstream systemOutput((OUTPUTFOLDER + "advancedSystemOutput_2.txt").c_str());

    // output metro-systeem
    MetroSystemOutput::advancedSystemOutput(system,systemOutput);
    systemOutput.close();

    EXPECT_TRUE(FileCompare(COMPAREFOLDER+"advancedSystemOutput_2.txt", OUTPUTFOLDER+"advancedSystemOutput_2.txt"));
}
