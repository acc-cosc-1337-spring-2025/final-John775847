#include "phase.h"
#include "shooter.h"
#include "roll.h"
#include "die.h"

#ifndef come_out_phase
#define come_out_phase
class ComeOutPhase : public Phase{
    public:
        enum RollOutcome get_outcome(Roll* rolled) override;
};
#endif
