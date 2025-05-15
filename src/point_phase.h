#include "phase.h"
#include "shooter.h"
#include "roll.h"
#include "die.h"

#ifndef point_phase
#define point_phase
class PointPhase : public Phase{
    public:
        PointPhase(int set_line) : point(set_line){}
        enum RollOutcome get_outcome(Roll* rolled) override;
    private:
        int point;
};
#endif
