#include "roll.h"

void Roll::roll_dice(){
    rolled_value_ = die1_.roll_dice() + die2_.roll_dice();
}

int Roll::roll_value() const{
    return rolled_value_;
}
