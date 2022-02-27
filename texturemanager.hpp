#ifndef _TEXTUREMANAGER_
#define _TEXTUREMANAGER_

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class CTextureManager {
    std::map<std::string, sf::Texture> m_Textures;

public:
    void Load(std::string Name, std::string Texture);
    sf::Texture& Get(std::string Path);
};

extern CTextureManager* g_TextureManager;

#endif