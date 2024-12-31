#include <iostream>
#include <string>
#include "raylib.h"

// Function Declaration
void AppendDigit(float Digit, float Display);
void RemoveDigit(float Digit, float Display);
void EraseDisplay(float Display);
void Add(float num1, float num2, float Display);
void Subtract(float num1, float num2, float Display);
void Multiply(float num1, float num2, float Display);
void Divide(float num1, float num2, float Display);

int main(){

    // Initialization
    const int screenWidth = 500;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "A Real Crappy Calulator");
    SetTargetFPS(60);

    // Costants
    Color VeryLightGrey = { 150, 150, 150, 255 };

    // Variables
    float display = 0.0f; // Where the result will output to
    std::string displaystr = "0000000000" ; // Constantly set to the str value of "display" in a function
    float num1 = 0.0f;
    float num2 = 0.0f;

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

// Function Definition
void AppendDigit(float Digit, float Display){

}
void RemoveDigit(float Digit, float Display){

}
void EraseDisplay(float Display){

}
void Add(float num1, float num2, float Display){

}
void Subtract(float num1, float num2, float Display){

}
void Multiply(float num1, float num2, float Display){

}
void Divide(float num1, float num2, float Display){
    
}
