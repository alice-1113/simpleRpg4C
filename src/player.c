#ifndef _PLAYER_C_
#define _PLAYER_C_
#include <string.h>
#include "actor.c"


void earn_exp(Status* status, const int exp) {
    printf("Earn %3d EXP!\n", exp);
    status->exp += exp;
}

int can_level_up(const Status status, const int exp) {
    int exp_table[100];
    int i;

    for (i=0; i<100; i++) {
        exp_table[i] = (4+i)*i;
    }

    for (i=0; i<100; i++) {
        if ((status.exp + exp) < exp_table[i]) { return i-status.level-1; }
    }
    return -1;
}

void level_up(Status* status) {
    if (status->level >= MAXLV) {
        return;
    }
    int newhp, newstr, newdef;
    newhp = rand() % 8 + 2;
    newstr = rand() % 6 + 2;
    newdef = rand() % 4 + 1;
    printf("Levelup!\n");
    printf("Lv : %3d -> %3d\n", status->level, status->level+1);
    printf("HP : %3d -> %3d\n", status->hitpoint,  status->hitpoint+newhp);
    printf("STR: %3d -> %3d\n", status->strength,  status->strength+newstr);
    printf("DEF: %3d -> %3d\n", status->defence,  status->defence+newdef);
    status->level++;
    status->hitpoint += newhp;
    status->strength += newstr;
    status->defence += newdef;
}


void init_player(Actor* player, const char name[20], const Status status, const int money) {
    strcpy(player->name, name);
    player->status = status;
    player->money = money;
}

void show_player(const Actor player) {
    printf("Name : %s\n", player.name);
    printf("Money: %5d\n", player.money);
    show_status(player.status);
}

void earn_money(Actor* player, const int money) {
    printf("Earn %3d G!\n", money);
    player->money += money;
}

void lose_money(Actor* player) {
    int money = rand() % (player->money/4) + 1;
    printf("Lost %3d G...\n", money);
    player->money -= money;
}

#endif // _PLAYER_C_