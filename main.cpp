#include <iostream>
#include <memory>

#include "include/core.h"
#include "include/factory_npc.h"
#include "include/observer.h"


int main() {
    std::shared_ptr<Npc> dragon_ptr = FactoryNpc::create_npc(TypeNpc::dragon);
    std::shared_ptr<Npc> frog_ptr = FactoryNpc::create_npc(TypeNpc::frog);
    std::shared_ptr<Npc> knight_errant_ptr = FactoryNpc::create_npc(TypeNpc::knight_errant);

    dragon_ptr->print(std::cout) << '\n';
    frog_ptr->print(std::cout) << '\n';
    knight_errant_ptr->print(std::cout) << '\n';

    std::ifstream in;
    in.open("../input.txt", std::ios::in);

    std::shared_ptr<Npc> frog_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::frog, in);
    std::shared_ptr<Npc> knight_errant_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::knight_errant, in);
    std::shared_ptr<Npc> dragon_ptr_from_file = FactoryNpc::create_npc_from_file(TypeNpc::dragon, in);

    std::cout << "Test factory from file:\n";

    std::cout << dragon_ptr_from_file->info() << '\n';
    std::cout << frog_ptr_from_file->info() << '\n';
    std::cout << knight_errant_ptr_from_file->info() << '\n';

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


    std::set<std::shared_ptr<Npc>> set_npc;
    set_npc.insert(dragon_ptr);
    set_npc.insert(frog_ptr);
    set_npc.insert(knight_errant_ptr);

    print_all_npc(std::cout, set_npc) << '\n';


    knight_errant_ptr->attach(stdin_observer);
    knight_errant_ptr->attach(log_observer);

    dragon_ptr_from_file->attach(stdin_observer);
    dragon_ptr_from_file->attach(log_observer);

    frog_ptr_from_file->attach(stdin_observer);
    frog_ptr_from_file->attach(log_observer);

    frog_ptr->attach(stdin_observer);
    frog_ptr->attach(log_observer);

    knight_errant_ptr->attach(stdin_observer);
    knight_errant_ptr->attach(log_observer);

    set_npc.insert(knight_errant_ptr);
    set_npc.insert(dragon_ptr_from_file);
    set_npc.insert(frog_ptr_from_file);

    start_fight(set_npc, 1);

    return 0;
}