//
//  Camera.hpp
//  The Sword
//
//  Created by Matt Buckley on 09/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Camera {
private:
    Vector2f position;
    Vector2f direction;
    Vector2f plane;
    double fov;
    
public:
    Camera(Vector2f position, Vector2f direction);
    Camera();
    Vector2f getPosition();
    Vector2f getDirection();
    double getFOV();
    void setPosition(Vector2f newPos);
    void setDirection(Vector2f direction);
    void setFOV(double fov);
    Vector2f getPlane();
    void rotateRight(double rotSpeed);
    void rotateLeft(double rotSpeed);
};

#endif /* Camera_hpp */
