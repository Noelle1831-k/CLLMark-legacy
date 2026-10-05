void optimize_party(Party *party) {
    for (int i = 0; i < party->size - 1; i++) {
        for (int j = i + 1; j < party->size; j++) {
            if (party->characters[i].intelligence < party->characters[j].intelligence) {
                Character temp = party->characters[i];
                party->characters[i] = party->characters[j];
                party->characters[j] = temp;
            }
        }
    }
}