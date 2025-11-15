#ifndef LAB_06_KNIGHT_ERRANT_H
#define LAB_06_KNIGHT_ERRANT_H

#include "npc.h"

class KnightErrant final: public Npc {
public:
    KnightErrant() : Npc() {};
    KnightErrant(const unsigned int x, const unsigned int y, const std::string &name) : Npc(x, y, name) {};

    void print() const override;
};


#endif //LAB_06_KNIGHT_ERRANT_H