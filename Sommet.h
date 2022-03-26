//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#ifndef PROJETGRAPHEALGO_SOMMET_H
#define PROJETGRAPHEALGO_SOMMET_H
#include<iosfwd>

/**
  class representing a point in the plane
*/
class Sommet {
public:
    ///Default constructor: Sommet (0,0,0)
    Sommet();
    Sommet(int numero);
/**
  Constructor with cartesian coordinates
  @param x x-coordinate
  @param y y-coordinate
  @param numero
*/
    Sommet(double x, double y, int numero);
/**
  pseudo-constructor with cartesian coordinates: static function
  returning a Sommet
  @param x x-coordinate
  @param y y-coordinate
*/
    static Sommet cartesian(double x, double y);
/**
  pseudo-constructor with polar coordinates: static function
  returning a Sommet
  @param rho distance from origin
  @param theta angle from the x-axis
*/
    static Sommet polar(double rho, double theta);

///@return the x-coordinate of the Sommet
    double x()  const;
///@return the y-coordinate of the Sommet
    double y()  const;
///@return the number of the Sommet
    double getnumero()  const;
/**
  Distance between two Sommets
  @param p Sommet to which the distance is computed
  @return the distance between the Sommet and p
*/
    double distance(const Sommet& p) const;
/**
  Change the coordinates of the point
  @param x the new x-coordinate
  @param y the new y-coordinate
*/
    void moveTo(double x, double y);
/**
  Move the point with a translation
  @param dx the deplacement along the x-axis
  @param dx the deplacement along the x-axis
*/
    void move(double dx, double dy);
/**
  Change the number the Sommet
  @param ost the stream on which the point is written
*/
    void setNumero(int numero);
    int getNumero() const;
/**
  Ouput of a point: (x,y)
  @param ost the stream on which the point is written
*/
    void print(std::ostream& ost) const;

private:
///Cartesian coordinates
    double d_x,d_y;
    int d_numero;
};


#endif //PROJETGRAPHEALGO_SOMMET_H
