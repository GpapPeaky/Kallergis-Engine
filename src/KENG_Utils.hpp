#pragma once

typedef long long unsigned int llui;
typedef unsigned char ui8;
typedef unsigned int ui32;

#include <iostream> // For args
#include <fstream>

namespace KENG::Utils {
    ui32 PackRGB(ui8 r, ui8 b, ui8 g);

    extern std::ofstream LOG_RLM;  // Realm logging file
    extern std::ofstream LOG_PROV; // Proving logging file
} // Keng/Utils