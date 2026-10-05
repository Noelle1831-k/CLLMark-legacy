void generate_track(struct Track *t, char *name, float length, int difficulty) {
    snprintf(t->name, sizeof(t->name), "%s", name);
    t->length = length;
    t->difficulty = difficulty;
}