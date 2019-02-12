#pragma once
#include <iostream>
using namespace std;

class LFSR {
public:
    LFSR(string seed, int t);
    int step();
    int generate(int k);
    friend ostream& operator<< (ostream& out, const LFSR &rhs);

private:
    string seed;
    int tap_idx;
    int max_idx;

    bool xor_at_idx(int idx_1, int idx_2);
};