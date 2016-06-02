#include "typeInspection.h"



void portableTypes()
{
    std::cout << "##############################################################\n";
    std::cout << " Portable Types:\n";
    std::cout << "##############################################################\n";
    printInfo("std::uint8_t(0xFF)", std::uint8_t(0xFF));
    printInfo("std::uint16_t(0xFFFF)", std::uint16_t(0xFFFF));
    printInfo("std::uint32_t(0xFFFFFFFF)", std::uint32_t(0xFFFFFFFF));
    printInfo("std::uint64_t(0xFFFFFFFFFFFFFFFF)", std::uint64_t(0xFFFFFFFFFFFFFFFF));
    printInfo("std::uint_least8_t(0xFF)", std::uint_least8_t(0xFF));
    printInfo("std::uint_least16_t(0xFFFF)", std::uint_least16_t(0xFFFF));
    printInfo("std::uint_least32_t(0xFFFFFFFF)", std::uint_least32_t(0xFFFFFFFF));
    printInfo("std::uint_least64_t(0xFFFFFFFFFFFFFFFF)", std::uint_least64_t(0xFFFFFFFFFFFFFFFF));
    printInfo("std::uint_fast8_t(0xFF)", std::uint_fast8_t(0xFF));
    printInfo("std::uint_fast16_t(0xFFFF)", std::uint_fast16_t(0xFFFF));
    printInfo("std::uint_fast32_(0xFFFFFFFF)", std::uint_fast32_t(0xFFFFFFFF));
    printInfo("std::uint_fast64_t(0xFFFFFFFFFFFFFFFF)", std::uint_fast64_t(0xFFFFFFFFFFFFFFFF));
    printInfo("std::int8_t(0xFF)", std::int8_t(0xFF));
    printInfo("std::int16_t(0xFFFF)", std::int16_t(0xFFFF));
    printInfo("std::int32_t(0xFFFFFFFF)", std::int32_t(0xFFFFFFFF));
    printInfo("std::int64_t(0xFFFFFFFFFFFFFFFF)", std::int64_t(0xFFFFFFFFFFFFFFFF));
    printInfo("std::int_least8_t(0xFF)", std::int_least8_t(0xFF));
    printInfo("std::int_least16_t(0xFFFF)", std::int_least16_t(0xFFFF));
    printInfo("std::int_least32_t(0xFFFFFFFF)", std::int_least32_t(0xFFFFFFFF));
    printInfo("std::int_least64_t(0xFFFFFFFFFFFFFFFF)", std::int_least64_t(0xFFFFFFFFFFFFFFFF));
    printInfo("std::int_fast8_t(0xFF)", std::int_fast8_t(0xFF));
    printInfo("std::int_fast16_t(0xFFFF)", std::int_fast16_t(0xFFFF));
    printInfo("std::int_fast32_t(0xFFFFFFFF)", std::int_fast32_t(0xFFFFFFFF));
    printInfo("std::int_fast64_t(0xFFFFFFFFFFFFFFFF)", std::int_fast64_t(0xFFFFFFFFFFFFFFFF));
}