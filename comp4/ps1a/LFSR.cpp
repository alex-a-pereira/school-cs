#include <iostream>
#include "LFSR.hpp"

LFSR::LFSR(string seed, int t) {
    this->seed = seed;
    this->max_idx = seed.length() - 1;
    this->tap_idx = this->max_idx - t;
}

int LFSR::step() {
    char rightmost;
    xor_at_idx(0, tap_idx) ? rightmost = '1' : rightmost = '0';

    for (int i = 0; i < this->max_idx; i++) {
        this->seed.at(i) = this->seed.at(i + 1);
    }

    this->seed.at(max_idx) = rightmost;

    return rightmost - 48;
}

int LFSR::generate(int k) {
    int val = 0;
    for (int i = 0; i < k; i++) {
        val = (val * 2) + step();
    }
    return val;
}

bool LFSR::xor_at_idx(int idx_1, int idx_2) {
    return this->seed.at(idx_1) != this->seed.at(idx_2);
}

ostream& operator<< (ostream& out, const LFSR &rhs) {
    return out << rhs.seed;
}