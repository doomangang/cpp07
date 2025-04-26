#include <iostream>
#include <string>
#include "iter.hpp"

// ─── 프린터 함수들  ─────────────────────────────────

void printInt(const int& x)             { std::cout << x << ' '; }
void printString(const std::string& s)  { std::cout << s << ' '; }
void printChar(const char& c)           { std::cout << c << ' '; }
void printDouble(const double& d)       { std::cout << d << ' '; }

// ─── 변형 함수들  ────────────────────────────────────

void incrementInt(int& x)               { ++x; }
void exclaimString(std::string& s)      { s += "!"; }
void toUpperChar(char& c) {
    if (c >= 'a' && c <= 'z')
        c = static_cast<char>(c - 'a' + 'A');
}

int main() {
    // 1) int 배열 테스트
    {
        std::cout << YELLOW << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        std::size_t len = sizeof(arr) / sizeof(*arr);
        std::cout << "Original int:   ";
        iter(arr, len, printInt);
        std::cout << "\n";

        iter(arr, len, incrementInt);
        std::cout << "Incremented:    ";
        iter(arr, len, printInt);
        std::cout << "\n\n";
    }

    // 2) std::string 배열 테스트
    {
        std::cout << GREEN ;
        std::string arr[] = {"hello", "world", "42", "iter"};
        std::size_t len = sizeof(arr) / sizeof(*arr);
        std::cout << "Original str:   ";
        iter(arr, len, printString);
        std::cout << "\n";

        iter(arr, len, exclaimString);
        std::cout << "Exclaimed:      ";
        iter(arr, len, printString);
        std::cout << "\n\n";
    }

    // 3) char 배열 테스트
    {
        std::cout << BLUE;
        char arr[] = {'a','b','c','d','e'};
        std::size_t len = sizeof(arr) / sizeof(*arr);
        std::cout << "Original char:  ";
        iter(arr, len, printChar);
        std::cout << "\n";

        iter(arr, len, toUpperChar);
        std::cout << "Uppercased:     ";
        iter(arr, len, printChar);
        std::cout << "\n\n";
    }

    // 4) const int 배열 테스트 (값 변경 함수 적용 불가 → print만)
    {
        std::cout << MAGENTA;
        const int arr[] = {10, 20, 30};
        std::size_t len = sizeof(arr) / sizeof(*arr);
        std::cout << "Const int arr:  ";
        iter(arr, len, printInt);
        std::cout << "\n\n";
    }

    // 5) const std::string 배열 테스트
    {
        std::cout << CYAN;
        const std::string arr[] = {"foo", "bar", "baz"};
        std::size_t len = sizeof(arr) / sizeof(*arr);
        std::cout << "Const strs:     ";
        iter(arr, len, printString);
        std::cout << "\n\n";
    }

    // 6) const double 배열 테스트
    {
        std::cout << RESET << GREEN;
        const double arr[] = {3.14, 2.71, 1.41};
        std::size_t len = sizeof(arr) / sizeof(*arr);
        std::cout << "Const double:   ";
        iter(arr, len, printDouble);
        std::cout << "\n\n";
    }

    // 7) 길이 0 배열 테스트
    {
        std::cout << GREY ;
        int arr[1] = { 0 };
        std::cout << "Length=0 test:  ";
        iter(arr, 0, printInt);
        std::cout << "(no output)\n";
        std::cout << RESET << std::endl;
    }

    return 0;
}
