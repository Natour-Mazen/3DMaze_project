//
// Created by mazen on 17/02/2023.
//

#ifndef UNTITLED2_OBJET_H
#define UNTITLED2_OBJET_H

class Objet {
private:
    int m_x;
    int m_y;
    int m_z;
    int m_points;
public:
    Objet(int x, int y, int z,int points);
    int getX() const;
    int getY() const;
    int getZ() const;
    int getPoints() const;
    void setX(int x);
    void setY(int y);
    void setZ(int z);
};

#endif //UNTITLED2_OBJET_H
