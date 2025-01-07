#pragma once

struct NumberOfXYParts {
    short nomOfX, nomOfY;
    NumberOfXYParts(short X = 0, short Y = 0) {
        this->nomOfX = X;
        this->nomOfY = Y;
    }
    NumberOfXYParts(NumberOfXYParts& const nomOfbath2)
    {
        nomOfX = nomOfbath2.nomOfX;
        nomOfY = nomOfbath2.nomOfY;
    }
    NumberOfXYParts(NumberOfXYParts&& nomOfbath2)
    {
        nomOfX = nomOfbath2.nomOfX;
        nomOfY = nomOfbath2.nomOfY;
    }
};
enum MotionDirection {
    UP_NO_GUN,
    RIGHT_NO_GUN,
    DOWN_NO_GUN,
    LEFT_NO_GUN,
    UP_WITH_GUN,
    RIGHT_WITH_GUN,
    DOWN_WITH_GUN,
    LEFT_WITH_GUN
};

enum MostionState {
    WALKING,
    RUNING = 3
};


enum ProjectileDirection{
    LEFT,
    LEFT_UP,
    UP,
    RIGHT_UP,
    RIGHT,
    RIGHT_DOWN,
    DOWN,
    LEFT_DOWN
};



void NormalizeVetor(sf::Vector2f& vec)
{
    float Mag = sqrt(vec.x * vec.x + vec.y * vec.y);
    vec.x /= Mag;
    vec.y /= Mag;
}