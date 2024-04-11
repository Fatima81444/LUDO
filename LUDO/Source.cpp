#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;


int main()
{
    int xpos=0, ypos = 0;
    // Create a window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Test");
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("Images/Board.jpg"))
    {
        return EXIT_FAILURE;
        }
    sf::Sprite boardS(boardTexture);

    boardS.setPosition(0, 0);


    sf::Texture PieceredText;
    if (!PieceredText.loadFromFile("Images/Rpawn.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite RedPieceS(PieceredText);
 /*   RedPieceS.setPosition(boardS.getGlobalBounds().width / 2.343, boardS.getGlobalBounds().height / 1.145);*/
 //   RedPieceS.setPosition(irx2,iry2);
   RedPieceS.setScale(0.8, 0.8);
    // Game loop
    int rollCount = 0;


    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Play the sound


                    xpos = event.mouseButton.x;
                    ypos = event.mouseButton.y;
                    cout << "Mouse clicked at: " << xpos << ", " << ypos << endl;

                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                  //RedPieceS.setPosition(RedPieceS.getPosition().x+27, RedPieceS.getPosition().y +16);
                    rollCount++;
                    movement(rollCount, RedPieceS);

                }
                if (event.key.code == sf::Keyboard::Down)
                {
                   //RedPieceS.move(-27,-16);
                    rollCount--;
                    movement(rollCount, RedPieceS);

                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    RedPieceS.move(34, 0);

                }
        


            }
        }


        // Clear the window
        window.clear();

        window.draw(boardS);
        window.draw(RedPieceS);
        // Display the window contents
        window.display();
    }

    return 0;
}
