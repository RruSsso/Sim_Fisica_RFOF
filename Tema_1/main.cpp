#include <iostream>
#include <Box2d/box2d.h>

int main() {

    //Gravedad
    b2Vec2 gravity(0.0f, -9.81f);
    b2World world(gravity);

    //definimos el mundo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    //creamos el mundo
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    //Le damos un tamanio al mundo
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);

    //hace que no se mueva
    groundBody->CreateFixture(&groundBox, 0.0f);

    //Creamos un cuerpo nuevo
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    //le damos un tamanio a la caja
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    //Define la densidad
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    //Le damos la densidad y friccion al cuerpo
    body->CreateFixture(&fixtureDef);

    //Le damos una frecuencia de muestreo que me dice que pasa cada segundo
    //definimos el tiempo que pasara
    float timeStep = 1.0f / 60.0f;

    //Definimos los efectos de muestra
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    //Actualiza el mundo y me da la posicion del objeto
    for (int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }


}
