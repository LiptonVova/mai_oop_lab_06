#ifndef LAB_06_FROG_H
#define LAB_06_FROG_H

#include "npc.h"

class Frog final: public Npc {
public:
    Frog() : Npc() {};
    Frog(const unsigned int x, const unsigned int y, const std::string &name) : Npc(x, y, name) {};

    void print() const override;
};

#endif //LAB_06_FROG_H