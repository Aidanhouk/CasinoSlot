#pragma once

// these variables can be changed
inline constexpr unsigned int N_SYMBOLS_PER_SPIN = 25u;
inline constexpr float SPIN_TIME = 3.0f;
inline constexpr float TIME_BETWEEN_DRUM_SPINS = 0.5f;

// these variables depend on slot interface and images size
inline constexpr unsigned int RES_X = 1280u, RES_Y = 720u;
inline constexpr unsigned int SYMBOL_HEIGHT_PIXELS = 180u;

inline constexpr unsigned int N_DRUMS = 5u;
inline constexpr unsigned int N_ROWS_ON_SCREEN = 3u;
inline constexpr unsigned int FIRST_RESULT_SYMBOL_INDEX = N_SYMBOLS_PER_SPIN - N_ROWS_ON_SCREEN;
