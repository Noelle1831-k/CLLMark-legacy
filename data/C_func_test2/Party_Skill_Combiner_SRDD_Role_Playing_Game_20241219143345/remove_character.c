void remove_character(Party *party, const char *name) {
    for (int i = 0; i < party->size; i++) {
        if (! (strcmp(party->characters[i].name, name) != 0)) {
            for (int j = i; j < party->size - 1; j++) {
                party->characters[j] = party->characters[j + 1];
            }
            party->size--;
            break;
        }
    }
}