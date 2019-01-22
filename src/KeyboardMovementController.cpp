//
//  KeyboardMovementController.cpp
//  The Sword
//
//  Created by Matt Buckley on 10/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#include "../include/KeyboardMovementController.hpp"

KeyboardMovementController::KeyboardMovementController(float magnitude)
: magnitude(magnitude) {}

Vector2f KeyboardMovementController::getMovementVector() {
    Vector2f movementVector(0, 0);
    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
        movementVector.x -= magnitude;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
        movementVector.x += magnitude;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
        movementVector.y += magnitude;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
        movementVector.y -= magnitude;
    }
    return movementVector;
}