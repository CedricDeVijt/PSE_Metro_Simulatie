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

TEST_F(ParserTest, VariableDistributionTest) {
    std::string INPUTFOLDERPATH   = "xmlFiles/tests/ParserTests/input/";
    std::string OUTPUTFOLDERPATH  = "xmlFiles/tests/ParserTests/output/";
    std::string COMPAREFOLDERPATH = "xmlFiles/tests/ParserTests/compare/";

    MetroXMLParser parser(INPUTFOLDERPATH+"variableDistributionTest.xml", std::cout);
    std::vector<Line*> lines = parser.getLines();
    std::vector<Tram*> trams = parser.getTrams();
    std::vector<Station*> stations = parser.getStations();

    //TESTING TRAMS
    EXPECT_EQ(1, static_cast<int>(trams.size()));
    EXPECT_EQ(12, trams[0]->getLineNumber());
    EXPECT_EQ("A", trams[0]->getStartStation()->getName());
    EXPECT_EQ(60, trams[0]->getSpeed());

    //TESTING STATIONS
    EXPECT_EQ(3, static_cast<int>(stations.size()));
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        Station *station = stations[i];
        EXPECT_EQ(12, station->getLineNumber());

        if (station->getName()=="A") {
            EXPECT_EQ("B", station->getNextTrack()->getAnEnd()->getName());
            EXPECT_EQ("C", station->getPrevTrack()->getBegin()->getName());
        } else if (station->getName()=="B") {
            EXPECT_EQ("C", station->getNextTrack()->getAnEnd()->getName());
            EXPECT_EQ("A", station->getPrevTrack()->getBegin()->getName());
        } else if (station->getName()=="C") {
            EXPECT_EQ("A", station->getNextTrack()->getAnEnd()->getName());
            EXPECT_EQ("B", station->getPrevTrack()->getBegin()->getName());
        }
    }

    //TESTING LINES
    EXPECT_EQ(1, static_cast<int>(lines.size()));
    EXPECT_EQ(12, lines[0]->getLineNumber());
    EXPECT_EQ(3, static_cast<int>(lines[0]->getTracks().size()));
    EXPECT_EQ(1, static_cast<int>(lines[0]->getTrams().size()));
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