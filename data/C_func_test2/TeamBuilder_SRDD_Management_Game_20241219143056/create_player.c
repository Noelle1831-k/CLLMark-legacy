Player create_player(char *name, int age, int skill_level, int stamina, int experience) {
    Player new_player;
    strcpy(new_player.name, name);
    new_player.age = age;
    new_player.skill_level = skill_level;
    new_player.stamina = stamina;
    new_player.experience = experience;
    return new_player;
}