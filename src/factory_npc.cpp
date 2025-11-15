#include "../include/factory_npc.h"

std::unique_ptr<Npc> FactoryNpc::create_npc(const TypeNpc &type) {
    switch (type) {
        case TypeNpc::dragon:
            return std::make_unique<Dragon>();
            break;
        case TypeNpc::frog:
            return std::make_unique<Frog>();
            break;
        case TypeNpc::knight_errant:
            return std::make_unique<KnightErrant>();
            break;
    }
    return nullptr;
}
