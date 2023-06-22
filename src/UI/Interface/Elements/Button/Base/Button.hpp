//
//  Button.hpp
//  War
//
//  Created by Austin Horn on 12/1/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <iostream>
#include <cmath>

#include "Clickable.hpp"
#pragma once
#include "../../../Shapes/StadiumShape.hpp"
#pragma once
#include "../../../Shapes/ConvexShape.hpp"
#pragma once
#include "../../../Shapes/RoundedRectangleShape.hpp"
#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#pragma once
#include <SFML/Graphics/ConvexShape.hpp>
#pragma once
#include <SFML/Window/Event.hpp>
#pragma once

template <typename T>
class Button : public Clickable {
public:
    
    // Default Constructor
    explicit Button(const T&, const sf::Text&);
    
    // Mutators
    void setTexture(const sf::Texture* texture);
    void setTextureRect(const sf::IntRect& rect);
    void setSize(const sf::Vector2f&);     ///< Set size of sf::Shape
    void setFillColor(const sf::Color&);          ///< Set the radius of the corners
    void setOutlineColor(const sf::Color&);       ///< Sets smoothness of curves (1 - 10)
    void setPosition(const sf::Vector2f&); ///< Set inside fill color
    void setPosition(const float&, const float&);        ///< Set position with a Vector2f
    void setString(const std::string&);           ///< Set position with float values
    void setFont(const sf::Font&);                ///< Set string of text
    void setCharacterSize(unsigned int);
    void setTextFillColor(const sf::Color&);      ///< Set font of text
    void setTextOutlineColor(const sf::Color&);   ///< Set fill color of text
    void setEnabled(const bool&);                 ///< Set outline color of text
    
    // Accessors
    const sf::Vector2f& getSize() const;             ///<
    sf::Color           getFillColor() const;        ///<
    sf::Color           getOutlineColor() const;     ///<
    const sf::Vector2f& getPosition() const;         ///<
    std::string         getString() const;           ///<
    const sf::Font*     getFont() const;             ///<
    sf::Color           getTextFillColor() const;    ///<
    sf::Color           getTextOutlineColor() const; ///<
    bool                getEnabled() const;          ///<
    sf::FloatRect       getGlobalBounds() const;     ///<
    const sf::Text&     getText() const;             ///<

    // Overridden Virtual Functions
    const bool contains(const sf::Vector2f&) const override;
    void       mouseOver() override;
    void       mouseLeave() override;
    void       leftClick() override;
    void       rightClick() override;
    
    // Event Functions
    void handleMouseButtonPressedEvent(sf::RenderWindow&, sf::Event);
    void handleMouseButtonReleasedEvent(sf::RenderWindow&, sf::Event);
    void handleMouseMoveEvent(sf::RenderWindow&, sf::Event);
    void handleEvent(sf::RenderWindow&, sf::Event);
    
public:
    
    template <typename S>
    void  setCornerRadius(const float&);
    template <typename S>
    void  setAntialiasing(const unsigned int&);
    template <typename S>
    float getCornerRadius() const;
    
    template <typename C>
    void  setRadius(const float&);
    template <typename C>
    float getRadius() const;
    
private:
    
    void updateTextCoords();
    void update();
    void draw(sf::RenderTarget&, sf::RenderStates) const override;

protected:
    
    T        m_shape;
    sf::Text m_text;
    bool     m_enabled;
    
};

typedef Button<sf::StadiumShape>          StadiumButton;
typedef Button<sf::CircleShape>           CircleButton;
typedef Button<sf::RectangleShape>        RectButton;
//typedef Button<sf::ConvexShape>           ConvexButton;
//typedef Button<sf::RoundedRectangleShape> RoundRectButton;

#endif /* Button_hpp */
