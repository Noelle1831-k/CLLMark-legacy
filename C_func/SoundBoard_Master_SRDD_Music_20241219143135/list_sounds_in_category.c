void list_sounds_in_category(char* category_name) {
    printf("\nSounds in category '%s':\n", category_name);
    for (int i = 0; i < clip_count; i++) {
        if (strcmp(clips[i].category, category_name) == 0) {
            printf("%s\n", clips[i].name);
        }
    }
}