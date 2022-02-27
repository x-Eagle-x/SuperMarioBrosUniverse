#include "entity.hpp"
#include "game.hpp"

void SCollidableBox::Create(float X, float Y, float SX, float SY, bool Solid) {
    m_BodyDef.fixedRotation = true;
    m_BodyDef.position.Set(X, Y);
    m_BodyDef.type = (Solid ? b2_staticBody : b2_dynamicBody);
    
    m_Body = g_GameManager->World()->CreateBody(&m_BodyDef);
    m_Shape.SetAsBox(SX / 2.0f, SY / 2.0f);

    m_FixtureDef.density = (Solid ? 0.0f : 1.f);
    m_FixtureDef.friction = 0.0f;
    m_FixtureDef.shape = &m_Shape;

    m_Body->CreateFixture(&m_FixtureDef);
}

bool CEntity::IsSolid() {
    return m_Solid;
}

SCollidableBox& CEntity::Box() {
    return m_Box;
}

sf::Sprite& CEntity::Sprite() {
    return m_Sprite;
}

sf::Vector2f& CEntity::Size() {
    return m_Size;
}

sf::Vector2f& CEntity::Position() {
    return m_Position;
}

void CEntity::Draw() {
    m_Position.x = m_Box.m_Body->GetPosition().x;
    m_Position.y = m_Box.m_Body->GetPosition().y;
    
    m_Sprite.setPosition(m_Position - g_GameManager->Camera());
    g_GameManager->Window().draw(m_Sprite);
}

CEntity::CEntity(float X, float Y, float SX, float SY, bool Solid) {
    m_Position.x = X;
    m_Position.y = Y;
    m_Size.x = SX;
    m_Size.y = SY;

    m_Solid = Solid;
    m_Clock.restart();

    m_Box.Create(X, Y, SX, SY, Solid);
}