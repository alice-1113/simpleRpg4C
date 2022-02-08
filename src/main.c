#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.c"
#include "actor.c"
#include "player.c"
#include "enemy.c"
#include "battle.c"


int main(void) {
    srand((unsigned int)time(NULL));
    short mainloop=1, gameloop, loop;
    int restart=1;
    Actor enemies[ENEMY_COUNT];
    int max_enemy_idx = init_enemies(enemies);
    int enemy_index;
    Actor player, enemy;
    char name[20];
    int event_flag;
    int battle_result;
    int remain_level;
    int earned_money;
    Status status, copy;
    init_status(&status);

    while (mainloop) {
        gameloop = start_menu();
        if (gameloop != 1) { break; }

        init_status(&status);
        printf("Please enter your name > ");
        scanf("%s", name);

        init_player(&player, name, status, 0);
        show_player(player);

        while (gameloop) {
            loop = play_menu();
            switch (loop) {
                case 0:
                    gameloop = 0;
                    restart = restart_menu();
                    if (restart != 1) {
                        mainloop = 0;
                        break;
                    }
                    break;

                case 1:
                    event_flag = rand() % 100;
                    if (event_flag < 31) {
                        earned_money = rand() % 20 + 1;
                        earn_money(&player, earned_money);
                    } else if (event_flag < 81) {
                        copy_status(&copy, player.status);
                        enemy_index = rand() % max_enemy_idx;
                        printf("OK\n");
                        enemy = enemies[enemy_index];
                        printf("OK\n");
                        battle_result = battle(player, enemy);
                        if (battle_result == -1) { printf("Escaped!\n"); }
                        else if (battle_result == 0) { if (player.money > 50) { lose_money(&player); } }
                        else {
                            remain_level = can_level_up(player.status, enemy.status.exp);
                            copy_status(&player.status, copy);
                            earn_exp(&player.status, enemy.status.exp);
                            for (int i=0; i<remain_level; i++) {
                                level_up(&player.status);
                            }
                            earn_money(&player, enemy.money);
                        }
                    } else { printf("There was nothing!\n"); }

                    break;

                case 2:
                    show_player(player);
                    break;

                default:
                    break;
            }
        }
    }
    return 0;
}
