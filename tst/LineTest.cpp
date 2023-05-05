#include "gtest/gtest.h"
#include "../src/Line.h"

class LineTest: public ::testing::Test{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(LineTest, addStationTest) {
    //we create line 0
    Line l(0);
    //We create a station Halte A
    TramStop *a = new Halte("A");
    //We add station
    l.addStation(a);
    //Now 1 station should be on the line
    EXPECT_TRUE(l.getStations().size()==1);
    //We add duplicate
    l.addStation(a);
    //Duplicates dont get added
    EXPECT_TRUE(l.getStations().size()==1);
    //Deallocate mem
    delete a;
}

TEST(LineTest, connectTest) {
    //we create line 0
    Line l(0);

    //We create a station halte A and B
    TramStop *a = new Halte("A");
    TramStop *b = new Halte("B");

    //We add both stations
    l.addStation(a);
    l.addStation(b);
    //Now 2 stations should be on the line
    EXPECT_TRUE(l.getStations().size()==2);

    //We connect the stations in both ways
    std::stringstream errorStream;
    l.connect("A", "B", errorStream);
    //There should be no errors
    EXPECT_TRUE(errorStream.str().empty());

    //A should now point to B
    EXPECT_TRUE(l.getNext(a)==b);
    //The prev from B is A
    EXPECT_TRUE(l.getPrev(b)==a);

    //Deallocate mem
    delete a;
    delete b;
}

TEST(LineTest, deployTramTest) {
    //we create line 0
    Line l(0);

    //We create station A
    TramStop *a = new Halte("A");
    //We add station A
    l.addStation(a);
    //Now 1 station should be on the line
    EXPECT_TRUE(l.getStations().size()==1);

    //We create an Albatros tram 0 that sits on no station yet
    Tram *t0 = new Albatros(0,NULL,0,0,0);

    //We deploy the tram to station A
    std::stringstream errorStream;
    l.deployTram(t0, "A", errorStream);
    //There should be no errors
    EXPECT_TRUE(errorStream.str().empty());

    //Now the tram should be on station a
    EXPECT_TRUE(t0->getStartStation()==a);
    EXPECT_TRUE(t0->getCurrentStation()==a);
    //The station should be occupied
    EXPECT_TRUE(a->isOccupied());

    //We create an Albatros tram 1
    Tram *t1 = new Albatros(1,NULL,0,0,0);
    //This tram also wants to deploy on an occupied station!? -> problem
    std::stringstream errorStream2;
    l.deployTram(t0, "A", errorStream2);
    //There should be errors
    EXPECT_TRUE(!errorStream2.str().empty());

    delete t0;
    delete t1;
    delete a;
}

