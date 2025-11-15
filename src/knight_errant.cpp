#include "../include/knight_errant.h"

#include "../include/visitor_simulate_fight.h"

void KnightErrant::print() const {
    std::cout << "I knight errant(" << this->x << ' ' << this->y << ") " << this->unique_name << '\n';
}

bool KnightErrant::accept(std::shared_ptr <Npc> npc_ptr) const {
    VisitorFightKnightErrant visitor_fight_knight_errant;
    return visitor_fight_knight_errant.fight(npc_ptr);
}
