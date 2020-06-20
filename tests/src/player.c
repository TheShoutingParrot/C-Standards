#include "../include/player.h"

#define DECAY_RATE    4
#define INITIAL_ALPHA 90
#define DECELERATION  0.90f
#define VELOCITY      5.0f

static void key_input_listener(void);

void init_player() {
    player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    player->x = SCREEN_WIDTH / 2;
    player->y = SCREEN_HEIGHT / 2;
    player->texture[0] = loadTexture("tests/res/img/player.png");
    SDL_QueryTexture(player->texture[0], NULL, NULL, &player->w, &player->h);
}

void player_update(void) {
    player->dx *= DECELERATION;
    player->dy *= DECELERATION;

    key_input_listener();
    add_trail(player, DECAY_RATE, INITIAL_ALPHA);

    player->x += player->dx;
    player->y += player->dy;
}

void player_draw(void) {
    blit(player->texture[0], player->x, player->y, false);
}

static void key_input_listener(void) {
    if (app.keyboard[SDL_SCANCODE_W]) {
        player->dy = -VELOCITY;
    }

    if (app.keyboard[SDL_SCANCODE_S]) {
        player->dy = VELOCITY;
    }

    if (app.keyboard[SDL_SCANCODE_A]) {
        player->dx = -VELOCITY;
    }

    if (app.keyboard[SDL_SCANCODE_D]) {
        player->dx = VELOCITY;
    }      
}
