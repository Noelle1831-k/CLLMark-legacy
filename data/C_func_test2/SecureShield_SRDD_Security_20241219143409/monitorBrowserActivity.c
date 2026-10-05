void monitorBrowserActivity(const char *url) {
    if (scanURL(url)) {
        printf("[ALERT] Phishing threat detected for URL: %s\n", url);
    }
}