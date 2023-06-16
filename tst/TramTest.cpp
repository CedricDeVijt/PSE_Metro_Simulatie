#include "gtest/gtest.h"
#include "../src/Tram.h"

class TramTest: public ::testing::Test {
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(LineTest, driveTest) {
    //Create 2 haltes
    TramStop *a = new Halte("A");
    TramStop *b = new Halte("B");

    //Create the tram and set its startstation to halte A
    Tram *t = new Albatros(0,NULL);
    t->setStartStation(a);
    a->setOccupied(true);

    //Drive to halte b
    std::stringstream ignoreStream;
    t->drive(b, true, ignoreStream);
    EXPECT_EQ(t->getCurrentStation(),b);

    //deallocate mem
    delete a;
    delete b;
    delete t;
}

TEST(LineTest, defectTest) {
    /**
     * This tram takes 5 loops to get repaired
     * This tram breaks down after 2 loops
     * This tram costs 10 to get repaired
     */
    PCC *t = new PCC(0, NULL, 5, 2, 10);
    std::stringstream ignoreStream;

    //Iterate 2 times and it should be defective
    for (int i = 0; i < 2; i++) {
        t->drive(NULL, true,ignoreStream);
    }
    EXPECT_TRUE(t->isDefect());
    EXPECT_EQ(t->getTotalCost(), 10);

    //It should be repaired after 5 iterations
    for (int i = 0; i < 5; i++) {
        t->drive(NULL, true,ignoreStream);
    }
    EXPECT_FALSE(t->isDefect());
    EXPECT_EQ(t->getTotalCost(), 10);

    //deallocate mem
    delete t;
}

