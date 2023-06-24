//
//  IntroState.cpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "IntroState.hpp"
#include "Base/StateMachine.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "../Core/Resources.hpp"

#include <iostream>
#include <memory>

IntroState::IntroState(StateMachine& machine, sf::RenderWindow& window, Resources& resources, const bool replace)
    : State{ machine, window, resources, replace }
    , m_alpha{ 0, 0, 0, 255 }
{
    const auto window_size = sf::Vector2f{ window.getSize() };
    
    // Fill the background with Gray
    m_background.setFillColor({100u, 100u, 100u});
    m_background.setSize(window_size);
    
    // Fill the fader surface with black
    m_fader.setFillColor(m_alpha);
    m_fader.setSize(window_size);
    
    // Initialize title
    m_title.setFont(resources.NeonLED);
    m_title.setString(PROJECT_NAME);
    m_title.setCharacterSize(90);
    m_title.setPosition({ window_size.x/2.f - m_title.getGlobalBounds().width/2.f, 50.f});
    
    // Initialize title description
    m_description.setFont(resources.Sansation);
    m_description.setString("Automated Prescription Vendor System");
    m_description.setCharacterSize(20);
    m_description.setPosition({ window_size.x/2.f - m_description.getGlobalBounds().width/2.f, m_title.getGlobalBounds().top + m_title.getGlobalBounds().height + 5.f});
    
    // Fill the Pick Up button with baby blue
    m_pick_up_button.setFillColor({91u, 197u, 246u});
    m_pick_up_button.setPosition({window_size.x/2.f - m_pick_up_button.getSize().x - 20.f, window_size.y/1.5f});
    m_pick_up_button.setString("Pick Up");
    m_pick_up_button.setFont(resources.Sansation);
    m_pick_up_button.setCharacterSize(30);
    
    // Fill the Drop Off button with light green
    m_drop_off_button.setFillColor({100u, 196u ,102u});
    m_drop_off_button.setPosition({window_size.x/2.f + 20.f, window_size.y/1.5f});
    m_drop_off_button.setString("Drop Off");
    m_drop_off_button.setFont(resources.Sansation);
    m_drop_off_button.setCharacterSize(30);
}

void IntroState::pause()
{
    //std::cout << "IntroState Pause" << std::endl;;
}

void IntroState::resume()
{
    //std::cout << "IntroState Resume" << std::endl;;
}

void IntroState::handleEvent()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        m_pick_up_button.handleEvent(m_window, event);
        m_drop_off_button.handleEvent(m_window, event);
        
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
                break;
                
            case sf::Event::KeyPressed:
                break;
                
            case sf::Event::TextEntered:
                break;
                
            default:
                break;
        }
    }
}

void IntroState::update()
{
    static const auto clock = sf::Clock{};
    static auto last_frame_time = sf::Time{};
    const auto delta_time = clock.getElapsedTime() - last_frame_time;
    last_frame_time = clock.getElapsedTime();
    
    handleEvent();
    
    if (m_pick_up_button.getClicked())
        m_next = StateMachine::build<DLInfoState>(m_machine, m_window, m_resources);

    if (m_alpha.a != 0) {
        m_alpha.a--;
        
        if (m_alpha.a != 0)
            m_alpha.a--;
    }

    m_fader.setFillColor(m_alpha);
}

void IntroState::draw()
{
    m_window.clear();
    
    m_window.draw(m_background);
    
    m_window.draw(m_title);
    m_window.draw(m_description);
    
    m_window.draw(m_pick_up_button);
    m_window.draw(m_drop_off_button);
    
    if (m_alpha.a != 0)
        m_window.draw(m_fader);

    m_window.display();
}

