#include "shooter.h"
#include "roll.h"
#include "die.h"

#ifndef phase
#define phase
enum class RollOutcome{
    natural,
    craps,
    point,
    seven_out,
    nopoint,
};

class Phase{
    public:
    protected:
        virtual enum RollOutcome get_outcome(Roll* rolled) = 0;
};
#endif
