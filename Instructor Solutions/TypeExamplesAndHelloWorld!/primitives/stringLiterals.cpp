#include "typeInspection.h"
#include <string>
  
void stringLiterals()
{
    using namespace std::string_literals; //C++14 std::string literals
    std::cout << "##############################################################\n";
    std::cout << " Literal Types:\n";
    std::cout << "##############################################################\n";

    // Character literals
    printInfo("A", 'A'); // char
    printInfo(R"](u8'A')]", u8"A"); // char
    printInfo(R"](L'A')]", L'A'); // wchar_t
    printInfo(R"](u'A')]", u'A'); // char16_t
    printInfo(R"](U'A')]", U'A'); // char32_t

    // String literals
    printInfo("hello", "hello"); // const char*
    printInfo(R"](L"hello")]", L"hello"); // const wchar_t*
    //SINCE C++11
    printInfo(R"](u8"hello")]", u8"hello"); // const char*, encoded as UTF-8  
    printInfo(R"](u"hello")]", u"hello"); // const char16_t*, encoded as UTF-16
    printInfo(R"](U"hello")]", U"hello"); // const char32_t*, encoded as UTF-32

    // Raw string literals containing unescaped \ and "
    // Raw string literal 'r' since C++11
    printInfo(R"](R"("Hello \ world")")]", R"("Hello \ world")"); // const char*
    printInfo(R"](u8R"("Hello \ world")")]", u8R"("Hello \ world")"); // const char*, encoded as UTF-8
    printInfo(R"](LR"("Hello \ world")")]", LR"("Hello \ world")"); // const wchar_t*
    printInfo(R"](uR"("Hello \ world")")]", uR"("Hello \ world")"); // const char16_t*, encoded as UTF-16
    printInfo(R"](UR"("Hello \ world")")]", UR"("Hello \ world")"); // const char32_t*, encoded as UTF-32

    // Combining string literals with standard s-suffix
    // std::string literals since C++14
    printInfo(R"]("hello"s)]", "hello"s); // std::string
    printInfo(R"](u8"hello"s)]", u8"hello"s); // std::string
    printInfo(R"](L"hello"s)]", L"hello"s); // std::wstring
    printInfo(R"](u"hello"s)]", u"hello"s); // std::u16string
    printInfo(R"](U"hello"s)]", U"hello"s); // std::u32string

    // Combining raw string literals with standard s-suffix
    printInfo(R"](R"("Hello \ world")"s)]", R"("Hello \ world")"s); // std::string from a raw const char*
    printInfo(R"](u8R"("Hello \ world")"s)]", u8R"("Hello \ world")"s); // std::string from a raw const char*, encoded as UTF-8
    printInfo(R"](LR"("Hello \ world")"s)]", LR"("Hello \ world")"s); // std::wstring from a raw const wchar_t*
    printInfo(R"](uR"("Hello \ world")"s)]", uR"("Hello \ world")"s); // std::u16string from a raw const char16_t*, encoded as UTF-16
    printInfo(R"](UR"("Hello \ world")"s)]", UR"("Hello \ world")"s); // std::u32string from a raw const char32_t*, encoded as UTF-32
}

