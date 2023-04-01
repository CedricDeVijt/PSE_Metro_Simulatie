#include "gtest/gtest.h"
#include "../src/MetroXMLParser.h"
#include "../src/MetroSystem.h"
#include "TestFuncs.h"

class ParserTest : public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(ParserTest, ParserTest_LoadTram_Test) {
    std::string filename = "ParserTest_LoadTram_Test.txt";
    std::string OUTPUTFOLDERPATH  = "xmlFiles/tests/ParserTests/output/";
    std::string COMPAREFOLDERPATH = "xmlFiles/tests/ParserTests/compare/";

    MetroSystem sys;
    std::ofstream errorStream((OUTPUTFOLDERPATH+filename).c_str());
    EXPECT_TRUE(errorStream.is_open());

    TiXmlElement *goodTram = new TiXmlElement("newTram");
    goodTram->Attribute("lijnNr");
    goodTram->Attribute("type");
    goodTram->Attribute("beginStation");

    MetroXMLParser::parseTram(sys, goodTram, errorStream);

    TiXmlElement *badTram = new TiXmlElement("newTram");
    badTram->Attribute("lijnNr");
    badTram->Attribute("type");
    badTram->Attribute("beginStation");

    MetroXMLParser::parseTram(sys, goodTram, errorStream);

    EXPECT_TRUE(FileCompare(COMPAREFOLDERPATH+filename, OUTPUTFOLDERPATH+filename));
}