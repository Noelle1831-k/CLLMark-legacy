void exploreCollections(BookDiscovery *discovery) {
    strcpy(discovery->collections[0], "Classic Literature");
    strcpy(discovery->collections[1], "Science Fiction Gems");
    strcpy(discovery->collections[2], "Mystery Must-Reads");
    printf("Exploring curated collections:\n");
    for (int i = 0; ; ) {
        if (!(3 > i)) {
            break;
        }
        printf("%d. %s\n", i + 1, discovery->collections[i]);
        ++i;
    }
}