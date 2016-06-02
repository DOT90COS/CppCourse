#include "typeInspection.h"

void primitiveTypes()
{
    std::cout << "##############################################################\n";
    std::cout << " Primitives Types:\n";
    std::cout << "##############################################################\n";

    // at least 8 bits
    printInfo("char('a')", char('a'));
    printInfo("signed char('a')", (signed char)('a'));
    printInfo("unsigned char(1)", (unsigned char)(1));

    //integer types

    // at least 16 bits
    printInfo("unsigned short(16543)", (unsigned short)(16543));
    printInfo("unsigned short int(16543)", (unsigned short int)(16543));
    printInfo("short(-16543)", (short)(-16543));
    printInfo("short int(-16543)", (short int)(-16543));
    printInfo("signed short int(-16543)", (signed short int)(-16543));
    printInfo("signed short(-16543)", (signed short)(-16543));

    // at least 16 bit (32 on most modern OSes)
    printInfo("unsigned int (900500)", (unsigned int)(900500));
    printInfo("unsigned(900500)", (unsigned)(900500));
    printInfo("int(-900500)", int(-900500));
    printInfo("signed(-900500)", signed(-900500));
    printInfo("signed int(-900500)", (signed int)(-900500));

    // at least 32 bit
    printInfo("long(5678)", long(5678));
    printInfo("long int(5678)", (long int)(5678));
    printInfo("signed long(56789)", (signed long)(56789));
    printInfo("signed long int(56789)", (signed long int)(56789));
    printInfo("unsigned long(56789)", (unsigned long)(56789));
    printInfo("unsigned long int(56789)", (unsigned long int)(56789));

    // at least 64 bits
    printInfo("long long(300000000)", (long long)(300000000));
    printInfo("long long int(300000000)", (long long int)(300000000));
    printInfo("signed long long(300000000)", (signed long long)(300000000));
    printInfo("signed long long int(300000000)", (signed long long int)(300000000));
    printInfo("unsigned long long(300000000)", (unsigned long long)(300000000));
    printInfo("unsigned long long int(300000000)", (unsigned long long int)(300000000));

    //floating point
    printInfo("float(1.0)", float(1.0));
    printInfo("double(2.111111)", double(2.111111));
    printInfo("long double(3.14)", (long double)(3.14));

    //boolean type
    printInfo("bool(true)", bool(true));
    printInfo("false", false);
    printInfo("true", true);

	//void and nullptr
	printInfo("nullptr", nullptr);

}
