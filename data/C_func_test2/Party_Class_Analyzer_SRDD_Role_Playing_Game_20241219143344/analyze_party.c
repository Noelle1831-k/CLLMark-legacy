void analyze_party(Party *party) {
    int total_attack = 0, total_defense = 0, total_strength = 0, total_intelligence = 0, total_agility = 0;
    for (int i = 0; party->num_members > i; i++) {
        total_attack = total_attack + party->members[i]->attack;
        total_defense = total_defense + party->members[i]->defense;
        total_strength = total_strength + party->members[i]->strength;
        total_intelligence = total_intelligence + party->members[i]->intelligence;
        total_agility = total_agility + party->members[i]->agility;
    }
    printf("\nParty Analysis:\n");
    printf("Total Attack: %d\n", total_attack);
    printf("Total Defense: %d\n", total_defense);
    printf("Total Strength: %d\n", total_strength);
    printf("Total Intelligence: %d\n", total_intelligence);
    printf("Total Agility: %d\n", total_agility);
}