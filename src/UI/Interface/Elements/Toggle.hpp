//
//  Toggle.hpp
//  Textbox
//
//  Created by Austin Horn on 1/29/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#ifndef Toggle_hpp
#define Toggle_hpp

#include "UIElement.hpp"
#include "../Shapes/StadiumShape.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class Toggle : public UIElement
{
public:
    
    Toggle(const sf::Vector2f& size = {60.f, 20.f}, bool on = false);
    
    void setSize(const sf::Vector2f& size);
    void setPosition(const sf::Vector2f& pos);
    
    const sf::Vector2f& getSize() const;
    const sf::Vector2f& getPosition() const;
    
    const bool contains(const sf::Vector2f& point) const;
    virtual void mouseOver() override;
    virtual void mouseLeave() override;
    
    virtual void handleEvent(sf::RenderWindow& window, sf::Event event) override;
    virtual void update(sf::Time elapsed) override;
    
private:
    
    void resize();
    void reposition();
    void animate(sf::Time elapsed);
    void animateOn(float elapsed);
    void animateOff(float elapsed);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
private:
    
    sf::StadiumShape m_background;
    sf::CircleShape  m_slider;
    bool             m_on;
    bool             m_clicked;
    sf::Vector2f     m_size;
    sf::Vector2f     m_position;
};

#endif /* Toggle_hpp */
