#include "../include/game.hpp"
using namespace std;
#include <ctype.h>

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
            score++;
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

    stringstream temp;
    temp << score;
    string point;
    temp >> point;
    return point;
}
void Game::tryAgain(sf::RenderWindow &window, sf::Text point)
{
    // ----------- write score in file ---------
    std::ofstream myFile("record_status.txt", ios::app);
    myFile << set_score() << std::endl;
    myFile.close();
    //------------------------------------------

    // ----------------- set photo -----------
    sf::Texture back_blur;
    sf::Texture tryAgain_icon;
    sf::Texture exit_icon;
    // -----------------------------------------

    // ----------- handle input ----------------
    try
    {
        font.loadFromFile("font.ttf");
        back_blur.loadFromFile("back_blur.png");
        tryAgain_icon.loadFromFile("tryagain.png");
        exit_icon.loadFromFile("exit_icon.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // -----------------------------------------

    // ---------- photo to shape ---------------

    sf::RectangleShape back_blur_shape(sf::Vector2f(x_SIZE, y_SIZE));
    sf::RectangleShape tryAgainIcon_shape(sf::Vector2f(200, 100));
    sf::RectangleShape exitIcon_shape(sf::Vector2f(100, 50));

    back_blur_shape.setTexture(&back_blur);
    tryAgainIcon_shape.setTexture(&tryAgain_icon);
    exitIcon_shape.setTexture(&exit_icon);
    // -----------------------------------------

    // ----- handel text and set pos shape  ----

    sf::Text score_text("your score is : ", font);
    sf::Text record_text("high score is : ", font);
    sf::Text High_Score("High_score", font);
    High_Score.setPosition(sf::Vector2f(610, 220));
    High_Score.setCharacterSize(15);
    High_Score.setFillColor(sf::Color::Black);

    record_text.setPosition(sf::Vector2f(500, 220));
    score_text.setPosition(sf::Vector2f(250, 200));
    record_text.setCharacterSize(15);
    record_text.setFillColor(sf::Color::Black);
    point.setPosition(sf::Vector2f(450, 205));
    point.setFillColor(sf::Color::White);
    tryAgainIcon_shape.setPosition(sf::Vector2f(300, 280));
    exitIcon_shape.setPosition(sf::Vector2f(350, 400));
    // -----------------------------------------

    // -------- read high score from file ------
    int high_score = 0;
    fstream my_file;
    my_file.open("record_status.txt", ios::in);
    if (!my_file)
    {
        cout << "No such file";
    }
    else
    {
        string s;
        int str = 0;

        while (getline(my_file, s))
        {
            cout << "string " << s << endl;
            str = stoi(s);
            cout << "int " << str << endl;
            if (my_file.eof())
            {
                break;
            }
            if (str > high_score)
            {
                high_score = str;
            }
        }
        stringstream temp;
        temp << high_score;
        string High_score;
        temp >> High_score;
        High_Score.setString(High_score);
    }
    my_file.close();

    // -----------------------------------------

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
        if (tryAgainIcon_shape.getGlobalBounds().contains(mouse))
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
        // ----------------- handle rendering ------------
        window.clear();
        window.draw(back_blur_shape);
        window.draw(score_text);
        window.draw(record_text);
        window.draw(tryAgainIcon_shape);
        window.draw(exitIcon_shape);
        window.draw(point);
        window.draw(High_Score);
        window.display();
        // -----------------------------------------------
    }
}