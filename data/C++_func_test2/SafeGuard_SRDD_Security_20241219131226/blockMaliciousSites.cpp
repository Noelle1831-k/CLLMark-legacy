void blockMaliciousSites(const vector<string> &urls) {
        for (size_t i = 0; i < urls.size(); i++) {
            validateURL(urls[i]);
        }
    }