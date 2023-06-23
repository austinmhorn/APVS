//
//  Toggle.cpp
//  Textbox
//
//  Created by Austin Horn on 1/29/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "Toggle.hpp"

#include <iostream>
#include <cmath>

#define PADDING 2.f

Toggle::Toggle(const sf::Vector2f& size, bool on)
    : m_background(size, size.y/2)
    , m_slider((size.y/2)-PADDING)
    , m_on(on)
    , m_clicked(false)
    , m_size(size)
    , m_position()
{
    if (m_on)
        m_background.setFillColor({151, 193, 169});
    else
        m_background.setFillColor({37, 37, 37});
    
    m_background.setOutlineColor({255, 255, 255}); // White
    m_background.setOutlineThickness(1.f);
    
    m_slider.setFillColor({255, 255, 255});
    
    reposition();
}
void Toggle::setSize(const sf::Vector2f& size)
{
    m_size = size;
    resize();
    reposition();
}
void Toggle::setPosition(const sf::Vector2f& pos)
{
    m_position = pos;
    reposition();
}
const sf::Vector2f& Toggle::getSize() const
{
    return m_background.getSize();
}
const sf::Vector2f& Toggle::getPosition() const
{
    return m_background.getPosition();
}
const bool Toggle::contains(const sf::Vector2f& point) const
{
    return getTransform().transformRect(m_background.getGlobalBounds()).contains(point);
}
void Toggle::mouseOver()
{
    m_slider.setFillColor({m_slider.getFillColor().r, m_slider.getFillColor().g, m_slider.getFillColor().b, 150});
}
void Toggle::mouseLeave()
{
    m_slider.setFillColor({m_slider.getFillColor().r, m_slider.getFillColor().g, m_slider.getFillColor().b, 255});
}
void Toggle::handleEvent(sf::RenderWindow& window, sf::Event event)
{
    static sf::Vector2f mouse_pos;
    
    if (event.type == sf::Event::MouseMoved)
    {
        mouse_pos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
        contains(mouse_pos) ? mouseOver() : mouseLeave();
    }
    if (event.type == sf::Event::MouseButtonReleased && contains(mouse_pos))
    {
        m_clicked = true;
    }
}
void Toggle::update(sf::Time elapsed)
{
    if (m_clicked)
        animate(elapsed);
}
void Toggle::resize()
{
    m_background.setSize(m_size);
    m_background.setCornersRadius(m_size.y/2);
    m_slider.setRadius((m_size.y/2)-PADDING);
}
void Toggle::reposition()
{
    ///< Move background
    m_background.setPosition(m_position);
    m_slider.setPosition(m_position.x+PADDING, m_position.y+PADDING);
}
void Toggle::animate(sf::Time elapsed)
{
    // Determine animation
    m_on ? animateOff(elapsed.asSeconds()) : animateOn(elapsed.asSeconds());
        
    // Set status complement
    m_on = !m_on;
    
    // Set to un-clicked
    m_clicked = false;
    
    // Recolor background stadium shape in correspondence with current status
    m_on ? m_background.setFillColor({151, 193, 169}) : m_background.setFillColor({37, 37, 37});
}
void Toggle::animateOn(float elapsed)
{
    const float x_final = m_position.x + m_background.getGlobalBounds().width - (2*m_slider.getRadius()) - (2*PADDING);
    //std::cout << x_final << std::endl;
    while (m_slider.getPosition().x < x_final)
        m_slider.move(elapsed, 0.f);
}
void Toggle::animateOff(float elapsed)
{
    const float x_final = m_position.x+PADDING;
    //std::cout << x_final << std::endl;
    while (m_slider.getPosition().x > x_final )
        m_slider.move(-elapsed, 0.f);
}
void Toggle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background);
    target.draw(m_slider);
}
