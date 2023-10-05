#include <iostream>

bool isMultipleOfThree(int n) {
    return n % 3 == 0;
}

bool isIncludeThree(int n) {
    while (n > 0) {
        if (n % 10 == 3) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    for(int i = 1; i <= 100; ++i) {
        if (isMultipleOfThree(i) || isIncludeThree(i))
            std::cout << i << std::endl;
    }
}