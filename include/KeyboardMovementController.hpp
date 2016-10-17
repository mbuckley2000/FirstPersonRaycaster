//
//  KeyboardMovementController.hpp
//  The Sword
//
//  Created by Matt Buckley on 10/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#ifndef KeyboardMovementController_hpp
#define KeyboardMovementController_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;


class KeyboardMovementController {
private:
    float magnitude;
public:
    KeyboardMovementController(float magnitude);
    Vector2f getMovementVector();
};

#endif /* KeyboardMovementController_hpp */
