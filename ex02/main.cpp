#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define main original_main
#include "OriginalTest.cpp"
#undef main

// ─── 헬퍼 함수 ───────────────────────────────────────────────────────────────

// int 배열 출력
void printIntArray(const Array<int>& arr) {
    for (unsigned i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

// string 배열 출력
void printStringArray(const Array<std::string>& arr) {
    for (unsigned i = 0; i < arr.size(); ++i)
        std::cout << '"' << arr[i] << "\" ";
    std::cout << '\n';
}

// ─── 추가 테스트 ────────────────────────────────────────────────────────────
void manualTest() {
    std::cout << std::endl;
    std::cout << "=== 1) 기본/크기 생성자 테스트 ===\n";
    Array<int> a0;
    std::cout << "a0.size() = " << a0.size() << "\n";

    Array<int> a1(5);
    std::cout << "a1 (5개 0 초기화): ";
    printIntArray(a1);

    // 값을 직접 지정
    for (unsigned i = 0; i < a1.size(); ++i)
        a1[i] = static_cast<int>(i * 10);
    std::cout << "a1 after assign: ";
    printIntArray(a1);

    std::cout << "\n=== 2) 복사 생성자/대입 연산자 테스트 ===\n";
    // 복사 생성자
    Array<int> a2(a1);
    std::cout << "a2 (copy of a1): ";
    printIntArray(a2);

    // 원본 변경 후 deep copy 확인
    a1[0] = 999;  
    std::cout << "a1 modified:        ";
    printIntArray(a1);
    std::cout << "a2 should unchanged:";
    printIntArray(a2);

    // 복사 대입 연산자
    Array<int> a3;
    a3 = a2;
    std::cout << "a3 (assigned from a2): ";
    printIntArray(a3);

    a2[1] = 888;
    std::cout << "a2 modified:            ";
    printIntArray(a2);
    std::cout << "a3 should unchanged:    ";
    printIntArray(a3);

    std::cout << "\n=== 3) 예외 처리 테스트 ===\n";
    try {
        a3[a3.size()] = 0;
    } catch (const std::exception&) {
        std::cout << "✔ Caught out-of-bounds a3[a3.size()]\n";
    }
    try {
        int x = a3[100]; (void)x;
    } catch (const std::exception&) {
        std::cout << "✔ Caught out-of-bounds a3[100]\n";
    }

    std::cout << "\n=== 4) 랜덤 스트레스 테스트 (작은 크기) ===\n";
    const int TEST_SIZE = 10;
    Array<int> randArr(TEST_SIZE);
    int* mirror = new int[TEST_SIZE];
    std::srand(static_cast<unsigned>(std::time(NULL)));
    for (int i = 0; i < TEST_SIZE; ++i) {
        int v = std::rand() % 1000;
        randArr[i] = v;
        mirror[i]  = v;
    }
    // 복사해서 스코프 벗어나기
    {
        Array<int> tmp = randArr;
        Array<int> tst(tmp);
    }
    // 원본과 미러 비교
    bool ok = true;
    for (int i = 0; i < TEST_SIZE; ++i)
        if (mirror[i] != randArr[i]) { ok = false; break; }
    std::cout << (ok 
        ? "✔ Random data preserved after copy\n" 
        : "✘ Random data mismatch!\n");
    delete[] mirror;

    std::cout << "\n=== 5) std::string 타입 테스트 ===\n";
    Array<std::string> sArr(3);
    sArr[0] = "foo";
    sArr[1] = "bar";
    sArr[2] = "baz";
    std::cout << "sArr contents: ";
    printStringArray(sArr);

    const Array<std::string>& cs = sArr;
    try {
        (void)cs[cs.size()];
    } catch (const std::exception&) {
        std::cout << "✔ Caught out-of-bounds cs[cs.size()]\n";
    }

    std::cout << "\nAll tests completed.\n\n";
}

int main() {
    std::cout << std::endl << GREEN << "===== 원본 테스트 시작 =====\n" << RESET;
    original_main(0, 0);
    std::cout << GREEN << "===== 원본 테스트 완료 =====\n" << RESET ;

    manualTest();
    std::cout << "모든 테스트 완료!\n";
    return 0;
}