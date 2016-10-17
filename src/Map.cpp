//
//  Map.cpp
//  The Sword
//
//  Created by Matt Buckley on 09/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#include "Map.hpp"

Map::Map(Vector2i size) : size(size) {
    tileID = new int*[size.x];
    for (int i=0; i<size.x; i++) {
        tileID[i] = new int[size.y];
    }
}

Map::~Map() {
    for (int i=0; i<size.x; i++) {
        delete[] tileID[i];
    }
    delete[] tileID;
}

Vector2i Map::getSize() {
    return size;
}

int Map::getTileID(int x, int y) {
    if (x>=0 && y>=0 && x<size.x && y<size.y) {
        return tileID[x][y];
    } else {
        return 0;
    }
}

bool Map::setTileID(int x, int y, int ID) {
    if (x>=0 && y>=0 && x<size.x && y<size.y) {
        tileID[x][y] = ID;
        return true;
    }
    return false;
}

void Map::generateRandom(int seed) {
    for (int x=0; x<size.x; x++) {
        tileID[x][0] = 1;
        tileID[x][size.y-1] = 1;
        for (int y=0; y<size.y; y++) {
            if (x/(y+1) == 2) {
                tileID[x][y] = 1;
            }
        }
    }
    for (int y=0; y<size.y; y++) {
        tileID[0][y] = 1;
        tileID[size.x-1][y] = 1;
    }
    
}

bool Map::tileWalkable(Vector2f position) {
    int x = position.x;
    int y = position.y;
    if (x>=0 && y>=0 && x<size.x && y<size.y) {
        if (tileID[x][y] == 0) {
            return true;
        }
    }
    return false;
}