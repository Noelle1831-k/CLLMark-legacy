void add_character_to_party(Party* party, Character* character) {
    if (party->size < MAX_PARTY_SIZE) {
        party->characters[party->size++] = *character;
    } else {
        printf("Party is full. Cannot add more characters.\n");
    }
}