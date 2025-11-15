#ifndef LAB_06_DRAGON_H
#define LAB_06_DRAGON_H

#include "npc.h"

class Dragon final : public Npc {
public:
    Dragon() : Npc() {};
    Dragon(const unsigned int x, const unsigned int y, const std::string &name) : Npc(x, y, name) {};

    void print() const override;
};

#endif //LAB_06_DRAGON_H