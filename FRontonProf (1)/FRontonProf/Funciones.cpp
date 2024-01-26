#include "Funciones.h"

/// <summary>
/// Funcion para dibujar todo 
/// </summary>
/// <param name="finestre"></param>
/// <param name="BolaSprite"></param>
/// <param name="playerSprite"></param>
/// <param name="barra"></param>
/// <param name="brickSprite"></param>
/// <param name="fondo"></param>
void Draw(RenderWindow& finestre, Sprite& BolaSprite, Sprite& playerSprite, RectangleShape& barra, Sprite* brickSprite, Sprite& fondo) {
    finestre.clear(); // No es necesario especificar un color al borrar

    // Dibujar el fondo primero
    finestre.draw(fondo);

    // Luego, dibujar la bola y el jugador
    finestre.draw(BolaSprite);
    finestre.draw(playerSprite);

    for (int i = 0; i < numeroladrillos; ++i) {                         //Para los mrucielagoss, como son son creados aleatoriamente, nos hara falta crear un bucle que cuando la i sea mas grande que nummurcielago vaya sumando de uno en uno ñ
        finestre.draw(brickSprite[i]);
    }
    finestre.display();
}


/// <summary>
/// Función para verificar colisión entre dos objetos
/// </summary>
/// <param name="playerSprite">Sprite de la barra que podemos </param>
/// <param name="BolaSprite"></param>
/// <param name="brickSprite"></param>
/// <param name="numBricks"></param>
/// <returns></returns>
bool checkCollision(Sprite& playerSprite, Sprite& BolaSprite, Sprite* brickSprite, int numBricks) {
    // Verificar colisión con la barra
    if (playerSprite.getGlobalBounds().intersects(BolaSprite.getGlobalBounds())) {
        return true;
    }

    // Verificar colisión con los ladrillos
    for (int i = 0; i < numBricks; ++i) {
        if (BolaSprite.getGlobalBounds().intersects(brickSprite[i].getGlobalBounds())) {
            // Manejar la colisión con el ladrillo (por ejemplo, destruir el ladrillo)
            // Aquí puedes poner la lógica que quieras para manejar la colisión con los ladrillos.
            // Por ejemplo
            brickSprite[i].setScale(0.0, 0.0);
            return true;
        }
    }
    return false;
}

/// <summary>
/// Funcion para poder iniciar el mundo 
/// </summary>
/// <param name="finestra"></param>
/// <param name=""></param>
void IniciMon(RenderWindow& finestra, Sprite& spritebackground1, Sprite& BolaSprite, RectangleShape& barra, Sprite* brickSprite, Texture& Bola, Texture& playerTexture, Texture& brickTexture, Sprite& playerSprite, Vector2f viewSize)
{
    finestra.setFramerateLimit(60);
    spritebackground1.setPosition(0, 0);

    BolaSprite.setScale(0.3, 0.3);
    BolaSprite.setTexture(Bola);
    BolaSprite.setOrigin(BolaSprite.getLocalBounds().width / 2.0f, BolaSprite.getLocalBounds().height / 2.0f);
    BolaSprite.setPosition(viewSize.x / 2, viewSize.y / 2);
    barra.setSize(Vector2f(longitut, amplada));
    barra.setScale(0.2, 0.2);
    barra.setPosition(viewSize.x / 5, viewSize.y - 50);
    playerSprite.setScale(0.5, 0.5);
    playerSprite.setPosition(viewSize.x / 3, viewSize.y - 300);

    for (int i = 0; i < numeroladrillos; ++i) {                         //Para los mrucielagoss, como son son creados aleatoriamente, nos hara falta crear un bucle que cuando la i sea mas grande que nummurcielago vaya sumando de uno en uno ñ

        brickSprite[i].setTexture(brickTexture);
        brickSprite[i].setOrigin(brickSprite[i].getPosition().x, brickSprite[i].getPosition().y);
        brickSprite[i].setPosition(distanciaEntreLadrillos * i, viewSize.y / 40);
        brickSprite[i].setScale(1.1, 1.1);
    }
}

