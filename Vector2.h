#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
public:
    float x;
    float y;

    Vector2(float x = 0.0f, float y = 0.0f);

    Vector2 operator+(const Vector2& other) const;
};

#endif