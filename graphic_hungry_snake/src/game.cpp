#include "../include/game.hpp"
using namespace std;

void Game::runGame(sf::RenderWindow &window)
{
    srand((unsigned)time(NULL));
    window.setFramerateLimit(60);

    // --------------- handle input from file -----
    try
    {
        font.loadFromFile("font.ttf");
        back_sound.loadFromFile("back_sound.wav");
        eat_sound.loadFromFile("eat_sound.wav");
        gameover_sound.loadFromFile("gameover_sound.wav");
        texture.loadFromFile("back.jpg");
        frog_image.loadFromFile("frog.png");
        snake_image.loadFromFile("snake.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    //---------------------------------------------

    //------------ handle font --------------------

    sf::Text point("0", font);
    sf::Text text("Score : ", font);
    text.setPosition(sf::Vector2f(5, 5));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    point.setPosition(sf::Vector2f(90, 5));
    point.setCharacterSize(25);
    point.setFillColor(sf::Color::Black);
    //---------------------------------------------

    // --------------- handle sound ---------------
    sf::Sound back(back_sound);
    back.setLoop(true);
    sf::Sound eat(eat_sound);
    sf::Sound gameover(gameover_sound);
    back.play();
    //---------------------------------------------

    //----------------- handle photo --------------
    sf::RectangleShape rectengle(sf::Vector2f(800, 600));
    sf::RectangleShape frog_shape(sf::Vector2f(50, 50));
    sf::RectangleShape snake_shape(sf::Vector2f(130, 120));
    rectengle.setTexture(&texture);
    snake_shape.setTexture(&snake_image);
    frog_shape.setTexture(&frog_image);
    //---------------------------------------------

    //---- set start positin for frog and snake ---
    snake_shape.setPosition(sf::Vector2f(x_SIZE / 2, y_SIZE - 100));
    frog_shape.setPosition(sf::Vector2f(frog.frogStartpos(), -50));
    //---------------------------------------------

    //----------- handle screen window ------------
    while (window.isOpen())
    {
        //------ poll and check event from mouse and keyboard -------
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
                    snake_shape.move(sf::Vector2f(-snake.get_snakeSpeed(), 0));
                }
                //------ check out of range snake line --------
                else
                {
                    snake_shape.setPosition(sf::Vector2f(x_SIZE - 30, y_SIZE - 100));
                }
                //---------------------------------------------
            }
            else if (event.key.code == sf::Keyboard::Key::D)
            {
                if (snake_shape.getPosition().x < x_SIZE - 30)
                {
                    snake_shape.move(sf::Vector2f(snake.get_snakeSpeed(), 0));
                }
                //------ check out of range snake line --------
                else
                {
                    snake_shape.setPosition(sf::Vector2f(-100, y_SIZE - 100));
                }
                //---------------------------------------------
            }
        }
        //---------------------------------------------

        //--------- down frog from line ---------------
        frog_shape.move(sf::Vector2f(0, frog.frog_getSpeed()));
        //---------------------------------------------

        //------ check hit between snake and frog ------
        if (frog_shape.getGlobalBounds().intersects(snake_shape.getGlobalBounds()))
        {

            eat.play();
            frog_shape.setPosition(sf::Vector2f(frog.frogStartpos(), -50));
            frog.frog_setSpeed();
            // ---- update player point-----
            point.setString(set_score());
            // -----------------------------
            snake.set_snakeSpeed();
        }
        //---------------------------------------------

        //------ check hit between frog and floor -----
        if (frog_shape.getPosition().y > y_SIZE)
        {
            gameover.play();
            tryAgain(window, point);
        }
        //---------------------------------------------

        //----------- handle rendering ----------------
        window.clear();
        window.draw(rectengle);
        window.draw(frog_shape);
        window.draw(snake_shape);
        window.draw(point);
        window.draw(text);
        window.display();
        //---------------------------------------------
    }
    //---------------------------------------------
}
string Game::set_score()
{
    score++;
    stringstream temp;
    temp << score;
    string point;
    temp >> point;
    return point;
}
void Game::tryAgain(sf::RenderWindow &window, sf::Text point)
{

    sf::Texture texture;
    sf::Texture start_icon;
    sf::Texture exit_icon;

    try
    {
        font.loadFromFile("font.ttf");
        texture.loadFromFile("back_blur.png");
        start_icon.loadFromFile("tryagain.png");
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

    sf::Text text("your score is : ", font);
    text.setPosition(sf::Vector2f(250, 200));
    point.setPosition(sf::Vector2f(450 , 205));
    point.setFillColor(sf::Color::White);
    startIcon_shape.setPosition(sf::Vector2f(300, 280));
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
                runGame(window);
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
        window.draw(text);
        window.draw(startIcon_shape);
        window.draw(exitIcon_shape);
        window.draw(point);
        window.display();
    }
}