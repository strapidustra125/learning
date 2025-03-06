#include "diagnostics.h"


Diagnostics::Diagnostics()
{
    std::cout << "Diagnostics constructor was called" << std::endl;
}

Diagnostics::~Diagnostics()
{
    std::cout << "Diagnostics destructor was called" << std::endl;
}

void Diagnostics::someDiagnosticsMethod()
{
    std::cout << "Switch Diagnostics flag: " << __isDiagRead << " -> " << !__isDiagRead << std::endl;

    __isDiagRead = !__isDiagRead;
}
