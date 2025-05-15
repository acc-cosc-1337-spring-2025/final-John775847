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
    Roll* shooter_roll = shoot.throw_dice(die1, die2);
    for(int i; i <= 10; i++){
        REQUIRE(shooter_roll->roll_value() >= 2);
        REQUIRE(shooter_roll->roll_value() <= 12);
    }
}

TEST_CASE("Test display dice") {
    Die die1, die2;
    // game.display_dice(5, 6);
    REQUIRE(true == true);
}


// TEST_CASE("Test game"){
//     Phase1 game;
//     int die1, die2;
//     die1=3;
//     die2=4;

//     phase 0 (main)
//     initial bets

//     phase 1
//     set bet
//     set guess
//     roll
//     if 7, game end, money to dealer
//     if under line, roll again, under line guesser wins
//     if above line, mark position, above line guesser wins, move to phase 2

//     phase 2
//     set bet
//     set guess
//     roll
//     if 7, game end, money to dealer
//     if marked position, game end, money to player
//     if under line, roll again, under line guesser wins
//     if above line, roll again, above line gueesser wins

// }
