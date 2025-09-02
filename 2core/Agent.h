#ifndef AGENT_H
#define AGENT_H

#include "Position.h"

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Agent
{
private:
    Position position;
    char symbol;
    int id;

public:
    // Constructor
    Agent(int x = 0, int y = 0, char sym = 'A', int agentId = 0);

    // Destructor
    ~Agent();

    // Core movement function - ONE STEP AT A TIME
    bool step(Direction dir, int gridWidth, int gridHeight);

    // Getters
    Position getPosition() const;
    int getX() const;
    int getY() const;
    char getSymbol() const;
    int getId() const;

    // Setters
    void setPosition(const Position &newPos);
    void setPosition(int x, int y);

    // Utility functions
    bool canMoveTo(int newX, int newY, int gridWidth, int gridHeight) const;
    void display() const;
};

#endif // AGENT_H