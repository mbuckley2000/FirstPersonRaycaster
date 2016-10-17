//
//  Object.cpp
//  The Sword
//
//  Created by Matt Buckley on 02/12/2015.
//  Copyright © 2015 Matt Buckley. All rights reserved.
//

#include "Object.hpp"

using namespace sf;

int Object::count;

Object::Object(char* filename) {
    texture.loadFromFile(filename);
    count++;
    ID = count;
}

void Object::draw(RenderWindow window) {
    if (!sprite.getTexture()) {
        sprite.setTexture(texture);
    }
    
    //convert worldspace to screenspace
    
    window.draw(sprite);
}

void Object::update() {
}

/*
class Object {
private:
    Vector2f position;
    int ID;
    static int count;
    
public:
    Object();
    void update();
    void draw(Window);
    int getID();
    Vector2f getPosition();
    static int getCount();
};
*/