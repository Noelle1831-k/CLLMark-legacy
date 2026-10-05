void init_category(Category *category, const char *name, const char *description) {
    strcpy(category->name, name);
    strcpy(category->description, description);
    category->achievement_count = 0;
}