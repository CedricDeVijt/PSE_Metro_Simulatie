#include "gtest/gtest.h"
#include "../src/MetroXMLParser.h"
#include "TestFuncs.h"

class ParserTest : public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

void compareLog(std::string filename) {
    std::string INPUTFOLDERPATH   = "xmlFiles/tests/ParserTests/input/";
    std::string OUTPUTFOLDERPATH  = "xmlFiles/tests/ParserTests/output/";
    std::string COMPAREFOLDERPATH = "xmlFiles/tests/ParserTests/compare/";

    //WERKT NOG NIET
    //ASSERT_TRUE(DirectoryExists(OUTPUTFOLDERPATH));
    //ASSERT_TRUE(DirectoryExists(INPUTFOLDERPATH));

    std::ofstream file((OUTPUTFOLDERPATH+filename).c_str());
    EXPECT_TRUE(file.is_open());

    MetroXMLParser m(INPUTFOLDERPATH+filename, file);
    file.close();

    EXPECT_TRUE(FileCompare(COMPAREFOLDERPATH+filename, OUTPUTFOLDERPATH+filename));
}

//FOUTE LINK
TEST_F(ParserTest, VerifyTest1) {
    compareLog("verifyTest1.xml");
}

//FOUT STARTSTATION
TEST_F(ParserTest, VerifyTest2) {
    compareLog("verifyTest2.xml");
}

//FOUT TRAMLINE_NR
TEST_F(ParserTest, VerifyTest3) {
    compareLog("verifyTest3.xml");
}

//Not every line has a tram
TEST_F(ParserTest, VerifyTest4) {
    compareLog("verifyTest4.xml");
}

//No stations
TEST_F(ParserTest, VerifyTest5) {
    compareLog("verifyTest5.xml");
}

//No trams
TEST_F(ParserTest, VerifyTest6) {
    compareLog("verifyTest6.xml");
}

//No file in dir
TEST_F(ParserTest, LoadFileTest1) {
    compareLog("baba.xml");
}

//No simdata
TEST_F(ParserTest, LoadFileTest2) {
    compareLog("nosimdata.xml");
}