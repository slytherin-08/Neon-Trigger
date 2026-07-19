#include "Audio.hpp"
#include "raylib.h"
#include "ResourceKeys.hpp"
#include "ResourceManager.hpp"


void Audio::Play(const char* key, float vol, float pitch)
{
    const Sound& snd = RM::get().GetSound(key);
    SetSoundVolume(snd, vol * sfxVol);
    SetSoundPitch(snd, pitch);
    PlaySound(snd);
}

void Audio::ApplyMusicVolume()
{
    SetMusicVolume(RM::get().GetMusic(RK::MUS_DARKLING), 0.4f * musicVol);
}
