#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    const int chip8Width = 64;
    const int chip8Height = 32;

    InitWindow(screenWidth, screenHeight, "Chip 8 Emulator");

    Image chip8Display = GenImageColor(chip8Width, chip8Height, BLACK);  // Chip 8 display is 64x32
    Texture2D texture = LoadTextureFromImage(chip8Display);

    while (!WindowShouldClose()) {
        // Chip 8 emulation and pixel manipulation logic
        for (int y = 0; y < chip8Height; ++y) {
            for (int x = 0; x < chip8Width; ++x) {
                // Example: Set a random pixel to white
                if (GetRandomValue(0, 100) > 99) {
                    ImageDrawPixel(&chip8Display, x, y, WHITE);
                }
            }
        }
        UpdateTexture(texture, chip8Display.data);

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the Chip 8 display scaled up
        DrawTextureEx(texture, (Vector2){ 100, 100 }, 0.0f, 10.0f, WHITE);

        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadImage(chip8Display);

    CloseWindow();

    return 0;
}
