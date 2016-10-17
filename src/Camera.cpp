//
//  Camera.cpp
//  The Sword
//
//  Created by Matt Buckley on 09/02/2016.
//  Copyright © 2016 Matt Buckley. All rights reserved.
//

#include "Camera.hpp"
#include <math.h>

Camera::Camera(Vector2f position, Vector2f direction)
: fov(fov), position(position), direction(direction) {
    plane = Vector2f(0, 0.66);
}

Camera::Camera()
: fov(fov) {
    position = Vector2f(10,10);
    direction = Vector2f(-1,0);
    plane = Vector2f(0, 0.66);
}

Vector2f Camera::getPosition() {
    return position;
}

Vector2f Camera::getDirection() {
    return direction;
}

double Camera::getFOV() {
    return fov;
}

void Camera::setPosition(Vector2f newPos) {
    position = newPos;
}

void Camera::setDirection(Vector2f direction) {
    direction = direction;
}

void Camera::setFOV(double fov) {
    fov = fov;
}

Vector2f Camera::getPlane() {
    return plane;
}

void Camera::rotateRight(double rotSpeed) {
    //both camera direction and camera plane must be rotated
    double oldDirX = direction.x;
    direction.x = direction.x * cos(-rotSpeed) - direction.y * sin(-rotSpeed);
    direction.y = oldDirX * sin(-rotSpeed) + direction.y * cos(-rotSpeed);
    double oldPlaneX = plane.x;
    plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
    plane.y = oldPlaneX * sin(-rotSpeed) + plane.y * cos(-rotSpeed);
}

void Camera::rotateLeft(double rotSpeed) {
    //both camera direction and camera plane must be rotated
    double oldDirX = direction.x;
    direction.x = direction.x * cos(rotSpeed) - direction.y * sin(rotSpeed);
    direction.y = oldDirX * sin(rotSpeed) + direction.y * cos(rotSpeed);
    double oldPlaneX = plane.x;
    plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
    plane.y = oldPlaneX * sin(rotSpeed) + plane.y * cos(rotSpeed);
}