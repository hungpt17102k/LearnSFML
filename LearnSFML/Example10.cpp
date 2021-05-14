//#include <iostream>
//#include <math.h>
//#include <vector>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <cstdlib>
//
//using namespace sf;
//using namespace std;
//
//// LENGTH OF VECTOR: ||V|| = sqrt(V.x^2 + V.y^2)
//// NORMALIZE VECTOR: U = V / ||V||
//
//class Bullet
//{
//public:
//	CircleShape shape;
//	Vector2f currVelocity;
//	float maxSpeed;
//
//	Bullet(float radius = 5.f) : currVelocity(0.f, 0.f), maxSpeed(15.f)
//	{
//		this->shape.setRadius(radius);
//		this->shape.setFillColor(Color::Red);
//	}
//};
//
//class Enemy
//{
//public:
//	RectangleShape shape;
//	Vector2f currVelocity;
//	float maxSpeed;
//
//	Enemy(float radius = 5.f) : currVelocity(0.f, 0.f), maxSpeed(7.f)
//	{
//		this->shape.setSize(Vector2f(30.f, 30.f));
//		this->shape.setFillColor(Color::Blue);
//	}
//};
//
//void playerMove(CircleShape& player);
//
//int main()
//{
//	srand(time(NULL));
//	RenderWindow window(VideoMode(800, 600), "360 Shooter!", Style::Default);
//	window.setFramerateLimit(60);
//
//	// Player
//	CircleShape player(20.f);
//	player.setFillColor(Color::White);
//	player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y / 2 - player.getRadius());
//	int hp = 10;
//	RectangleShape hpBar(Vector2f((float)hp * 20.f, 20.f));
//	hpBar.setFillColor(Color::Red);
//	float barposx = window.getSize().x / 2 - hpBar.getSize().x / 2;
//	hpBar.setPosition(barposx, 10.f);
//	int score = 0;
//
//	// Bullets
//	Bullet b1;
//	vector<Bullet> bullets;
//	int shootTimer = 0;
//	int timeBtwShot = 10;
//
//	// Enemy
//	Enemy enemy;
//	vector<Enemy> enemies;
//	int maxEnemis = 30;
//	int spawnCounter = 0;
//	int timeBtwSqawn = 30;
//
//	// Vectors
//	Vector2f playerCenter;
//	Vector2f mousePosWindow;
//	Vector2f aimDir; // For bullet
//	Vector2f aimDirNorm; // For bullet
//	// Vectors for enemy
//	Vector2f targetDir;
//	Vector2f targetDirNorm;
//
//	while (window.isOpen())
//	{
//		Event evt;
//		while (window.pollEvent(evt))
//		{
//			if (evt.type == Event::Closed)
//			{
//				window.close();
//			}
//		}
//
//		// When player is dead
//		if (hp <= 0)
//		{
//			break;
//		}
//
//		// Update
//		// Vectors
//		playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
//		mousePosWindow = Vector2f(Mouse::getPosition(window));
//		aimDir = mousePosWindow - playerCenter;
//		aimDirNorm = aimDir / (float)sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
//		//cout << aimDirNorm.x << " | " << aimDirNorm.y << endl;
//
//		// Player
//		playerMove(player);
//
//		// Enemies
//		if (spawnCounter < timeBtwSqawn)
//			spawnCounter++;
//
//		if (spawnCounter >= timeBtwSqawn && enemies.size() < maxEnemis)
//		{
//			float sqawnX = rand() % window.getSize().x;
//			float sqawnY = rand() % window.getSize().y;
//			enemy.shape.setPosition(sqawnX, sqawnY);
//
//			// Vector to get dir btw enemy and player
//			targetDir = enemy.shape.getPosition() - playerCenter;
//			targetDirNorm = targetDir / (float)sqrt(pow(targetDir.x, 2) + pow(targetDir.y, 2));
//			//cout << targetDirNorm.x << " | " << targetDirNorm.y << endl;
//			enemy.currVelocity = -targetDirNorm * enemy.maxSpeed;
//			enemies.push_back(enemy);
//
//			spawnCounter = 0;
//		}
//
//		// Enemy move
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			enemies[i].shape.move(enemies[i].currVelocity);
//
//			// Out of bounds
//			if (enemies[i].shape.getPosition().x < 0 || enemies[i].shape.getPosition().x > window.getSize().x
//				|| enemies[i].shape.getPosition().y < 0 || enemies[i].shape.getPosition().y > window.getSize().y)
//			{
//				enemies.erase(enemies.begin() + i);
//			}
//			else
//			{
//				for (size_t k = 0; k < enemies.size(); k++)
//				{
//					// Collision with the player
//					if (enemies[k].shape.getGlobalBounds().intersects(player.getGlobalBounds()))
//					{
//						enemies.erase(enemies.begin() + k);
//						hp--;
//						break;
//					}
//				}
//			}	
//		}
//
//		// Shooting
//		if (shootTimer < timeBtwShot)
//			shootTimer++;
//
//		if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= timeBtwShot)
//		{
//			b1.shape.setPosition(playerCenter);
//			b1.currVelocity = aimDirNorm * b1.maxSpeed;
//
//			bullets.push_back(b1);
//			shootTimer = 0;
//		}
//
//		for (size_t i = 0; i < bullets.size(); i++)
//		{
//			bullets[i].shape.move(bullets[i].currVelocity);
//
//			// Out of bounds
//			if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window.getSize().x
//				|| bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
//			{
//				bullets.erase(bullets.begin() + i);
//			}
//			else
//			{
//				// Enemy collision
//				for (size_t k = 0; k < enemies.size(); k++)
//				{
//					if (bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
//					{
//						bullets.erase(bullets.begin() + i);
//						enemies.erase(enemies.begin() + k);
//
//						score++;
//						break;
//					}
//				}
//			}
//		}
//
//		// UI
//		hpBar.setSize(Vector2f((float)hp * 20.f, 20.f));
//
//		// Refesh the frame
//		window.clear();
//
//		// Draw
//		// Draw player
//		window.draw(player);
//
//		// Draw enemy
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			window.draw(enemies[i].shape);
//		}
//
//		// Draw bullets
//		for (size_t i = 0; i < bullets.size(); i++)
//		{
//			window.draw(bullets[i].shape);
//		}
//
//		// Draw hp Bar
//		window.draw(hpBar);
//
//		// Render
//		window.display();
//	}
//
//	cout << "Your score is : " << score << endl;
//	system("Pause");
//
//	return 0;
//}
//
//void playerMove(CircleShape& player)
//{
//	float speed = 5.f;
//
//	if (Keyboard::isKeyPressed(Keyboard::A))
//	{
//		player.move(-speed, 0.f);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::W))
//	{
//		player.move(0.f, -speed);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::D))
//	{
//		player.move(speed, 0.f);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::S))
//	{
//		player.move(0.f, speed);
//	}
//}
