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
    TiXmlElement* lijnNrElement = new TiXmlElement("lijnNr");
    lijnNrElement->LinkEndChild(new TiXmlText("5"));
    goodTram->LinkEndChild(lijnNrElement);

    TiXmlElement* typeElement = new TiXmlElement("type");
    lijnNrElement->LinkEndChild(new TiXmlText("Stadslijner"));
    goodTram->LinkEndChild(typeElement);

    TiXmlElement* beginStationElement = new TiXmlElement("beginStation");
    lijnNrElement->LinkEndChild(new TiXmlText("A"));
    goodTram->LinkEndChild(beginStationElement);

    TiXmlElement* voertuigNrElement = new TiXmlElement("voertuigNr");
    lijnNrElement->LinkEndChild(new TiXmlText("0"));
    goodTram->LinkEndChild(voertuigNrElement);

    MetroXMLParser::parseTram(sys, goodTram, errorStream);

    TiXmlElement *badTram = new TiXmlElement("newTram");
    lijnNrElement = new TiXmlElement("lijnNr");
    lijnNrElement->LinkEndChild(new TiXmlText("5"));
    badTram->LinkEndChild(lijnNrElement);

    typeElement = new TiXmlElement("type");
    lijnNrElement->LinkEndChild(new TiXmlText("Stadslijner"));
    badTram->LinkEndChild(typeElement);

    beginStationElement = new TiXmlElement("beginStation");
    lijnNrElement->LinkEndChild(new TiXmlText("A"));
    badTram->LinkEndChild(beginStationElement);

    MetroXMLParser::parseTram(sys, badTram, errorStream);

    EXPECT_TRUE(FileCompare(COMPAREFOLDERPATH+filename, OUTPUTFOLDERPATH+filename));
}