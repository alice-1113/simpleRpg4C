#ifndef _ENEMY_C_
#define _ENEMY_C_

#include "actor.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int init_enemies(Actor enemies[100]) {
    FILE* fp;
    Actor tmp;
    char* fname = "enemy.tsv";
    char buff[150];
    int idx=0;
    char name[30], lv[3], hp[4], str[4], def[4], exp[4], money[4];
    fp = fopen(fname, "r");
    if (fp==NULL) { exit(1); }
    while (fgets(buff, 150, fp) != NULL) {
        sscanf(buff, "%s %s %s %s %s %s %s", name, lv, hp, str, def, exp, money);
        strcpy(tmp.name, name);
        Status stmp = {atoi(lv), atoi(hp), atoi(str), atoi(def), atoi(exp)};
        tmp.status = stmp;
        tmp.money = atoi(money);
        enemies[idx] = tmp;
        idx++;
    }
    fclose(fp);
    return idx;
}


#endif // _ENEMY_C_