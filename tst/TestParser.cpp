#include "gtest/gtest.h"
#include "../src/MetroXMLParser.h"
#include "TestFuncs.h"

class ParserTest : public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

void compareLog(const std::string &filename) {
    std::string INPUTFOLDERPATH   = "xmlFiles/tests/ParserTests/input/";
    std::string OUTPUTFOLDERPATH  = "xmlFiles/tests/ParserTests/output/";
    std::string COMPAREFOLDERPATH = "xmlFiles/tests/ParserTests/compare/";

    std::ofstream file((OUTPUTFOLDERPATH+filename+".txt").c_str());
    EXPECT_TRUE(file.is_open());

    Logger::setErrorStream(&file);

    MetroSystem sys;
    MetroXMLParser::loadMetroSystem(sys, INPUTFOLDERPATH+filename+".xml");
    file.close();

    EXPECT_TRUE(FileCompare(COMPAREFOLDERPATH+filename+".txt", OUTPUTFOLDERPATH+filename+".txt"));
}

//FOUTE LINK
TEST_F(ParserTest, VerifyTest1) {
    compareLog("verifyTest1");
}

//FOUT STARTSTATION
TEST_F(ParserTest, VerifyTest2) {
    compareLog("verifyTest2");
}

//FOUT TRAMLINE_NR
TEST_F(ParserTest, VerifyTest3) {
    compareLog("verifyTest3");
}

//Not every line has a tram
TEST_F(ParserTest, VerifyTest4) {
    compareLog("verifyTest4");
}

//No stations
TEST_F(ParserTest, VerifyTest5) {
    compareLog("verifyTest5");
}

//No trams
TEST_F(ParserTest, VerifyTest6) {
    compareLog("verifyTest6");
}

//Double deploy
TEST_F(ParserTest, VerifyTest7) {
    compareLog("verifyTest7");
}

//No file in dir
TEST_F(ParserTest, LoadFileTest1) {
    compareLog("baba");
}

//No metronet
TEST_F(ParserTest, LoadFileTest2) {
    compareLog("noMetroNet");
}