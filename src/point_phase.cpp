#include "point_phase.h"

enum RollOutcome PointPhase::get_outcome(Roll* rolled){
    int roll_val = rolled->roll_value();
    if (roll_val == point) {
        return RollOutcome::point;
    }else if (roll_val == 7){
        return RollOutcome::seven_out;
    }else{
        return RollOutcome::nopoint;
    }
}
