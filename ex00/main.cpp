#include "whatever.hpp"

int main() {
    
    int x = 2, y = 3;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << GREEN << "x = " << x << ", y = " << y  << " after swap" << std::endl;
    std::cout << YELLOW << "min(x,y) = " << ::min(x, y) << std::endl;
    std::cout << YELLOW << "max(x,y) = " << ::max(x, y) << std::endl << RESET;

    std::cout << std::endl;
    
    std::string s1 = "hello", s2 = "hell";
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    ::swap(s1, s2);
    std::cout << GREEN << "s1 = " << s1 << ", s2 = " << s2 << " after swap" << std::endl;
    std::cout << YELLOW << "min(s1,s2) = " << ::min(s1, s2) << std::endl;
    std::cout << YELLOW << "max(s1,s2) = " << ::max(s1, s2) << std::endl << RESET ;

    std::cout << std::endl;
    
    std::cout <<"------------ CONST TEST ------------"<<std::endl;
    const int a(2);
    const int b(3);
    // ::swap( a, b ); // compile error when un-commented
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << std::endl;

    const std::string c ("chaine1");
    const std::string d ("chaine2");
    // ::swap(c, d); // compile error when un-commented
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}