#include <iostream>
#include <vector>

#include "roll.h"
#include "die.h"

#ifndef shooter
#define shooter
class Shooter : public Roll{
    public:
        Shooter(Die& die1, Die& die2) : Roll(die1, die2) {}
        ~Shooter();
        Roll* throw_dice(Die& die1, Die& die2);
        void display_rolled_values();
    private:
        std::vector<Roll*> rolls;
        void display_dice(int die1, int die2);
};
#endif
