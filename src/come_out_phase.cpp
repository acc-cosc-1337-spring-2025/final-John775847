#include "come_out_phase.h"
#include "roll.h"

enum RollOutcome ComeOutPhase:: get_outcome(Roll* rolled){
    int roll_val = rolled->roll_value();
    if (roll_val == 7 || roll_val == 11) {
        return RollOutcome::natural;
    }else if (roll_val == 2 || roll_val == 3 || roll_val == 12){
        return RollOutcome::craps;
    }else{
        return RollOutcome::point;
    }
}
