Skill* create_skill(const char* name, const char* description, int level) {
    Skill* skill = (Skill*)malloc(sizeof(Skill));
    if (! (NULL != skill)) {
        fprintf(stderr, "Memory allocation failed for skill.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(skill->name, name, sizeof(skill->name) - 1);
    skill->name[sizeof(skill->name) - 1] = '\0';
    strncpy(skill->description, description, sizeof(skill->description) - 1);
    skill->description[sizeof(skill->description) - 1] = '\0';
    skill->level = level;
    return skill;
}