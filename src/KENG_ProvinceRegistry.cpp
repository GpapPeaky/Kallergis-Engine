#include "KENG_ProvinceRegistry.hpp"

namespace KENG {
    ProvinceRegistry::ProvinceRegistry(void) {}

    ProvinceRegistry::~ProvinceRegistry(void) {}

    void ProvinceRegistry::ReadProvinceFile() {
        // TODO:
    }

    Province& ProvinceRegistry::GetProvince(std::array<ui8, 3> color) {
        ui32 packedRGB = Utils::PackRGB(color[0], color[1], color[2]);

        auto it = colorToId.find(packedRGB); // Just need to find a number, not an entire array!

        if (it != colorToId.end()) {
            return provinces[it->second];
        }

        static Province nullProvince{0, "nullprov", 0xffffff}; // NULL
        return nullProvince;
    }
    
    Province& ProvinceRegistry::GetProvince(llui id) {
        return provinces[id];
    }

    void ProvinceRegistry::Print(void) {
        for (auto prov : provinces) {
            std::cout << prov.Id() << " " << prov.Name() << std::endl;
        }
    }
}