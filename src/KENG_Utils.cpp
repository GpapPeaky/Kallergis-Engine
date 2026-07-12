#include "KENG_Utils.hpp"

namespace KENG::Utils{
    ui32 PackRGB(ui8 r, ui8 b, ui8 g) {
        return (static_cast<ui32>(r) << 16) | 
               (static_cast<ui32>(g) << 8)  | 
                static_cast<ui32>(b);
    }
}
