#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 400;
const int KEY_WIDTH = 60;
const int KEY_HEIGHT = 200;
const int KEY_SPACING = 10;

const char* FONT_PATH = "arial.ttf";

struct Note {
    const char* label;
    const char* soundFile;
    SDL_Rect rect;
    Mix_Chunk* sound;
};

int main(int argc, char* argv[]) {
    // Inisialisasi SDL, SDL_TTF, dan SDL_Mixer
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 || TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL or SDL_ttf: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Buffer size lebih kecil untuk mengurangi latency
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 512) < 0) {
        std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        return -1;
    }

    // Buat window
    SDL_Window* window = SDL_CreateWindow("Pianika", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load font
    TTF_Font* font = TTF_OpenFont(FONT_PATH, 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return -1;
    }

    // Load sounds dan setup rect untuk tuts pianika
    Note notes[] = {
        {"Do", "assets/do.wav", {50, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Re", "assets/re.wav", {120, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Mi", "assets/mi.wav", {190, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Fa", "assets/fa.wav", {260, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Sol", "assets/sol.wav", {330, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"La", "assets/la.wav", {400, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Si", "assets/si.wav", {470, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Do (Stretched)", "assets/do_stretched.wav", {540, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Fa (Stretched)", "assets/fa_stretched.wav", {610, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr},
        {"Sol (Stretched)", "assets/sol_stretched.wav", {680, 100, KEY_WIDTH, KEY_HEIGHT}, nullptr}
    };

    for (auto& note : notes) {
        note.sound = Mix_LoadWAV(note.soundFile);
        if (!note.sound) {
            std::cerr << "Failed to load sound: " << Mix_GetError() << std::endl;
            return -1;
        }
    }

    bool quit = false;
    bool isPressed[10] = {false}; // Array untuk melacak status tuts
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
                bool keyDown = (e.type == SDL_KEYDOWN);
                switch (e.key.keysym.sym) {
                    case SDLK_a: isPressed[0] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[0].sound, 0); break;
                    case SDLK_s: isPressed[1] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[1].sound, 0); break;
                    case SDLK_d: isPressed[2] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[2].sound, 0); break;
                    case SDLK_f: isPressed[3] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[3].sound, 0); break;
                    case SDLK_g: isPressed[4] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[4].sound, 0); break;
                    case SDLK_h: isPressed[5] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[5].sound, 0); break;
                    case SDLK_j: isPressed[6] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[6].sound, 0); break;
                    case SDLK_k: isPressed[7] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[7].sound, 0); break;
                    case SDLK_l: isPressed[8] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[8].sound, 0); break;
                    case SDLK_m: isPressed[9] = keyDown; if (keyDown) Mix_PlayChannel(-1, notes[9].sound, 0); break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 10; ++i) {
            if (isPressed[i]) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Warna merah ketika ditekan
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Warna hitam ketika tidak ditekan
            }
            SDL_RenderFillRect(renderer, &notes[i].rect);

            SDL_Color color = {255, 255, 255, 255};
            SDL_Surface* surface = TTF_RenderText_Solid(font, notes[i].label, color);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect = {notes[i].rect.x + 10, notes[i].rect.y + 80, surface->w, surface->h};
            SDL_RenderCopy(renderer, texture, nullptr, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    for (auto& note : notes) {
        Mix_FreeChunk(note.sound);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
