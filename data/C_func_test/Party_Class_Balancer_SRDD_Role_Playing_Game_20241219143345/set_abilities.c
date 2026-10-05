void set_abilities(CharacterClass* cclass, int num_abilities) {
    cclass->num_abilities = num_abilities;
    cclass->abilities = (Ability*)malloc(sizeof(Ability) * num_abilities);
    if (!cclass->abilities) {
        printf("Memory allocation for abilities failed.\n");
        exit(1);
    }
    for (int i = 0; i < num_abilities; i++) {
        printf("Enter ability %d for class %s: ", i + 1, cclass->name);
        scanf("%s", cclass->abilities[i].name);
        printf("Enter strength for %s: ", cclass->abilities[i].name);
        scanf("%d", &cclass->abilities[i].strength);
    }
}