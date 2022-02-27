#ifndef _GAME_
#define _GAME_

#define WINDOW_X 1024
#define WINDOW_Y 576
#define GAME_TITLE "Super Mario Bros. Universe"

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>

class CGame {
    b2World *m_World;
    
    sf::Clock m_Clock;
    sf::Vector2f m_Camera;
    sf::RenderWindow m_Window;

    bool m_Pressed = false;
    float m_DeltaTime = 0.0f;

public:
    b2World*& World();

    sf::Vector2f& Camera();
    sf::RenderWindow& Window();

    void Run();
    void Update();

    CGame();
};

extern CGame* g_GameManager;

#endif