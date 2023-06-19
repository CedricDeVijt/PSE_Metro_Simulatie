#include "gtest/gtest.h"
#include "../src/Tram.h"
#include "../src/Logger.h"

class TramTest: public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(TramTest, driveTest) {
    //Create 2 haltes
    TramStop *a = new Halte("A");
    TramStop *b = new Halte("B");

    //Create the tram and set its startstation to halte A
    Tram *t = new Albatros(0,NULL);
    t->setStartStation(a);
    a->setOccupied(true);

    //Drive to halte b
    std::stringstream ignoreStream;
    Logger::setOutputStream(&ignoreStream);
    t->drive(b, false);
    EXPECT_EQ(t->getCurrentStation(),b);

    //deallocate mem
    delete a;
    delete b;
    delete t;
}
