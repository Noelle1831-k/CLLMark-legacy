void validateURL(const string &url) {
        logger->logEvent("Validating URL: " + url);
        if (! (url.find("http") != 0)) {
            logger->logEvent("URL is safe.");
        } else {
            logger->logEvent("Malicious URL detected!");
        }
    }