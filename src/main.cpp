#include <SFML/Graphics.hpp>
#include "RaycastRenderer.hpp"
#include "KeyboardMovementController.hpp"
#include "MouseCameraController.hpp"
#include "Camera.hpp"
#include "Map.hpp"

using namespace sf;

int main()
{
    // create the window
    RenderWindow window(sf::VideoMode(3200, 1800), "Tilemap", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    Map map(Vector2i(24, 24));
    map.generateRandom(10);
    Camera camera;
    KeyboardMovementController movementController(0.1);
    MouseCameraController cameraController(0.01);
    RaycastRenderer renderer;
    Clock frameTimer;
    int targetFrameTimeMillis = 16;
    
    // run the main loop
    while (window.isOpen())
    {
        frameTimer.restart(); //Time based movement

        // handle events
        Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;
                default://do nothing
                    break;
            }
        }
        
        // draw the map
        window.clear();
        
        double camRot = cameraController.getRotation();
        
        if (camRot > 0) {
            camera.rotateRight(camRot);
        } else if (camRot < 0) {
            camera.rotateLeft(-camRot);
        }

        Vector2f camPos = camera.getPosition();
        Vector2f camDir = camera.getDirection();
        Vector2f camDirPerp(camDir.y, -camDir.x);
        Vector2f movementDelta = camDir * movementController.getMovementVector().y + camDirPerp * movementController.getMovementVector().x;
        Vector2f newCamPos = camPos + movementDelta;
        if (map.tileWalkable(newCamPos)) {
            camera.setPosition(newCamPos);
        }
        
        renderer.render(&window, &camera, &map);
        
        window.display();
        
        
        //Timer based movement
        while (frameTimer.getElapsedTime().asMilliseconds() < targetFrameTimeMillis){}
    }
    
    return 0;
}

int WinMain() {
	return main();
}