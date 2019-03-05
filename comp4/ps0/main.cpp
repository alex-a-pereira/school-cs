#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.setFramerateLimit(60);

	RectangleShape background(Vector2f(200, 200));
	background.setFillColor(Color(43, 53, 52));

	CircleShape circle_frame(100.f);
	circle_frame.setFillColor(Color(107, 134, 144));

	Texture sprite_texture;
	sprite_texture.loadFromFile("./sprite.png");
	Sprite my_sprite(sprite_texture);

	// Size of my sprite
	int texture_x = sprite_texture.getSize().x;
	int texture_y = sprite_texture.getSize().y;
	// Window attributes
	int max_boundary_x = window.getSize().x - texture_x;
	int max_boundary_y = window.getSize().y - texture_y;
	int center_x = (window.getSize().x - texture_x) / 2;
	int center_y = (window.getSize().y - texture_y) / 2;
	
	// Position of my sprite, originally start in center
	int location_x = center_x;
	int location_y = center_y;
	
	// Movement directions.. bool b/c it can move more than one direction at once
	bool north = false;
	bool south = false;
	bool east = false;
	bool west = false;

	while (window.isOpen())
	{

		my_sprite.setPosition(location_x, location_y);

		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed) {
				window.close();
			}
			else if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Space) {
					location_x = center_x;
					location_y = center_y;
					break;
				}
				switch (event.key.code) {
				case Keyboard::Up:
					north = true;
					break;
				case Keyboard::Right:
					east = true;
					break;
				case Keyboard::Down:
					south = true;
					break;
				case Keyboard::Left:
					west = true;
					break;
				default: break;
				}
			}
			else if (event.type == Event::KeyReleased) {
				switch (event.key.code) {
				case Keyboard::Up:
					north = false;
					break;
				case Keyboard::Right:
					east = false;
					break;
				case Keyboard::Down:
					south = false;
					break;
				case Keyboard::Left:
					west = false;
					break;
				default: break;
				}
			}
				
		}
		// Handle sprite movement
		if (north && location_y - 2 > 0) {
			location_y -= 2;
		}
		if (east && location_x + 2 < max_boundary_x) {
			location_x += 2;
		}
		if (south && location_y + 2 < max_boundary_y) {
			location_y += 2;
		}
		if (west && location_x - 2 > 0) {
			location_x -= 2;
		}

		window.clear();
		window.draw(background);
		window.draw(circle_frame);
		window.draw(my_sprite);
		window.display();
	}

	return 0;
}

