#include "KENG_ProvinceRegistry.hpp"

namespace KENG {
    void ProvinceRegistry::ReadProvinceFile(void) {
        // TODO:
    }

    Province& ProvinceRegistry::GetProvince(std::array<ui8, 3> color) {
        ui32 packedRGB = Utils::PackRGB(color[0], color[1], color[2]);

        auto it = colorToId.find(packedRGB); // Just need to find a number, not an entire array!

        if (it != colorToId.end()) {
            return registry[it->second];
        }

        static Province nullProvince{0, "nullprov", {0, 0, 0}}; // NULL
        return nullProvince;
    }
    
    Province& ProvinceRegistry::GetProvince(llui id) {
        return registry[id];
    }
}