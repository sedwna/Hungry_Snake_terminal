#include <SFML/Graphics.hpp>
#include "../include/game.hpp"
using namespace std;


void Game::runGame()
{
    srand((unsigned)time(NULL));
    sf::RenderWindow window(sf::VideoMode(x_SIZE, y_SIZE), "Hungry Snake");
    window.setFramerateLimit(60);
    sf::Texture texture;
    sf::Texture snake_image;
    sf::Texture frog_image;

    try
    {
        texture.loadFromFile("back.jpg");
        frog_image.loadFromFile("frog.png");
        snake_image.loadFromFile("snake.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    sf::RectangleShape rectengle(sf::Vector2f(800, 600));
    sf::RectangleShape frog_shape(sf::Vector2f(50, 50));
    sf::RectangleShape snake_shape(sf::Vector2f(130, 120));
    rectengle.setTexture(&texture);
    snake_shape.setTexture(&snake_image);
    frog_shape.setTexture(&frog_image);

    snake_shape.setPosition(sf::Vector2f(x_SIZE / 2, y_SIZE - 100));
    frog_shape.setPosition(sf::Vector2f(frog.frogStartpos(), -50));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
            {
                window.close();
            }
            else if (event.key.code == sf::Keyboard::Key::A)
            {
                if (snake_shape.getPosition().x > -100)
                {
                    snake_shape.move(sf::Vector2f(-snake.moveSpeed, 0));
                }
                else
                {
                    snake_shape.setPosition(sf::Vector2f(x_SIZE - 30 , y_SIZE - 100));
                }
            }
            else if (event.key.code == sf::Keyboard::Key::D)
            {
                if (snake_shape.getPosition().x < x_SIZE - 30 )
                {
                    snake_shape.move(sf::Vector2f(snake.moveSpeed, 0));
                }
                else
                {
                    snake_shape.setPosition(sf::Vector2f(-100 , y_SIZE - 100));
                }
            }
        }
        frog_shape.move(sf::Vector2f(0, frog.speed));
        if (frog_shape.getGlobalBounds().intersects(snake_shape.getGlobalBounds()))
        {
            frog_shape.setPosition(sf::Vector2f(frog.frogStartpos(), -50));
            frog.speed += 0.3;
            score++;
            snake.snakeSpeed();
            cout << score << endl;
        }
        if (frog_shape.getPosition().y > y_SIZE)
        {
            window.close();
        }

        window.clear();
        window.draw(rectengle);
        window.draw(frog_shape);
        window.draw(snake_shape);
        window.display();
    }
}
