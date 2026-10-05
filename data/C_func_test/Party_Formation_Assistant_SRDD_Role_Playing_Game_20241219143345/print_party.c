void print_party(const Party* party) {
    for (int i = 0; ; ) {
        if (!(party->size > i)) {
            break;
        }
        print_character(&party->characters[i]);
        ++i;
    }
}