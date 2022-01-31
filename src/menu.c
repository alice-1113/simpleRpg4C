#ifndef _MENU_C_
#define _MENU_C_

int start_menu(void) {
    int mode;
    printf("SimpleRPG!\n");
    printf("[1]Start [0]Exit > ");
    scanf("%d", &mode);
    return mode;
}

int play_menu(void) {
    int mode;
    printf("[1]Explore [2]Status [0]Exit > ");
    scanf("%d", &mode);
    return mode;
}

int restart_menu(void) {
    int mode;
    printf("Restart?\n");
    printf("[1]Yes [0]No > ");
    scanf("%d", &mode);
    return mode;
}

#endif // _MENU_C_