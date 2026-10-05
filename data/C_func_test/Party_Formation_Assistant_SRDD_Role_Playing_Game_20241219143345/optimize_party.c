void optimize_party(Party* party, Character* characters, int num_characters) {
    int best_effectiveness = -1;
    Party best_party;
    Party current_party;
    initialize_party(&best_party);
    initialize_party(&current_party);
    find_best_party(&best_party, &best_effectiveness, &current_party, characters, num_characters, 0);
    *party = best_party;
}