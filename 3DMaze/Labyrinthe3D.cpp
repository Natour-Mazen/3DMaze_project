//
// Created by mazen on 17/02/2023.
//

#include <iostream>
#include "Labyrinthe3D.h"


Labyrinthe3D::Labyrinthe3D(int largeur, int hauteur, int profondeur, Joueur mJoueur)
        : m_largeur(largeur), m_hauteur(hauteur), m_profondeur(profondeur), m_joueur(mJoueur) {
    // Initialiser la grille de cases vides
    m_cases.resize(m_largeur);
    for (int i = 0; i < m_largeur; ++i) {
        m_cases[i].resize(m_hauteur);
        for (int j = 0; j < m_hauteur; ++j) {
            m_cases[i][j].resize(m_profondeur, ' ');
        }
    }
}

void Labyrinthe3D::genererLabyrinthe(int densite) {
    // Générer un labyrinthe aléatoire avec une certaine densité de murs
    std::srand(std::time(nullptr));
    for (int i = 0; i < m_largeur; ++i) {
        for (int j = 0; j < m_hauteur; ++j) {
            for (int k = 0; k < m_profondeur; ++k) {
                if (std::rand() % 80 < densite) {
                    m_cases[i][j][k] = '#';
                }
            }
        }
    }
}

void Labyrinthe3D::ajouterObjet(int x, int y, int z, int points) {
// Ajout d'un objet aux coordonnées x, y, z avec un certain nombre de points
    m_objets.push_back(Objet(x, y, z, points));
}

void Labyrinthe3D::supprimerObjet(int x, int y, int z) {
// Suppression de l'objet situé aux coordonnées x, y, z
    for (int i = 0; i < m_objets.size(); i++) {
        Objet objet = m_objets[i];
        if (objet.getX() == x && objet.getY() == y && objet.getZ() == z) {
            m_objets.erase(m_objets.begin() + i);
            return;
        }
    }
}

bool Labyrinthe3D::estCaseVide(int x, int y, int z) const {
// Vérification si la case aux coordonnées x, y, z est vide (contient un espace)
    return m_cases[x][y][z] == ' ';
}

bool Labyrinthe3D::estDansLabyrinthe(int x, int y, int z) const {
// Vérification si les coordonnées x, y, z sont à l'intérieur du labyrinthe pour debug seuleument
    return (x >= 0 && x < m_largeur && y >= 0 && y < m_hauteur && z >= 0 && z < m_profondeur);
}

std::vector<std::vector<std::vector<char>>> Labyrinthe3D::getCases() const {
// Récupération de toutes les cases du labyrinthe
    return m_cases;
}

std::vector<Objet> Labyrinthe3D::getObjets() const {
// Récupération de tous les objets dans le labyrinthe
    return m_objets;
}

bool Labyrinthe3D::isobjectThere(int x,int y,int z){
    // on verifie si y a un objet à un endroit donner
    for (Objet objet : this->getObjets()) {
        if (objet.getX() == x &&
            objet.getY() == y &&
            objet.getZ() == z )
        {
            return true;
        }
    }
    return false;
}

int Labyrinthe3D::getLargeur() const {
// Récupération de la largeur du labyrinthe
    return m_largeur;
}

int Labyrinthe3D::getHauteur() const {
// Récupération de la hauteur du labyrinthe
    return m_hauteur;
}

int Labyrinthe3D::getProfondeur() const{
 // Récupération de la Profondeur du labyrinthe
    return m_profondeur;
}

void Labyrinthe3D::gererEvenements(std::string *action,Joueur *joueur, bool *stop) {
    // Vérifier si le joueur est sur une case contenant un objet
    for (Objet& objet : m_objets) {
        if (objet.getX() == m_joueur.getX() &&
            objet.getY() == m_joueur.getY() &&
            objet.getZ() == m_joueur.getZ())
        {
            this->collecterObjet(m_joueur);
            supprimerObjet(objet.getX(), objet.getY(), objet.getZ());
            break;
        }
    }

    if (*action == "haut") {
        joueur->deplacerHaut();
    } else if (*action == "bas") {
        joueur->deplacerBas();
    } else if (*action == "gauche") {
        joueur->deplacerGauche();
    } else if (*action == "droite") {
        joueur->deplacerDroite();
    } else if (*action == "monte") {
        joueur->monteNiveau();
    } else if (*action == "descend") {
        joueur->descendreNiveau();
    } else if (*action == "quitter") {
       *stop = true;
    }

    // Vérifier si le joueur est sur une case non-vide (collision)
    if (!estCaseVide(m_joueur.getX(), m_joueur.getY(), m_joueur.getZ())) {
        this->detecterCollisions(m_joueur);
    }


}

void Labyrinthe3D::detecterCollisions(Joueur &j) {
    if (!this->estCaseVide(j.getX(),j.getY() ,j.getZ())) {
        // Le joueur a heurté un mur
        // Déplacer le joueur dans la direction opposée à la collision
        if (this->estCaseVide(j.getX() + 1, j.getY() , j.getZ())) {

            j.setX(j.getX()+1);
        } else if (this->estCaseVide(j.getX() - 1, j.getY() , j.getZ())) {
            j.setX(j.getX()-1);
        } else if (this->estCaseVide(j.getX(), j.getY()  + 1, j.getZ())) {
            j.setY(j.getY()+1);
        } else if (this->estCaseVide(j.getX(), j.getY()  - 1, j.getZ())) {
            j.setY(j.getY()-1);
        } else if (this->estCaseVide(j.getX(), j.getY() , j.getZ() + 1)) {
            j.setZ(j.getZ()+1);
        } else if (this->estCaseVide(j.getX(), j.getY() , j.getZ() - 1)) {
            j.setZ(j.getZ()-1);
        }
    }
}

void Labyrinthe3D::collecterObjet(Joueur &j) {
    for (int i = 0; i < this->m_objets.size(); i++) {
        Objet objet = this->m_objets[i];
        if (j.getX() == objet.getX() && j.getY() == objet.getY() && j.getZ() == objet.getZ()) {
            j.m_score += objet.getPoints();
            this->supprimerObjet(j.getX(), j.getY(),  j.getZ());
        }
    }
}