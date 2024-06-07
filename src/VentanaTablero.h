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
    bool ventana_coronado = false;
    bool ventana_turno;
    bool ventana_jaque = false;
    bool stand_by=false;
    ETSIDI::Sprite turno=("bin/imagenes/JueganBlancas.png");
    
    

    CasillaVacia*& get_CasillaVacia(const Coordenadas entrada);
public:
    
    void detecta(GLdouble x, GLdouble y);
    void click();
    void dibuja() ;
    void restart();
   

    void poner_torre();
    void poner_alfil();
    void poner_reina();
    void poner_caballo();
    void eliminar_jaque();
    void restart_v2();
    VentanaTablero(const GLdouble& Ancho, const GLdouble& Alto, std::string Path, Juego juego);
};

