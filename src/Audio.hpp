#pragma once

namespace Audio
{
    inline float musicVol = 1.0f;
    inline float sfxVol = 1.0f;

    void Play(const char* key, float vol = 1.0f, float pitch = 1.0f);
    void ApplyMusicVolume();
}
