#include "KENG_ProvinceController.hpp"

namespace KENG {
    ProvinceController::ProvinceController(void) {}

    ProvinceController::~ProvinceController(void) {}

    Province& ProvinceController::GetHoveredProvince(ProvinceRegistry& pr, GLuint provMap) {
        hoveredColor = Utils::GetPixelAtMouse(provMap);
        std::array<float, 3> color = Utils::UnpackRGB_01(hoveredColor);

        // std::cout << color[0] << " " << color[1] << " " << color[2] << "\n";

        return pr.GetProvince(Utils::UnpackRGB_0255(hoveredColor));
    }
}