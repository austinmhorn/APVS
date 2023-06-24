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
Button<sf::StadiumShape>::Button()
    : m_shape(sf::StadiumShape{})
    , m_text(sf::Text{})
    , m_enabled(true)
    , m_pointCount(30)
    , m_clicked(false)
    , m_antialiasing(8)
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
void Button<sf::StadiumShape>::setEnabled(const bool& enabled)
{
    m_enabled = enabled;
}
template <>
void Button<sf::StadiumShape>::setClicked(const bool& clicked)
{
    m_clicked = clicked;
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
const bool& Button<sf::StadiumShape>::getClicked() const
{
    return m_clicked;
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
void Button<sf::StadiumShape>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text);
}







template <>
void Button<sf::StadiumShape>::handleEvent(sf::RenderWindow& window, sf::Event event)
{
    const auto mouse_button_pos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    const auto mouse_move_pos = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
    
    switch (event.type)
    {
        case sf::Event::MouseMoved:
            contains(mouse_move_pos) ? mouseOver() : mouseLeave();
            break;
            
        case sf::Event::MouseButtonPressed:
            if (contains(mouse_button_pos))
                setClicked( !getClicked() );
                
            break;
        default:
            break;
    }
}

template <>
void Button<sf::StadiumShape>::reset()
{
    m_clicked = false;
}

template <>
std::size_t Button<sf::StadiumShape>::getPointCount() const
{
    return m_shape.getPointCount();
}

template <>
sf::Vector2f Button<sf::StadiumShape>::getPoint(std::size_t index) const
{
    return m_shape.getPoint(index);
}

#endif /* StadiumButton_cpp */
