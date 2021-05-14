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
//	RenderWindow window(VideoMode(800, 600), "Text intro", Style::Default);
//	window.setFramerateLimit(60);
//
//	Font font;
//	if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
//		throw("Could not load font!");
//
//	Text text;
//	text.setFont(font);
//	text.setCharacterSize(24);
//	text.setFillColor(Color::Cyan);
//	text.setStyle(Text::Bold);
//	text.setString("Hello Nha");
//	text.setPosition(window.getSize().x / 2 - (text.getGlobalBounds().width / 2), window.getSize().y / 2);
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
//		text.move(0.f, 3.f);
//
//		if (text.getPosition().y > window.getSize().y)
//			text.setPosition(window.getSize().x / 2 - (text.getGlobalBounds().width / 2), 0.f);
//
//		// Refesh the frame
//		window.clear();
//
//		// Draw
//		window.draw(text);
//
//		// Render
//		window.display();
//	}
//
//
//	return 0;
//}