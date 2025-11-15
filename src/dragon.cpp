#include "../include/dragon.h"

void Dragon::print() const {
    std::cout << "I dragon(" << this->x << ' ' << this->y << ") " << this->unique_name << '\n';
}
