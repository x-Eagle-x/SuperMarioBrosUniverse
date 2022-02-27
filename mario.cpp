#include "mario.hpp"
#include "soundmanager.hpp"

#include <math.h>

void CMario::Update() {
    auto BodyMass = m_Box.m_Body->GetMass();
    auto YVelocity = m_Box.m_Body->GetLinearVelocity().y;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_Box.m_Body->SetLinearVelocity(b2Vec2(-25.0, YVelocity));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_Box.m_Body->SetLinearVelocity(b2Vec2(25.0, YVelocity));
    }
    else {
        m_Box.m_Body->SetLinearVelocity(b2Vec2(0.0, YVelocity));
    }

    auto XVelocity = m_Box.m_Body->GetLinearVelocity().x;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (!m_JumpPressed) {
            m_Box.m_Body->SetLinearVelocity(b2Vec2(XVelocity, -250.0));
            m_JumpPressed = true;
        }
    }
    else {
        m_JumpPressed = false;
    }

    Draw();
}

CMario::CMario(float X, float Y) : CEntity(X, Y, 32.0, 24.0, false) {
    m_Sprite.setTexture(g_TextureManager->Get("mario"));
    m_Sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    m_Sprite.setScale(2.0, 2.0);
}

CMario* g_Mario = new CMario(32.0, 32.0);