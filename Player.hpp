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

    void addLife(int lives);
    void loseLife();

    void levelUp();

    void setLife(int lives);
    void setPoints(int points);

    int getLives();
    int getPoints();
    int getLevel();
};
#endif