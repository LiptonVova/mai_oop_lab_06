#include "../include/frog.h"

#include "../include/visitor_simulate_fight.h"

void Frog::print() const {
    std::cout << "I frog(" << this->x << ' ' << this->y << ") " << this->unique_name << '\n';
}

bool Frog::accept(std::shared_ptr <Npc> npc_ptr) const {
    VisitorFightFrog visitor;
    return visitor.fight(npc_ptr);
}