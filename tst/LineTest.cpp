#include "gtest/gtest.h"
#include "../src/Line.h"

class LineTest: public ::testing::Test {
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
    l.deployTram(t1, "A", errorStream2);
    //There should be errors
    EXPECT_TRUE(!errorStream2.str().empty());

    delete a;
}

TEST(LineTest, updateTestAlbatros) {
    //We create line 0
    Line l(0);

    //Init Tramstops a,b,c
    TramStop *a = new Metrostation("A");
    TramStop *b = new Halte("B");
    TramStop *c = new Metrostation("C");

    //Add the tramstops to the line
    l.addStation(a);
    l.addStation(b);
    l.addStation(c);
    EXPECT_TRUE(l.getStations().size()==3);

    //We connect the stations without an error
    std::stringstream errorStreamConnection;
    l.connect("A", "B", errorStreamConnection);
    l.connect("B", "C", errorStreamConnection);
    l.connect("C", "A", errorStreamConnection);
    EXPECT_TRUE(errorStreamConnection.str().empty());

    //Init tram and deploy on A without an error
    Tram *alba = new Albatros(0, NULL, 0, 100, 0);
    std::stringstream errorStreamDeploy;
    l.deployTram(alba, "A", errorStreamDeploy);
    EXPECT_TRUE(errorStreamDeploy.str().empty());
    EXPECT_TRUE(alba->getCurrentStation()==a);

    std::stringstream ignoreStream;
    l.update(ignoreStream);
    //Now the albatros should skip the Halte B because it's an albatros
    EXPECT_TRUE(alba->getCurrentStation()==c);
    //Now go back to a
    l.update(ignoreStream);
    EXPECT_TRUE(alba->getCurrentStation()==a);

    //deallocate Mem
    delete a;
    delete b;
    delete c;
}

TEST(LineTest, updateTestStadsLijner) {
    //We create line 0
    Line l(0);

    //Init Tramstops a,b,c
    TramStop *a = new Metrostation("A");
    TramStop *b = new Halte("B");
    TramStop *c = new Metrostation("C");

    //Add the tramstops to the line
    l.addStation(a);
    l.addStation(b);
    l.addStation(c);
    EXPECT_TRUE(l.getStations().size()==3);

    //We connect the stations without an error
    std::stringstream errorStreamConnection;
    l.connect("A", "B", errorStreamConnection);
    l.connect("B", "C", errorStreamConnection);
    l.connect("C", "A", errorStreamConnection);
    EXPECT_TRUE(errorStreamConnection.str().empty());

    //Init tram and deploy on A without an error
    Tram *stadsL = new Stadslijner(0, NULL, 0, 100, 0);
    std::stringstream errorStreamDeploy;
    l.deployTram(stadsL, "A", errorStreamDeploy);
    EXPECT_TRUE(errorStreamDeploy.str().empty());
    EXPECT_TRUE(stadsL->getCurrentStation()==a);

    std::stringstream ignoreStream;
    l.update(ignoreStream);
    //Now the Stadslijner should skip the Halte B because it's a Stadslijner
    EXPECT_TRUE(stadsL->getCurrentStation()==c);
    //Now go back to a
    l.update(ignoreStream);
    EXPECT_TRUE(stadsL->getCurrentStation()==a);

    //deallocate Mem
    delete a;
    delete b;
    delete c;
}

TEST(LineTest, updateTestPCC) {
    //We create line 0
    Line l(0);

    //Init Tramstops a,b,c
    TramStop *a = new Metrostation("A");
    TramStop *b = new Halte("B");
    TramStop *c = new Metrostation("C");

    //Add the tramstops to the line
    l.addStation(a);
    l.addStation(b);
    l.addStation(c);
    EXPECT_TRUE(l.getStations().size()==3);

    //We connect the stations without an error
    std::stringstream errorStreamConnection;
    l.connect("A", "B", errorStreamConnection);
    l.connect("B", "C", errorStreamConnection);
    l.connect("C", "A", errorStreamConnection);
    EXPECT_TRUE(errorStreamConnection.str().empty());

    //Init tram and deploy on A without an error
    Tram *pcc = new PCC(0, NULL, 0, 100, 0);
    std::stringstream errorStreamDeploy;
    l.deployTram(pcc, "A", errorStreamDeploy);
    EXPECT_TRUE(errorStreamDeploy.str().empty());
    EXPECT_TRUE(pcc->getCurrentStation()==a);

    std::stringstream ignoreStream;
    l.update(ignoreStream);
    //Now the pcc should not skip the Halte B because it's a pcc
    EXPECT_TRUE(pcc->getCurrentStation()==b);
    //Now go back to a
    l.update(ignoreStream);
    l.update(ignoreStream);
    EXPECT_TRUE(pcc->getCurrentStation()==a);

    //deallocate Mem
    delete a;
    delete b;
    delete c;
}