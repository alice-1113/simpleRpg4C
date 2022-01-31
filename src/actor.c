#ifndef _ACTOR_C_
#define _ACTOR_C_
#define MAXLV 100


typedef struct {
    int level;
    int hitpoint;
    int strength;
    int defence;
    int exp;
} Status;

typedef struct {
    char name[20];
    Status status;
    int money;
} Actor;

void init_status(Status* status) {
    status->level = 1;
    status->hitpoint = 32;
    status->strength = 12;
    status->defence = 8;
    status->exp = 0;
}

void copy_status(Status* copy, const Status status) {
    copy->level = status.level;
    copy->hitpoint = status.hitpoint;
    copy->strength = status.strength;
    copy->defence = status.defence;
    copy->exp = status.exp;
}

void show_status(const Status status) {
    printf("Lv : %3d\n", status.level);
    printf("HP : %3d\n", status.hitpoint);
    printf("STR: %3d\n", status.strength);
    printf("DEF: %3d\n", status.defence);
    printf("EXP: %3d\n", status.exp);
}


int calc_damage(const Actor target, const Actor source) {
    return (source.status.strength * 4 / target.status.defence * 2) + rand() % (source.status.strength / 4);

}

void receve_damage(Actor* source, const int damage, int message_type) {
    if (message_type == 0) {
        printf("%s took %d damage!\n", source->name, damage);
    } else {
        printf("Inflicted %d damage on %s!\n", damage, source->name);
    }
    source->status.hitpoint -= damage;
}

int isdead(const Actor source) {
    return source.status.hitpoint <= 0;
}

#endif // _ACTOR_C_