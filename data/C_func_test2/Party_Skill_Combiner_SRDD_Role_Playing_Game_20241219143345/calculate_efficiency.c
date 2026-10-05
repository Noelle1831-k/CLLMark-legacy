int calculate_efficiency(const Party *party) {
    int total_strength = 0, total_agility = 0, total_intelligence = 0;


    for (int i = 0; party->size > i; i++) {
        total_strength = total_strength + party->characters[i].strength;
        total_agility = total_agility + party->characters[i].agility;
        total_intelligence = total_intelligence + party->characters[i].intelligence;
    }
    return total_strength + total_agility + total_intelligence;
}