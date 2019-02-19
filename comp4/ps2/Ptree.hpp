#ifndef PTREE_PTREE_H
#define PTREE_PTREE_H

#include <iostream>
#include <SFML/Graphics.hpp>

const double SCALE = 0.707106781186528;

class Ptree: public sf::Drawable, sf::Transformable {
public:
    Ptree(double baseSize, int recursionDepth);
    Ptree(double size, float rotationAngle, char side, sf::Vector2f basePoint, int depth);
    ~Ptree();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Vector2f getGlobalPoint(int index);


private:
    sf::RectangleShape* self;
    Ptree* left;
    Ptree* right;

};


#endif //PTREE_PTREE_H
