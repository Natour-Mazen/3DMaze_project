//
// Created by mazen on 17/02/2023.
//

#include "Objet.h"


Objet::Objet(int x, int y, int z, int points) : m_x(x), m_y(y), m_z(z), m_points(points) {}

int Objet::getX() const {
    return m_x;
}

int Objet::getY() const {
    return m_y;
}

int Objet::getZ() const {
    return m_z;
}

int Objet::getPoints() const {
    return m_points;
}

void Objet::setX(int x) {
    m_x = x;
}

void Objet::setY(int y) {
    m_y = y;
}

void Objet::setZ(int z) {
    m_z = z;
}