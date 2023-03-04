//
// Created by mazen on 17/02/2023.
//

#ifndef UNTITLED2_LABYRINTHE3D_H
#define UNTITLED2_LABYRINTHE3D_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "objet.h"
#include "Joueur.h"


class Labyrinthe3D {
private:
    Joueur m_joueur;
    int m_largeur;
    int m_hauteur;
    int m_profondeur;
    std::vector<std::vector<std::vector<char>>> m_cases;
    std::vector<Objet> m_objets;
public:
    Labyrinthe3D(int largeur, int hauteur, int profondeur, Joueur mJoueur);
    void genererLabyrinthe(int densite);
    void ajouterObjet(int x, int y, int z, int points);
    void supprimerObjet(int x, int y, int z);
    bool estCaseVide(int x, int y, int z) const;
    bool estDansLabyrinthe(int x, int y, int z) const;
    std::vector<std::vector<std::vector<char>>> getCases() const;
    std::vector<Objet> getObjets() const;
    bool isobjectThere(int x,int y,int z);
    int getLargeur() const;
    int getHauteur() const;
    int getProfondeur() const;
    void gererEvenements(std::string *action,Joueur *joueur, bool *stop);
    void detecterCollisions(Joueur &j);
    void collecterObjet(Joueur &j);
};


#endif //UNTITLED2_LABYRINTHE3D_H
