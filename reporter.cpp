#include <iostream>
#include <fstream>
#include <string>

struct employee {
    int num;
    char name[10];
    double hours;
};

int main(int argc, char* argv[]) {
    std::string bin_name = argv[1];
    std::string text_name = argv[2];
    double rate = std::stod(argv[3]);

    std::ifstream bin_file(bin_name, std::ios::binary);
    std::ofstream text_file(text_name);

    text_file << "file report: " << bin_name << "\n";
    text_file << "id, name, hours, wage\n";

    employee emp;
    while (bin_file.read((char*)&emp, sizeof(employee))) {
        double salary = emp.hours * rate;
        text_file << emp.num << " " << emp.name << " " << emp.hours << " " << salary << "\n";
    }

    bin_file.close();
    text_file.close();
    return 0;
}
