#include <iostream>
#include <memory>

#include "include/factory_npc.h"
#include "include/observer.h"


int main() {
    std::shared_ptr<Npc> dragon_ptr = FactoryNpc::create_npc(TypeNpc::dragon);
    std::shared_ptr<Npc> frog_ptr = FactoryNpc::create_npc(TypeNpc::frog);
    std::shared_ptr<Npc> knight_errant_ptr = FactoryNpc::create_npc(TypeNpc::knight_errant);

    dragon_ptr->print();
    frog_ptr->print();
    knight_errant_ptr->print();

    std::ifstream in;
    in.open("../input.txt", std::ios::in);

    std::shared_ptr<Npc> frog_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::frog, in);
    std::shared_ptr<Npc> knight_errant_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::knight_errant, in);
    std::shared_ptr<Npc> dragon_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::dragon, in);

    std::cout << "Test factory from file:\n";

    dragon_ptr_from_file->print();
    frog_ptr_from_file->print();
    knight_errant_ptr_from_file->print();

    std::cout << dragon_ptr_from_file->accept(dragon_ptr) << std::endl;
    std::cout << dragon_ptr_from_file->accept(knight_errant_ptr) << std::endl;

    auto stdin_observer = std::make_shared<StdinObserver>();
    auto log_observer = std::make_shared<FileObserver>();
    dragon_ptr->attach(stdin_observer);
    dragon_ptr->attach(log_observer);

    dragon_ptr->notify(*frog_ptr);

    std::cout << "after detach : \n";
    dragon_ptr->detach(stdin_observer);

    dragon_ptr->notify(*frog_ptr);



    return 0;
}