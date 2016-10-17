//
//  Object.hpp
//  The Sword
//
//  Created by Matt Buckley on 02/12/2015.
//  Copyright © 2015 Matt Buckley. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Object {
private:
    Vector2f position;
    Sprite sprite;
    Texture texture;
    int ID;
    static int count;
    
public:
    Object(char* filename);
    void update();
    void draw(RenderWindow window);
    int getID();
    Vector2f getPosition();
    static int getCount();
};

#endif /* Object_hpp */