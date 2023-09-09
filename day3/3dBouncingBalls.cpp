# made my 2d bouncing balls 3d for fun 
#include <raylib.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Sphere {
public:
    Vector3 pos;
    float radius;
    Color color;
    Vector3 velocity;

    static Sphere spawnSphere() {
        Sphere sphere;
        sphere.radius = (float)GetRandomValue(1, 5);

        // Adjusted spawn position within the camera's view, slightly above zero
        sphere.pos = {(float)GetRandomValue(-20, 20),
                      11.0f, // Adjusted initial height above zero
                      (float)GetRandomValue(-20, 20)};

        // Set a random color
        int colorValue = GetRandomValue(1, 3);
        if (colorValue == 1) {
            sphere.color = RED;
        }
        else if (colorValue == 2) {
            sphere.color = BLUE;
        }
        else {
            sphere.color = GREEN;
        }

        // Set a random velocity
    sphere.velocity.x = (float)GetRandomValue(-1.0f, 1.0f); // Adjust as needed
    sphere.velocity.y = (float)GetRandomValue(-0.02f, 0.02f);
    sphere.velocity.z = (float)GetRandomValue(-1.0f, 1.0f); ;

        return sphere;
    }

    float distance(Vector3 p1, Vector3 p2) {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
    }

    float dotProduct(Vector3 v1, Vector3 v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    float vectorLength(Vector3 v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    };
    static Vector3 Normalize(Vector3 v) {
        float length = sqrt(v.x * v.x + v.y * v.y +v.z * v.z);
        if (length > 0)
            return Vector3{ v.x / length, v.y / length, v.z / length };
        else
            return Vector3{ 0, 0, 0 };
    }

    static Vector3 Scale(Vector3 v, float scale) {
        return Vector3{ v.x * scale, v.y * scale, v.z * scale };
    }
};

class SphereManager {
public:
    static const int MAX_SPHERES = 200;
    int sphereCount;
    std::vector<Sphere> spheres;

    SphereManager() : sphereCount(0) {}

    void addSphere() {
        if (sphereCount < MAX_SPHERES) {
            Sphere newSphere = Sphere::spawnSphere();
            spheres.push_back(newSphere);
            sphereCount++;
        }
    }

    void update() {
        for (int i = 0; i < sphereCount; i++) {
            // Update sphere position and apply gravity as before
            spheres[i].pos.x += spheres[i].velocity.x;
            spheres[i].pos.y += spheres[i].velocity.y;
            spheres[i].pos.z += spheres[i].velocity.z;

            // Apply gravity
            spheres[i].velocity.y -= 0.02f;
       
            // Check for collisions with other spheres
            for (int j = 0; j < sphereCount; j++) {
                if (i != j) {
                    float distance = spheres[i].distance(spheres[i].pos, spheres[j].pos);
                    float sumRadii = spheres[i].radius + spheres[j].radius;
                    if (distance < sumRadii) {
                        // Spheres i and j are colliding
                        Vector3 collisionNormal = {
                            spheres[i].pos.x - spheres[j].pos.x,
                            spheres[i].pos.y - spheres[j].pos.y,
                            spheres[i].pos.z - spheres[j].pos.z
                        };
                        collisionNormal = Sphere::Normalize(collisionNormal);

                        // Calculate relative velocity
                        Vector3 relativeVelocity = {
                            spheres[j].velocity.x - spheres[i].velocity.x,
                            spheres[j].velocity.y - spheres[i].velocity.y,
                            spheres[j].velocity.z - spheres[i].velocity.z
                        };

                        // Calculate impulse (change in velocity) using restitution factor
                        float impulse = -2.0f * spheres[i].dotProduct(relativeVelocity, collisionNormal) / (1.0f / 0.8f);

                        // Apply impulse to spheres i and j
                        spheres[i].velocity = {
                            spheres[i].velocity.x - collisionNormal.x * impulse,
                            spheres[i].velocity.y - collisionNormal.y * impulse,
                            spheres[i].velocity.z - collisionNormal.z * impulse
                        };
                        spheres[j].velocity = {
                            spheres[j].velocity.x + collisionNormal.x * impulse,
                            spheres[j].velocity.y + collisionNormal.y * impulse,
                            spheres[j].velocity.z + collisionNormal.z * impulse
                        };
                    }
                }
            }

    // Check for collisions with walls and reflect velocity (You'll need to add this part)
 

            // Check for collisions with walls and reflect velocity
            if (spheres[i].pos.y - spheres[i].radius < 0) {
                // Bounce on ground (Y-level 0)
                spheres[i].pos.y = spheres[i].radius;
                spheres[i].velocity.y *= -0.7f; // Bounce factor
            }

            if (spheres[i].pos.y + spheres[i].radius > 100.0f) {
                // Bounce off the ceiling
                spheres[i].pos.y = 100.0f - spheres[i].radius;
                spheres[i].velocity.y *= -0.7f; // Bounce factor
            }

            if (spheres[i].pos.x - spheres[i].radius < -50.0f) {
                // Bounce off the left wall
                spheres[i].pos.x = -50.0f + spheres[i].radius;
                spheres[i].velocity.x *= -0.7f; // Bounce factor
            }

            if (spheres[i].pos.x + spheres[i].radius > 50.0f) {
                // Bounce off the right wall
                spheres[i].pos.x = 50.0f - spheres[i].radius;
                spheres[i].velocity.x *= -0.7f; // Bounce factor
            }

            if (spheres[i].pos.z - spheres[i].radius < -50.0f) {
                // Bounce off the back wall
                spheres[i].pos.z = -50.0f + spheres[i].radius;
                spheres[i].velocity.z *= -0.7f; // Bounce factor
            }

            if (spheres[i].pos.z + spheres[i].radius > 50.0f) {
                // Bounce off the front wall
                spheres[i].pos.z = 50.0f - spheres[i].radius;
                spheres[i].velocity.z *= -0.7f; // Bounce factor
            }
            // Bounce on ground (Y-level 0)
            if (spheres[i].pos.y - spheres[i].radius < 0) {
                spheres[i].pos.y = spheres[i].radius;
                spheres[i].velocity.y *= -0.7f; // Bounce factor
            }
        }
    }
};



int main(void) {
    InitWindow(1280, 720, "Spheres Falling");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 60.0f, 60.0f, 60.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 3.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SphereManager manager;
    bool isMouseButtonDown = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && !isMouseButtonDown) {
            manager.addSphere();
            isMouseButtonDown = true;
        }
        else if (!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            isMouseButtonDown = false;
        }

        manager.update();

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);
        DrawGrid(100, 1.0f);
        for (int i = 0; i < manager.sphereCount; i++) {
            DrawSphere(manager.spheres[i].pos, manager.spheres[i].radius, manager.spheres[i].color);
            DrawSphereWires(manager.spheres[i].pos, manager.spheres[i].radius, 10, 10, WHITE);
        }
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

