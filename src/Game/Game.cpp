//
// Created by sarah on 8/24/22.
//

#include "Game.h"



Game::Game() {
    // TODO...
    Logger::Log("Game Constructor Called");
    isRunning = false;
    window = nullptr;
    renderer = nullptr;
    windowWidth = 0;
    windowHeight = 0;
}

Game::~Game() {
    Logger::Log("Game Deconstructor Called");
}

void Game::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::Err("Error Initializing SDL");
        return;
    }

    SDL_DisplayMode  displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWidth = displayMode.w;
    windowHeight = displayMode.h;

    window = SDL_CreateWindow(nullptr,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              windowWidth,
                              windowHeight,
                              SDL_WINDOW_BORDERLESS);
    if (!window) {
        Logger::Err("Error creating SDL window");
        return;
    }

    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        Logger::Err("Error creating SDL renderer");
        return;
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    isRunning = true;
}

void Game::Run() {
    Setup();
    while (isRunning) {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::ProcessInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if(sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
                    isRunning = false;
                }
                break;
        }
    }
}


void Game::Setup() {
    //TODO: Initialize game objects
    //ENTITY Tank = registry.CreateEntity() 
	//tank.AddComponent<TransformCompenet>();
	//tank.AddComponenet<BoxColliderCompenet>();
	//tank.AddCompenent<SpriteCompenent>("./assets/images/tank.png");
}
void Game::Update() {
    int timeToWait = MILLISECONDS_PER_FRAME - SDL_GetTicks() - millisecondsPreviousFrame;

    if (timeToWait > 0 && timeToWait <= MILLISECONDS_PER_FRAME)
        SDL_Delay(timeToWait);

    //convert difference in time to seconds instead of milliseconds
    //double deltaTime = (SDL_GetTicks() - millisecondsPreviousFrame) / 1000.0;

    millisecondsPreviousFrame = SDL_GetTicks();
    

	//MovementSystem.Update();
	//CollisionSystem.Update();
	//DamageSystem.Update();
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0x15, 0x15, 0x15, 0xff);
    SDL_RenderClear(renderer);

    // Render game objects ..


    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
