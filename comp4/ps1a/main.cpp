#include <iostream>
#include "LSFR.hpp"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    string seed = "01101000010";
    int tap = 8;

    LSFR my_l(seed, tap);

    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;
    cout << my_l.step() << " " << my_l << endl;

    cout << endl;

    cout << my_l << " " << my_l.generate(5) << endl;
    cout << my_l << " " << my_l.generate(5) << endl;
    cout << my_l << " " << my_l.generate(5) << endl;
    cout << my_l << " " << my_l.generate(5) << endl;
    cout << my_l << " " << my_l.generate(5) << endl;
    cout << my_l << " " << my_l.generate(5) << endl;
    cout << my_l << " " << my_l.generate(5) << endl;
    cout << my_l << " " << my_l.generate(5) << endl;

    return 0;
}