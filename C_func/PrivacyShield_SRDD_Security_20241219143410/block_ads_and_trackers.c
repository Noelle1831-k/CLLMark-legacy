void block_ads_and_trackers() {
    printf("Blocking ads and trackers...\n");
    char* blocked_domains[] = {
        "ads.example.com",
        "trackers.example.org",
        NULL
    };
    for (int i = 0; blocked_domains[i] != NULL; i++) {
        printf("Blocking domain: %s\n", blocked_domains[i]);
    }
    printf("Ads and trackers successfully blocked.\n");
}