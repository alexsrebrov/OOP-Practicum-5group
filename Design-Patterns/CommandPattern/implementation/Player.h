#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Player {
private:
    int x, y, timesJumped;
    vector<int> targetsShot;
public:
    Player() : x(0), y(0), timesJumped(0) {}

    void move(int x, int y) {
        this->x += x;
        this->y += y;
        cout << "Move (" << x << ", " << y << ")\n";
    }

    void shoot(int t) {
        targetsShot.push_back(t);
        cout << "Shoot " << t << "\n";
    }

    void jump() {
        timesJumped++;
        cout << "Jump\n";
    }

    void printStatus() {
        cout << "Player is at (" << x << ", " << y << ")\n";
        cout << "Player has jumped " << timesJumped << " times\n";
        cout << "Player has shot targets: ";
        for (int t : targetsShot) {
            cout << t << " ";
        }
        cout << "\n";
    }
};