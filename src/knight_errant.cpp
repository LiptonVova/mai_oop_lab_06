#include "../include/knight_errant.h"

void KnightErrant::print() const {
    std::cout << "I knight errant(" << this->x << ' ' << this->y << ") " << this->unique_name << '\n';
}
