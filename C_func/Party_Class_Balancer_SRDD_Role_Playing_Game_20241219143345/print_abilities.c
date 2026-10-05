void print_abilities(const CharacterClass* cclass) {
    printf("Abilities for %s:\n", cclass->name);
    for (int i = 0; i < cclass->num_abilities; i++) {
        printf("  %s: Strength %d\n", cclass->abilities[i].name, cclass->abilities[i].strength);
    }
}