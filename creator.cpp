#include <iostream>
#include <fstream>
#include <string>

struct employee {
    int num;
    char name[10];
    double hours;
};

int main(int argc, char* argv[]) {
    std::string filename = argv[1];
    int count = std::stoi(argv[2]);

    std::ofstream file(filename, std::ios::binary);

    for (int i = 0; i < count; i++) {
        employee emp;
        std::cout << "enter emp data (id name hours): ";
        std::cin >> emp.num >> emp.name >> emp.hours;

        file.write((char*)&emp, sizeof(employee));
    }

    file.close();
    return 0;
}
