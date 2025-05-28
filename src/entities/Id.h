#ifndef ID_H
#define ID_H

#include <string>

class Id {
public:
    std::string id;
    Id(std::string id): id(id) {}
    ~Id() {}

    bool operator==(const Id& other) {
        return (this->id == other.id);
    }
};

#endif
