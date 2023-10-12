#include "iostream"
#include <Box2d/box2d.h>

int main() {
    // Create a triangle shape.
    b2PolygonShape triangleShape;
    b2Vec2 triangleVertices[3];
    triangleVertices[0].Set(0.0f, 0.0f); // Bottom left vertex.
    triangleVertices[1].Set(1.0f, 0.0f); // Bottom right vertex.
    triangleVertices[2].Set(0.0f, 1.0f); // Top vertex.
    triangleShape.Set(triangleVertices, 3); // Set the triangle shape's vertices.

    // Create a square shape.
    b2PolygonShape squareShape;
    b2Vec2 squareVertices[4];
    squareVertices[0].Set(0.0f, 0.0f); // Bottom left vertex.
    squareVertices[1].Set(1.0f, 0.0f); // Bottom right vertex.
    squareVertices[2].Set(1.0f, 1.0f); // Top right vertex.
    squareVertices[3].Set(0.0f, 1.0f); // Top left vertex.
    squareShape.Set(squareVertices, 4); // Set the square shape's vertices.

    // Create a pentagon shape.
    b2PolygonShape pentagonShape;
    b2Vec2 pentagonVertices[5];
    for (int i = 0; i < 5; ++i) {
        float angle = i * (2 * b2_pi / 5); // Calculate the angle for each vertex.
        pentagonVertices[i].Set(cos(angle), sin(angle)); // Set the vertex position.
    }
    pentagonShape.Set(pentagonVertices, 5); // Set the pentagon shape's vertices.

    // Create a hexagon shape.
    b2PolygonShape hexagonShape;
    b2Vec2 hexagonVertices[6];
    for (int i = 0; i < 6; ++i) {
        float angle = i * (2 * b2_pi / 6); // Calculate the angle for each vertex.
        hexagonVertices[i].Set(cos(angle), sin(angle)); // Set the vertex position.
    }
    hexagonShape.Set(hexagonVertices, 6); // Set the hexagon shape's vertices.

    // Create an octagon shape.
    b2PolygonShape octagonShape;
    b2Vec2 octagonVertices[8];
    for (int i = 0; i < 8; ++i) {
        float angle = i * (2 * b2_pi / 8); // Calculate the angle for each vertex.
        octagonVertices[i].Set(cos(angle), sin(angle)); // Set the vertex position.
    }
    octagonShape.Set(octagonVertices, 8); // Set the octagon shape's vertices.

    return 0;
}