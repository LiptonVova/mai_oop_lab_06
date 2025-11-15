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

    std::ifstream in;
    in.open("../input.txt", std::ios::in);

    std::unique_ptr<Npc> frog_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::frog, in);
    std::unique_ptr<Npc> knight_errant_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::knight_errant, in);
    std::unique_ptr<Npc> dragon_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::dragon, in);

    std::cout << "Test factory from file:\n";

    dragon_ptr_from_file->print();
    frog_ptr_from_file->print();
    knight_errant_ptr_from_file->print();

    return 0;
}