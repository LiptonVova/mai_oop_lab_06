#include "../include/frog.h"

void Frog::print() const {
    std::cout << "I frog(" << this->x << ' ' << this->y << ") " << this->unique_name << '\n';
}
