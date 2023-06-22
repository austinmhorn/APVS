//
//  CircleButton.cpp
//  War
//
//  Created by Austin Horn on 12/2/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef CircleButton_cpp
#define CircleButton_cpp

#include "Base/Button.hpp"

template <>
void Button<sf::CircleShape>::updateTextCoords()
{
    sf::FloatRect shape_rect = m_shape.getGlobalBounds();
    sf::FloatRect text_rect = m_text.getGlobalBounds();
    
    float x = shape_rect.left+std::round(shape_rect.width/2.f)-std::round(text_rect.width/2.f);
    float y = shape_rect.top+std::round(shape_rect.height/2.6f)-std::round(text_rect.height/2.f);
    
    m_text.setPosition(x, y);
}
template <>
void Button<sf::CircleShape>::update()
{
    this->updateTextCoords();
}
template <>
Button<sf::CircleShape>::Button(const sf::CircleShape& stadium, const sf::Text& text) :
m_shape(stadium),
m_text(text)
{
    m_text.setFillColor(sf::Color::Black);
    this->update();
}
template <>
void Button<sf::CircleShape>::setTextureRect(const sf::IntRect& rect)
{
    m_shape.setTextureRect(rect);
    this->update();
}
template <>
void Button<sf::CircleShape>::setTexture(const sf::Texture* texture)
{
    m_shape.setTexture(texture);
    this->update();
}
template <>
void Button<sf::CircleShape>::setFillColor(const sf::Color& color)
{
    m_shape.setFillColor(color);
    this->update();
}
template <>
void Button<sf::CircleShape>::setOutlineColor(const sf::Color& color)
{
    m_shape.setOutlineColor(color);
    this->update();
}
template <>
void Button<sf::CircleShape>::setPosition(const sf::Vector2f& position)
{
    m_shape.setPosition(position);
    this->update();
}
template <>
void Button<sf::CircleShape>::setPosition(const float& x, const float& y)
{
    m_shape.setPosition(x, y);
    this->update();
}
template <>
void Button<sf::CircleShape>::setString(const std::string& string)
{
    m_text.setString(string);
    this->update();
}
template <>
void Button<sf::CircleShape>::setFont(const sf::Font& font)
{
    m_text.setFont(font);
    this->update();
}
template <>
void Button<sf::CircleShape>::setTextFillColor(const sf::Color& color)
{
    m_text.setFillColor(color);
    this->update();
}
template <>
void Button<sf::CircleShape>::setTextOutlineColor(const sf::Color& color)
{
    m_text.setOutlineColor(color);
    this->update();
}












template <>
sf::FloatRect Button<sf::CircleShape>::getGlobalBounds() const
{
    return getTransform().transformRect(m_shape.getGlobalBounds());
}
template <>
sf::Color Button<sf::CircleShape>::getFillColor() const
{
    return m_shape.getFillColor();
}
template <>
sf::Color Button<sf::CircleShape>::getOutlineColor() const
{
    return m_shape.getOutlineColor();
}
template <>
const sf::Vector2f& Button<sf::CircleShape>::getPosition() const
{
    return m_shape.getPosition();
}
template <>
std::string Button<sf::CircleShape>::getString() const
{
    return m_text.getString();
}
template <>
const sf::Font* Button<sf::CircleShape>::getFont() const
{
    return m_text.getFont();
}
template <>
sf::Color Button<sf::CircleShape>::getTextFillColor() const
{
    return m_text.getFillColor();
}
template <>
sf::Color Button<sf::CircleShape>::getTextOutlineColor() const
{
    return m_text.getOutlineColor();
}
template <>
bool Button<sf::CircleShape>::getEnabled() const
{
    return m_enabled;
}
















template <>
template <typename C>
void Button<sf::CircleShape>::setRadius(const float& radius)
{
    m_shape.setRadius(radius);
}
template <>
template <typename C>
float Button<sf::CircleShape>::getRadius() const
{
    return m_shape.getRadius();
}













template <>
const bool Button<sf::CircleShape>::contains(const sf::Vector2f& point) const
{
    return getGlobalBounds().contains(point);
}
template <>
void Button<sf::CircleShape>::mouseOver()
{
    m_shape.setOutlineThickness(3.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 150});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 150});
}
template <>
void Button<sf::CircleShape>::mouseLeave()
{
    
    m_shape.setOutlineThickness(0.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 255});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 255});
}
template <>
void Button<sf::CircleShape>::leftClick()
{
    setClicked(!getClicked());
}
template <>
void Button<sf::CircleShape>::rightClick()
{
    std::cout << static_cast<std::string>(m_text.getString()) << " button was right clicked" << std::endl;
}
template <>
void Button<sf::CircleShape>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text);
}







template <>
void Button<sf::CircleShape>::handleMouseButtonPressedEvent(sf::RenderWindow& window, sf::Event event)
{
    
}
template <>
void Button<sf::CircleShape>::handleMouseButtonReleasedEvent(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mouse_pos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    
    if (contains(mouse_pos)) {
        switch (event.mouseButton.button) {
            case sf::Mouse::Left:  leftClick();  break;
            case sf::Mouse::Right: rightClick(); break;
            default: break;
        }
    }
}
template <>
void Button<sf::CircleShape>::handleMouseMoveEvent(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mouse_pos = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
    
    (contains(mouse_pos)) ? mouseOver() : mouseLeave();
}
template <>
void Button<sf::CircleShape>::handleEvent(sf::RenderWindow& window, sf::Event event)
{
    switch (event.type) {
        case sf::Event::MouseButtonPressed:  handleMouseButtonPressedEvent(window, event);  break;
        case sf::Event::MouseButtonReleased: handleMouseButtonReleasedEvent(window, event); break;
        case sf::Event::MouseMoved:          handleMouseMoveEvent(window, event);           break;
        default: break;
    }
}

#endif /* CircleButton */
