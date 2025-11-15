#include <iostream>
#include <memory>

#include "include/factory_npc.h"
#include "include/observer.h"


int main() {
    std::shared_ptr<Npc> dragon_ptr = FactoryNpc::create_npc(TypeNpc::dragon);
    std::shared_ptr<Npc> frog_ptr = FactoryNpc::create_npc(TypeNpc::frog);
    std::shared_ptr<Npc> knight_errant_ptr = FactoryNpc::create_npc(TypeNpc::knight_errant);

    std::cout << dragon_ptr->info();
    std::cout << frog_ptr->info();
    std::cout << knight_errant_ptr->info();

    std::ifstream in;
    in.open("../input.txt", std::ios::in);

    std::shared_ptr<Npc> frog_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::frog, in);
    std::shared_ptr<Npc> knight_errant_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::knight_errant, in);
    std::shared_ptr<Npc> dragon_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::dragon, in);

    std::cout << "Test factory from file:\n";

    std::cout << dragon_ptr_from_file->info();
    std::cout << frog_ptr_from_file->info();
    std::cout << knight_errant_ptr_from_file->info();

    std::cout << "Test save npc in file\n";

    std::ofstream os("../log.txt", std::ios::app);

    dragon_ptr->save(os);
    frog_ptr->save(os);
    knight_errant_ptr->save(os);

    os.close();

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