#include <algorithm>    // remove_if, find, sort
#include <iostream>
#include <vector>
#include <random>       // random_device, uniform_int_distribution
#include <ctime>        // valor para el srand
#include <cstdlib>      // srand, rand
#include <iomanip>

void print(const std::vector<int>& vec) {
    for (auto& item: vec) std::cout << item << " ";
    std::cout << std::endl;
}

void borrar_valores_1() {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);
    std::vector<int> vec(20);
    for (auto& item: vec) item = dist(rd);
    print(vec);
    for (auto it = vec.begin(); it != vec.end();) {
        if (*it >= 60) {
            vec.erase(it);
        }
        else {
            ++it;
        }
    }
    std::cout << std::endl;
    print(vec);
}

void borrar_valores_2() {
    srand(time(nullptr));
    std::vector<int> vec(20);
    for (auto& item: vec) item = rand() % 100 + 1;
    print(vec);
    for (auto it = vec.begin(); it != vec.end();) {
        if (*it >= 60) {
            vec.erase(it);
        }
        else {
            ++it;
        }
    }
    std::cout << std::endl;
    print(vec);
}

bool mayores_de_60(int value) { return value >= 60; }

void borrar_valores_3() {
    srand(time(nullptr));
    std::vector<int> vec(20);
    for (auto& item: vec) item = rand() % 100 + 1;
    print(vec);
    vec.erase(std::remove_if(vec.begin(), vec.end(), mayores_de_60), vec.end());
    std::cout << std::endl;
    print(vec);
}

void buscar_valores_1() {
    srand(time(nullptr));
    std::vector<int> vec(20);
    for (auto& item: vec) item = rand() % 100 + 1;
    print(vec);
    auto it = std::find(vec.begin(), vec.end(), 60);
    if (it != vec.end()) {
        std::cout << *it << std::endl;
    }
    else {
        std::cout << "No encontrado";
    }
}

bool multiplo_de_2_y_7(int value) { return value%2 == 0 && value%7 == 0; }

void buscar_valores_2() {
    srand(time(nullptr));
    std::vector<int> vec(20);
    for (auto& item: vec) item = rand() % 100 + 1;
    print(vec);
    auto it = std::find_if(vec.begin(), vec.end(), multiplo_de_2_y_7);
    if (it != vec.end()) {
        std::cout << *it << std::endl;
    }
    else {
        std::cout << "No encontrado";
    }
}

void buscar_valores_3() {
    srand(time(nullptr));
    std::vector<int> vec(120);
    for (auto& item: vec) item = rand() % 100 + 1;
    print(vec);
    auto it = vec.begin();
    while (it != vec.end()) {
        it = std::find_if(it, vec.end(), multiplo_de_2_y_7);
        if (it != vec.end()) {
            std::cout << *it << std::endl;
            ++it;
        }
        else {
            std::cout << "No encontrado";
        }
    }
}

void ordenar_valores_1() {
    srand(time(nullptr));
    std::vector<int> vec(20);
    for (auto& item: vec) item = rand() % 100 + 1;
    print(vec);
    std::sort(vec.begin(), vec.end(), std::less<>());
    print(vec);
    std::sort(vec.begin(), vec.end(), std::greater<>());
    print(vec);
}

using TMatrix = std::vector<std::vector<int>>;

void print_matriz(const TMatrix& matrix, int width = 4) {
    for (auto& row: matrix) {
        for (auto& item: row) {
            std::cout << std::setw(width) << item << " ";
        }
        std::cout << std::endl;
    }
}

void generar_matriz_1() {
    int rows = 2;
    int cols = 3;
    TMatrix matriz(rows, std::vector<int>(cols));
    matriz = {
        {100, 27, 37},
        {4, 5, 6}
    };
    print_matriz(matriz, 3);
}
int main() {
    // borrar_valores_1();
    // borrar_valores_2();
    // borrar_valores_3();
    // buscar_valores_1();
    // buscar_valores_2();
    // buscar_valores_3();
    // ordenar_valores_1();
    generar_matriz_1();
    return 0;
}
