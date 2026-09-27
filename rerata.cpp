#include <iostream>

int main() {
    double nilai1, nilai2, nilai3;

    std::cout << "Masukkan nilai 1: ";
    std::cin >> nilai1;

    std::cout << "Masukkan nilai 2: ";
    std::cin >> nilai2;

    std::cout << "Masukkan nilai 3: ";
    std::cin >> nilai3;

    const double rata_rata = (nilai1 + nilai2 + nilai3) / 3.0;

    std::cout << "Rata-rata = " << rata_rata << std::endl;

    return 0;
}
