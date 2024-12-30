#include "raylib.h"
#include <iostream>
#include <string>

void AddDigit(std::string &numDisplay, char digit);
void RemoveDigit(std::string &numDisplay);
void EraseDisplay(std::string &numDisplay);
void ConvertResultToDisplay(std::string &numDisplay);
void Add(std::string &numDisplay, float num1, float num2);

// Program main entry point
int main(void)
{
    // Initialization

    int screenWidth = 320;
    int screenHeight = 320;

    float num1 = 0.0f;
    float abs = 0.0f;
    char calcOperator;
    float result = 0.0f;
    float numSwitchCache = 0.0f;

    // the '0' acts as a bool, and the space is the operator
    char opMoreThan1[2] = {'0', ' '};

    float ButtonScaleFactor = 1.0f;

    std::string display = "0000000000";

    InitWindow(screenWidth, screenHeight, "World's Greatest Calculator");

    Texture2D ButtonSheet = LoadTexture("Sprites/Square Buttons.png");
    Texture2D ButtonSheet2 = LoadTexture("Sprites/Rectangle Buttons.png");

    Rectangle ButtonSheet2_1Source = {0.0f, 0.0f, 32.0f, 64.0f};
    Rectangle ButtonSheet2_2Source = {32.0f, 0.0f, 32.0f, 64.0f};
    Rectangle ButtonSheet2_1Dest = {256.0f, 64.0f, 64.0f * ButtonScaleFactor, 128.0f * ButtonScaleFactor};
    Rectangle ButtonSheet2_2Dest = {256.0f, 192.0f, 64.0f * ButtonScaleFactor, 128.0f * ButtonScaleFactor};

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        Vector2 mousePosition = GetMousePosition();

        // Draw

        BeginDrawing();

            ClearBackground(DARKGRAY);

            DrawText(display.c_str(), 7, 18, 52, BLACK);

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                if(CheckCollisionPointRec(mousePosition, ButtonSheet2_1Dest)){
                    switch(calcOperator){
                        case '+':
                        //Operation()
                        abs = std::stof(display);
                        EraseDisplay(display);
                        display = std::to_string(num1 + abs);
                        //display.insert(display.begin(), 10.0f - );
                        break;
                        case '-':

                        break;
                        case '*':

                        break;
                        case '/':

                        break;
                    }
                }
            }

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                if(CheckCollisionPointRec(mousePosition, ButtonSheet2_2Dest)){
                    AddDigit(display, '.');
                }
            }

            for (int a = 0; a <= 3; a++) {
                for (int i = 0; i <= 3; i++) {
                    Rectangle sourceButtonRec = {i * 32.0f, a * 32.0f, 32.0f, 32.0f};
                    Rectangle destinationButtonRec = {i * 64.0f, (a * 64.0f) + 64.0f , 64.0f * ButtonScaleFactor, 64.0f * ButtonScaleFactor};
                    DrawTexturePro(ButtonSheet, sourceButtonRec, destinationButtonRec, (Vector2){0, 0}, 0.0f, WHITE);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        if(CheckCollisionPointRec(mousePosition, destinationButtonRec)){
                            if(num1 == numSwitchCache){
                                num1 = 0.0f;
                            }
                            switch(a){
                                case 0:
                                switch(i){
                                    case 0:
                                    AddDigit(display, '1');
                                    break;
                                    case 1:
                                    AddDigit(display, '2');
                                    break;
                                    case 2:
                                    AddDigit(display, '3');
                                    break;
                                    case 3:
                                    num1 = std::stof(display);
                                    EraseDisplay(display);
                                    calcOperator = '+';
                                    break;
                                }
                                break;
                                case 1:
                                switch(i){
                                    case 0:
                                    AddDigit(display, '4');
                                    break;
                                    case 1:
                                    AddDigit(display, '5');
                                    break;
                                    case 2:
                                    AddDigit(display, '6');
                                    break;
                                    case 3:
                                    num1 = std::stof(display);
                                    EraseDisplay(display);
                                    calcOperator = '-';
                                    break;
                                }
                                break;
                                case 2:
                                switch(i){
                                    case 0:
                                    AddDigit(display, '7');
                                    break;
                                    case 1:
                                    AddDigit(display, '8');
                                    break;
                                    case 2:
                                    AddDigit(display, '9');
                                    break;
                                    case 3:
                                    num1 = std::stof(display);
                                    EraseDisplay(display);
                                    calcOperator = '*';
                                    break;
                                }
                                break;
                                case 3:
                                switch(i){
                                    case 0:

                                    break;
                                    case 1:
                                    AddDigit(display, '0');
                                    break;
                                    case 2:
                                    RemoveDigit(display);
                                    break;
                                    case 3:
                                    num1 = std::stof(display);
                                    EraseDisplay(display);
                                    calcOperator = '/';
                                    break;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            DrawTexturePro(ButtonSheet2, ButtonSheet2_1Source, ButtonSheet2_1Dest, (Vector2){0, 0}, 0.0f, WHITE);
            DrawTexturePro(ButtonSheet2, ButtonSheet2_2Source, ButtonSheet2_2Dest, (Vector2){0, 0}, 0.0f, WHITE);

        EndDrawing();
    }

    UnloadTexture(ButtonSheet);

    // De-Initialization
    CloseWindow();

    return 0;
}

void AddDigit(std::string &numDisplay, char digit){
    numDisplay.insert(numDisplay.end(), digit);
    numDisplay.erase(numDisplay.begin());
}

void RemoveDigit(std::string &numDisplay){
    numDisplay.erase(numDisplay.end() - 1);
    numDisplay.insert(numDisplay.begin(), '0');
}

void EraseDisplay(std::string &numDisplay){
    for(int i = 0; i < 10; i++){
        RemoveDigit(numDisplay);
    }
}

void ConvertResultToDisplay(std::string &numDisplay){

}

/*void Operation(std::string &numDisplay, float num1, float num2, char op){
    switch(op)
        case '+':

        break;
        case '-':

        break;
        case '*':

        break;
        case '/':

        break;
}*/
