void display_track_info(const struct Track *t) {
    printf("Track: %s\n", t->name);
    printf("Length: %.2f meters\n", t->length);
    printf("Difficulty: %d\n", t->difficulty);
}