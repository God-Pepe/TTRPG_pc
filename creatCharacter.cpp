#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int creat_intelectCr() {
    return (rand() % 4 + 1) + 2;
};

int creat_strengthCr() {
    return (rand() % 4 + 1) + 2;
};

int creat_dexterityCr() {
    return (rand() % 4 + 1) + 2;
};

int creat_accuracyCr() {
    return (rand() % 4 + 1) + 2;
};

int creat_hpCr() {
    return (rand() % 12 + 1) + 10;
};