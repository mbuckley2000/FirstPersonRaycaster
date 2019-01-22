//
//  RaycastRenderer.cpp
//  The Sword
//
//  Created by Matt Buckley on 09/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#include "../include/RaycastRenderer.hpp"
#include <cmath>

Vector3i RaycastRenderer::traceRay(int screenX, RenderWindow* window, Camera* camera, Map* map) {
    //Initialise variables used for trace
    double cameraX = 2 * screenX / double(window->getSize().x) - 1; //x-coordinate in camera space
    Vector2f rayPos = camera->getPosition();
    Vector2f rayDir = camera->getDirection() + camera->getPlane() * (float)cameraX;
    Vector2i mapPos = (Vector2i)camera->getPosition();
    Vector2f sideDist;  //length of ray from current position to next x or y-side
    Vector2f deltaDist(sqrt(1 + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x)), sqrt(1 + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y)));   //length of ray from one x or y-side to next x or y-side
    float perpWallDist;
    Vector2i step;      //what direction to step in x or y-direction (either +1 or -1)
    bool hit = false;   //was there a wall hit?
    int hitSide;        //was a NS or a EW wall hit?
    
    
    //calculate step and initial sideDist
    if (rayDir.x < 0) {
        step.x = -1;
        sideDist.x = (rayPos.x - mapPos.x) * deltaDist.x;
    } else {
        step.x = 1;
        sideDist.x = (mapPos.x + 1.0 - rayPos.x) * deltaDist.x;
    }
    
    if (rayDir.y < 0) {
        step.y = -1;
        sideDist.y = (rayPos.y - mapPos.y) * deltaDist.y;
    } else {
        step.y = 1;
        sideDist.y = (mapPos.y + 1.0 - rayPos.y) * deltaDist.y;
    }
    
    
    //Perform DDA
    while (!hit) {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDist.x < sideDist.y) {
            sideDist.x += deltaDist.x;
            mapPos.x += step.x;
            hitSide = 0;
        } else {
            sideDist.y += deltaDist.y;
            mapPos.y += step.y;
            hitSide = 1;
        }
        
        //Check if ray has hit a wall
        if (map->getTileID(mapPos.x, mapPos.y) > 0) {
            hit = true;
        }
    }
    
    //Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
    if (hitSide == 0)
        perpWallDist = fabs((mapPos.x - rayPos.x + (1 - step.x) / 2) / rayDir.x);
    else
        perpWallDist = fabs((mapPos.y - rayPos.y + (1 - step.y) / 2) / rayDir.y);
    
    //Calculate height of line to draw on screen
    int lineHeight = abs(int(window->getSize().y / perpWallDist));
    
    //calculate lowest and highest pixel to fill in current stripe
    int drawStart = -lineHeight / 2 + window->getSize().y / 2;
    if(drawStart < 0)
        drawStart = 0;
    
    int drawEnd = lineHeight / 2 + window->getSize().y / 2;
    if(drawEnd >= window->getSize().y)
        drawEnd = window->getSize().y - 1;
    
    return Vector3i(drawStart, drawEnd, hitSide * 50);
}

void RaycastRenderer::render(RenderWindow* window, Camera* camera, Map* map) {
    for(int x = 0; x < window->getSize().x; x++) {
        Vector3i lineVector = traceRay(x, window, camera, map);
        Vertex ceilingLine[] = {
            Vertex(Vector2f(x, 0), Color(135,206,250)),
            Vertex(Vector2f(x, lineVector.x), Color(200,235,255))
        };
        Vertex wallLine[] = {
            Vertex(Vector2f(x, lineVector.x), Color(255 - lineVector.z, 255 - lineVector.z, 255 - lineVector.z)),
            Vertex(Vector2f(x, lineVector.y), Color(235 - lineVector.z, 235 - lineVector.z, 235 - lineVector.z))
        };
        Vertex floorLine[] = {
            Vertex(Vector2f(x, lineVector.y), Color(150, 150, 150)),
            Vertex(Vector2f(x, window->getSize().y), Color(100, 100, 100))
        };
        
        window->draw(ceilingLine, 2, sf::Lines);
        window->draw(wallLine, 2, sf::Lines);
        window->draw(floorLine, 2, sf::Lines);

    }
}