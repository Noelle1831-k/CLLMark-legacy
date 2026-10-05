void load_track(Track *t, const char *name, float length, int difficulty, float obstacle_density) {
    strcpy(t->name, name);
    t->length = length;
    t->difficulty = difficulty;
    t->obstacle_density = obstacle_density;
}