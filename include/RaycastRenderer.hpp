//
//  RaycastRenderer.hpp
//  The Sword
//
//  Created by Matt Buckley on 09/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#ifndef RaycastRenderer_hpp
#define RaycastRenderer_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Camera.hpp"
#include "Map.hpp"

using namespace sf;

class RaycastRenderer {
private:
    Vector3i traceRay(int screenX, RenderWindow* window, Camera* camera, Map* map);
    
public:
    void render(RenderWindow* window, Camera* camera, Map* map);
};

#endif /* RaycastRenderer_hpp */
