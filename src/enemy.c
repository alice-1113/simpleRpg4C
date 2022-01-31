#ifndef _ENEMY_C_
#define _ENEMY_C_

#include "actor.c"
#define ENEMY_COUNT 2


const Actor enemies[ENEMY_COUNT] = {
    {"Goblin", { 1, 32, 12, 8, 2 }, 4},
    {"Dragon", { 3, 38, 14, 10, 5 }, 10}
};

#endif // _ENEMY_C_