#include <iostream>

int main() {
    int count;
    std::string s;
    while(std::cin >> s) {
        count++;
    }
    std::cout << count << std::endl;
}