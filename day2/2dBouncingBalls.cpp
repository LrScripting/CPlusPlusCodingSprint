#bad syntax bouncing balls program with raylib to see how using libraries works
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class cBall {
public:
    Vector2 position;
    int radius;
    Vector2 velocity;
    Color color;
    int maxBalls;

    static cBall spawnCBall(Vector2 mousePos) {
        cBall newBall;
        newBall.position = mousePos;
        newBall.radius = GetRandomValue(20, 50);
        newBall.velocity.x = GetRandomValue(-0.6, 0.6);
        newBall.velocity.y = GetRandomValue(-0.8, 1);
        int colorValue = GetRandomValue(1, 3);
        if (colorValue == 1) {
            newBall.color = RED;
        }
        if (colorValue == 2) {
            newBall.color = BLUE;
        }
        if (colorValue == 3) {
            newBall.color = GREEN;
        }
        return newBall;
    }

    float distance(Vector2 p1, Vector2 p2) {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }

    float dotProduct(Vector2 v1, Vector2 v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    float vectorLength(Vector2 v) {
        return sqrt(v.x * v.x + v.y * v.y);
    }
};

class ballManager {
public:
    static const int MAX_BALLS = 1000;
    int ballCount;
    static cBall balls[MAX_BALLS];

    ballManager() : ballCount(0) {}

    void addBall() {
        static bool wasMouseButtonDown = false;
        bool isMouseButtonDown = IsMouseButtonDown(MOUSE_LEFT_BUTTON);

        if (isMouseButtonDown && !wasMouseButtonDown && ballCount < MAX_BALLS) {
            cBall myBall = cBall::spawnCBall(GetMousePosition());
            balls[ballCount] = myBall;
            ballCount++;
        }

        wasMouseButtonDown = isMouseButtonDown;
    }   

    void collisionManager(cBall& b1, cBall& b2) {
        float d = b1.distance(b1.position, b2.position);
        if (d <= b1.radius + b2.radius) {
            // Calculate the direction vector between the balls
            Vector2 dir = { b2.position.x - b1.position.x, b2.position.y - b1.position.y };

            // Normalize the direction vector
            float dirLength = b1.vectorLength(dir);
            dir.x /= dirLength;
            dir.y /= dirLength;

            // Calculate relative velocity
            Vector2 relVel = { b2.velocity.x - b1.velocity.x, b2.velocity.y - b1.velocity.y };

            // Calculate impulse (change in velocity)
            float impulse = 2.0f * b1.dotProduct(relVel, dir) / (1.0f / b1.radius + 1.0f / b2.radius);

            // Apply impulse to both balls
            b1.velocity.x += impulse * dir.x / b1.radius;
            b1.velocity.y += impulse * dir.y / b1.radius;
            b2.velocity.x -= impulse * dir.x / b2.radius;
            b2.velocity.y -= impulse * dir.y / b2.radius;
        }
    }

    void update() {
        Vector2 screenSize = { 1280, 720 };
        for (int i = 0; i < ballCount; i++) {
            balls[i].velocity.y += 0.005;
            balls[i].position.x += balls[i].velocity.x;
            balls[i].position.y += balls[i].velocity.y;

            DrawCircleV(balls[i].position, balls[i].radius, balls[i].color);
            for (int j = i + 1; j < ballCount; j++) {
                cBall& b1 = balls[i];
                cBall& b2 = balls[j];
                collisionManager(b1, b2);
            }
            if (balls[i].position.x - balls[i].radius <= 0 || balls[i].position.x + balls[i].radius >= screenSize.x) {
                balls[i].velocity.x *= -1;
            }
            if (balls[i].position.y - balls[i].radius <= 0 || balls[i].position.y + balls[i].radius >= screenSize.y) {
                balls[i].velocity.y *= -1;
            }
        }
    }
};

cBall ballManager::balls[ballManager::MAX_BALLS];

int main() {
    InitWindow(1280, 720, "Bouncing Balls Example");
    ballManager manager;
    int fps = 200;
    SetTargetFPS(fps);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        manager.addBall();
        manager.update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
