#include <algorithm>
#include "raylib.h"
#include "GameConfig.hpp"
#include "ResourceManager.hpp"
#include "Game.hpp"


int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GameConfig::BASE_W, GameConfig::BASE_H, "NEON TRIGGER");
    InitAudioDevice();
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    RM::get().Load();

    RenderTexture2D canvas = LoadRenderTexture(GameConfig::BASE_W, GameConfig::BASE_H);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_BILINEAR);

    Game game; // Whole Game.cpp constructor ke ekhane anbe

    while (!WindowShouldClose() && !game.HandleInput())
    {
        game.Update(GetFrameTime());
        game.Draw(canvas);

        //letterboxing korbo next 6 line
        float scale = std::min(
            (float)GetScreenWidth() / GameConfig::BASE_W,
            (float)GetScreenHeight() / GameConfig::BASE_H);

        float offsetX = (GetScreenWidth() - GameConfig::BASE_W * scale) * 0.5f;
        float offsetY = (GetScreenHeight() - GameConfig::BASE_H * scale) * 0.5f;

        Rectangle src = {0, 0, (float)GameConfig::BASE_W, -(float)GameConfig::BASE_H};
        Rectangle dest = {offsetX, offsetY, GameConfig::BASE_W * scale, GameConfig::BASE_H * scale};

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(canvas.texture, src, dest, {0, 0}, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(canvas);
    RM::get().Unload();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
