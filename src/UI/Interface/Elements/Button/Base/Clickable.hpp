//
//  Clickable.hpp
//  War
//
//  Created by Austin Horn on 12/1/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Clickable_hpp
#define Clickable_hpp

#include "../../../../../Entity/Base/Entity.hpp"
#pragma once

///////////////////////////////////////////////////////////////////////////
///< \class Clickable
///< 
///< \brief
///////////////////////////////////////////////////////////////////////////
class Clickable : public Entity {
protected:
    
    bool m_clicked;
    
    Clickable() : m_clicked(false) {}
    
public:

    void setClicked(bool clicked) { m_clicked = clicked; }
    bool getClicked() const { return m_clicked; }
    
    virtual const bool contains(const sf::Vector2f&) const = 0;
    virtual void mouseOver() = 0;
    virtual void mouseLeave() = 0;
    virtual void leftClick() = 0;
    virtual void rightClick() = 0;
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

#endif /* Clickable_hpp */
