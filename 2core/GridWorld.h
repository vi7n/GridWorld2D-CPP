#ifndef GRIDWORLD_H
#define GRIDWORLD_H

#include <vector>
#include "Position.h"
#include "Agent.h"

enum class CellType
{
    EMPTY = '.',
    OBSTACLE = '#',
    GOAL = 'G'
};

class GridWorld
{
private:
    int width, height;
    std::vector<std::vector<CellType>> grid;
    Position goalPosition;
    bool hasGoalSet;

public:
    // Constructor & Destructor
    GridWorld(int w = 10, int h = 10);
    ~GridWorld();

    // Grid management
    void initializeGrid();
    void clearGrid();

    // Goal management
    void setGoal(int x, int y);
    void setGoal(const Position &pos);
    bool isGoalReached(const Position &agentPos) const;
    Position getGoalPosition() const;

    // Obstacle management
    void addObstacle(int x, int y);
    void addObstacle(const Position &pos);
    void removeObstacle(int x, int y);
    bool hasObstacle(int x, int y) const;

    // Grid queries
    bool isValidPosition(int x, int y) const;
    bool isValidPosition(const Position &pos) const;
    CellType getCellType(int x, int y) const;

    // Display
    void displayGrid(const Agent &agent) const;
    void displayGrid() const;

    // Getters
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Save/Load (for later goals)
    void saveToFile(const std::string &filename) const;
    bool loadFromFile(const std::string &filename);
};

#endif // GRIDWORLD_H