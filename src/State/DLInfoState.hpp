//
//  DLInfoState.hpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#ifndef DLInfoState_hpp
#define DLInfoState_hpp

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Base/State.hpp"

#include "../UI/Interface/Elements/Textbox/Textbox.hpp"
#include "../UI/Interface/Elements/Button/Base/Button.hpp"

struct Resources;

class DLInfoState final : public State
{
public:
    DLInfoState(StateMachine& machine, sf::RenderWindow& window, Resources& resources, const bool replace = true);

    void pause() override;
    void resume() override;
    void handleEvent() override;
    void update() override;
    void draw() override;
    
private:
    
    sf::RectangleShape m_background;
    sf::Vector2f       m_current_mouse_position;
    
    sf::Text      m_header;
    Textbox       m_license_textbox;
    Textbox       m_exp_textbox;
    StadiumButton m_continue;
    bool          m_valid_input;
};


#endif /* DLInfoState_hpp */

