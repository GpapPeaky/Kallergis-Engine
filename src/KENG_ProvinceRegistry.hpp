#pragma once

#include "KENG_Utils.hpp"
#include "KENG_Province.hpp"

#include <vector>
#include <unordered_map>

namespace KENG {
    class ProvinceRegistry {
        private:
            std::unordered_map<ui32, llui> colorToId;
            std::vector<Province> registry;
        public:
            ProvinceRegistry(void);
            ~ProvinceRegistry(void);

            void ReadProvinceFile(void); // One specific file History/Provs.dat

            Province& GetProvince(std::array<ui8, 3> color);
            
            Province& GetProvince(llui id);
    };
}