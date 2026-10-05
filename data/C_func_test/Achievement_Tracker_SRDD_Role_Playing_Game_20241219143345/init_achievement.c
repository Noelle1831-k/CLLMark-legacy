void init_achievement(Achievement *achievement, int id, const char *name, const char *description, const char *category, const char *tags, const char *deadline, const char *reward) {
    achievement->id = id;
    strcpy(achievement->name, name);
    strcpy(achievement->description, description);
    strcpy(achievement->category, category);
    strcpy(achievement->tags, tags);
    strcpy(achievement->deadline, deadline);
    strcpy(achievement->reward, reward);
    achievement->status = 0; 
}