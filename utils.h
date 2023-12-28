#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <vector>

class Square;

using Block = Square*;

const int BLOCK = 30;

const int SCORE = 10;

const int COLUMNS = 10;
const int ROWS = 20;

const int TETRO_CENTER = COLUMNS / 2 - 2;

enum Directions { DOWN, RIGHT, LEFT };
enum SceneType { MAIN, NEXT, HOLD, DEFAULT };
enum RotationState { SPAWN, CLOCKWISE, SECOND, COUNTER_CLOCKWISE };
enum DataSet { NORMAL, O_PEACE, I_PEACE };

enum TetrominoType {
    HORIZONTAL,
    LEFT_CORNER,
    RIGHT_CORNER,
    SQUARE,
    STEP_UP_RIGHT,
    PYRAMID,
    STEP_UP_LEFT,
    NUMBER_OF_TETROMINOS
};

struct Coords {
    Coords() : x(0), y(0) {}
    Coords(const double& x_, const double& y_) : x(x_), y(y_) {}
    Coords(const Coords& c) : x(c.x), y(c.y) {}
    Coords operator+(const Coords& p) const { return Coords(x + p.x, y + p.y); }
    Coords operator-(const Coords& p) const { return Coords(x - p.x, y - p.y); }
    bool operator==(const Coords& p) const { return x == p.x && y == p.y; }
    Coords(Directions direction) {
        switch (direction) {
        case DOWN:
            x = 0;
            y = 1;
            break;

        case RIGHT:
            x = 1;
            y = 0;
            break;

        case LEFT:
            x = -1;
            y = 0;
            break;

        default:
            x = 0;
            y = 0;
            break;
        }
    }

    double x;
    double y;
};

using Dataset = std::map<RotationState, std::vector<Coords>>;

static Dataset normalDataset = {
    {SPAWN, {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},
    {CLOCKWISE, {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}}},
    {SECOND, {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}},
    {COUNTER_CLOCKWISE, {{0, 0}, {-1, 0}, {-1, 1}, {0, -1}, {-1, -2}}}};

static Dataset IBlockDataset = {
    {SPAWN, {{0, 0}, {-1, 0}, {2, 0}, {-1, 0}, {2, 0}}},
    {CLOCKWISE, {{-1, 0}, {0, 0}, {0, 0}, {0, -1}, {0, 2}}},
    {SECOND, {{-1, -1}, {1, -1}, {-2, -1}, {1, 0}, {-2, 0}}},
    {COUNTER_CLOCKWISE, {{0, -1}, {0, -1}, {0, -1}, {0, 1}, {0, -2}}}};

static Dataset OBlockDataset = {{SPAWN, {{0, 0}}},
                                {CLOCKWISE, {{0, 1}}},
                                {SECOND, {{-1, 1}}},
                                {COUNTER_CLOCKWISE, {{-1, 0}}}};

#endif // UTILS_H
