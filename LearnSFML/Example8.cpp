//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <cstdlib>
//
//#include<vector>
//
//using namespace sf;
//using namespace std;
//
//int main()
//{
//	srand(time(NULL));
//
//	RenderWindow window(VideoMode(640, 480), "Ball Shooter", Style::Default);
//	window.setFramerateLimit(60);
//
//	// Create object
//	// Create bullet
//	CircleShape projectile(5.f);
//	projectile.setFillColor(Color::Red);
//
//	// Create enemy
//	RectangleShape enemy(Vector2f(30.f, 30.f));
//	enemy.setFillColor(Color::Yellow);
//	float moveSpeed = 3.f;
//	int enemySqawnTimer = 0;
//	int timeBtwSqawn = 40;
//
//	// Create player
//	CircleShape player(20.f);
//	player.setFillColor(Color::White);
//	player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y - player.getRadius() * 2 - 10.f);
//	Vector2f playerCenter; // To make a shotting point
//	float proSpeed = 10.f;
//	int shootTimer = 0;
//	int timeBtwShot = 15;
//
//	// To store bullets
//	vector<CircleShape> projectiles;
//	projectiles.push_back(projectile);
//
//	// To store enemies
//	vector<RectangleShape> enemies;
//	enemies.push_back(enemy);
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
//		// UPDATE
//		// PLAYER
//		// Make the shotting point follow the player
//		playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
//		// Move player by mouse
//		player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);
//
//		// BULLETS
//		if (shootTimer < timeBtwShot)
//			shootTimer++;
//		// To shoot the bullet
//		if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= timeBtwShot) // Shoot
//		{
//			projectile.setPosition(playerCenter);
//			projectiles.push_back(projectile);
//
//			shootTimer = 0;
//		}
//
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			projectiles[i].move(0.f, -proSpeed);
//
//			if (projectiles[i].getPosition().y < 0)
//				projectiles.erase(projectiles.begin() + i); // Delete the bullet
//		}
//
//		// ENEMIES
//		if (enemySqawnTimer < timeBtwSqawn)
//			enemySqawnTimer++;
//
//		// Sqwaning enemies
//		if (enemySqawnTimer >= timeBtwSqawn)
//		{
//			float sqawnX = rand() % int(window.getSize().x - enemy.getSize().x);
//			enemy.setPosition(sqawnX, 0.f);
//			enemies.push_back(enemy);
//
//			enemySqawnTimer = 0;
//		}
//
//		// Enemies move
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			enemies[i].move(0.f, moveSpeed);
//
//			if (enemies[i].getPosition().y > window.getSize().y)
//				enemies.erase(enemies.begin() + i); // Delet the enemy
//		}
//
//		// Collision
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			for (size_t k = 0; k < enemies.size(); k++)
//			{
//				// To check if the bullet hit the enemy
//				if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
//				{
//					projectiles.erase(projectiles.begin() + i);
//					enemies.erase(enemies.begin() + k);
//					break;
//				}
//			}
//		}
//
//		// Refesh the frame
//		window.clear();
//
//		// Draw
//		window.draw(player);
//
//		// Draw the enemies
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			window.draw(enemies[i]);
//		}
//
//		// Draw the bullets
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			window.draw(projectiles[i]);
//		}
//
//		// Render
//		window.display();
//	}
//
//	return 0;
//}