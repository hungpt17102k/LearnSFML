//#include <iostream>
//#include <math.h>
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
//#include <cstdlib>
//
//// THIS FILE WILL DEMO ABOUT TURN VECTOR INTO MOTION IN PROCEESING
//
//using namespace sf;
//using namespace std;
//
//int width = 800;
//int height = 600;
//
//// Create a Vector class
//class PVector
//{
//public:
//	float x;
//	float y;
//
//	PVector() = default;
//
//	PVector(float x_, float y_)
//	{
//		x = x_;
//		y = y_;
//	}
//
//	// Adding Vector
//	void add(PVector v) {
//		x = x + v.x;
//		y = y + v.y;
//	}
//
//	// Subtract Vector
//	void sub(PVector v) {
//		x = x - v.x;
//		y = y - v.y;
//	}
//
//	// Multiplying a vector
//	void mult(float n) {
//		x = x * n;
//		y = y * n;
//	}
//
//	// Divie a vector
//	void div(float n) {
//		x = x / n;
//		y = y / n;
//	}
//
//	// Vector Magnitude
//	float mag() {
//		return sqrt(x * x + y * y);
//	}
//
//	// Normalize the vector, make a vector unit
//	void normalize() {
//		float m = mag();
//		if (m != 0) {
//			div(m);
//		}
//	}
//
//	void setMag(float len) {
//		normalize();
//		mult(len);
//	}
//
//	void limit(float max) {
//		if (mag() > max * max) {
//			normalize();
//			mult(max);
//		}
//	}
//};
//
//static PVector add(PVector v1, PVector v2) {
//	PVector v3 = PVector(v1.x + v2.x, v1.y + v2.y);
//	return v3;
//}
//
//static PVector sub(PVector v1, PVector v2) {
//	PVector v3 = PVector(v1.x - v2.x, v1.y - v2.y);
//	return v3;
//}
//
//class Mover
//{
//public:
//	PVector location;
//	PVector velocity;
//	PVector acceleration;
//	float topspeed;
//
//	Mover() {
//		float posX = rand() % width / static_cast<float>(2);
//		float posY = rand() % height / static_cast<float>(2);
//		location = PVector(posX, posY);
//		velocity = PVector(0.f, 0.f);
//		acceleration = PVector(0.f, 0.f);
//		topspeed = 3;
//	}
//
//	void update(RenderWindow &window) {
//		PVector mouse = PVector(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
//		//cout << location.x << " | " << location.y << endl;
//		PVector dir = sub(mouse, location);
//		dir.setMag(0.5f);
//		acceleration = dir;
//
//		// Velocity changes according to acceleration
//		velocity.add(acceleration);
//		// Limit the velocity by topspeed
//		velocity.limit(topspeed);
//		// Location changes by velocity
//		location.add(velocity);
//	}
//
//	void display(RenderWindow& window, CircleShape& ball) {
//		ball.setPosition(location.x, location.y);
//		window.draw(ball);
//	}
//
//	void checkEdges(RenderWindow& window, CircleShape& ball) {
//		if (location.x > window.getSize().x - ball.getRadius() * 2) {
//			location.x = 0;
//		}
//		else if (location.x < 0)
//		{
//			location.x = window.getSize().x - ball.getRadius() * 2;
//		}
//
//		if (location.y > window.getSize().y - ball.getRadius() * 2) {
//			location.y = 0;
//		}
//		else if (location.y < 0)
//		{
//			location.y = window.getSize().y - ball.getRadius() * 2;
//		}
//	}
//};
//
//float deltaTime(Clock &dtClock)
//{
//	return dtClock.restart().asSeconds();
//}
//
//int main()
//{
//	srand(time(NULL));
//
//	Clock dtClock;
//
//	RenderWindow window(VideoMode(width, height), "Motion Demo", Style::Default);
//	window.setFramerateLimit(60);
//
//	// A circle
//	CircleShape ball(30.f);
//	ball.setOutlineThickness(2);
//	ball.setOutlineColor(Color::Red);
//
//	int numberOfBall = 5;
//	Mover movers[5];
//
//	for (size_t i = 0; i < numberOfBall; i++)
//	{
//		movers[i] = Mover();
//	}
//
//	while (window.isOpen())
//	{
//		
//
//		Event evt;
//		while (window.pollEvent(evt))
//		{
//			if (evt.type == Event::Closed)
//			{
//				window.close();
//			}
//		}
//
//		// Update
//		for (size_t i = 0; i < numberOfBall; i++)
//		{
//			movers[i].update(window);
//		}
//
//		cout << deltaTime(dtClock) << endl;
//
//		// Refesh the frame
//		window.clear();
//
//		// Draw
//		for (size_t i = 0; i < numberOfBall; i++)
//		{
//			movers[i].display(window, ball);
//		}
//
//		// Render
//		window.display();
//	}
//
//	return 0;
//}