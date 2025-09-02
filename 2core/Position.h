#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
    int x, y;

public:
    // Constructors
    Position(int x = 0, int y = 0);
    Position(const Position &other);

    // Getters
    int getX() const { return x; }
    int getY() const { return y; }

    // Setters
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    void set(int newX, int newY)
    {
        x = newX;
        y = newY;
    }

    // Operators
    Position &operator=(const Position &other);
    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;

    // Utility
    double distanceTo(const Position &other) const;
    void display() const;
};

#endif // POSITION_H