#include <iostream>
#include <memory>

#include "include/factory_npc.h"



int main() {
    std::unique_ptr<Npc> dragon_ptr = FactoryNpc::create_npc(TypeNpc::dragon);
    std::unique_ptr<Npc> frog_ptr = FactoryNpc::create_npc(TypeNpc::frog);
    std::unique_ptr<Npc> knight_errant_ptr = FactoryNpc::create_npc(TypeNpc::knight_errant);

    dragon_ptr->print();
    frog_ptr->print();
    knight_errant_ptr->print();

    return 0;
}