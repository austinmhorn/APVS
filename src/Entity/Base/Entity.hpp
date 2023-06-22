//
//  Entity.hpp
//  War
//
//  Created by Austin Horn on 12/1/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>
#pragma once

///////////////////////////////////////////////////////////////////////////
/// \class Entity
///
/// \brief Base class representing drawables (sf::Shape, sf::Sprite, etc.)
///////////////////////////////////////////////////////////////////////////
class Entity : public sf::Transformable, public sf::Drawable {
protected:
    
    Entity() = default;
    ~Entity() override = default;
    
    Entity(const Entity&) = default;
    Entity& operator=(const Entity&) = default;
    
    Entity(Entity&&) noexcept = default;
    Entity& operator=(Entity&&) noexcept = default;
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
    
};

#endif /* Entity_hpp */
