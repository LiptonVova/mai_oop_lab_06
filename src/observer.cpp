#include "../include/observer.h"


void FileObserver::update(const Npc &attacker, const Npc &defender) {
    log_file.open("../log_file.txt", std::ios::app);

    if (log_file.is_open()) {
        log_file << "file observer: ...\n";
    }
    else {
        throw std::logic_error("File could not be opened");
    }
    log_file.close();
}

void StdinObserver::update(const Npc &attacker, const Npc &defender) {
    std::cout << "stdin observer: ...\n";
}
