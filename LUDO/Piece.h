#pragma once
#include<string>
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
#define ipx1 323
#define ipy1 655
#define ibx1 256
#define iby1 450
#define ibx2 82
#define iby2 477
#define igx1 223
#define igy1 315
#define igx2 119
#define igy2 178
#define iyx1 323
#define iyy1 225
#define iyx2 390
#define iyy2 55
#define iox1 453
#define ioy1 262
#define iox2 635
#define ioy2 234
#define irx1 494
#define iry1 394
#define irx2 598
#define iry2 534
#define ipx2 390
#define ipy2 484
struct pos {
    int x;
    int y;
};
class Piece {

    string color;
    string state;
    pos position;
    int boxnumC;
public:

    Piece(string pieceColor) : color(pieceColor)
    {
        if (color == "purple")
        {
            sf::Texture purpPieceText;
      /*      if (!purpPieceText.loadFromFile("Images/Board.jpg"))
            {
                return EXIT_FAILURE;
            }*/
            sf::Sprite purpPieceS(purpPieceText);
            movement(boxnumC, purpPieceS);
 
        }
        if (color == "blue")
        {
            sf::Texture bluePieceText;
         /*   if (!bluePieceText.loadFromFile("Images/Board.jpg"))
            {
                return EXIT_FAILURE;
            }*/
            sf::Sprite bluePieceS(bluePieceText);
            movement(boxnumC, bluePieceS);
        }
        if (color == "green")
        {
           
        }
        if (color == "yellow")
        {
          
        }
        if (color == "orange")
        {
        
        }
        if (color == "red")
        {
       
        }

    }
    std::string getColor() const { return color; }
    std::string getState() const { return state; }
    pos getPosition() const { return position; }

    void move(int steps) {

        position.x += steps;
        position.y += steps;
    }
    void enterHome() {
        state = "Home";
        position = { -1, -1 };
    }

    void moveToStartPos(pos startPos) {
        state = "InPlay";
        position = startPos;
    }



    void movement(int boxnumC, sf::Sprite& PieceS)
    {

        if (boxnumC > 0 && boxnumC <= 5)   //purple
        {

            PieceS.setPosition(ipx1, ipy1);

            int  mult = boxnumC;
            PieceS.move(0, mult * -34);

        }
        else if (boxnumC >= 6 && boxnumC <= 11) //blue  down
        {
            PieceS.setPosition(ibx1, iby1);

            int  mult = boxnumC - 6;
            PieceS.move(mult * -29, mult * +17);
        }
        else if (boxnumC >= 13 && boxnumC <= 18)  //blue up
        {
            PieceS.setPosition(ibx2, iby2);
            int  mult = boxnumC - 13;
            PieceS.move(mult * 29, mult * -17);
        }
        else if (boxnumC >= 19 && boxnumC <= 24) // green down
        {
            PieceS.setPosition(igx1, igy1);
            int  mult = boxnumC - 19;
            PieceS.move(mult * -27, mult * -16);
        }
        else if (boxnumC >= 26 && boxnumC <= 31)  //green up
        {
            PieceS.setPosition(igx2, igy2);
            int  mult = boxnumC - 26;
            PieceS.move(mult * +27, mult * +16);
        }
        else if (boxnumC >= 32 && boxnumC <= 37)//yellow up
        {
            PieceS.setPosition(iyx1, iyy1);
            int  mult = boxnumC - 32;
            PieceS.move(mult * 0, mult * -34);

        }
        else if (boxnumC >= 39 && boxnumC <= 44)//yellow down
        {
            PieceS.setPosition(iyx2, iyy2);
            int  mult = boxnumC - 39;
            PieceS.move(mult * 0, mult * 34);
        }
        else if (boxnumC >= 45 && boxnumC <= 50)//orange up
        {
            PieceS.setPosition(iox1, ioy1);
            int  mult = boxnumC - 45;
            PieceS.move(mult * 29, mult * -17);
        }
        else if (boxnumC >= 52 && boxnumC <= 57)//orange down
        {
            PieceS.setPosition(iox2, ioy2);
            int  mult = boxnumC - 52;
            PieceS.move(mult * -29, mult * +17);
        }
        else if (boxnumC >= 58 && boxnumC <= 63)//red up
        {
            PieceS.setPosition(irx1, iry1);
            int  mult = boxnumC - 58;
            PieceS.move(mult * +27, mult * +16);
        }
        else if (boxnumC >= 65 && boxnumC <= 70)//red down
        {
            PieceS.setPosition(irx2, iry2);
            int  mult = boxnumC - 65;
            PieceS.move(mult * -27, mult * -16);
        }
        else if (boxnumC >= 71 && boxnumC <= 76)//purpple down
        {
            PieceS.setPosition(ipx2, ipy2);
            int  mult = boxnumC - 71;
            PieceS.move(mult * 0, mult * 34);
        }
    }







};