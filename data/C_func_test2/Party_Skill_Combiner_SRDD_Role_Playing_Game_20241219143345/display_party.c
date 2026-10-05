void display_party(const Party *party) {
    printf("Party Members:\n");
    for (int i = 0; i < party->size; i++) {
        display_character(&party->characters[i]);
        printf("\n");
    }
}