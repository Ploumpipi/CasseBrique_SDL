#pragma once
#include <SDL.h>

#define BOARD_WIDTH 18
#define BOARD_HEIGHT 12
#define BOARD_BRWIDTH 64
#define BOARD_BRHEIGHT 24

class Briques {
private :
	int type;
	bool state;

public :
	int getType();
	bool getState();

	void setType(int x);
	void setState(bool verif);

};

class Table {
private :
	float briquesOffSetX, briquesOffSetY;

public :
	Briques brique[BOARD_WIDTH][BOARD_HEIGHT];

	Table(SDL_Renderer* renderer);

	~Table();

	float getBriquesOffSetX();
	float getBriquesOffSetY();

	void setBriquesOffSetX(float x);
	void setBriquesOffSetY(float y);

	void Render();
};