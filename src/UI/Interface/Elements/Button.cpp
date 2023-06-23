//
//  Button.cpp
//  Textbox
//
//  Created by Austin Horn on 1/29/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "Button.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <cmath>

#define _USE_MATH_DEFINES

Button::Button(const sf::Vector2f& radius, float pointCount)
    : m_radius(radius)
    , m_pointCount(pointCount)
    , m_clicked(false)
{
    Shape::update();
}
void Button::setRadius(const sf::Vector2f& radius)
{
    m_radius = radius;
    Shape::update();
}
void Button::setPointCount(float pointCount)
{
    m_pointCount = pointCount;
    Shape::update();
}
const sf::Vector2f& Button::getRadius() const
{
    return m_radius;
}
const bool Button::clicked() const
{
    return m_clicked;
}
const bool Button::contains(const sf::Vector2f& mousePos) const
{
    return Button::getGlobalBounds().contains(mousePos);
}
std::size_t Button::getPointCount() const
{
    return m_pointCount;
}
sf::Vector2f Button::getPoint(std::size_t index) const
{
    float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
    float x = std::cos(angle) * m_radius.x;
    float y = std::sin(angle) * m_radius.y;
    return sf::Vector2f(m_radius.x + x, m_radius.y + y);
}
void Button::mouseOver()
{
    Button::setFillColor({Button::getFillColor().r, Button::getFillColor().g, Button::getFillColor().b, 100});
}
void Button::mouseLeave()
{
    Button::setFillColor({Button::getFillColor().r, Button::getFillColor().g, Button::getFillColor().b, 255});
}
void Button::handleEvent(sf::RenderWindow &window, sf::Event event)
{
    const auto mouse_position = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
    switch (event.type)
    {
        case sf::Event::MouseMoved:
            contains(mouse_position) ? mouseOver() : mouseLeave();
            break;
        case sf::Event::MouseButtonReleased:
            if (contains(mouse_position))
                m_clicked = !m_clicked;
            break;
        default:
            break;
    }
}
void Button::reset()
{
    m_clicked = false;
}
