#include "Game.h"

#include "States/StatePlaying.h"

#include <GL/glew.h>

Game::Game()
:   m_context       ()
,   m_window        (m_context.window)
,   m_fpsCounter    ("FPS", {10, 10})
,   m_tpsCounter    ("TPS", {8,  25})
{
    m_window.setVerticalSyncEnabled(true);
    pushState<StatePlaying>(*this);
}

void Game::run()
{
    constexpr   unsigned    TPS             = 5; //ticks per seconds
    const       sf::Time    timePerUpdate   = sf::seconds(1.0f / float(TPS));
    unsigned                ticks           = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag      = sf::Time::Zero;

    while (m_window.isOpen() && !m_states.empty())
    {
        auto& state = getCurrentState();

        //Get times
        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;

        lastTime = time;
        lag += elapsed;

        //Real time update
        state.handleInput();
        state.update(elapsed);
        m_fpsCounter.update();

        //Fixed time update
        while (lag >= timePerUpdate)
        {
            ticks++;
            lag -= timePerUpdate;
            state.fixedUpdate(elapsed);
            m_tpsCounter.update();
        }

        //Render
        glClearColor(0.5, 0.5, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        state.render(m_renderer);

        m_renderer.render();

        //prep for SFML drawing
        glDisable(GL_DEPTH_TEST);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        glUseProgram(0);
        //reset gl states
        m_window.pushGLStates();
        m_window.resetGLStates();
        m_fpsCounter.draw(m_window);
        m_tpsCounter.draw(m_window);
        m_window.popGLStates();
        m_window.resetGLStates();
        //end sfml drawing

        m_window.display();


        //Handle window events
        handleEvent();
        tryPop();
    }
}

void Game::tryPop()
{
    if (m_shouldPop)
    {
        m_states.pop_back();
    }
}

void Game::handleEvent()
{
    sf::Event e;

    while (m_window.pollEvent(e))
    {
        getCurrentState().handleEvent(e);
        switch (e.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;

        }
    }
}

StateBase& Game::getCurrentState()
{
    return *m_states.back();
}

void Game::popState()
{
    m_shouldPop = true;
}

const sf::RenderWindow& Game::getWindow() const
{
    return m_window;
}
