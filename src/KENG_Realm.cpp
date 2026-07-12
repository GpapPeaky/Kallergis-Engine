#include "KENG_Realm.hpp"

namespace KENG {
    Realm::Realm(llui id, std::string name, ui32 color) {
        this->id = id;
        this->name = name;
        this->color = color;
    }

    Realm::~Realm(void) {}

    llui Realm::Id(void) const {
        return id;
    }

    ui32 Realm::Color(void) {
        return color;
    }

    std::string Realm::Name(void) {
        return name;
    }
}