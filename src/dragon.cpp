#include "../include/dragon.h"

#include "../include/visitor_simulate_fight.h"

void Dragon::print() const {
    std::cout << "I dragon(" << this->x << ' ' << this->y << ") " << this->unique_name << '\n';
}

bool Dragon::accept(std::shared_ptr <Npc> npc_ptr) const {
    VisitorFightDragon visitor_fight_dragon;
    return visitor_fight_dragon.fight(npc_ptr);
}