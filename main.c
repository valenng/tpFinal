#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Autos.h"
#include "Clientes.h"
#include "menu.h"

int main()
{
    setlocale(LC_ALL, "") ;
    menu();
    return 0;
}
