//
//  StadiumShape.cpp
//  Textbox
//
//  Created by Austin Horn on 1/29/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "StadiumShape.hpp"

#include <cmath>
#define _USE_MATH_DEFINES

namespace sf
{
    StadiumShape::StadiumShape(const sf::Vector2f& size, float radius)
        : m_size(size)
        , m_radius(radius)
        , m_antialiasing(8)
    {
        Shape::update();
    }
    void StadiumShape::setSize(const sf::Vector2f& size)
    {
        m_size = size;
        Shape::update();
    }
    void StadiumShape::setCornersRadius(float radius)
    {
        m_radius = radius;
        Shape::update();
    }
    void StadiumShape::setAntialiasing(unsigned int antialiasing)
    {
        m_antialiasing = antialiasing;
        Shape::update();
    }
    void StadiumShape::setTranslucent(const bool &translucent)
    {
        translucent ? setFillColor({getFillColor().r, getFillColor().g, getFillColor().b, 150})
                    : setFillColor({getFillColor().r, getFillColor().g, getFillColor().b, 255});
    }
    const sf::Vector2f& StadiumShape::getSize() const
    {
        return m_size;
    }
    float StadiumShape::getCornersRadius() const
    {
        return m_radius;
    }
    std::size_t StadiumShape::getPointCount() const
    {
        return m_antialiasing*4;
    }
    sf::Vector2f StadiumShape::getPoint(std::size_t index) const
    {
        if(index >= m_antialiasing*4) { return sf::Vector2f(0,0); }

        float deltaAngle = 90.f/(m_antialiasing-1);
        sf::Vector2f center;
        unsigned int centerIndex = index/std::round(m_antialiasing);
        
        switch(centerIndex) {
            case 0: center.x = m_size.x - m_radius; center.y = m_radius;            break;
            case 1: center.x = m_radius;            center.y = m_radius;            break;
            case 2: center.x = m_radius;            center.y = m_size.y - m_radius; break;
            case 3: center.x = m_size.x - m_radius; center.y = m_size.y - m_radius; break;
        }

        return sf::Vector2f(m_radius*std::cos(deltaAngle*(index-centerIndex)*M_PI/180)+center.x,
                           -m_radius*std::sin(deltaAngle*(index-centerIndex)*M_PI/180)+center.y);
    }
}
