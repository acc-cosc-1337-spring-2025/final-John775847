#include <iostream>

#include "point_phase.h"
#include "come_out_phase.h"
#include "phase.h"
#include "shooter.h"
#include "roll.h"
#include "die.h"

using std::cout;
using std::cin;
using std::string;

int main(){
    srand(time(0));
    Die die1, die2;
    Shooter shoot(die1, die2);
    Roll* rolled;
    int rolled_val;
    string confirm;

    ComeOutPhase phase1;
    do{
        rolled = shoot.throw_dice(die1, die2);
        rolled_val = rolled->roll_value();
        // cout<<"Rolled Value: "<<rolled_val<<"\n";
        cin>>confirm;
    }while(phase1.get_outcome(rolled) == RollOutcome::natural || phase1.get_outcome(rolled) == RollOutcome::craps);

    cout<<"Start of point phase with: "<<rolled_val<<"\n";
    cin>>confirm;
    cout<<"Roll your dice until you roll "<<rolled_val<<" or you roll 7\n";
    cin>>confirm;

    PointPhase phase2(rolled_val);
    do{
        rolled = shoot.throw_dice(die1, die2);
        rolled_val = rolled->roll_value();
        // cout<<"Rolled Value: "<<rolled_val<<"\n";
        cin>>confirm;
    }while(phase2.get_outcome(rolled) == RollOutcome::nopoint);

    cout<<"End of point phase with: "<<rolled_val<<"\n";
    cin>>confirm;
    cout<<"History of rolled values: ";
    shoot.display_rolled_values();

	return 0;
}
