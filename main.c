#include <stdio.h>
#include <allegro.h>

#include "initialisation_allegro.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    initialisation_allegro();

    afficher_menu();

    allegro_exit();
    return 0;
}END_OF_MAIN();