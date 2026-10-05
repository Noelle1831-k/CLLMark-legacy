void update_details(Achievement *achievement, const char *name, const char *description, const char *category, const char *tags, const char *deadline, const char *reward) {
    strcpy(achievement->name, name);
    strcpy(achievement->description, description);
    strcpy(achievement->category, category);
    strcpy(achievement->tags, tags);
    strcpy(achievement->deadline, deadline);
    strcpy(achievement->reward, reward);
}