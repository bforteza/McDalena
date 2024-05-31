#pragma once
class Coordenadas {
public:
	int col, fil;

	Coordenadas(int _col, int _fil) {
		if (_col >= 1 && _fil >= 1) {
			col = _col;
			fil = _fil;
		}
	}
};
