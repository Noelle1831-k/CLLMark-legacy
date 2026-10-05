Tag *createTag(const char *name) {
    Tag *tag = (Tag *)malloc(sizeof(Tag));
    strcpy(tag->name, name);
    printf("Tag '%s' created.\n", tag->name);
    return tag;
}