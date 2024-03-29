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
    EXPECT_EQ((int)l.getStations().size(),1);
    //We add duplicate
    l.addStation(a);
    //Duplicates dont get added
    EXPECT_EQ((int)l.getStations().size(),1);
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
    EXPECT_EQ((int)l.getStations().size(),2);

    //We connect the stations in both ways
    std::stringstream errorStream;
    Logger::setErrorStream(&errorStream);
    l.connect("A", "B");
    //There should be no errors
    EXPECT_TRUE(errorStream.str().empty());

    //A should now point to B
    EXPECT_EQ(l.getNext(a),b);
    //The prev from B is A
    EXPECT_EQ(l.getPrev(b),a);

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
    EXPECT_EQ((int)l.getStations().size(),1);

    //We create an Albatros tram 0 that sits on no station yet
    Tram *t0 = new Albatros(0,NULL);

    //We deploy the tram to station A
    std::stringstream errorStream;
    Logger::setErrorStream(&errorStream);
    l.deployTram(t0, "A");
    //There should be no errors
    EXPECT_TRUE(errorStream.str().empty());

    //Now the tram should be on station a
    EXPECT_EQ(t0->getStartStation(),a);
    EXPECT_EQ(t0->getCurrentStation(),a);
    //The station should be occupied
    EXPECT_TRUE(a->isOccupied());

    //We create an Albatros tram 1
    Tram *t1 = new Albatros(1,NULL);
    //This tram also wants to deploy on an occupied station!? -> problem
    std::stringstream errorStream2;
    Logger::setErrorStream(&errorStream2);
    l.deployTram(t1, "A");
    //There should be errors
    EXPECT_FALSE(errorStream2.str().empty());

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
    EXPECT_EQ((int)l.getStations().size(),3);

    //We connect the stations without an error
    std::stringstream errorStreamConnection;
    Logger::setErrorStream(&errorStreamConnection);
    l.connect("A", "B");
    l.connect("B", "C");
    l.connect("C", "A");
    EXPECT_TRUE(errorStreamConnection.str().empty());

    //Init tram and deploy on A without an error
    Tram *alba = new Albatros(0, NULL);
    std::stringstream errorStreamDeploy;
    Logger::setErrorStream(&errorStreamDeploy);
    l.deployTram(alba, "A");
    EXPECT_TRUE(errorStreamDeploy.str().empty());
    EXPECT_EQ(alba->getCurrentStation(),a);

    std::stringstream ignoreStream;
    Logger::setOutputStream(&ignoreStream);
    l.update();
    //Now the albatros should skip the Halte B because it's an albatros
    EXPECT_EQ(alba->getCurrentStation(),c);
    //Now go back to a
    l.update();
    EXPECT_EQ(alba->getCurrentStation(),a);

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
    EXPECT_EQ((int)l.getStations().size(),3);

    //We connect the stations without an error
    std::stringstream errorStreamConnection;
    Logger::setErrorStream(&errorStreamConnection);
    l.connect("A", "B");
    l.connect("B", "C");
    l.connect("C", "A");
    EXPECT_TRUE(errorStreamConnection.str().empty());

    //Init tram and deploy on A without an error
    Tram *stadsL = new Stadslijner(0, NULL);
    std::stringstream errorStreamDeploy;
    Logger::setErrorStream(&errorStreamDeploy);
    l.deployTram(stadsL, "A");
    EXPECT_TRUE(errorStreamDeploy.str().empty());
    EXPECT_EQ(stadsL->getCurrentStation(),a);

    std::stringstream ignoreStream;
    Logger::setOutputStream(&ignoreStream);
    l.update();
    //Now the Stadslijner should skip the Halte B because it's a Stadslijner
    EXPECT_EQ(stadsL->getCurrentStation(),c);
    //Now go back to a
    l.update();
    EXPECT_EQ(stadsL->getCurrentStation(),a);

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
    EXPECT_EQ((int)l.getStations().size(),3);

    //We connect the stations without an error
    std::stringstream errorStreamConnection;
    Logger::setErrorStream(&errorStreamConnection);
    l.connect("A", "B");
    l.connect("B", "C");
    l.connect("C", "A");
    EXPECT_TRUE(errorStreamConnection.str().empty());

    //Init tram and deploy on A without an error
    Tram *pcc = new PCC(0, NULL, 0, 100, 0);
    std::stringstream errorStreamDeploy;
    Logger::setErrorStream(&errorStreamDeploy);
    l.deployTram(pcc, "A");
    EXPECT_TRUE(errorStreamDeploy.str().empty());
    EXPECT_EQ(pcc->getCurrentStation(),a);

    std::stringstream ignoreStream;
    Logger::setOutputStream(&ignoreStream);
    l.update();
    //Now the pcc should not skip the Halte B because it's a pcc
    EXPECT_EQ(pcc->getCurrentStation(),b);
    //Now go back to a
    l.update();
    l.update();
    EXPECT_EQ(pcc->getCurrentStation(),a);

    //deallocate Mem
    delete a;
    delete b;
    delete c;
}