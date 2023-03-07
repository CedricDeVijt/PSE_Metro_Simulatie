#include "gtest/gtest.h"
#include "../src/Tram.h"
#include "../src/MetroXMLParser.h"
#include "../src/Track.h"
#include "../src/Line.h"

class ParserTest : public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(ParserTest, Test1) {
    MetroXMLParser parser("xmlFiles/test1.xml");
    std::vector<Line*> lines = parser.getLines();
    std::vector<Tram*> trams = parser.getTrams();
    std::vector<Station*> stations = parser.getStations();

    EXPECT_TRUE(parser.isProperlyInitialized());

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
        EXPECT_TRUE(station->isProperlyInitialized());

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