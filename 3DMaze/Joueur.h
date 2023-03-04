//
// Created by mazen on 17/02/2023.
//

#ifndef UNTITLED2_JOUEUR_H
#define UNTITLED2_JOUEUR_H


#include "Objet.h"

class Joueur {
public:
    Joueur(int x, int y, int z);
    void deplacerHaut();
    void deplacerBas();
    void deplacerGauche();
    void deplacerDroite();
    int getX() const;
    int getY() const;
    int getZ() const;
    void setX(int x) ;
    void setY(int y) ;
    void setZ(int z);
    int m_score; // à pas faire en temps normal , normalement ajouter des getters et setters mais là seulement pour aller plus vite
private:
    int m_x;
    int m_y;
    int m_z;

};

#endif //UNTITLED2_JOUEUR_H
