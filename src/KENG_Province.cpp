#include "KENG_Province.hpp"

namespace KENG {
    Province::Province(llui id, std::string name, std::array<ui8, 3> color) {
        this->id = id;
        this->name = name;
        this->color = color;
    }

    Province::~Province(void) {}
}