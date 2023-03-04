#include <iostream>
#include "Labyrinthe3D.h"

int main() {

    // un bool pour arreter le jeu
    bool stop = false;

    // Créer un joueur au milieu du labyrinthe
    Joueur joueur(0, 0, 0);

    // Créer un labyrinthe de 3x3x3 cases et le générer aléatoirement
    Labyrinthe3D labyrinthe(3, 3,3, joueur);
    labyrinthe.genererLabyrinthe(50); // densité de murs

    // Ajouter quelques objets dans le labyrinthe
    labyrinthe.ajouterObjet(2, 2, 2, 10);
    labyrinthe.ajouterObjet(1, 2, 3, 20);
    labyrinthe.ajouterObjet(3, 2, 2, 5);

    // Boucle principale du jeu
    while (!stop) {
        // Afficher le labyrinthe
        auto cases = labyrinthe.getCases();
        for (int z = 0; z < labyrinthe.getProfondeur(); z++) {
            for (int y = 0; y < labyrinthe.getHauteur(); y++) {
                for (int x = 0; x < labyrinthe.getLargeur(); x++) {
                    if (x == joueur.getX() && y == joueur.getY() && z == joueur.getZ()) {
                        std::cout << "X";
                    }else if ( labyrinthe.isobjectThere (x,y,z)){
                        std::cout << "!";
                    }
                    else{
                        std::cout << cases[x][y][z];
                    }
                }
                std::cout << std::endl;
            }
            std::cout <<" --------------------------------------------------"<<std::endl;
        }
        std::cout << "Player position: (X: " << joueur.getX() << ",Y: " << joueur.getY() << ",Z: " << joueur.getZ() << ")"<<std::endl;


        // Gérer les événements (déplacements du joueur)
        std::string action;
        std::cout << "Que voulez-vous faire ? (haut/bas/gauche/droite/monte/descend/quitter) ";
        std::cin >> action;

        labyrinthe.gererEvenements(&action,&joueur,&stop);

        // Vérifier si le joueur a gagné (collecté tous les objets)
        if (labyrinthe.getObjets().empty()) {
            std::cout << "Bravo, vous avez collecté tous les objets !" << std::endl;
            stop = true;
        }

        std::cout <<"\n\n" <<std::endl;
    }

    return 0;
}
