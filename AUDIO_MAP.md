# Audio Asset Map

Which sound file plays at which moment, and where to change it.

## Music

| File | Used for | Triggered in |
|------|----------|--------------|
| `Darkling.mp3` | Background music, loops on every screen | Started in `Game` constructor; volume via Audio settings |

## Player

| File | Used for | Triggered in |
|------|----------|--------------|
| `212606__nail.wav` | Gunshot (every shot) | `Game::updateShooting` |
| `concrete-footsteps-6752.wav` | Walking loop while moving | `Player::Update` |
| `concrete-footsteps-stop.wav` | Scuff when you stop moving; also the test "tick" on the SFX slider | `Player::Update`, `Game` Audio settings |
| `515624__PlayerHurt1.wav` | Player takes a hit (random pick 1 of 2) | `Player::Hit` |
| `515623__PlayerHurt2.wav` | Player takes a hit (the other 50%) | `Player::Hit` |
| `469567__PlayerDie.wav` | Player dies (last HP lost) | `Player::Hit` |
| `484298__Knight_Grunt.wav` | Battle cry at each wave start | `Game::startWave` |

## Enemies

| File | Used for | Triggered in |
|------|----------|--------------|
| `316264__Zombie_Pain.wav` | ANY enemy surviving a hit (random pitch) | `Enemy::TakeDamage` |
| `316260__Zombie_Death.wav` | Death of **cockroach** and **troll** | `Enemy::Kill` |
| `76961_Mutant_Death.wav` | Death of **scorpion** and **kliver** | `Enemy::Kill` |
| `316258__Zombie_Grunt.wav` | Ambient grunt of **cockroach** (distance-based volume) | `Enemy::grunt` |
| `76973__Mutant_Grunt.wav` | Ambient grunt of **scorpion** and **kliver** | `Enemy::grunt` |
| `76957__Grunt_Grunt.wav` | Ambient grunt of **troll** | `Enemy::grunt` |

## Pickups

| File | Used for | Triggered in |
|------|----------|--------------|
| `523655__powerup.wav` | Health potion collected | `Game::updateCollisions` |

All 14 audio files are in use; none are idle.

## How to replace a sound

1. **Swap the file, keep the name** — drop the new .wav into `assets/audio`
   with the same filename. Zero code changes.
2. **New filename** — edit ONE line in `ResourceManager::Load()`
   (`src/ResourceManager.cpp`), e.g.
   `loadSound(RK::SND_SHOOT, "my-new-gun.wav");`
   The rest of the code refers to the key (`RK::SND_SHOOT`), never the filename.
3. **Change which enemy uses which death/grunt sound** — edit the last two
   columns of the type table in `src/EnemyType.hpp`.
4. **Add a brand-new sound** — add a key in `src/ResourceKeys.hpp`, a
   `loadSound` line in `ResourceManager::Load()`, then play it anywhere with
   `Audio::Play(RK::YOUR_KEY)`.
