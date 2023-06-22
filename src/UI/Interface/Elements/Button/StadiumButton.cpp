//
//  StadiumButton.cpp
//  War
//
//  Created by Austin Horn on 12/2/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef StadiumButton_cpp
#define StadiumButton_cpp

#include "Base/Button.hpp"

template <>
void Button<sf::StadiumShape>::updateTextCoords()
{
    sf::FloatRect shape_rect = m_shape.getGlobalBounds();
    sf::FloatRect text_rect = m_text.getGlobalBounds();
    
    float x = shape_rect.left+(shape_rect.width/2.f)-(text_rect.width/2.f);
    float y = shape_rect.top+(shape_rect.height/2.f)-(m_text.getCharacterSize()/2.f);
    
    m_text.setPosition(x, y);
}
template <>
void Button<sf::StadiumShape>::update()
{
    m_shape.StadiumShape::update();
    this->updateTextCoords();
}
template <>
Button<sf::StadiumShape>::Button(const sf::StadiumShape& stadium, const sf::Text& text) :
m_shape(stadium),
m_text(text)
{
    m_text.setFillColor(sf::Color::Black);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setTextureRect(const sf::IntRect& rect)
{
    m_shape.setTextureRect(rect);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setTexture(const sf::Texture* texture)
{
    m_shape.setTexture(texture);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setSize(const sf::Vector2f& size)
{
    m_shape.setSize(size);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setFillColor(const sf::Color& color)
{
    m_shape.setFillColor(color);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setOutlineColor(const sf::Color& color)
{
    m_shape.setOutlineColor(color);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setPosition(const sf::Vector2f& position)
{
    m_shape.setPosition(position);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setPosition(const float& x, const float& y)
{
    m_shape.setPosition(x, y);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setString(const std::string& string)
{
    m_text.setString(string);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setFont(const sf::Font& font)
{
    m_text.setFont(font);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setCharacterSize(unsigned int size)
{
    m_text.setCharacterSize(size);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setTextFillColor(const sf::Color& color)
{
    m_text.setFillColor(color);
    this->update();
}
template <>
void Button<sf::StadiumShape>::setTextOutlineColor(const sf::Color& color)
{
    m_text.setOutlineColor(color);
    this->update();
}





template <>
const sf::Vector2f& Button<sf::StadiumShape>::getSize() const
{
    return m_shape.getSize();
}
template <>
sf::FloatRect Button<sf::StadiumShape>::getGlobalBounds() const
{
    return getTransform().transformRect(m_shape.getGlobalBounds());
}
template <>
const sf::Text& Button<sf::StadiumShape>::getText() const
{
    return m_text;
}
template <>
sf::Color Button<sf::StadiumShape>::getFillColor() const
{
    return m_shape.getFillColor();
}
template <>
sf::Color Button<sf::StadiumShape>::getOutlineColor() const
{
    return m_shape.getOutlineColor();
}
template <>
const sf::Vector2f& Button<sf::StadiumShape>::getPosition() const
{
    return m_shape.getPosition();
}
template <>
std::string Button<sf::StadiumShape>::getString() const
{
    return m_text.getString();
}
template <>
const sf::Font* Button<sf::StadiumShape>::getFont() const
{
    return m_text.getFont();
}
template <>
sf::Color Button<sf::StadiumShape>::getTextFillColor() const
{
    return m_text.getFillColor();
}
template <>
sf::Color Button<sf::StadiumShape>::getTextOutlineColor() const
{
    return m_text.getOutlineColor();
}
template <>
bool Button<sf::StadiumShape>::getEnabled() const
{
    return m_enabled;
}















template <>
template <typename S>
void Button<sf::StadiumShape>::setCornerRadius(const float& radius)
{
    m_shape.setCornersRadius(radius);
    this->update();
}
template <>
template <typename S>
void Button<sf::StadiumShape>::setAntialiasing(const unsigned int& quality)
{
    m_shape.setAntialiasing(quality);
    this->update();
}
template <>
template <typename S>
float Button<sf::StadiumShape>::getCornerRadius() const
{
    return m_shape.getCornersRadius();
}









template <>
const bool Button<sf::StadiumShape>::contains(const sf::Vector2f& point) const
{
    return getGlobalBounds().contains(point);
}
template <>
void Button<sf::StadiumShape>::mouseOver()
{
    m_shape.setOutlineThickness(3.f);
    m_shape.setTranslucent(true);
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 150});
}
template <>
void Button<sf::StadiumShape>::mouseLeave()
{
    
    m_shape.setOutlineThickness(0.f);
    m_shape.setTranslucent(false);
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 255});
}
template <>
void Button<sf::StadiumShape>::leftClick()
{
    setClicked(!getClicked());
}
template <>
void Button<sf::StadiumShape>::rightClick()
{
    std::cout << static_cast<std::string>(m_text.getString()) << " button was right clicked" << std::endl;
}
template <>
void Button<sf::StadiumShape>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text);
}







template <>
void Button<sf::StadiumShape>::handleMouseButtonPressedEvent(sf::RenderWindow& window, sf::Event event)
{
    
}
template <>
void Button<sf::StadiumShape>::handleMouseButtonReleasedEvent(sf::RenderWindow& window, sf::Event event)
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
void Button<sf::StadiumShape>::handleMouseMoveEvent(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mouse_pos = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
    
    (contains(mouse_pos)) ? mouseOver() : mouseLeave();
}
template <>
void Button<sf::StadiumShape>::handleEvent(sf::RenderWindow& window, sf::Event event)
{
    switch (event.type) {
        case sf::Event::MouseButtonPressed:  handleMouseButtonPressedEvent(window, event);  break;
        case sf::Event::MouseButtonReleased: handleMouseButtonReleasedEvent(window, event); break;
        case sf::Event::MouseMoved:          handleMouseMoveEvent(window, event);           break;
        default: break;
    }
}

#endif /* StadiumButton_cpp */
