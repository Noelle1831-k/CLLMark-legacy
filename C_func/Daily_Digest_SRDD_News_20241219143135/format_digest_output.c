void format_digest_output(Digest *digest) {
    for (int i = 0; i < digest->count; i++) {
        printf("Title: %s\nCategory: %s\nTimestamp: %ld\n\n", digest->articles[i].title, digest->articles[i].category, digest->articles[i].timestamp);
    }
}