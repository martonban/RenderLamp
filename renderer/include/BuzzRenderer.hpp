#ifndef BUZZ_RENDERER_HPP
#define BUZZ_RENDERER_HPP

#include "Arca.hpp"

class BuzzRenderer {
    public:
        // Insntace Realted Funtions
        static BuzzRenderer& GetInstance() {
            static BuzzRenderer instance;
            return instance;
        }
        void StartInstance(const std::filesystem::path& tmpPath);
    protected:
        BuzzRenderer() = default;
    private:
        // Instace realated guard functions 
        BuzzRenderer(const BuzzRenderer&) = delete;
        BuzzRenderer& operator=(const BuzzRenderer&) = delete;
};

#endif