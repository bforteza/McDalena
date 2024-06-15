#pragma once
#include "Ventana.h"
#include "Tablero.h"
#include "Partida.h"

class VentanaTablero :
    public Ventana
{
private:
    Tablero tablero;
    Partida partida;
    GLdouble origenx, origeny;
    GLdouble finalx, finaly;
    GLdouble lado;
    std::vector< CasillaVacia* > base;
    bool ventana_coronado = false;
    bool ventana_jaque = false;
    
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

    void savear();

    void loadear();
    
    VentanaTablero(const GLdouble& Ancho, const GLdouble& Alto, std::string Path, Juego juego);
};

