#include <iostream>
#include <Box2D/Box2D.h>

int main() {
    b2Vec2 gravity(0.0f, 9.8f);
    b2World world(gravity);

    // Define the radius of the ball
    float radius = 1.0f; // Radius in meters

    // Create a dynamic body (the ball)
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    b2Body* ballBody = world.CreateBody(&ballBodyDef);

    // Define the shape of the ball (a circle)
    b2CircleShape ballShape;
    ballShape.m_radius = radius;

    // Create a fixture (physical properties) for the ball
    b2FixtureDef ballFixtureDef;
    ballFixtureDef.shape = &ballShape;
    ballFixtureDef.friction = 0.3f; //friction

    // Attach the fixture to the ball's body
    ballBody->CreateFixture(&ballFixtureDef);

    // Define the initial angle and velocity of the throw
    float initialAngleDegrees = 75.0f; // Angle in degrees
    float initialVelocity = 5.55556; // Initial velocity in meters per second

    // Convert the angle to radians
    float initialAngleRadians = initialAngleDegrees * b2_pi / 180.0f;

    // Calculate the initial velocity components
    float initialVelocityX = initialVelocity * cos(initialAngleRadians);
    float initialVelocityY = initialVelocity * sin(initialAngleRadians);

    // Create a velocity vector
    b2Vec2 initialVelocityVector(initialVelocityX, initialVelocityY);

    // Set the initial velocity of the ball
    ballBody->SetLinearVelocity(initialVelocityVector);

    // Simulation loop
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int32 i = 0; i < 300; ++i) { // Simulate for 5 seconds
        world.Step(timeStep, velocityIterations, positionIterations);

        // Get the position of the ball
        b2Vec2 position = ballBody->GetPosition();

        // Print the position of the ball
        std::cout << "Time: " << i * timeStep << "s, Position: (" << position.x << ", " << position.y << ")" << std::endl;
    }
    return 0;
}