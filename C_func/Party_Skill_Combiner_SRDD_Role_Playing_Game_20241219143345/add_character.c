void add_character(Party *party, const Character *character) {
    if (party->size < 10) {
        party->characters[party->size] = *character;
        party->size++;
    }
}