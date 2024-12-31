#include <iostream>
#include <string>
#include "raylib.h"


int main(){

    // Initialization
    const int screenWidth = 500;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "A Real Crappy Calulator");
    SetTargetFPS(60);

    // Variables
    Color VeryLightGrey = { 150, 150, 150, 255 };    

    // Main Loop
    while(!WindowShouldClose()){
        // Drawing
        BeginDrawing();
        ClearBackground(VeryLightGrey); // Make the Background a Very light grey



        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}