#include <iostream>

#ifndef die
#define die
class Die{
    public:
        int roll_dice(){return 1 + std::rand() % 6;}

    private:
        int sides{6};
};
#endif
