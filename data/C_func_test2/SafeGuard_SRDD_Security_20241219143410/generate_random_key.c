void generate_random_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = 'A' + (rand() % 26);
    }
    key[length] = '\0';
    printf("Generated key: %s\n", key);
}