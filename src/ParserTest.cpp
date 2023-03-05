#include "gtest/gtest.h"
#include "Tram.h"
#include "MetroXMLParser.h"

class ParserTest : public ::testing::Test {
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(ParserTest, Test1) {
    MetroXMLParser parser("xmlFiles/test.xml");
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
}