//
//  RectButton.cpp
//  War
//
//  Created by Austin Horn on 12/2/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef RectButton_cpp
#define RectButton_cpp

#include "Base/Button.hpp"

template <>
void Button<sf::RectangleShape>::updateTextCoords()
{
    sf::FloatRect shape_rect = m_shape.getGlobalBounds();
    sf::FloatRect text_rect = m_text.getGlobalBounds();
    
    float x = shape_rect.left+std::round(shape_rect.width/2.f)-std::round(text_rect.width/2.f);
    float y = shape_rect.top+std::round(shape_rect.height/2.6f)-std::round(text_rect.height/2.f);
    
    m_text.setPosition(x, y);
}
template <>
void Button<sf::RectangleShape>::update()
{
    this->updateTextCoords();
}
template <>
Button<sf::RectangleShape>::Button()
    : m_shape(sf::RectangleShape{})
    , m_text(sf::Text{})
    , m_enabled(true)
    , m_pointCount(30)
    , m_clicked(false)
{
    m_text.setFillColor(sf::Color::Black);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setTextureRect(const sf::IntRect& rect)
{
    m_shape.setTextureRect(rect);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setTexture(const sf::Texture* texture)
{
    m_shape.setTexture(texture);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setSize(const sf::Vector2f& size)
{
    m_shape.setSize(size);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setFillColor(const sf::Color& color)
{
    m_shape.setFillColor(color);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setOutlineColor(const sf::Color& color)
{
    m_shape.setOutlineColor(color);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setPosition(const sf::Vector2f& position)
{
    m_shape.setPosition(position);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setPosition(const float& x, const float& y)
{
    m_shape.setPosition(x, y);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setString(const std::string& string)
{
    m_text.setString(string);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setFont(const sf::Font& font)
{
    m_text.setFont(font);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setTextFillColor(const sf::Color& color)
{
    m_text.setFillColor(color);
    this->update();
}
template <>
void Button<sf::RectangleShape>::setTextOutlineColor(const sf::Color& color)
{
    m_text.setOutlineColor(color);
    this->update();
}





template <>
const sf::Vector2f& Button<sf::RectangleShape>::getSize() const
{
    return m_shape.getSize();
}
template <>
sf::FloatRect Button<sf::RectangleShape>::getGlobalBounds() const
{
    return getTransform().transformRect(m_shape.getGlobalBounds());
}
template <>
sf::Color Button<sf::RectangleShape>::getFillColor() const
{
    return m_shape.getFillColor();
}
template <>
sf::Color Button<sf::RectangleShape>::getOutlineColor() const
{
    return m_shape.getOutlineColor();
}
template <>
const sf::Vector2f& Button<sf::RectangleShape>::getPosition() const
{
    return m_shape.getPosition();
}
template <>
std::string Button<sf::RectangleShape>::getString() const
{
    return m_text.getString();
}
template <>
const sf::Font* Button<sf::RectangleShape>::getFont() const
{
    return m_text.getFont();
}
template <>
sf::Color Button<sf::RectangleShape>::getTextFillColor() const
{
    return m_text.getFillColor();
}
template <>
sf::Color Button<sf::RectangleShape>::getTextOutlineColor() const
{
    return m_text.getOutlineColor();
}
template <>
bool Button<sf::RectangleShape>::getEnabled() const
{
    return m_enabled;
}












template <>
const bool Button<sf::RectangleShape>::contains(const sf::Vector2f& point) const
{
    return getGlobalBounds().contains(point);
}
template <>
void Button<sf::RectangleShape>::mouseOver()
{
    m_shape.setOutlineThickness(3.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 150});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 150});
}
template <>
void Button<sf::RectangleShape>::mouseLeave()
{
    
    m_shape.setOutlineThickness(0.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 255});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 255});
}
template <>
void Button<sf::RectangleShape>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text);
}






template <>
void Button<sf::RectangleShape>::handleEvent(sf::RenderWindow& window, sf::Event event)
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

template <>
void Button<sf::RectangleShape>::reset()
{
    m_clicked = false;
}

template <>
std::size_t Button<sf::RectangleShape>::getPointCount() const
{
    return 4;
}

template <>
sf::Vector2f Button<sf::RectangleShape>::getPoint(std::size_t index) const
{
    return m_shape.getPoint(index);
}

#endif /* RectButton_cpp */
