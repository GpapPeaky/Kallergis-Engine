#include "KENG_Utils.hpp"

namespace KENG::Utils{
    ui32 PackRGB(ui8 r, ui8 b, ui8 g) {
        return (static_cast<ui32>(r) << 16) | 
               (static_cast<ui32>(g) << 8)  | 
                static_cast<ui32>(b);
    }

    std::array<float, 3> UnpackRGB_01(ui32 rgb) {
        return {
            static_cast<float>((rgb >> 16) & 0xFF) / 255.0f, // R
            static_cast<float>((rgb >> 8)  & 0xFF) / 255.0f, // G
            static_cast<float>( rgb        & 0xFF) / 255.0f  // B
        };
    }

    std::array<ui8, 3> UnpackRGB_0255(ui32 rgb) {
        return {
            static_cast<ui8>((rgb >> 16) & 0xFF), // R
            static_cast<ui8>((rgb >> 8)  & 0xFF), // G
            static_cast<ui8>( rgb        & 0xFF)  // B
        };
    }

    ui32 GetPixelAtMouse(GLuint texture) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        int windowWidth, windowHeight;
        SDL_GetWindowSize(SDL2_Win, &windowWidth, &windowHeight);

        // Convert SDL top-left coordinates to OpenGL bottom-left coordinates
        int openGLX = mouseX;
        int openGLY = windowHeight - mouseY - 1;

        GLuint fbo;
        glGenFramebuffers(1, &fbo);

        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        glFramebufferTexture2D(
            GL_FRAMEBUFFER,
            GL_COLOR_ATTACHMENT0,
            GL_TEXTURE_2D,
            texture,
            0
        );

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
            glDeleteFramebuffers(1, &fbo);
            return 0;
        }

        GLubyte pixelColors[3];

        glReadPixels(
            openGLX,
            openGLY,
            1,
            1,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            pixelColors
        );

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glDeleteFramebuffers(1, &fbo);

        return PackRGB(pixelColors[0], pixelColors[1], pixelColors[2]);
    }

    std::ofstream LOG_PROV = std::ofstream("logs/prov.log");
    std::ofstream LOG_RLM = std::ofstream("logs/rlm.log");
}
