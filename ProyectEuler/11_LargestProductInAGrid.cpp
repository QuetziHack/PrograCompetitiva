#include <fstream>
#include <print>
#include <array>

int main() {
    // Leerla la matriz del archivo
    std::array<std::array<int,20>,20> copia{};
    {
        std::ifstream in{"11_LargestProductInAGrid.txt", std::ios::binary};
        if (!in) { std::print("Error al leer\n"); return 1; }
        in.read(reinterpret_cast<char*>(copia.data()), sizeof(copia));
    }

    std::print("Elemento [0][0] = {}\n", copia[0][0]);
    std::print("Elemento [19][19] = {}\n", copia[19][19]);
}


