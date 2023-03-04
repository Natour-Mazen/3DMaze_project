//
// Created by mazen on 17/02/2023.
//

#include "Joueur.h"

Joueur::Joueur(int x, int y, int z) {
    // Initialisation de la position et du score du joueur
    m_x = x;
    m_y = y;
    m_z = z;
}
void Joueur::deplacerHaut() {
    m_y++;
}

void Joueur::deplacerBas() {
    m_y--;
}

void Joueur::deplacerGauche() {
    m_x--;
}

void Joueur::deplacerDroite() {
    m_x++;
}
void Joueur::monteNiveau() {
    m_z++;
}
void Joueur::descendreNiveau() {
    m_z--;
}

int  Joueur::getX() const{
    return m_x;
};

int  Joueur::getY() const{
    return m_y;
};
int  Joueur::getZ() const{
    return m_z;
};

void  Joueur::setX(int x) {
    m_x = x;
};

void  Joueur::setY(int y) {
    m_y = y;
};
void  Joueur::setZ(int z) {
    m_z=z;
};

