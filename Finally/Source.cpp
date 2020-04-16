#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Lesson 1. kychka-pc.ru");

	sf::Image hero_img;
	hero_img.createMaskFromColor(sf::Color(158, 120, 114, 0));
	hero_img.loadFromFile("Hero.png");

	sf::Texture hero_texture;
	hero_texture.loadFromImage(hero_img);

	sf::Sprite hero_sprite;
	hero_sprite.setTexture(hero_texture);
	hero_sprite.setTextureRect(sf::IntRect(2, 614+200, 201, 813));
	hero_sprite.setPosition(0, 0);

	sf::Clock clock;
	float currentFrame = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3) currentFrame -= 3;
			hero_sprite.setTextureRect(sf::IntRect(2*time, 614 + 200, 201, 813));
			hero_sprite.move(-0.1 * time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 3) currentFrame -= 3;
			hero_sprite.setTextureRect(sf::IntRect(2 * time, 614 + 200, 405, 813));
			hero_sprite.move(0.1 * time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			hero_sprite.move(0, -0.1 * time);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			hero_sprite.move(0, 0.1 * time);

		window.clear();
		window.draw(hero_sprite);
		window.display();
	}
	return 0;
}