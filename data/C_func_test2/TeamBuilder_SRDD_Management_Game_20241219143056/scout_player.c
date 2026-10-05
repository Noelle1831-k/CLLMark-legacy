Player scout_player() {
    char name[50];
    sprintf(name, "Player%d", rand() % 1000);
    int age = rand() % 10 + 18;
    int skill_level = rand() % 50 + 50;
    int stamina = rand() % 30 + 50;
    int experience = rand() % 40 + 10;
    Player new_player = create_player(name, age, skill_level, stamina, experience);
    printf("Scouted new player: %s\n", new_player.name);
    return new_player;
}