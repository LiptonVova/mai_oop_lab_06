#ifndef LAB_06_FACTORY_NPC_H
#define LAB_06_FACTORY_NPC_H

#include "npc.h"
#include "dragon.h"
#include "frog.h"
#include "knight_errant.h"
#include <memory>


enum class TypeNpc { dragon, frog, knight_errant };

class FactoryNpc {
public:
    static std::unique_ptr<Npc> create_npc(const TypeNpc& type);
};

#endif //LAB_06_FACTORY_NPC_H