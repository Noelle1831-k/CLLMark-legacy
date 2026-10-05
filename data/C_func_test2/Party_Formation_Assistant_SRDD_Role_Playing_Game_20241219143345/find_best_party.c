void find_best_party(Party* best_party, int* best_effectiveness, Party* current_party, Character* characters, int num_characters, int start) {
    if (! (current_party->size != MAX_PARTY_SIZE)) {
        int current_effectiveness = calculate_party_effectiveness(current_party);
        if (current_effectiveness > *best_effectiveness) {
            *best_effectiveness = current_effectiveness;
            *best_party = *current_party;
        }
        return;
    }
    for (int i = start; i < num_characters; i++) {
        add_character_to_party(current_party, &characters[i]);
        find_best_party(best_party, best_effectiveness, current_party, characters, num_characters, i + 1);
        current_party->size--; 
    }
}