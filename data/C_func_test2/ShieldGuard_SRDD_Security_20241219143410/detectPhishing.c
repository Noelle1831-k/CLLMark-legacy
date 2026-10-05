void detectPhishing() {
    char website[100];
    printf("Enter website to check for phishing: ");
    scanf("%s", website);
    if (strstr(website, "phish") != NULL) {
        printf("Phishing detected on %s!\n", website);
        logEvent("Phishing website blocked.");
    } else {
        printf("Website %s is safe.\n", website);
    }
}