//
//  Utility.cpp
//  sfmlMac
//
//  Created by Alexis Louis on 23/12/2015.
//  Copyright © 2015 Alexis Louis. All rights reserved.
//

#include "Utility.hpp"

sf::Text text;
sf::Font font;
sf::Text simpleText(std::string str,int xOrigin, int yOrigin, int charSize){

    font.loadFromFile("/Library/Fonts/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(charSize);
    text.setOrigin(-xOrigin, -yOrigin);
    text.setString(str);
    
    return text;
}