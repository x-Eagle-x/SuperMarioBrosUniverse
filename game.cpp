#include "game.hpp"
#include "entitymanager.hpp"
#include "blocks.hpp"
#include "mario.hpp"

CGame *g_GameManager = new CGame();

b2World*& CGame::World() {
    return m_World;
}

sf::Vector2f& CGame::Camera() {
    return m_Camera;
}

sf::RenderWindow& CGame::Window() {
    return m_Window;
}

void CGame::Run() {
    sf::Event Event;

    while (m_Window.isOpen()) {
        while (m_Window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                m_Window.close();
                return;
            }
        }

        m_Window.clear(sf::Color::Blue);
        m_DeltaTime = m_Clock.restart().asSeconds();
        Update();
        m_Window.display();
    }
}

void CGame::Update() {
    std::printf("delta: %f\n", m_DeltaTime);
    m_World->Step(1 / 75, 1, 1);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_Pressed) {
        auto MousePos = sf::Mouse::getPosition(m_Window);
        g_EntityManager->Add(new CGroundBlock(floor(MousePos.x / 32.0f) * 32.0f, floor(MousePos.y / 32.0f) * 32.0f));
        m_Pressed = true;
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_Pressed) {
        m_Pressed = false;
    }

    // Update every entity
    for (auto Entity : g_EntityManager->GetEntities()) {
        Entity->Update();
    }
}

CGame::CGame() : m_Window(sf::VideoMode(WINDOW_X, WINDOW_Y), GAME_TITLE) {
    m_World = new b2World(b2Vec2(0.0f, 98.1f));
}