// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <sstream>
#include <SFML/Audio.hpp>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;
// Function declaration

// Where is the player/branch? 
const int NUM_BRANCHES = 6;
// Left or Right
enum class side { LEFT, RIGHT, NONE };              //define una enumeración llamada side i contiene los valores de left, right, i none
//Constantes encima del main para el tiempo 
const int MaxWidth= 1920;							 //ancho maximo en pixeles 
const int MaxHeight= 1080;							 //altura maxima en pixeles
const int PosTimeBar = 980;                          //posicion especifica del timebar

struct murcielago {
	bool active;					//Indica si el murcielago esta activo o no
	Sprite sprite;				    //Representa la imagen e objeto grafico
	int speed;					    //almacena la velocidad del murcielago
};

int main()
{
	Sprite branches[NUM_BRANCHES];                       //se declra un arreglo llamado branches que contiene objetos de la clase NUM_BRANCHES
	side branchPositions[NUM_BRANCHES];                 //Indica el tamaño del arreglo de NUM_BRANCHES con el elemento side

	//Strings
	int score = 0;                                      //Creamis un score que empieze por 0 

	// Create a video mode object
	VideoMode vm(1920, 1080);                           //Crea un objeto de clase y lo inicia con los valores de 1920x1080, que son la altura y la anchura de pixeles de la configuracion de modo de video 

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!");                //Renderizame un pantalla que diga timber 
	window.setFramerateLimit(60);                         //Le configuramos el limite de frames 

	// Create a texture to hold a graphic on the GPU
	Texture texturebackground2;                            //Creamos las texturas del fondo

	// Load a graphic into the texture
	texturebackground2.loadFromFile("graphics/background2.jpg");      //aqui utilizamos la textura de background2 para poder intrducirle un archivo de imagen y que el fondo tenga una imagen

	// Create a sprite
	Sprite spritebackground2;                                     //Creamos el sprite del fondo de pantalla 

	// Attach the texture to the sprite
	spritebackground2.setTexture(texturebackground2);

	// Set the spriteBackground to cover the screen
	spritebackground2.setPosition(0, 0);

	// Make a tree sprite                                               //Empezamos a crear el primer arbol 
	Texture textureTree;                                             //Creamos la textura de arbol
	textureTree.loadFromFile("graphics/tree.png");                   //cargamos la textura de arbol y cojemos el archivo de la carpetq graphics llamado tree
	Sprite spriteTree;                                               //Asi se podra cargar el sprite de arbol
	spriteTree.setTexture(textureTree);                             //
	spriteTree.setPosition(810, 0);
	spriteTree.setColor(Color::Magenta);

	// Make a second tree 
	Texture texturetree4;
	texturetree4.loadFromFile("graphics/tree4.png");
	Sprite spritetree4;
	spritetree4.setTexture(texturetree4);
	spritetree4.setPosition(-60, 240);
	spritetree4.setScale(1.0, 1.0);

	// Prepare the bee
	Texture texturecasper;
	texturecasper.loadFromFile("graphics/casper.png");
	Sprite spritecasper;
	spritecasper.setTexture(texturecasper);
	spritecasper.setPosition(0, 0);
	spritecasper.setScale(0.15, 0.15);

	// Is the bee currently moving?
	bool casperActive = false;

	// How fast can the bee fly
	float casperSpeed = 0.0f;

	// make 3 cloud sprites from 1 texture
	Texture texturemurcielago;

	// Load 1 new texture
	texturemurcielago.loadFromFile("graphics/murcielago.png");

	// Variables to control time itself
	Clock clock;

	// Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

	// Track whether the game is running
	bool paused = true;
	// Draw some text
	Text messageText;
	Text scoreText;

	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	// Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);
	// Assign the actual message
	messageText.setString("Press Enter!");
	scoreText.setString("Score = 0");
	// Make it really big
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	// Choose a color
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
	scoreText.setPosition(20, 20);
	RectangleShape rectanglescore(Vector2f(580, 120));
	rectanglescore.setFillColor(Color(25, 25, 25, 150));
	rectanglescore.setPosition(10, 20);


	// Prepare 5 branches
	// Set the texture for each branch sprite
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch2.jpg");

	for (int i = 0; i < NUM_BRANCHES; i++) {
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);
		branches[i].setOrigin(220, 20);
		branches[i].setScale(0.30, 0.30);
	}
	// Prepare the player
	Texture textureplayer;
	textureplayer.loadFromFile("graphics/fantasma2.png");
	Sprite spriteplayer;
	spriteplayer.setTexture(textureplayer);
	spriteplayer.setPosition(550, 600);
	spriteplayer.setScale(0.50, 0.50);

	// The player starts on the left
	side playerSide = side::LEFT;
	branchPositions[3] = side::NONE;

	// Prepare the gravestone
	Texture texturerip;
	texturerip.loadFromFile("graphics/rip.png");
	Sprite spriterip;
	spriterip.setTexture(texturerip);
	spriterip.setPosition(600, 850);

	// Prepare the axe
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/guadaña3.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(600, 600);
	spriteAxe.setScale(0.25, 0.25);

	// Line the axe up with the tree
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITIONRIGHT = 1075;
	// Prepare the flying log
	Texture texturelog;
	texturelog.loadFromFile("graphics/log.png");
	Sprite spritelog;
	spritelog.setTexture(texturelog);
	spritelog.setPosition(810, 810);
	spritelog.setColor(Color::Magenta);

	// Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;
	// Control the player input
	bool acceptInput = false;
	// Prepare the sound
	// The player chopping sound
	SoundBuffer chopBuffer;
	chopBuffer.loadFromFile("sound/chop.wav");
	Sound chop;
	chop.setBuffer(chopBuffer);
	// The player has met his end under a branch
	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);
	// Out of time
	SoundBuffer ootBuffer;
	ootBuffer.loadFromFile("sound/out_of_time.wav");
	Sound outOfTime;
	outOfTime.setBuffer(ootBuffer);

	//Cloud data 
	struct murcielago {
		bool active;
		Sprite sprite;
		int speed;
	};
	//Cloud data array

	// Manage the clouds
	const int nummurcielago = 5;
	const int distance = 150;
	murcielago spritemurcielago[nummurcielago];

	for (int i = 0; i < nummurcielago; ++i) {
		spritemurcielago[i].active = false;
		spritemurcielago[i].sprite.setTexture(texturemurcielago);
		spritemurcielago[i].sprite.setPosition(0, 0 * distance);
		spritemurcielago[i].speed = 0.0f;
		spritemurcielago[i].sprite.setScale(0.15, 0.15);

	}

	//game loop
	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				paused = false;
				//Reset the time and the score 
				score = 0;
				timeRemaining = 6;
				
				for (int i = 1; i < NUM_BRANCHES; i++)
				{
					branchPositions[i] = side::NONE;
				}
				spriterip.setPosition(675, 2000);
				spriteplayer.setPosition(580, 720);
				acceptInput = true;


			}
				if (event.type == Event::KeyReleased && !paused)
				{
				// Listen for key presses again
				acceptInput = true;
				// hide the axe
				spriteAxe.setPosition(2000,
				spriteAxe.getPosition().y);
				}
				
				if (Keyboard::isKeyPressed(Keyboard::Escape))
					{
					window.close();
					}
		}
		////Make sure the gravestone is hidden
		//spriterip.setPosition(675, 2000);
		////Move the player into position
		//spriteplayer.setPosition(580, 720);
		// Wrap the player controls to
		// Make sure we are accepting input
		if (acceptInput)
		{
			// First handle pressing the right cursor key
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				// Make sure the player is on the right
				playerSide = side::RIGHT;
				score++;
				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;
				spriteAxe.setPosition(AXE_POSITIONRIGHT, spriteAxe.getPosition().y);
				spriteplayer.setPosition(1200, 720);
				// update the branches
				for (int j = NUM_BRANCHES - 1; j > 0; j--) {
					branchPositions[j] = branchPositions[j - 1];
					//spawn a new branch at position 0
					//LEFT, RIGHT or NONE
				}
				int r = (rand() % 5);
				switch (r) {
				case 0:
					branchPositions[0] = side::LEFT;
					break;
				case 1:
					branchPositions[0] = side::RIGHT;
					break;
				default:
					branchPositions[0] = side::NONE;
					break;
				}
					// set the log flying to the left
					spritelog.setPosition(810, 700);
					logSpeedX = -5000;
					logActive = true;
					acceptInput = false;
					chop.play();
				
			}
				// Handle the left cursor key
				if (Keyboard::isKeyPressed(Keyboard::Left))
				{
					// Make sure the player is on the left
					playerSide = side::LEFT;
					score++;
					// Add to the amount of time remaining
					timeRemaining += (2 / score) + .15;

					spriteAxe.setPosition(AXE_POSITION_LEFT,
						spriteAxe.getPosition().y);

					spriteplayer.setPosition(580, 720);
					// update the branches
					for (int j = NUM_BRANCHES - 1; j > 0; j--) {
						branchPositions[j] = branchPositions[j - 1];
					}
					int r = (rand() % 5);
					switch (r) {
					case 0:
						branchPositions[0] = side::LEFT;
						break;
					case 1:
						branchPositions[0] = side::RIGHT;
						break;
					default:
						branchPositions[0] = side::NONE;
						break;
					}

						// set the log flyin}
					spritelog.setPosition(810, 720);
					logSpeedX = 5000;
					logSpeedY = true;
					acceptInput = false;

					// Play a chop sound
					chop.play();
				}
		}
				/*
				****************************************
				Update the scene
				****************************************
				*/

				if (!paused)
				{

					// Measure time
					Time dt = clock.restart();

					// Subtract from the amount of time remaining
					timeRemaining -= dt.asSeconds();
					// size up the time bar
					timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));
					// Pause the game
					if (timeRemaining <= 0.0f) {
						paused = true;
						// Change the message shown to the player
						messageText.setString("Out of time!!");
						//Reposition the text based on its new size
						FloatRect textRect = messageText.getLocalBounds();
						messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
						messageText.setPosition(MaxWidth / 2.0f, MaxHeight / 2.0f);
						// Play the out of time sound
					}
					// Setup the bee
					if (!casperActive)
					{
						//How fast is the bee
						srand((int)time(0));
						casperSpeed = (rand() % 200) + 100;

						//How high is the bee
						srand((int)time(0) * 10);
						float height = (rand() % 500) + 500;
						spritecasper.setPosition(2000, height);

						casperActive = true;
					}
					else
						// Move the bee
					{
						spritecasper.setPosition(
							spritecasper.getPosition().x -
							(casperSpeed * dt.asSeconds()),
							spritecasper.getPosition().y);
					}
					// Has the bee reached the right hand edge of the screen?
					if (spritecasper.getPosition().x < -100)
					{

						// Set it up ready to be a whole new cloud next frame
						casperActive = false;
					}


					for (int i = 0; i < nummurcielago; ++i) {
						if (!spritemurcielago[i].active) {
							spritemurcielago[i].speed = rand() % 200;
							float height = rand() % (distance * (i + 1));
							spritemurcielago[i].sprite.setPosition(-200, height);
							spritemurcielago[i].active = true;

						}
						else {
							spritemurcielago[i].sprite.setPosition(spritemurcielago[i].sprite.getPosition().x + (spritemurcielago[i].speed * dt.asSeconds()), spritemurcielago[i].sprite.getPosition().y);
							if (spritemurcielago[i].sprite.getPosition().x > MaxWidth) {
								spritemurcielago[i].active = false;
							}
						}
					}

					// Update the score text
					stringstream ss;
					ss << "Score = " << score;
					scoreText.setString(ss.str());
					// update the branch sprites

					for (int i = 0; i < NUM_BRANCHES; i++)
					{
						float height = i * 150;
						if (branchPositions[i] == side::LEFT)
						{
							//Move the sprite to the left side 
							branches[i].setPosition(800, height);
							//Flip the sprite round the other way 
							branches[i].setRotation(180);
						}
						else if (branchPositions[i] == side::RIGHT)
						{
							//Move the sprite to the right side 
							branches[i].setPosition(1100, height);
							//Set the sprite rotation to normal
							branches[i].setRotation(0);
						}
						else
						{
							//Hide the branch
							branches[i].setPosition(3000, height);

						}
					}

					// Handle a flying log
					if (logActive)
					{
						spritelog.setPosition(
							spritelog.getPosition().x +
							(logSpeedX * dt.asSeconds()),
							spritelog.getPosition().y +
							(logSpeedY * dt.asSeconds())
						);
								
						  // Has the log reached the right hand edge?
						if (spritelog.getPosition().x < -100 ||
							spritelog.getPosition().x > 2000)
						{
							// Set it up ready to be a whole new log next frame
							logActive = false;
							spritelog.setPosition(810, 720);
						}
					}

					// Has the player been squished by a branch?
					if (branchPositions[5] == playerSide)
					{
						// Death
						paused = true;
						acceptInput = false;

						// Draw the gravestone
						spriterip.setPosition(525, 760);

						// Hide the player
						spriteplayer.setPosition(2000, 660);

						// Change the text of the message
						messageText.setString("YOU DIED, UNLUCKY!!");
						spriterip.setPosition(580, 720);
			
						// Center it on the screen
						FloatRect textRect = messageText.getLocalBounds();

						messageText.setOrigin(textRect.left +
							textRect.width / 2.0f,
							textRect.top + textRect.height / 2.0f);

						messageText.setPosition(1920 / 2.0f,
							1080 / 2.0f);

						// Play the death sound
						death.play();
					}
			// has the player been squished by a branch?

				}// End if(!paused)

				 /*
				 ****************************************
				 Draw the scene
				 ****************************************
				 */

				 // Clear everything from the last frame
				window.clear();

				// Draw our game scene here
				window.draw(spritebackground2);
				//score magenta
				window.draw(rectanglescore);
				// Draw the clouds
				for (int i = 0; i < nummurcielago; ++i) {
					window.draw(spritemurcielago[i].sprite);
				}
				// Draw the branches
				for (int i = 0; i < NUM_BRANCHES; i++) {
					window.draw(branches[i]);
				}
				// Draw the tree
				window.draw(spriteTree);
				//Draw th second tree
				window.draw(spritetree4);
				//Draw the insect
				window.draw(spritecasper);
				// Draw the player
				window.draw(spriteplayer);
				// Draw the axe
				window.draw(spriteAxe);
				// Draraw the flying log
				window.draw(spritelog);
				// Draw the gravestone
				window.draw(spriterip);
				// Draw the score
				window.draw(scoreText);
				if (paused)
				{
					window.draw(messageText);
				}
				// Draw the timebar
				window.draw(timeBar);
			
				// Show everything we just drew
				window.display();

			
	
	
	}
	return 0;
}
