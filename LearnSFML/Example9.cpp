//#include <iostream>
//
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//
//using namespace sf;
//using namespace std;
//
//void playerMove(Sprite &player);
//
//int main()
//{
//	RenderWindow window(VideoMode(640, 480), "Cat do(d)ge", Style::Default);
//	window.setFramerateLimit(60);
//
//	// Cat
//	Texture catTex;
//	Sprite cat;
//	if (!catTex.loadFromFile("Texture/cat.png"))
//		throw "Could not load cat.png!";
//
//	cat.setTexture(catTex);
//	cat.setScale(Vector2f(0.15f, 0.15f));
//	float speedMove = 5.f;
//	int catSqawnTimer = 0;
//	int timeBtwSqawn = 40;
//
//	vector<Sprite> cats;
//	cats.push_back(cat);
//
//	// Doge
//	Texture dogeTex;
//	Sprite doge;
//	// Player HP
//	int hp = 11;
//	RectangleShape hpBar(Vector2f((float)hp * 20.f, 20.f));
//	hpBar.setFillColor(Color::Red);
//	float barPosX = window.getSize().x / 2 - hpBar.getSize().x / 2;
//	hpBar.setPosition(barPosX, 10.f);
//
//	if (!dogeTex.loadFromFile("Texture/doge1.png"))
//		throw "Could not load doge.png!";
//
//	doge.setTexture(dogeTex);
//	doge.setScale(Vector2f(0.2f, 0.2f));
//
//	while (window.isOpen() && hp > 0)
//	{
//		Event evt;
//		while (window.pollEvent(evt))
//		{
//			if (evt.type == Event::Closed)
//				window.close();
//			
//			if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Escape)
//				window.close();
//		}
//
//		// Update
//		// DOGE (PLAYER)
//		// Doge keyboard input to move
//		//doge.setPosition(doge.getPosition().x, Mouse::getPosition().y);
//		playerMove(doge);
//
//		// Collision for doge with window
//		if (doge.getPosition().y > window.getSize().y - doge.getGlobalBounds().height)
//			doge.setPosition(doge.getPosition().x, window.getSize().y - doge.getGlobalBounds().height);
//
//		if (doge.getPosition().y < 0)
//			doge.setPosition(doge.getPosition().x, 0.f);
//
//		if (doge.getPosition().x < 0)
//			doge.setPosition(0.f, doge.getPosition().y);
//
//		// CATS (ENEMIES)
//		for (size_t i = 0; i < cats.size(); i++)
//		{
//			cats[i].move(-speedMove, 0.f);
//
//			if (cats[i].getPosition().x < 0 - cat.getGlobalBounds().width)
//				cats.erase(cats.begin() + i);
//		}
//
//		if (catSqawnTimer < timeBtwSqawn)
//			catSqawnTimer++;
//
//		if (catSqawnTimer >= timeBtwSqawn)
//		{
//			float posX = window.getSize().x;
//			float posY = rand() % int(window.getSize().y - cat.getGlobalBounds().height);
//			cat.setPosition(Vector2f(posX, posY));
//			cats.push_back(cat);
//			catSqawnTimer = 0;
//		}
//
//		// COLLISION
//		for (size_t i = 0; i < cats.size(); i++)
//		{
//			if (doge.getGlobalBounds().intersects(cats[i].getGlobalBounds()))
//			{
//				hp--;
//				cats.erase(cats.begin() + i);
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
//		window.draw(doge);
//
//		for (size_t i = 0; i < cats.size(); i++)
//		{
//			window.draw(cats[i]);
//		}
//
//		window.draw(hpBar);
//
//		// Render
//		window.display();
//	}
//
//	return 0;
//}
//
//void playerMove(Sprite& player)
//{
//	float speed = 5.f;
//
//	if (Keyboard::isKeyPressed(Keyboard::Left))
//	{
//		player.move(-speed, 0.f);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Up))
//	{
//		player.move(0.f, -speed);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Right))
//	{
//		player.move(speed, 0.f);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Down))
//	{
//		player.move(0.f, speed);
//	}
//}