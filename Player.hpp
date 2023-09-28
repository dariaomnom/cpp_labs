#ifndef PLAYER_H
#define PLAYER_H
class Player {
private:
    int lives;
    int points;
    int level;

public:
    explicit Player(int lives = 10, int points = 0);

    ~Player() = default;

    void addPoints(int points);

    void addLives(int lives = 1);
    void loseLives(int lives = 1);

    void levelUp();

    void setLives(int lives);
    void setPoints(int points);
    void setLevel(int level);

    int getLives();
    int getPoints();
    int getLevel();

    void printPoints();
    void printLives();
    void printLevel();
    void printStats();
};
#endif