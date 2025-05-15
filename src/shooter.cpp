#include <iostream>
#include <vector>

#include "shooter.h"

Shooter::~Shooter(){
    for(auto& i: rolls){
        delete i;
    }
}

Roll* Shooter::throw_dice(Die& die1, Die& die2){
    Roll* two_dice = new Roll(die1, die2);
    two_dice->roll_dice();
    rolls.push_back(two_dice);
    return two_dice;
}

void Shooter::display_rolled_values(){
    for(auto& i: rolls){
        std::cout<<"\n\tTotal: "<<i->roll_value();
    }
    std::cout<<"\n";
}


