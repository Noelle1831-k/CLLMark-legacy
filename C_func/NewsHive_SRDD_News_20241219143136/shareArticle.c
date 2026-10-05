void shareArticle() {
    printf("Sharing article on social media...\n");
    char *platforms[] = {"Facebook", "Twitter", "LinkedIn"};
    for (int i = 0; i < 3; i++) {
        printf("Sharing on %s...\n", platforms[i]);
        sleep(1);
        printf("Article shared on %s successfully.\n", platforms[i]);
    }
}