//
//  MouseCameraController.cpp
//  The Sword
//
//  Created by Matt Buckley on 10/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#include "../include/MouseCameraController.hpp"

MouseCameraController::MouseCameraController(float magnitude)
: magnitude(magnitude) {
    oldMousePosition = Mouse::getPosition();
}

Vector2i MouseCameraController::getMouseDelta() {
    Vector2i mouseDelta = Mouse::getPosition() - oldMousePosition;
    oldMousePosition = Mouse::getPosition();
    return mouseDelta;
}

float MouseCameraController::getRotation() {
    return getMouseDelta().x * magnitude;
}