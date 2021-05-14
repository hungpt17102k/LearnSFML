//#include <iostream>
//
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//
//using namespace sf;
//
//void Update(RectangleShape& square, int &keyTime, RenderWindow& window);
//
//void Draw(RenderWindow& window, RectangleShape& square);
//
//int main()
//{
//	int keyTime = 8;
//
//	RenderWindow window(VideoMode(640, 480), "Simple Square Swag", Style::Default);
//	window.setFramerateLimit(60);
//
//	RectangleShape square(Vector2f(100.f, 100.f));
//	square.setFillColor(Color::Red);
//	square.setPosition(window.getSize().x / 2, window.getSize().y / 2);
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
//			if (evt.KeyPressed && evt.key.code == Keyboard::Escape)
//				window.close();
//		}
//
//		// Update
//		Update(square, keyTime, window);
//
//		// Draw
//		Draw(window, square);
//	}
//
//	return 0;
//}
//
//void Update(RectangleShape& square, int &keyTime, RenderWindow& window)
//{
//	float speed = 5.f;
//
//	if (keyTime < 8)
//		keyTime++;
//
//	if (Keyboard::isKeyPressed(Keyboard::A) && square.getPosition().x > 0)
//	{
//		square.move(-speed, 0.f);
//		keyTime = 0;
//	}
//	if (Keyboard::isKeyPressed(Keyboard::D) && square.getPosition().x + square.getSize().x < window.getSize().x)
//	{
//		square.move(speed, 0.f);
//		keyTime = 0;
//	}
//	if (Keyboard::isKeyPressed(Keyboard::W) && square.getPosition().y > 0)
//	{
//		square.move(0.f, -speed);
//		keyTime = 0;
//	}
//	if (Keyboard::isKeyPressed(Keyboard::S) && square.getPosition().y + square.getSize().y < window.getSize().y)
//	{
//		square.move(0.f, speed);
//		keyTime = 0;
//	}
//	if (Mouse::isButtonPressed(Mouse::Left))
//	{
//		square.setFillColor(Color::Blue);
//		keyTime = 0;
//	}
//	else
//	{
//		square.setFillColor(Color::Red);
//	}
//}
//
//void Draw(RenderWindow& window, RectangleShape& square)
//{
//	window.clear(Color::Black);
//
//	// Draw stuff
//	window.draw(square);
//
//	window.display();
//}