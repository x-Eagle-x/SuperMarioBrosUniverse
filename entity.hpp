#ifndef _ENTITY_
#define _ENTITY_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "texturemanager.hpp"

struct SCollidableBox {
    b2Body* m_Body;
    b2BodyDef m_BodyDef;
    
    b2FixtureDef m_FixtureDef;
    b2PolygonShape m_Shape;

    void Create(float X, float Y, float SX, float SY, bool Solid);
};

class CEntity {
protected:
    bool m_Solid;
    SCollidableBox m_Box;

    sf::Sprite m_Sprite;
    sf::Vector2f m_Size;
    sf::Vector2f m_Position;
    sf::Clock m_Clock;

public:
    bool IsSolid();
    SCollidableBox& Box();

    sf::Sprite& Sprite();
    sf::Vector2f& Size();
    sf::Vector2f& Position();

    void Draw();
    virtual void Update() {};

    CEntity(float X, float Y, float SX, float SY, bool Solid = true);
    virtual ~CEntity() {};
};

#endif