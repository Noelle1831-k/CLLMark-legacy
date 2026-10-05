int calculate_party_effectiveness(const Party* party) {
    int total_effectiveness = 0;
    for (int i = 0; i < party->size; i++) {
        total_effectiveness += calculate_effectiveness(&party->characters[i]);
    }
    return total_effectiveness;
}