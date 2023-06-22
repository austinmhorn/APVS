#ifndef Textbox_hpp
#define Textbox_hpp

#include "ResourcePath.hpp"
#include "UIElement.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include <cctype>
#include <iostream>

class Textbox : public UIElement
{
public:
        
    Textbox();
        
    void setSize(const sf::Vector2f& size);
    void setPosition(const sf::Vector2f& position);
    void setFocus(bool focus);
    
    const sf::Vector2f& getSize() const;
    const sf::Vector2f& getPosition() const;
    const bool hasFocus() const;
    
    const bool contains(const sf::Vector2f point) const;
    void processKey(sf::Uint32 unicode);
    
    virtual void mouseOver() override;
    virtual void mouseLeave() override;
    virtual void handleEvent(sf::RenderWindow& window, sf::Event event) override;
    virtual void update(sf::Time elapsed) override;
    
    std::string clear();
    
private:
    
    void updateText(sf::Time elapsed);
    void positionText();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
private:
    
    sf::RectangleShape m_rect;
    std::string        m_input;
    sf::Text           m_text;
    sf::Font           m_font;
    bool               m_focus;
    sf::Time           m_timer;
};

#endif /* Textbox_hpp */
