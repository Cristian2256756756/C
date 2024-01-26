#include "Funciones.h"


int main()
{
//Variables
// Finestra
    Vector2f viewSize(x_max, y_max);
    VideoMode vm(viewSize.x, viewSize.y);
    RenderWindow window(vm, title, Style::Default);
// Fondo
    Texture background1;
    background1.loadFromFile("graphics/background3.jpg");
    Sprite spritebackground1;
    spritebackground1.setTexture(background1);
 // Pilota
    Texture Bola;
    Bola.loadFromFile("graphics/Bola2.png");
    Sprite BolaSprite;
    BolaSprite.setScale(0.3, 0.3);
// Barra del jugador
    RectangleShape barra;
    FloatRect barraRRect;
// Sprite barra del jugador
    Texture playerTexture;
    playerTexture.loadFromFile("graphics/player.png");
    Sprite playerSprite(playerTexture);
//brick
    Texture brickTexture;
    brickTexture.loadFromFile("graphics/neon.png");
    Sprite brickSprite[10];

    barraRRect = barra.getLocalBounds();
    barra.setOrigin(barraRRect.left + barraRRect.width / 2.0f, barraRRect.top + barraRRect.height / 2.0f);
    IniciMon(window, spritebackground1, BolaSprite, barra, brickSprite, Bola, playerTexture, brickTexture, playerSprite, viewSize);



    // Velocidad inicial de la pilota
    float ballSpeedX, ballSpeedY;
    ballSpeedY = ballSpeedBase * 1;
    ballSpeedX = ballSpeedBase * 1.7;

        //para hacer una segunfa fila, le pomgo un 2 al lado del 10 del sprite y le añado un j despues de las i
    Clock clock;

    while (window.isOpen()) {
        Time dt = clock.restart();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
            // Mover hacia la izquierda
            playerSprite.move(-playerSpeed * dt.asSeconds(), 0);
        }

        if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
            // Mover hacia la derecha
            playerSprite.move(playerSpeed * dt.asSeconds(), 0);
        }

        // Movimiento de la bola
        BolaSprite.move(ballSpeedX * dt.asSeconds(), ballSpeedY * dt.asSeconds());

        // Verificar colisiones
        if (checkCollision(playerSprite, BolaSprite, brickSprite, numeroladrillos)) {
            cout << "Colisión detectada!" << endl;
            // Manejar la colisión, por ejemplo, invertir la velocidad en la dirección Y
            ballSpeedY = -ballSpeedY;
        }

        // Verificar y corregir rebotes en el borde de la ventana
        if (BolaSprite.getPosition().x < x_min || BolaSprite.getPosition().x > x_max) {
            ballSpeedX = -ballSpeedX;  // Invertir la velocidad en dirección X
        }

        if (BolaSprite.getPosition().y < y_min || BolaSprite.getPosition().y > y_max) {
            ballSpeedY = -ballSpeedY;  // Invertir la velocidad en la dirección Y
        }


        // Dibujar el juego
        Draw(window, BolaSprite, playerSprite, barra, brickSprite, spritebackground1);
    }

    return 0;
}


