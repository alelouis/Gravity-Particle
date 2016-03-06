//
//  Projectile.hpp
//  sfmlMac
//
//  Created by Alexis Louis on 22/12/2015.
//  Copyright © 2015 Alexis Louis. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include <stdio.h>
#include <Header.h>

class Projectile
{
public:
    Projectile();
    Projectile(float x, float y, float ox, float oy, float ax, float ay);
    
    float getX(){return pos.x;};
    float getY(){return pos.y;};
    float getoX(){return opos.x;};
    float getoY(){return opos.y;};
    float getaox(){return acc.x;};
    float getay(){return acc.y;};
    bool isTrailed(){return trail;};
    void setPos(float x, float y);
    void setOldPos(float x, float y);
    //void setVel(float x, float y);
    void setAcc(float x, float y);
    void update(float dt);
    void HandleCollision();
    void addTrail();
    void delTrail();
    void updateTrail(int nbPoint);
    std::deque<sf::CircleShape*> getTrail(){return trailDraw;};
    
private:
    sf::Vector2f pos, opos, acc;
    bool trail;
    std::deque<sf::CircleShape*> trailDraw;
};

#endif /* Projectile_hpp */
