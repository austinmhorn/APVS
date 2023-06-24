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

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include "../../../Shapes/StadiumShape.hpp"
#include <SFML/Window/Event.hpp>

template <typename T>
class Button : public sf::Shape
{
public:
    
    Button();
    ~Button() override = default;

    Button(const Button&) = default;
    Button& operator=(const Button&) = default;

    Button(Button&&) noexcept = default;
    Button& operator=(Button&&) noexcept = default;
    
    // Mutators
    void setTexture(const sf::Texture*);          ///< Set texture
    void setTextureRect(const sf::IntRect&);      ///< Set texture rectangle
    void setSize(const sf::Vector2f&);            ///< Set size of sf::Shape
    void setFillColor(const sf::Color&);          ///< Set radius of the corners
    void setOutlineColor(const sf::Color&);       ///< Set smoothness of curves (1 - 10)
    void setPosition(const sf::Vector2f&);        ///< Set inside fill color
    void setPosition(const float&, const float&); ///< Set position with a Vector2f
    void setString(const std::string&);           ///< Set position with individual floats
    void setFont(const sf::Font&);                ///< Set string of text
    void setCharacterSize(unsigned int);          ///< Set character size of text
    void setTextFillColor(const sf::Color&);      ///< Set font of text
    void setTextOutlineColor(const sf::Color&);   ///< Set fill color of text
    void setEnabled(const bool&);                 ///< Set outline color of text
    void setClicked(const bool&);                 ///< Set clicked state

    // Accessors
    const sf::Vector2f& getSize() const;             ///< Get size of shape
    sf::Color           getFillColor() const;        ///< Get fill color of shape
    sf::Color           getOutlineColor() const;     ///< Get outline color of shape
    const sf::Vector2f& getPosition() const;         ///< Get position of shape
    std::string         getString() const;           ///< Get text string
    const sf::Font*     getFont() const;             ///< Get text font
    sf::Color           getTextFillColor() const;    ///< Get text fill color
    sf::Color           getTextOutlineColor() const; ///< Get text outline color
    bool                getEnabled() const;          ///< Get is enabled
    sf::FloatRect       getGlobalBounds() const;     ///< Get global bounding rectangle of entity
    const sf::Text&     getText() const;             ///< Get entire text object
    const bool&         getClicked() const;          ///< Determine if button was clicked
    
    // Event Functions
    const bool contains(const sf::Vector2f&) const;      ///< Determine if button contains a point
    void       mouseOver();                               ///< Function for mouse over event
    void       mouseLeave();                              ///< Function for mouse leave event
    void       handleEvent(sf::RenderWindow&, sf::Event); ///< Main event function
    void       reset();                                   ///< Reset button and past click events

public:
    
    // Template functions for sf::StadiumShape button instantiations
    template <typename S>
    void  setCornerRadius(const float&);
    template <typename S>
    void  setAntialiasing(const unsigned int&);
    template <typename S>
    float getCornerRadius() const;
    
    // Template functions for sf::CircleShape button instantiations
    template <typename C>
    void  setRadius(const float&);
    template <typename C>
    float getRadius() const;
    
private:
    
    // Virtually overridden sf::Shape class functions
    virtual std::size_t  getPointCount() const override;
    virtual sf::Vector2f getPoint(std::size_t index) const override;
    
    // Private geometry functions
    void updateTextCoords();
    void update();
    
    // Virtually overridden sf::Drawable class draw function
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;

protected:
    
    T            m_shape;
    sf::Text     m_text;
    bool         m_enabled;
    std::size_t  m_pointCount;
    bool         m_clicked;
    std::uint8_t m_antialiasing;
};

typedef Button<sf::StadiumShape>   StadiumButton;
typedef Button<sf::CircleShape>    CircleButton;
typedef Button<sf::RectangleShape> RectButton;


#endif /* Button_hpp */
