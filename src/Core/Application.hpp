//
//  Application.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Application_hpp
#define Application_hpp

#include "State/Base/StateMachine.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

#include "Resources.hpp"

class Application
{
public:
    
    void run();
    void loadResources();

private:
    
    StateMachine     m_machine;
    sf::RenderWindow m_window;
    Resources        m_resources;
};


#endif /* Application_hpp */
