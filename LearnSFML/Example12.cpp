#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Bullet
{
public:
	Sprite shape;

	Bullet(Texture* texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);

		this->shape.setScale(0.07f, 0.07f);

		this->shape.setPosition(pos);
	}

	~Bullet() {}
};

class Player
{
public:
	Sprite shape;

	int HP;
	int HPMax;

	vector<Bullet> bullets;

	Player(Texture* texture)
	{
		this->HPMax = 10;
		this->HP = this->HPMax;

		this->shape.setTexture(*texture);

		this->shape.setScale(0.1f, 0.1f);
	}

	~Player()
	{

	}

};

class Enemy
{
public:
	Sprite shape;

	int HP;
	int HPMax;

	Enemy(Texture* texture, Vector2f pos)
	{
		this->HPMax = rand() % 3 + 1;
		this->HP = HPMax;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.1f, 0.1f);
		this->shape.setPosition(pos);
	}

	~Enemy() {}
};

void playerMove(Player& player);
void playerCollision(RenderWindow &window, Player& player);
void enemyBehavior(RenderWindow& window, vector<Enemy> &enemies, Player& player);

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(800, 600), "Spaceship Action", Style::Default);
	window.setFramerateLimit(60);

	//Init text
	Font font;
	font.loadFromFile("Fonts/Dosis-Light.ttf");

	//Init texture
	Texture playerTex;
	playerTex.loadFromFile("Texture/ship.png");

	Texture enemyTex;
	enemyTex.loadFromFile("Texture/enemy.png");

	Texture bulletTex;
	bulletTex.loadFromFile("Texture/missileTex01.png");

	// UI Score init
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::Green);
	scoreText.setPosition(10.f, 10.f);

	// UI GameOver
	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(50);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setString("GAME OVER!");
	gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2, 250.f);

	// Player init
	int score = 0;
	Player player(&playerTex);
	int shootTimer = 0;
	int shootBtwTime = 15;

	// UI for Player
	Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(15);
	hpText.setFillColor(Color::Red);

	// Enemy init
	int enemySpawnTimer = 0;
	int enemySpawnBtwTime = 30;

	vector<Enemy> enemies;

	// UI for enemy
	Text eHpText;
	eHpText.setFont(font);
	eHpText.setCharacterSize(12);
	eHpText.setFillColor(Color::White);

	while (window.isOpen())
	{
		Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				window.close();
			}
		}

		if (player.HP > 0)
		{
			// Player
			playerMove(player);

			hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
			hpText.setString(to_string(player.HP) + "/" + to_string(player.HPMax));

			// Collision with window
			playerCollision(window, player);

			// Update Controll
			if (shootTimer < shootBtwTime)
				shootTimer++;
			else if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= shootBtwTime) // Shooting
			{
				player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
				shootTimer = 0;
			}

			// Bullets
			for (size_t i = 0; i < player.bullets.size(); i++)
			{
				// Move
				player.bullets[i].shape.move(20.f, 0.f);

				// Bullet out of window will be destroy
				if (player.bullets[i].shape.getPosition().x > window.getSize().x)
				{
					player.bullets.erase(player.bullets.begin() + i);
					break;
				}

				// Enemy collision
				for (size_t k = 0; k < enemies.size(); k++)
				{
					if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
					{
						if (enemies[k].HP <= 1)
						{
							score += enemies[k].HPMax;
							enemies.erase(enemies.begin() + k);
						}
						else
							enemies[k].HP--; // Enemy take damage

						player.bullets.erase(player.bullets.begin() + i);
						break;
					}
				}
			}

			// Enemy
			// Enemy spawn
			if (enemySpawnTimer < enemySpawnBtwTime)
				enemySpawnTimer++;
			else
			{
				Vector2f enemyPos = Vector2f(window.getSize().x, rand() % (int)(window.getSize().y - 60.f));
				enemies.push_back(Enemy(&enemyTex, enemyPos));
				enemySpawnTimer = 0;
			}

			// Enemy behavior
			enemyBehavior(window, enemies, player);

			// UI update
			scoreText.setString("Score: " + to_string(score));
		}

		// Draw ===================================== DRAW ===================================
		// Refesh the frame
		window.clear();

		// Player
		window.draw(player.shape);

		// Bullets
		for (size_t i = 0; i < player.bullets.size(); i++)
		{
			window.draw(player.bullets[i].shape);
		}

		// Enemy
		for (size_t i = 0; i < enemies.size(); i++)
		{
			eHpText.setString(to_string(enemies[i].HP) + "/" + to_string(enemies[i].HPMax));
			Vector2f hpPos(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
			eHpText.setPosition(hpPos);
			window.draw(eHpText);
			window.draw(enemies[i].shape);
		}

		// UI
		window.draw(scoreText);
		window.draw(hpText);

		if (player.HP <= 0)
		{
			window.draw(gameOverText);
		}

		// Render
		window.display();
	}

	return 0;
}

void playerMove(Player &player)
{
	float speed = 7.f;

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player.shape.move(-speed, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player.shape.move(0.f, -speed);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.shape.move(speed, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player.shape.move(0.f, speed);
	}
}

void playerCollision(RenderWindow& window, Player& player)
{
	if (player.shape.getPosition().x <= 0) // Left
		player.shape.setPosition(0.f, player.shape.getPosition().y);

	else if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width) // Right
		player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);

	else if (player.shape.getPosition().y <= 0) // Top
		player.shape.setPosition(player.shape.getPosition().x, 0.f);

	else if (player.shape.getPosition().y >= window.getSize().y - player.shape.getGlobalBounds().height) // Bottom
		player.shape.setPosition(player.shape.getPosition().x, window.getSize().y - player.shape.getGlobalBounds().height);
}

void enemyBehavior(RenderWindow& window, vector<Enemy> &enemies, Player& player)
{
	//float speed = 6.f;

	for (size_t i = 0; i < enemies.size(); i++)
	{
		// Movement
		enemies[i].shape.move(-6.f, 0.f);

		// Out of window
		if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
		{
			enemies.erase(enemies.begin() + i);
			break;
		}

		// Collision with player
		if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
		{
			enemies.erase(enemies.begin() + i);

			player.HP--; // Player take damege

			break;
		}
	}
}