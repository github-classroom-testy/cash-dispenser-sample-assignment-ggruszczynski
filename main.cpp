
#include "Chain.h"


int main(int argc, char *argv[]) {

    for(int i = 0; i < argc; i++){
        cout << "Argument "<< i << " = " << argv[i] << endl;
    }

    ATM atm(new FeeTaker(20, new Dispenser(100, new Dispenser(50, new Dispenser(20, new Dispenser(10))))));
    // process the requests
    cout << "---------------" << endl;
    atm.WithdrawCash(610);
    cout << "---------------" << endl;
    atm.WithdrawCash(50);
    cout << "---------------" << endl;
    atm.WithdrawCash(123);
    cout << "---------------" << endl;

//    ATM_v2 atm_v2;
//    atm_v2.AddNewElementToChain(new FeeTaker(20));  // order of chain elements matters
//    atm_v2.AddNewElementToChain(new Dispenser(100));
//    atm_v2.AddNewElementToChain(new Dispenser(50));
//    atm_v2.AddNewElementToChain(new Dispenser(20));
//    atm_v2.AddNewElementToChain(new Dispenser(10));
//    // process the requests
//    cout << "---------------" << endl;
//    atm_v2.WithdrawCash(610);
//    cout << "---------------" << endl;
//    atm_v2.WithdrawCash(50);
//    cout << "---------------" << endl;
//    atm_v2.WithdrawCash(123);
//    cout << "---------------" << endl;

    return EXIT_SUCCESS;
};

//Output:

//---------------
//Subtracting fee: 20$.
//To dispense: 5 x 100$ banknote.
//To dispense: 1 x 50$ banknote.
//To dispense: 2 x 20$ banknote.
//---------------
//Subtracting fee: 20$.
//To dispense: 1 x 20$ banknote.
//To dispense: 1 x 10$ banknote.
//---------------
//Subtracting fee: 20$.
//To dispense: 1 x 100$ banknote.
//Can't dispense further... Remainder: 1$ < banknote face value: 10$.
//---------------
//~FeeTaker: 20$.
//~Dispenser: 100$.
//~Dispenser: 50$.
//~Dispenser: 20$.
//~Dispenser: 10$.
//
//Process finished with exit code 0
