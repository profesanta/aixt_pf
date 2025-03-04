// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Andrés Felipe Fajardo y Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin port management functions (PIC18F2550 port)

module port

#include <xc.h>

#define port__out  0   // port mode (direction)
#define port__in   1