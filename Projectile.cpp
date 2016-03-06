//
//  Projectile.cpp
//  sfmlMac
//
//  Created by Alexis Louis on 22/12/2015.
//  Copyright © 2015 Alexis Louis. All rights reserved.
//

#include "Projectile.hpp"
#include <iostream>

Projectile::Projectile(){
    setPos(0,0);
    setAcc(0,0);
    trail = false;
}

Projectile::Projectile(float x, float y, float ox, float oy, float ax, float ay){
    setPos(x,y);
    setOldPos(ox,oy);
    setAcc(ax,ay);
    trail = true;
    std::deque<sf::CircleShape*> trailDraw;
}

void Projectile::setPos(float x, float y){
    pos.x = x;
    pos.y = y;
}

void Projectile::setOldPos(float x, float y){
    opos.x = x;
    opos.y = y;
}


void Projectile::setAcc(float x, float y){
    acc.x = x;
    acc.y = y;
}

void Projectile::update(float dt){
    sf::Vector2f temp = pos;
    pos.x += pos.x - opos.x + acc.x*dt;
    pos.y += pos.y - opos.y + acc.y*dt;
    opos = temp;
}

void Projectile::addTrail(){
    trail = true;
}

void Projectile::delTrail(){
    trail = false;
}

void Projectile::updateTrail(int nbPoint){
    if(trail){
        if(trailDraw.size()==nbPoint){
            trailDraw.push_front(new sf::CircleShape(2));
            trailDraw.front()->setOrigin(-pos.x, -pos.y);
            
            trailDraw.resize(nbPoint);
        }else{
            trailDraw.push_front(new sf::CircleShape(2));
            trailDraw.front()->setOrigin(-pos.x, -pos.y);
        }
        trailDraw.front()->setFillColor(sf::Color::Red);
    }
}

void Projectile::HandleCollision(){
    if (pos.x <= 0) {
        pos.x *= -1;
    }
    if (pos.x >= 1600) {
        pos.x = 1600 + (1600 - pos.x);
    }
    if (pos.y <= 0) {
        pos.y *= -1;
    }
    if (pos.y >= 800) {
        pos.y = 800 + (800 - pos.y);
    }
}

