#include "../include/core.h"

#include "../include/visitor_simulate_fight.h"

void start_fight(const std::set<std::shared_ptr<Npc> > &set_npc, const int distance) {
    std::set dead_list = simulate_fight(set_npc, distance);

    for (auto &dead_npc : dead_list) {
        dead_list.erase(dead_npc);
    }
}
