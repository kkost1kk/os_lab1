#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 

struct employee {
    int num;
    char name[10];
    double hours;
};

int main() {
    std::string bin_name;
    int count;

    std::cout << "enter file name: ";
    std::cin >> bin_name;
    std::cout << "enter records count: ";
    std::cin >> count;
    std::string cmd1 = "Creator.exe " + bin_name + " " + std::to_string(count);

    char command1[200];
    strcpy(command1, cmd1.c_str());
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    CreateProcessA(NULL, command1, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    std::ifstream bin_file(bin_name, std::ios::binary);
    employee emp;
    std::cout << "\nyour file:\n";
    while (bin_file.read((char*)&emp, sizeof(employee))) {
        std::cout << emp.num << " " << emp.name << " " << emp.hours << "\n";
    }
    bin_file.close();

    std::string text_name;
    double rate;
    std::cout << "\nenter report name: ";
    std::cin >> text_name;
    std::cout << "enter hour rate: ";
    std::cin >> rate;
    std::string cmd2 = "Reporter.exe " + bin_name + " " + text_name + " " + std::to_string(rate);
    char command2[200];
    strcpy(command2, cmd2.c_str());

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    CreateProcessA(NULL, command2, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    std::ifstream text_file(text_name);
    std::string line;
    std::cout << "\nreport:\n";
    while (std::getline(text_file, line)) {
        std::cout << line << "\n";
    }
    text_file.close();

    return 0;
}
