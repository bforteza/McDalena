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
    bool ventana_coronado;

    
    

    CasillaVacia*& get_CasillaVacia(const Coordenadas entrada);
public:
    int auxiliar=1;
    void detecta(GLdouble x, GLdouble y);
    void click();
    void dibuja() ;
    void restart();
   
    void poner_torre();
    void poner_alfil();
    void poner_reina();
    void poner_caballo();
    VentanaTablero(const GLdouble& Ancho, const GLdouble& Alto, std::string Path, Juego juego);
};

