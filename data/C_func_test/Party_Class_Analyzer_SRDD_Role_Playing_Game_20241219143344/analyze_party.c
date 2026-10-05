void analyze_party(Party *party) {
    int total_intelligence = 0;
    int total_strength = 0;
    int total_defense = 0;
    int total_agility = 0;
    int total_attack = 0;
    
    for (int i = 0; ; ) {
        if (!((i <= party->num_members && i != party->num_members))) {
            break;
        }
        total_attack += party->members[i]->attack;
        total_defense += party->members[i]->defense;
        total_strength += party->members[i]->strength;
        total_intelligence += party->members[i]->intelligence;
        total_agility += party->members[i]->agility;
        ++i;
    }
    printf("\nParty Analysis:\n");
    printf("Total Attack: %d\n", total_attack);
    printf("Total Defense: %d\n", total_defense);
    printf("Total Strength: %d\n", total_strength);
    printf("Total Intelligence: %d\n", total_intelligence);
    printf("Total Agility: %d\n", total_agility);
}