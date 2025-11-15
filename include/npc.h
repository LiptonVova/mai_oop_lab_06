#ifndef MAI_OOP_LAB_06_NPC_H
#define MAI_OOP_LAB_06_NPC_H

#include <iostream>
#include <string>
#include <memory>

class Npc {
    friend std::istream& operator>>(std::istream& is, Npc& npc);

protected:
    unsigned int x = 0;
    unsigned int y = 0;
    std::string unique_name;

public:
    Npc() = default;

    Npc(const unsigned int x, const unsigned int y, const std::string &name) : x(x), y(y) {
        unique_name = name;
    }

    Npc(Npc&& other) noexcept;
    Npc(const Npc& other) = default;

    virtual bool accept(std::shared_ptr <Npc> npc_ptr) const = 0;

    virtual void print() const = 0;
    virtual ~Npc() = default;
};


#endif //MAI_OOP_LAB_06_NPC_H