#include "texturemanager.hpp"

void CTextureManager::Load(std::string Name, std::string Path) {
    m_Textures[Name].loadFromFile("./Resources/Textures/" + Path);
}

sf::Texture& CTextureManager::Get(std::string Name) {
    return m_Textures[Name];
}

CTextureManager* g_TextureManager = new CTextureManager();