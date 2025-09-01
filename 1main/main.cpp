#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Agent.h"
#include "GridWorld.h"

int main()
{
    std::cout << "=== 2D Grid World - C++ Classes Demo ===" << std::endl;

    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // Create a 10x10 grid world
    GridWorld world(10, 10);

    // Create an agent at position (1, 1)
    Agent player(1, 1, 'P', 1);

    // Set a goal at position (8, 8)
    world.setGoal(8, 8);

    // Add some obstacles
    world.addObstacle(3, 3);
    world.addObstacle(3, 4);
    world.addObstacle(4, 3);
    world.addObstacle(6, 6);
    world.addObstacle(6, 7);

    std::cout << "\nInitial Grid:" << std::endl;
    world.displayGrid(player);

    std::cout << "\nControls: w(up), s(down), a(left), d(right), q(quit)" << std::endl;
    std::cout << "Goal: Reach the target 'G' at position (8,8)" << std::endl;

    char input;
    int steps = 0;

    // Game loop - ONE STEP AT A TIME
    while (true)
    {
        std::cout << "\nStep " << (steps + 1) << " - Enter move: ";
        std::cin >> input;

        Direction dir;
        bool validInput = true;

        // Convert input to direction
        switch (input)
        {
        case 'w':
        case 'W':
            dir = Direction::UP;
            break;
        case 's':
        case 'S':
            dir = Direction::DOWN;
            break;
        case 'a':
        case 'A':
            dir = Direction::LEFT;
            break;
        case 'd':
        case 'D':
            dir = Direction::RIGHT;
            break;
        case 'q':
        case 'Q':
            std::cout << "Thanks for playing! Total steps: " << steps << std::endl;
            return 0;
        default:
            std::cout << "Invalid input! Use w/a/s/d or q to quit." << std::endl;
            validInput = false;
        }

        if (!validInput)
            continue;

        // Try to make the step
        Position oldPos = player.getPosition();
        bool moved = player.step(dir, world.getWidth(), world.getHeight());

        if (!moved)
        {
            std::cout << "Can't move there! Hit boundary." << std::endl;
            continue;
        }

        // Check for obstacle collision
        if (world.hasObstacle(player.getX(), player.getY()))
        {
            std::cout << "Hit an obstacle! Moving back." << std::endl;
            player.setPosition(oldPos);
            continue;
        }

        steps++;

        // Check if goal reached
        if (world.isGoalReached(player.getPosition()))
        {
            std::cout << "\n🎉 GOAL REACHED! 🎉" << std::endl;
            std::cout << "Completed in " << steps << " steps!" << std::endl;
            world.displayGrid(player);
            break;
        }

        // Display updated grid
        std::cout << "\nCurrent Grid:" << std::endl;
        world.displayGrid(player);
        std::cout << "Position: (" << player.getX() << ", " << player.getY() << ")" << std::endl;
    }

    return 0;
}