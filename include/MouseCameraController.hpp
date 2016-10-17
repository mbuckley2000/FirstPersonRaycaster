//
//  MouseCameraController.hpp
//  The Sword
//
//  Created by Matt Buckley on 10/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#ifndef MouseCameraController_hpp
#define MouseCameraController_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class MouseCameraController {
private:
    float magnitude;
    Vector2i oldMousePosition;
    Vector2i getMouseDelta();
    
public:
    MouseCameraController(float magnitude);
    float getRotation();
};

#endif /* MouseCameraController_hpp */
