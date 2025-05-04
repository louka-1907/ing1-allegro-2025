#include <allegro.h>

#include "initialisation_allegro.h"

void initialisation_allegro() {
    allegro_init(); // appel obligatoire (var.globales, recup. infos syst�me ...)
    install_keyboard(); //pour utiliser le clavier
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    set_color_depth(32);

    //sélection du mode graphique
    // avec choix d'un driver+mode+résolution de l'écran
    /// si échec, le programme s'arrête
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_mouse(); //pour utiliser la souris
    show_mouse(screen);
}
