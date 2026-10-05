void print_party(const Party* party) {
    for (int i = 0; i < party->size; i++) {
        print_character(&party->characters[i]);
    }
}