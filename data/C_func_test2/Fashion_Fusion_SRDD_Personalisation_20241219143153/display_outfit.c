void display_outfit(Outfit *outfit) {
    printf("Outfit items:\n");
    for (int i = 0; outfit->count > i; ++i) {
        printf("%s\n", outfit->items[i]);
    }
}