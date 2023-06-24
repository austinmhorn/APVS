#pragma once

#include <SFML/Graphics/Shape.hpp>

#include <cmath>

class RoundedRectangleShape : public sf::Shape
{
    
public:
    
    explicit RoundedRectangleShape(const sf::Vector2f& size = {0.f, 0.f}, float radius = 0, unsigned int cornerPointCount = 0);

    void setSize(const sf::Vector2f& size);
    void setRadius(float radius);
    void setCornerPointCount(unsigned int count);

    const sf::Vector2f& getSize() const;
    float getRadius() const;
    unsigned int getCornerPointCount();
    
    virtual std::size_t getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;

private:
    
    sf::Vector2f m_size;
    float        m_radius;
    unsigned int m_cornerPointCount;
};
