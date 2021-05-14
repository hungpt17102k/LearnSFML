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
//int main()
//{
//	RenderWindow window(VideoMode(640, 400), "SFML App", Style::Default);
//	window.setFramerateLimit(60);
//
//	// Create a triangle
//	CircleShape triangle;
//	triangle.setRadius(50.f);
//	triangle.setPointCount(3);
//
//	// Create lines
//	Vertex lines[] = 
//	{
//		Vertex(Vector2f(100.f, 100.f)),
//		Vertex(Vector2f(400.f, 100.f))
//	};
//
//	// Create a convex shape
//	ConvexShape convex;
//	convex.setPosition(Vector2f(400.f, 50.f));
//
//	// Resize it to 5 points
//	convex.setPointCount(5);
//
//	// Define the points
//	convex.setPoint(0, Vector2f(0, 0));
//	convex.setPoint(1, Vector2f(150, 10));
//	convex.setPoint(2, Vector2f(120, 90));
//	convex.setPoint(3, Vector2f(30, 100));
//	convex.setPoint(4, Vector2f(0, 50));
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
//		// Update
//
//		// Refesh the frame
//		window.clear();
//
//		// Draw
//		window.draw(triangle);
//		window.draw(lines, 2, Lines);
//		window.draw(convex);
//
//		// Render
//		window.display();
//	}
//
//
//	return 0;
//}