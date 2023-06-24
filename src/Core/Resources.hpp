//
//  Resources.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Assets_hpp
#define Assets_hpp

#include <iostream> // std::cin, std::cout
#include <new>      // std::bad_alloc
#include <cmath>    // std::ceil, std::log
#include <map>

#include <SFML/Graphics.hpp>

#ifndef PROJECT_NAME
#define PROJECT_NAME "APVS"

static const std::basic_string<char> __filepath_icon      = "src/Assets/icon.png";
static const std::basic_string<char> __filepath_Sansation = "src/Assets/Fonts/sansation.ttf";
static const std::basic_string<char> __filepath_NeonLED   = "src/Assets/Fonts/neonled.otf";

static sf::Image icon_init()
{
    static sf::Image icon;
    assert(icon.loadFromFile("src/Assets/icon.png"));
    return icon;
}



////////////////////////////////////////////////////////////
/// \namespace Fonts
///
/// \brief
////////////////////////////////////////////////////////////
namespace Fonts {

    enum class FontType : unsigned {
        Sansation = 0,
        NeonLED   = 1,
        
        ///< Keep last -- the total number of Fonts
        FontCount = 2
    };

    static const sf::Font __init_Sansation() {
        static sf::Font font;
        if(!font.loadFromFile(__filepath_Sansation))
            std::exit( EXIT_FAILURE );
        return font;
    }
    static const sf::Font __init_NeonLED() {
        static sf::Font font;
        if(!font.loadFromFile(__filepath_NeonLED))
            std::exit( EXIT_FAILURE );
        return font;
    }

} // MARK: End of namespace 'Font'




////////////////////////////////////////////////////////////
/// \namespace Textures
///
/// \brief
////////////////////////////////////////////////////////////
namespace Textures {
/*
     static const std::basic_string<char> path_to_texture = "filepath/to/texture.png";

     static sf::Texture init_texture() {
        static sf::Texture texture;
        try {
            if ( !texture.loadFromFile(path_to_texture) )
                throw std::runtime_error("Failed loading texture " + path_to_texture);
        }
        catch(const std::runtime_error &e) {
            std::cerr << "std::runtime_error::what(): " << e.what() << std::endl;
        }
        return texture;
    }
*/
} // MARK: End of namespace 'Textures'



struct Resources
{
    static const sf::Font Sansation;
    static const sf::Font NeonLED;
    
    static const sf::Color Gray;
    static const sf::Color DarkGreen;
    static const sf::Color DarkRed;
    static const sf::Color DarkPurple;
    static const sf::Color LightBlue;
    static const sf::Color Seafoam;
    static const sf::Color LightGreen;
    static const sf::Color Peach;
    static const sf::Color Tan;
    static const sf::Color Pink;
    static const sf::Color LightPurple;
    static const sf::Color Orange;
    static const sf::Color DarkBlue;
    
    sf::Cursor HandCursor;
    sf::Cursor ArrowCursor;
    sf::Cursor TextCursor;
    sf::Cursor CrossCursor;
    sf::Cursor HelpCursor;
            
};

#endif /* PROJECT_NAME */

#endif /* Assets_hpp */
