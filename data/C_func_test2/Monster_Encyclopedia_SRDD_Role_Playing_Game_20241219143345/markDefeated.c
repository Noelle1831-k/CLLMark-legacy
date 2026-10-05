void markDefeated(Monster *monster) {
    monster->defeated = 1;
    printf("Monster %s marked as defeated.\n", monster->name);
}