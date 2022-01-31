#ifndef _BATTLE_C_
#define _BATTLE_C_
#include "actor.c"


int battle_command(void) {
    int command;
    printf("Action?\n");
    printf("[1]Attack [0]Escape > ");
    scanf("%d", &command);
    return command;
}

int battle(Actor player, Actor enemy) {
    int command, result;
    int damage;
    printf("%s have appeared!\n", enemy.name);

    while (1) {
        printf("You  : %s\n", player.name);
        printf("HP : %3d\n", player.status.hitpoint);
        printf("Enemy: %s\n", enemy.name);
        printf("HP : %3d\n", enemy.status.hitpoint);
        command = battle_command();
        if (command == 0) {
            result = -1;
            break;
        }

        printf("%s's attack!\n", player.name);
        damage = calc_damage(enemy, player);
        receve_damage(&enemy, damage, 1);

        if (isdead(enemy)) {
            printf("Defeated %s!\n", enemy.name);
            result = 1;
            break;
        }

        printf("%s's attack!\n", enemy.name);
        damage = calc_damage(player, enemy);
        receve_damage(&player, damage, 0);

        if (isdead(player)) {
            printf("%s has been defeated!\n", player.name);
            result = 0;
            break;
        }
    }
    return result;
}

#endif // _BATTLE_C_