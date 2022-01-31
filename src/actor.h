#ifndef _ACTOR_H_
#define _ACTOR_H_

typedef char* string;

typedef struct {
    int level;
    int hitpoint;
    int magicpower;
    int strength;
    int defence;
    int exp;
} Status;

typedef struct {
    string name;
    Status status;
    int money;
} Actor;

void init_status(Status* status);
void earn_exp(Status* status, const int exp);
int canLevelUp(const Status status, const int exp);
void levelUp(Status* status);
void show_status(const Status status);
void show_player(const Actor player);
void earn_money(Actor* player, const int money);

#endif // _ACTOR_H_