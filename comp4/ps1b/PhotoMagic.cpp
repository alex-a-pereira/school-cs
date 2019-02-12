#include <iostream>
#include "LFSR.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <sstream>

// http://www.cplusplus.com/forum/beginner/21802/

using namespace std;
// using namespace sf;

void password_conversion(string password, int &tap, string &seed);

int main(int argc, char* argv[]) {
    string seed;
    int tap;

    // determine style of program call. 5 args means seed and tap, 4 means password
    switch(argc) {
    case 5:
        seed = argv[3];
        tap = atoi(argv[4]);
        break;
    case 4:
        password_conversion(argv[3], tap, seed);
        break;
    default:
        cout << "Run the program like this:" << endl;
        cout << "./PhotoMagic [input-file] [output-file] [seed] [tap]" << endl;
        cout << "OR" << endl;
        cout << "./PhotoMagic [input-file] [output-file] [password]" << endl;
        exit(1);
    }

    LFSR my_l(seed, tap);

    sf::Image infile;
    sf::Image outfile;
    if (!infile.loadFromFile(argv[1]) || !outfile.loadFromFile(argv[2])) {
        exit(1);
    }

	sf::Color p;
	sf::Vector2u size = infile.getSize();
	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			p = infile.getPixel(x, y);
			p.r = p.r ^ my_l.generate(8);
			p.g = p.g ^ my_l.generate(8);
			p.b = p.b ^ my_l.generate(8);
			outfile.setPixel(x, y, p);
		}
	}

	sf::Texture in_texture;
    sf::Texture out_texture;
	in_texture.loadFromImage(infile);
    out_texture.loadFromImage(outfile);

	sf::Sprite in_sprite;
    sf::Sprite out_sprite;
	in_sprite.setTexture(in_texture);
    out_sprite.setTexture(out_texture);

	sf::RenderWindow in_window(sf::VideoMode(size.x, size.y), argv[1]);
    sf::RenderWindow out_window(sf::VideoMode(size.x, size.y), argv[2]);
    while (in_window.isOpen() && out_window.isOpen()) {
        sf::Event event;
        while (in_window.pollEvent(event) || out_window.pollEvent(event) ) {
            if (event.type == sf::Event::Closed)
                in_window.close();
        }

        in_window.clear();
        in_window.draw(in_sprite);
        in_window.display();

        out_window.clear();
        out_window.draw(out_sprite);
        out_window.display();
    }


	if (!outfile.saveToFile(argv[2])) {
		return -1;
    }

	return 0;

}

void password_conversion(string password, int &tap, string &seed) {
    int current;
    int total = 0;
    string temp;

    for (int i = 0; i < password.length(); i++) {
        current = password.at(i);
        temp += to_string((current * 15) % 2);
        total += current;
    }

    tap = total % password.length();
    seed = temp;
}