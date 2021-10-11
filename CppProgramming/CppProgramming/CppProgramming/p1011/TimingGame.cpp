#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
private:
    const int totalN; // total number of Players
    static int order; // to determine player ID;
    int id; // player ID
    int waiting; // time to wait for raising hands
    bool done; // already raised hands (participated in the game already)
    void setTime(); // to determine the value of waiting
public:
    Player(int num); // constructor (parameter: total number of players)
    bool play(); // wait (not raise) or raise hands at each time tick
    bool isOver(); // return the value of done (to check whether the player has participated in the game)
    inline int getId() { return this->id; }
};

int Player::order = 1;

class TimingGame {
private:
    static int curTime; // current Time tick
    const int totalN; // # of players
    Player** players; // pointer to point the array of Player objects

public:
    TimingGame(int playerN); // constructor (parameter : # of players)
    void simulateGame(); // start simulation
    ~TimingGame();
};

int getPlayerNum() {
    char in[100];
    
    while (true) {
        std::cout << "Input player number: ";
        std::cin >> in;

        bool isNumber = false;
        for (int i = 0; i < 100; ++i) {
            if (in[i] == 0) {
                isNumber = true;
                break;
            }
            
            if ('0' > in[i] || '9' < in[i]) {
                break;
            }
        }

        if (isNumber) {
            return atoi(in);
        }
        else {
            std::cout << "Input type is not number." << std::endl;
            continue;
        }
    }   
}

int main() {
    srand(time(NULL));

    int playerNum = getPlayerNum();
    TimingGame game = TimingGame(playerNum);
    game.simulateGame();

    return 0;
}

TimingGame::TimingGame(int playerN): totalN(playerN)
{
    players = new Player*[playerN];

    for (int i = 0; i < playerN; ++i) {
        players[i] = new Player(playerN);
    }
}

void TimingGame::simulateGame()
{
    Player* risedPlayer = nullptr;

    for (int i = 0; i < this->totalN; ++i) {
        std::cout << i << "-th turn" << std::endl;
        risedPlayer = nullptr;

        for (int j = 0; j < this->totalN; ++j) {
            bool isRise = players[j]->play();

            if (isRise) {
                std::cout << players[j]->getId() << " says I am here" << std::endl;

                if (risedPlayer == nullptr) {
                    risedPlayer = players[j];
                }
                else {
                    std::cout << "game is over with conflict at " << i << "-th turn." << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "game is over without conflict. last rised: " << risedPlayer->getId() << std::endl;
}

TimingGame::~TimingGame()
{
    for (int i = 0; i < totalN; ++i) {
        delete players[i];
    }
    delete players;
}

void Player::setTime()
{
    this->waiting = rand() % totalN;
    std::cout << id << " says I pick up " << this->waiting << std::endl;
}

Player::Player(int num) : totalN(num), done(false), waiting(0)
{
    this->id = order++;
    this->setTime();
}

bool Player::play()
{
    if (this->waiting == 0) {
        this->done = true;
        return true;
    }
    else {
        this->waiting -= 1;
        return false;
    }
}

bool Player::isOver()
{
    return this->done;
}
