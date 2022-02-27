#include "blocks.hpp"

void CGroundBlock::Update() {
    Draw();
}

CGroundBlock::CGroundBlock(float X, float Y) : CEntity(X, Y, 32.0, 32.0, true) {
    m_Sprite.setTexture(g_TextureManager->Get("spritesheet"));
    m_Sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    m_Sprite.setScale(2.0, 2.0);
}