#include <iostream>
#include "roll.h"

void Roll::roll_dice(){
    int result1 = die1_.roll_dice();
    int result2 = die2_.roll_dice();
    display_dice(result1, result2);
    rolled_value_ = result1 + result2;
}

int Roll::roll_value() const{
    return rolled_value_;
}

void Roll::display_dice(int die1, int die2){
    std::cout<<"   ____     ____ \n";
    std::cout<<"  /___/|   /___/| \n";
    std::cout<<"  | "<<die1<<" |/   | "<<die2<<" |/ \n";
    std::cout<<"   ----     ----";
    std::cout<<"\n\tTotal: "<<die1+die2<<"\n";
}
