#pragma once

#include "KENG_Utils.hpp"

#include <string>
#include <array>

namespace KENG {
    class Province {
        private:
            llui id                               = 0;
            std::string name                      = "PROV";
            std::array<ui8, 3> color              = {255, 255, 255};

        public:
            Province(llui id, std::string name, std::array<ui8, 3> color);
            ~Province(void);
    }; // Province class
    
} // Kallergis engine namespace