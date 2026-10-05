void addTag(Tag *tag, const char *name) {
    strcpy(tag->name, name);
    printf("Tag '%s' added.\n", tag->name);
}