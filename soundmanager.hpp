#ifndef _SOUNDMANAGER_
#define _SOUNDMANAGER_

#include <SFML/Audio.hpp>
#include <map>
#include <string>

class CSoundManager {
    std::map<std::string, std::pair<sf::SoundBuffer, sf::Sound>> m_Sounds;

public:
    void Load(std::string Name, std::string Path);
    sf::Sound& Get(std::string Name);
};

extern CSoundManager* g_SoundManager;

#endif