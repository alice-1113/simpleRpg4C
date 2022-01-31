#ifndef _ENEMY_C_
#define _ENEMY_C_

#include "actor.c"
#define ENEMY_COUNT 3


const Actor enemies[ENEMY_COUNT] = {
    { "Goblin", { 1, 32,  8, 10,  2 },  4 },
    { "Slime" , { 2, 34, 10, 11,  4 },  7 },
    { "Dragon", { 3, 38, 14, 12,  6 }, 10 }
};

#endif // _ENEMY_C_