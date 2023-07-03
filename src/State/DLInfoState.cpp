//
//  DLInfoState.cpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "DLInfoState.hpp"
#include "PatientInfoState.hpp"
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
    
    m_valid_input = false;
    
    m_header = sf::Text{"Enter Drivers License Information", m_resources.Sansation, 45};
    m_header.setPosition(window_size.x/2.f - m_header.getGlobalBounds().width/2.f, m_header.getGlobalBounds().height + 10.f);
        
    // Fill the background with Gray
    m_background.setFillColor({100u, 100u, 100u});
    m_background.setSize(window_size);
    
    // Init License Number Texbox
    auto pos = sf::Vector2f{window_size.x/2.f - m_license_textbox.getSize().x/2.f,
                            window_size.y/2.f - m_license_textbox.getSize().y/2.f - 60.f};
    m_license_textbox.setPosition(pos);
    m_license_textbox.setOutlineColor(sf::Color::White);
    m_license_textbox.setTextFillColor(sf::Color::White);
    m_license_textbox.setDescriptionSide(Textbox::Side::Top);
    m_license_textbox.setDescriptionString("License Number");
    m_license_textbox.setDescriptionCharacterSize(20);
    m_license_textbox.setDescriptionFillColor(sf::Color::Yellow);
    
    // Init License Expiration Texbox
    pos = sf::Vector2f{window_size.x/2.f - m_exp_textbox.getSize().x/2.f,
                       window_size.y/2.f - m_exp_textbox.getSize().y/2.f + 60.f};
    m_exp_textbox.setPosition(pos);
    m_exp_textbox.setOutlineColor(sf::Color::White);
    m_exp_textbox.setTextFillColor(sf::Color::White);
    m_exp_textbox.setDescriptionSide(Textbox::Side::Top);
    m_exp_textbox.setDescriptionString("Expiration Date");
    m_exp_textbox.setDescriptionCharacterSize(20);
    m_exp_textbox.setDescriptionFillColor(sf::Color::Yellow);
    
    // Fill the Continue button with yellow
    m_continue.setFillColor({255u, 233u, 0u});
    m_continue.setPosition({window_size.x/2.f - m_continue.getSize().x/2.f, window_size.y - m_continue.getSize().y - 20.f});
    m_continue.setString("Continue");
    m_continue.setFont(resources.Sansation);
    m_continue.setCharacterSize(30);
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
        
        m_continue.handleEvent(m_window, event);
        m_license_textbox.handleEvent(m_window, event);
        m_exp_textbox.handleEvent(m_window, event);
        
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
                
                break;
                
            case sf::Event::KeyPressed:
                break;
                
            case sf::Event::TextEntered:
                if ( m_license_textbox.hasFocus() )
                {
                    if (event.key.code == 10) // New Line
                        std::cout << m_license_textbox.clear() << std::endl;
                    else
                        m_license_textbox.processKey(event.key.code);
                }
                else if ( m_exp_textbox.hasFocus() )
                {
                    if (event.key.code == 10) // New Line
                        std::cout << m_exp_textbox.clear() << std::endl;
                    else
                        m_exp_textbox.processKey(event.key.code);
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
    
    m_valid_input = ( m_license_textbox.getInputString().size() && m_exp_textbox.getInputString().size() );
    
    if ( m_valid_input )
    {
        
        if ( m_continue.getClicked() )
        {
            
        }
    }
    
    m_license_textbox.update(delta_time);
    m_exp_textbox.update(delta_time);
}

void DLInfoState::draw()
{
    m_window.clear();
    
    m_window.draw(m_background);
    m_window.draw(m_header);
    m_window.draw(m_license_textbox);
    m_window.draw(m_exp_textbox);
    m_window.draw(m_continue);

    m_window.display();
}


