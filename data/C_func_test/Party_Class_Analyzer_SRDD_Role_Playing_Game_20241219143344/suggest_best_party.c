void suggest_best_party(Party *party) {
    int total_attack = 0, total_defense = 0, total_strength = 0, total_intelligence = 0, total_agility = 0;
    for (int i = 0; i < party->num_members; i++) {
        total_attack += party->members[i]->attack;
        total_defense += party->members[i]->defense;
        total_strength += party->members[i]->strength;
        total_intelligence += party->members[i]->intelligence;
        total_agility += party->members[i]->agility;
    }
    if (total_attack > total_defense && total_strength > total_intelligence) {
        printf("Suggested Party Composition: Focus on offense and physical strength.\n");
    } else {
        printf("Suggested Party Composition: Focus on defense and intelligence.\n");
    }
}