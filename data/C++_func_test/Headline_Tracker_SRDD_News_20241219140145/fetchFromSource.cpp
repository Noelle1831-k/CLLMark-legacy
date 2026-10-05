string NewsFetcher::fetchFromSource(string sourceUrl) {
    CURL *curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, sourceUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            logError("CURL error: " + string(curl_easy_strerror(res)));
            return "";
        }
        curl_easy_cleanup(curl);
    } else {
        logError("Error initializing CURL!");
    }
    return readBuffer;
}