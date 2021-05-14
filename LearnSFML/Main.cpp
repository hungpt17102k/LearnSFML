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
//	RenderWindow window(VideoMode(640, 480), "SFML App", Style::Default);
//	window.setFramerateLimit(60);
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
//		//window.draw();
//
//		// Render
//		window.display();
//	}
//
//
//	return 0;
//}