#include "soundmanager.hpp"

void CSoundManager::Load(std::string Name, std::string Path) {
    auto Buffer = &m_Sounds[Name].first;
    auto Sound = &m_Sounds[Name].second;

    Buffer->loadFromFile("./Resources/Sounds/" + Path);
    Sound->setBuffer(*Buffer);
}

sf::Sound& CSoundManager::Get(std::string Name) {
    return m_Sounds[Name].second;
}

CSoundManager* g_SoundManager = new CSoundManager();