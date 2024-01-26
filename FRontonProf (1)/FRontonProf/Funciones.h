#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;


// Constantes globales
const string title = "Fronton";
const float ballSpeedBase = 300.0f;
const float playerSpeed = 500.0f;
const int x_min = 0, x_max = 1920;
const int y_min = 0, y_max = 1080;
const int incre_xr = 10, incre_yr = 10;
const int longitut = 100, amplada = 20, radi = 25;


//brick

const float distanciaEntreLadrillos = 230.0f;
const float alturaLadrillos = 50.0f;
const float numeroladrillos = 10;


// Prototipos
void Draw(RenderWindow& finestre, Sprite& BolaSprite, Sprite& playerSprite, RectangleShape& barra, Sprite* brickSprite, Sprite& fondo);
bool checkCollision(Sprite& playerSprite, Sprite& BolaSprite, Sprite* brickSprite, int numBricks);
void IniciMon(RenderWindow& finestra, Sprite& spritebackground1, Sprite& BolaSprite, RectangleShape& barra, Sprite* brickSprite, Texture& Bola, Texture& playerTexture, Texture& brickTexture, Sprite& playerSprite, Vector2f viewSize);
