#include "Ptree.hpp"

Ptree::Ptree(double baseSize, int recursionDepth) {
    if (recursionDepth <= 1) {
        return;
    }

    this->self = new sf::RectangleShape(sf::Vector2f(baseSize, baseSize));
    this->self->setOrigin(sf::Vector2f(0, baseSize));
    this->self->setPosition(sf::Vector2f(baseSize * 2.5, baseSize * 4));

    sf::Vector2f topLeft(baseSize * 2.5, baseSize * 3);
    sf::Vector2f topRight(baseSize * 3.5, baseSize * 3);
    this->left = new Ptree(baseSize * SCALE, -45, 'L', topLeft, recursionDepth - 1);
    this->right = new Ptree(baseSize * SCALE, 45, 'R', topRight, recursionDepth - 1);
}

Ptree::Ptree(double size, float angle, char side, sf::Vector2f basePoint, int depth) {
    // Base case
    if (depth <= 0) {
        return;
    }

    this->self = new sf::RectangleShape(sf::Vector2f(size, size));

    switch (side) {
        case 'L':
            this->self->setOrigin(sf::Vector2f(0, size));
            break;
        case 'R':
            this->self->setOrigin(sf::Vector2f(size, size));
            break;
        default:
            exit(1);
    }

    this->self->setPosition(basePoint);
    this->self->setRotation(angle);

    if (depth >= 1) {
        this->left = new Ptree(size * SCALE, angle - 45, 'L', this->getGlobalPoint(0), depth - 1);
        this->right = new Ptree(size * SCALE, angle + 45, 'R', this->getGlobalPoint(1), depth - 1);
    }
}

void Ptree::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (this->self) target.draw(*this->self);
    if (this->left) this->left->draw(target, states);
    if (this->right) this->right->draw(target, states);
}

sf::Vector2f Ptree::getGlobalPoint(int index) {
    return this->self->getTransform().transformPoint(this->self->getPoint(index));
}

Ptree::~Ptree() {
    delete this->self;
    delete this->left;
    delete this->right;
}
    
    
