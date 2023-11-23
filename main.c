#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "menu.h"

#include "Autos.h"

int main()
{
    setlocale(LC_ALL, "") ;
    menu();
    return 0;
}
