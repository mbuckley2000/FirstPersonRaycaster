//
//  Map.hpp
//  The Sword
//
//  Created by Matt Buckley on 09/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Map {
private:
    int** tileID;
    Vector2i size;
    
public:
    Map(Vector2i size);
    ~Map();
    Vector2i getSize();
    int getTileID(int x, int y);
    bool setTileID(int x, int y, int ID);
    void generateRandom(int seed);
    bool tileWalkable(Vector2f position);
};

#endif /* Map_hpp */
