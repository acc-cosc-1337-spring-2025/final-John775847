#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include "catch.hpp"

#include "point_phase.h"
#include "come_out_phase.h"
#include "phase.h"
#include "shooter.h"
#include "roll.h"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test Dic") {
    Die die1, die2;
    int roll1, roll2;

    for(int i; i <= 10; i++){
        roll1 = die1.roll_dice();
        roll2 = die2.roll_dice();
        REQUIRE(roll1 > 0);
        REQUIRE(roll1 <= 6);
        REQUIRE(roll2 > 0);
        REQUIRE(roll2 <= 6);
        REQUIRE(roll1 + roll2 > 0);
        REQUIRE(roll1 + roll2 <= 12);
    }
	//repitition because the "input" is random.
}

TEST_CASE("Test Roll"){
    Die die1, die2;
    Roll rolls(die1, die2);
    for(int i; i <= 10; i++){
        rolls.roll_dice();
        REQUIRE(rolls.roll_value() >= 2);
        REQUIRE(rolls.roll_value() <= 12);
    }
}

TEST_CASE("Test Shooter"){
    Die die1, die2;
    Shooter shoot(die1, die2);
    for(int i; i <= 10; i++){
        Roll* shooter_roll = shoot.throw_dice(die1, die2);
        REQUIRE(shooter_roll->roll_value() >= 2);
        REQUIRE(shooter_roll->roll_value() <= 12);
    }
}

TEST_CASE("Test ComeOutPhase"){
    Die die1, die2;
    Shooter shoot(die1, die2);

    ComeOutPhase phase1;

    Roll* rolls;
    do{
        rolls = shoot.throw_dice(die1, die2);
    }while(rolls->roll_value() != 7);
    REQUIRE(phase1.get_outcome(rolls) == RollOutcome::natural);

    do{
        rolls = shoot.throw_dice(die1, die2);
    }while(rolls->roll_value() != 2);
    REQUIRE(phase1.get_outcome(rolls) == RollOutcome::craps);

    do{
        rolls = shoot.throw_dice(die1, die2);
    }while(rolls->roll_value() != 4);
    REQUIRE(phase1.get_outcome(rolls) == RollOutcome::point);
}

TEST_CASE("Test PointPhase"){
    Die die1, die2;
    Shooter shoot(die1, die2);

    PointPhase phase2(8);

    Roll* rolls;
    do{
        rolls = shoot.throw_dice(die1, die2);
    }while(rolls->roll_value() != 8);
    REQUIRE(phase2.get_outcome(rolls) == RollOutcome::point);

    do{
        rolls = shoot.throw_dice(die1, die2);
    }while(rolls->roll_value() != 7);
    REQUIRE(phase2.get_outcome(rolls) == RollOutcome::seven_out);

    do{
        rolls = shoot.throw_dice(die1, die2);
    }while(rolls->roll_value() != 4);
    REQUIRE(phase2.get_outcome(rolls) == RollOutcome::nopoint);
}
