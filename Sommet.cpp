//
// Created by Houlessodji Kokouvi on 11/03/2022.
//

#include "Sommet.h"
#include<iostream>
#include<cmath>



Sommet::Sommet() : Sommet {0}
{}

Sommet::Sommet(int numero) : Sommet {0.0,0.0, numero}
{}

Sommet::Sommet(double x, double y, int numero) : d_x{x}, d_y{y}, d_numero{numero}
{}

Sommet Sommet::cartesian(double x, double y)
{
    return {x,y, 0};
}

Sommet Sommet::polar(double rho, double theta)
{
    return {rho*std::cos(theta),rho*std::sin(theta), 0};
}

double Sommet::x() const
{
    return d_x;
}

double Sommet::y() const
{
    return d_y;
}

double Sommet::getnumero() const
{
    return d_numero;
}
void Sommet::setNumero(int numero)
{
    d_numero = numero;
}
double Sommet::distance(const Sommet& p) const
{
    double dx = p.d_x-d_x, dy = p.d_y-d_y;
    return std::sqrt(dx*dx + dy*dy);
}

void Sommet::moveTo(double x, double y)
{
    d_x = x;
    d_y = y;
}

void Sommet::move(double dx, double dy)
{
    d_x += dx;
    d_y += dy;
}

void Sommet::print(std::ostream& ost) const
{
    ost<<'('<<d_x<<','<<d_y<<')';
}

int Sommet::getNumero() const {
    return d_numero;
}



