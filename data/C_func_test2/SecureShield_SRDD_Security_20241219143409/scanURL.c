int scanURL(const char *url) {
    if (isInThreatDatabase(url)) {
        return 1;
    }
    if (isSuspiciousURL(url) || containsPhishingKeywords(url) || hasUnusualCharacters(url)) {
        return 1;
    }
    return 0;
}