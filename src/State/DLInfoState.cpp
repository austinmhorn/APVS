//
//  DLInfoState.cpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "DLInfoState.hpp"
#include "Base/StateMachine.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "../Core/Resources.hpp"

#include <iostream>
#include <memory>

DLInfoState::DLInfoState(StateMachine& machine, sf::RenderWindow& window, Resources& resources, const bool replace)
    : State{ machine, window, resources, replace }
{
    const auto window_size = sf::Vector2f{ window.getSize() };
    
    // Fill the background with Gray
    m_background.setFillColor({100u, 100u, 100u});
    m_background.setSize(window_size);
    
    auto pos = sf::Vector2f{window_size.x/2.f - m_drivers_license_box.getSize().x/2.f,
                            window_size.y/2.f - m_drivers_license_box.getSize().y/2.f};
    m_drivers_license_box.setPosition(pos);
}

void DLInfoState::pause()
{
    //std::cout << "DLInfoState Pause" << std::endl;;
}

void DLInfoState::resume()
{
    //std::cout << "DLInfoState Resume" << std::endl;;
}

void DLInfoState::handleEvent()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        
        switch (event.type)
        {
            case sf::Event::Closed:
                m_machine.quit();
                break;
                
            case sf::Event::MouseMoved:
                ///< Get new mouse position
                m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
                                    
                break;
                
            case sf::Event::MouseButtonPressed:
                ///< Get location for mouse button press event
                m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                break;
                
            case sf::Event::MouseButtonReleased:
                ///< Get location for mouse button release event
                m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                
                ///< Set focus to Textbox if clicked
                m_drivers_license_box.contains(m_current_mouse_position)
                    ? m_drivers_license_box.setFocus(true)
                    : m_drivers_license_box.setFocus(false);
                
                break;
                
            case sf::Event::KeyPressed:
                break;
                
            case sf::Event::TextEntered:
                if (m_drivers_license_box.hasFocus())
                {
                    if (event.key.code == 10) // New Line
                        std::cout << m_drivers_license_box.clear() << std::endl;
                    else
                        m_drivers_license_box.processKey(event.key.code);
                }
                break;
                
            default:
                break;
        }
    }
    


}

void DLInfoState::update()
{
    static const auto clock = sf::Clock{};
    static auto last_frame_time = sf::Time{};
    const auto delta_time = clock.getElapsedTime() - last_frame_time;
    last_frame_time = clock.getElapsedTime();
    
    handleEvent();

    m_drivers_license_box.update(delta_time);
}

void DLInfoState::draw()
{
    m_window.clear();
    
    m_window.draw(m_background);
    
    m_window.draw(m_drivers_license_box);

    m_window.display();
}


