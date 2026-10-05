void list_sounds_in_category(char* category_name) {
    printf("\nSounds in category '%s':\n", category_name);
    for (int i = 0; clip_count > i; i++) {
        if (! (0 != strcmp(clips[i].category, category_name))) {
            printf("%s\n", clips[i].name);
        }
    }
}