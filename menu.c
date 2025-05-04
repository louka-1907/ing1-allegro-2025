#include <allegro.h>

#include "Menu.h"

// Positions des boutons
#define BOUTON_JOUER_X 150
#define BOUTON_JOUER_Y 150
#define BOUTON_QUITTER_X 100
#define BOUTON_QUITTER_Y 250
#define LARGEUR_BOUTON 250
#define HAUTEUR_BOUTON 50

int afficher_menu() {
    BITMAP *buffer = create_bitmap(800, 600);
    BITMAP *fond = load_bitmap("fond_menu.bmp", NULL);
    BITMAP *jouer = load_bitmap("jouer.bmp", NULL);
    BITMAP *jouer_selec = load_bitmap("jouer_selec.bmp", NULL);
    BITMAP *quitter = load_bitmap("quitter.bmp", NULL);







    if (!fond || !jouer || !jouer_selec || !quitter || !quitter_selec) {
        allegro_message("Erreur chargement images du menu !");
        return -1;
    }

    int choix = -1;

    while (choix == -1) {
        clear_to_color(buffer, makecol(0, 0, 0));

        // Affichage du fond
        draw_sprite(buffer, fond, 0, 0);

        int mouse_x_pos = mouse_x;
        int mouse_y_pos = mouse_y;

        // Affichage des boutons selon survol souris
        if (mouse_x_pos > BOUTON_JOUER_X && mouse_x_pos < BOUTON_JOUER_X + LARGEUR_BOUTON &&
            mouse_y_pos > BOUTON_JOUER_Y && mouse_y_pos < BOUTON_JOUER_Y + HAUTEUR_BOUTON) {
            draw_sprite(buffer, jouer_selec, BOUTON_JOUER_X, BOUTON_JOUER_Y);
            if (mouse_b & 1) choix = 1; // Clique sur jouer
        } else {
            draw_sprite(buffer, jouer, BOUTON_JOUER_X, BOUTON_JOUER_Y);
        }

        if (mouse_x_pos > BOUTON_QUITTER_X && mouse_x_pos < BOUTON_QUITTER_X + LARGEUR_BOUTON &&
            mouse_y_pos > BOUTON_QUITTER_Y && mouse_y_pos < BOUTON_QUITTER_Y + HAUTEUR_BOUTON) {
            draw_sprite(buffer, quitter_selec, BOUTON_QUITTER_X, BOUTON_QUITTER_Y);
            if (mouse_b & 1) choix = 0; // Clique sur quitter
        } else {
            draw_sprite(buffer, quitter, BOUTON_QUITTER_X, BOUTON_QUITTER_Y);
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        rest(20);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(fond);
    destroy_bitmap(jouer);
    destroy_bitmap(jouer_selec);
    destroy_bitmap(quitter);
    destroy_bitmap(quitter_selec);

    return choix;
}