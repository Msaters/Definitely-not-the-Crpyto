#include "CardProviderService/CardProvider.hpp"

#include <windows.h>
#include <iostream>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "STARTED" << std::endl;
    const CardProvider cardProvider;
    return 0;
}