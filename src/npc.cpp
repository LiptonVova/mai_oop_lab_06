#include "../include/npc.h"

#include <memory>


std::istream& operator>>(std::istream& is, Npc& npc) {
    is >> npc.x >> npc.y >> npc.unique_name;
    // getline(is, npc.unique_name);

    return is;
}

Npc::Npc(Npc&& other) noexcept {
    unique_name = std::move(other.unique_name);
    x = other.x;
    y = other.y;
}