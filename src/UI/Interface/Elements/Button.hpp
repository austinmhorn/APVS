//
//  Button.hpp
//  Textbox
//
//  Created by Austin Horn on 1/29/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Button : public sf::Shape
{
public: ///< Main
    
    explicit Button(const sf::Vector2f& radius = {0.f, 0.f}, float pointCount = 30.f);
    
    void setRadius(const sf::Vector2f& radius);
    void setPointCount(float pointCount);
    
    const sf::Vector2f& getRadius() const;
    virtual std::size_t getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;
    
    const bool clicked() const;
    const bool contains(const sf::Vector2f& mousePos) const;

    virtual void mouseOver();
    virtual void mouseLeave();
    virtual void handleEvent(sf::RenderWindow& window, sf::Event event);
    virtual void reset();
        
private: ///< Private data members

    sf::Vector2f m_radius;
    std::size_t  m_pointCount;
    bool         m_clicked;
};


#endif /* Button_hpp */
