#pragma once
#include "Ventana.h"
#include "Tablero.h"
class VentanaTablero :
    public Ventana
{
private:
    Tablero tablero;
    GLdouble origenx, origeny;
    GLdouble finalx, finaly;
    GLdouble lado;
    std::vector< CasillaVacia* > base;


    
    

    CasillaVacia*& get_CasillaVacia(const Coordenadas entrada);
public:
    void detecta(GLdouble x, GLdouble y);
    void click();
    void dibuja() ;

   
    VentanaTablero(const GLdouble& Ancho, const GLdouble& Alto, std::string Path, Juego juego);
};

