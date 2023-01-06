#include "../include/app.hpp"

// -------------------------------------------------------
App::App()
{
    menu();
}
// -------------------------------------------------------

// -------------------------------------------------------
void App::menu()
{
    sf::RenderWindow window(sf::VideoMode(x_SIZE, y_SIZE), "Hungry Snake");
    window.setFramerateLimit(60);
    sf::Texture texture;
    sf::Texture start_icon;
    sf::Texture exit_icon;

    try
    {
        texture.loadFromFile("back_blur.png");
        start_icon.loadFromFile("start_icon.png");
        exit_icon.loadFromFile("exit_icon.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    sf::RectangleShape texture_shape(sf::Vector2f(x_SIZE, y_SIZE));
    sf::RectangleShape startIcon_shape(sf::Vector2f(200, 100));
    sf::RectangleShape exitIcon_shape(sf::Vector2f(100, 50));

    texture_shape.setTexture(&texture);
    startIcon_shape.setTexture(&start_icon);
    exitIcon_shape.setTexture(&exit_icon);

    startIcon_shape.setPosition(sf::Vector2f(300, 150));
    exitIcon_shape.setPosition(sf::Vector2f(350, 400));

    while (window.isOpen())
    {
        sf ::Event event;
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
        if (startIcon_shape.getGlobalBounds().contains(mouse))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                game.runGame(window);
            }
        }
        else if (exitIcon_shape.getGlobalBounds().contains(mouse))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.close();
            }
        }

        window.clear();
        window.draw(texture_shape);
        window.draw(startIcon_shape);
        window.draw(exitIcon_shape);
        window.display();
    }
}
