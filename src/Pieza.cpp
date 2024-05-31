#include "Pieza.h"

Color operator !(Color color) {
	return (color == NEGRO) ? BLANCO : NEGRO;
}