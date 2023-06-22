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


static const std::basic_string<char> __filepath_icon      = "src/Assets/icon.png";
static const std::basic_string<char> __filepath_Sansation = "src/Assets/Fonts/sansation.ttf";




static sf::Image icon_init() {
    static sf::Image icon;
    std::cout << "Loading icon" << std::endl;
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
        
        ///< Keep last -- the total number of Fonts
        FontCount = 1
    };

    static const sf::Font __init_Sansation() {
        static sf::Font font;
        if(!font.loadFromFile(__filepath_Sansation))
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


#endif /* Assets_hpp */







































/*
static std::basic_string<unsigned> gen_alpha_num_id() {
    std::mt19937 gen32;
    std::mt19937_64 gen64;
    
    for (auto n{1}; n != 10'000; gen32(), gen64(), ++n)
        assert(gen32() == 4'123'659'995 and gen64() == 9'981'545'732'273'789'042ULL);
    
    std::uniform_int_distribution<> num_distrib(48, 57);
    std::uniform_int_distribution<> uppcase_distrib(65, 90);
    std::uniform_int_distribution<> lowcase_distrib(97, 122);
    
    std::basic_string<unsigned> s;
    s.resize(19);
    
    for(auto& c : s)
    {
        std::cout << "+" << std::endl;
    }
    
    dlist<std::int_fast8_t> id;
    
    for (int i=0; i<19; i++)
    {
        
        auto *newNode = id.getNewNode(i);
        std::int_fast8_t n = num_distrib(gen64);
        
        id.insert(n);
    }
}
 // reddit funny names

 // 48 - 57
 // 65 - 90
 // 97 - 122
 */
/*
 
 namespace Colors {
     enum Color {
         Gray        = 0,        ///< Gray color
         DarkGreen   = 1,        ///< Dark Green color
         DarkRed     = 2,        ///< Dark Red color
         DarkPurple  = 3,        ///< Dark Purple color
         LightBlue   = 4,        ///< Light Blue color
         Seafoam     = 5,        ///< Seafoam color
         LightGreen  = 6,        ///< Light Green color
         Peach       = 7,        ///< Peach color
         Tan         = 8,        ///< Tan color
         Pink        = 9,        ///< Pink color
         LightPurple = 10,       ///< Light Purple color
         Orange      = 11,       ///< Orange color
         DarkBlue    = 12,       ///< Dark Blue Color
         
         ///< Keep last -- the total number of Colors
         ColorCount = 13
     };

     static std::map<Color, const char*> colorMap;
     static void _init_color_nomenclature() {
         maps::primitive_type_map_init(colorMap)
             (Colors::Color::Gray, "Gray")
             (Colors::Color::DarkGreen, "DarkGreen")
             (Colors::Color::DarkRed, "DarkRed")
             (Colors::Color::DarkPurple, "DarkPurple")
             (Colors::Color::LightBlue, "LightBlue")
             (Colors::Color::Seafoam, "Seafoam")
             (Colors::Color::LightGreen, "LightGreen")
             (Colors::Color::Peach, "Peach")
             (Colors::Color::Tan, "Tan")
             (Colors::Color::Pink, "Pink")
             (Colors::Color::LightPurple, "LightPurple")
             (Colors::Color::Orange, "Orange")
             (Colors::Color::DarkBlue, "DarkBlue")
         ;
     }
 }
 */
