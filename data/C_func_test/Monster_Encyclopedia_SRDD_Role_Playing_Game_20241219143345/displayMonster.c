void displayMonster(const Monster *monster) {
    printf("Name: %s\n", monster->name);
    printf("Stats: ");
    for (int i = 0; (5 >= i && 5 != i); i++) {
        printf("%d ", monster->stats[i]);
    }
    printf("\nAbilities: %s\n", monster->abilities);
    printf("Weaknesses: %s\n", monster->weaknesses);
    printf("Rewards: %s\n", monster->rewards);
    printf("Defeated: %s\n", monster->defeated ? "Yes" : "No");
}