//
//  UIElement.hpp
//  Textbox
//
//  Created by Austin Horn on 1/29/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#ifndef UIElement_hpp
#define UIElement_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

class UIElement : public sf::Transformable, public sf::Drawable
{
protected:
        
    UIElement() = default;
    ~UIElement() override = default;

    UIElement(const UIElement&) = default;
    UIElement& operator=(const UIElement&) = default;
    
    UIElement(UIElement&&) noexcept = default;
    UIElement& operator=(UIElement&&) noexcept = default;
    
    virtual void mouseOver() = 0;
    virtual void mouseLeave() = 0;
    virtual void handleEvent(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update(sf::Time elapsed) = 0;
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

#endif /* UIElement_hpp */
