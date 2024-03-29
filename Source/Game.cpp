#include "Game.h"

#include "States/StatePlaying.h"

#include "Glad/glad.h"

Game::Game()
:   m_context       ()
,   m_window        (m_context.window)
,   m_fpsCounter    ("FPS", {10, 10})
,   m_tpsCounter    ("TPS", {8,  25})
,   m_renderer      (m_window.getSize().x, m_window.getSize().y)
,   m_camera        (m_window)
{
    m_window.setFramerateLimit(60);
    pushState<StatePlaying>(*this, m_camera);
}

void Game::run()
{
    constexpr   unsigned    TPS             = 10; //ticks per seconds
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

        //Real time input
        state.handleInput();

        //Real time update
        state.update(elapsed, m_camera);
        m_fpsCounter.update();
        m_camera.update();

        //Fixed time update
        while (lag >= timePerUpdate)
        {
            ticks++;
            lag -= timePerUpdate;
            state.fixedUpdate(elapsed, m_camera);
            m_tpsCounter.update();
        }

        //Render
        glClearColor(0.05, 0.05, 0.1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        state.render(m_renderer);
        m_fpsCounter.draw(m_renderer);
        m_tpsCounter.draw(m_renderer);

        m_renderer.render(m_window, m_camera);

        m_window.display();


        //Handle window events
        handleEvent();
        tryPop();
    }
}

void Game::tryPop()
{
    while (m_popCount != 0)
    {
        m_states.pop_back();
        m_popCount--;
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

            case sf::Event::KeyPressed:
                switch(e.key.code)
                {
                    case sf::Keyboard::Q:
                        m_window.close();
                        break;

                    default:
                        break;
                }

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
    m_popCount++;
}

const sf::RenderWindow& Game::getWindow() const
{
    return m_window;
}
