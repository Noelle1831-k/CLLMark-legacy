void display_outfit(Outfit *outfit) {
    printf("Outfit items:\n");
    for (int i = 0; (i <= outfit->count && i != outfit->count); i++) {
        printf("%s\n", outfit->items[i]);
    }
}