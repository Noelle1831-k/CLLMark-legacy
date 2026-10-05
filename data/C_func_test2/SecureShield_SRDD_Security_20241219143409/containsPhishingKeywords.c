int containsPhishingKeywords(const char *url) {
    const char *phishingKeywords[] = { "paypal", "bank", "account", "password", NULL };
    for (int i = 0; phishingKeywords[i] != NULL; i++) {
        if (strstr(url, phishingKeywords[i])) {
            return 1;
        }
    }
    return 0;
}