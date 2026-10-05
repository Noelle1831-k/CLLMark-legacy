int scanEmail(const char *emailContent) {
    if (containsSuspiciousLinks(emailContent) || containsPhishingKeywordsInEmail(emailContent)) {
        return 1;
    }
    return 0;
}