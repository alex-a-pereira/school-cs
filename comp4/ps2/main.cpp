#include <iostream>
#include "Ptree.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    float base = atof(argv[1]);
    int recursion_depth = atoi(argv[2]);


    Ptree my_tree(base, recursion_depth);

    sf::RenderWindow window(sf::VideoMode(base * 6.0, base * 4.0), "Pythagorean Tree");

    window.setFramerateLimit(1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(my_tree);
        window.display();
    }

    return 0;
}
