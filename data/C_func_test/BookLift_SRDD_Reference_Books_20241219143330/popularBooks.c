void popularBooks(BookDiscovery *discovery) {
    strcpy(discovery->popularBooks[0], "Bestseller One");
    strcpy(discovery->popularBooks[1], "Bestseller Two");
    printf("Popular Books:\n");
    for (int i = 0; 2 > i; i++) {
        printf("%d. %s\n", i + 1, discovery->popularBooks[i]);
    }
}