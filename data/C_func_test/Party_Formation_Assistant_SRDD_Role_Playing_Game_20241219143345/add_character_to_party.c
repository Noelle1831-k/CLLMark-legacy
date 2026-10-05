void add_character_to_party(Party* party, Character* character) {
    if (MAX_PARTY_SIZE > party->size) {
        party->characters[party->size++] = *character;
    } else {
        printf("Party is full. Cannot add more characters.\n");
    }
}