#include "../include/visitor_simulate_fight.h"

std::set<std::shared_ptr<Npc>> simulate_fight(const std::set<std::shared_ptr<Npc> > &set_npc, const int distance) {
    std::set<std::shared_ptr<Npc> > dead_list;

    for (auto& attacker : set_npc) {
        for (auto &defender : set_npc) {
            if (attacker == defender) continue;

            if (attacker->accept(defender)) {
                dead_list.insert(defender);
            }
        }
    }
    return dead_list;
}

bool VisitorFightDragon::fight(std::shared_ptr <Npc> defender) {
    // атакующий дракон
    if (dynamic_pointer_cast<KnightErrant>(defender)) {
        // если защищающийся рыцарь
        return true;
    }
    return false;
}

bool VisitorFightFrog::fight(std::shared_ptr <Npc> defender) {
    // атакующий жаба - всегда побеждает
    return true;
}

bool VisitorFightKnightErrant::fight(std::shared_ptr <Npc> defender) {
    // атакующий рыцарь
    if (dynamic_pointer_cast<Dragon>(defender)) {
        // если защищающийся дракон
        return true;
    }
    return false;
}

