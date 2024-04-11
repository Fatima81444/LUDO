#include "Piece.h" 
using namespace std;
class Player {
private:
    std::string color;
    std::vector<Piece> pieces; 

public:

    Player(const std::string& playerColor) : color(playerColor) {
    
        for (int i = 0; i < 4; ++i) {
            pieces.push_back(Piece(playerColor));
        }
    }


    void movePiece(int pieceIndex, int steps) {
        pieces[pieceIndex].move(steps);
    }

    void movePieceTo(int pieceIndex, int boxnumC) {
        pieces[pieceIndex].movement(boxnumC);
    }

    //// Method to get a piece's sprite
    //sf::Sprite getPieceSprite(int pieceIndex) const {
    //    return pieces[pieceIndex].getSprite();
    //}

};

class Player1 : public Player {
public:
    Player1() : Player("purple") {} 
};

class Player2 : public Player {
public:
    Player2() : Player("blue") {} 
};


