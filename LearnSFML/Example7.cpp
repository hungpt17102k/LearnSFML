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
//int main()
//{
//	RenderWindow window(VideoMode(640, 480), "Simple game", Style::Default);
//	window.setFramerateLimit(60);
//
//	// Create a hoop
//	CircleShape hoop(40.f);
//	int dir = 0;
//	float speed = 3.f;
//	hoop.setFillColor(Color::White);
//	hoop.setOutlineThickness(2);
//	hoop.setOutlineColor(Color::Green);
//	hoop.setPosition(Vector2f(0.f, 10.f));
//
//	// Create a ball
//	CircleShape ball(20.f);
//	bool isShot = false;
//	ball.setFillColor(Color::Red);
//	ball.setPosition(Vector2f(0.f, window.getSize().y - ball.getRadius() * 3));
//
//	int score = 0;
//
//	while (window.isOpen())
//	{
//		Event evt;
//		while (window.pollEvent(evt))
//		{
//			if (evt.type == Event::Closed)
//				window.close();
//			if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Escape)
//				window.close();
//		}
//
//		// Update function
//		// Update for the hoop
//		if (hoop.getPosition().x <= 0)
//			dir = 1;
//		else if (hoop.getPosition().x + hoop.getRadius() * 2 >= window.getSize().x)
//			dir = 0;
//
//		if (dir == 0)
//			hoop.move(-speed, 0.f);
//		else
//			hoop.move(speed, 0.f);
//
//		// Update for the ball
//		// Shot the ball when press
//		if (Mouse::isButtonPressed(Mouse::Left))
//			isShot = true;
//
//		if (!isShot)
//			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
//		else
//			ball.move(0.f, -5.f);
//
//		// Collision ball
//		if (ball.getPosition().y < 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
//		{
//			if (ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
//				score++;
//
//			// Reset the ball position
//			isShot = false;
//			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
//		}
//			
//		// Refesh the frame
//		window.clear(Color::Black);
//
//		//Draw
//		window.draw(hoop);
//		window.draw(ball);
//
//		// Render
//		window.display();
//	}
//
//	cout << "Your score is: " << score << endl;
//
//	system("Pause");
//
//	return 0;
//}