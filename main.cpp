#include "texturemanager.hpp"
#include "entitymanager.hpp"
#include "soundmanager.hpp"
#include "blocks.hpp"
#include "game.hpp"
#include "mario.hpp"

int main() {
    g_GameManager->Window().setFramerateLimit(75);
    g_TextureManager->Load("spritesheet", "spritesheet.png");
    g_TextureManager->Load("mario", "mario.png");
    g_SoundManager->Load("jump_small", "JumpSmall.wav");

    for (float X = 0.0; X < 32.0 * 10; X += 32.0) {
        g_EntityManager->Add(new CGroundBlock(X, WINDOW_Y - 32.0));
    }

    g_EntityManager->Add(g_Mario);
    g_GameManager->Run();

    delete g_GameManager;
    delete g_EntityManager;
    delete g_TextureManager;
    delete g_SoundManager;
    delete g_Mario;
}