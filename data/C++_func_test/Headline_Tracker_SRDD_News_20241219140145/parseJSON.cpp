vector<string> NewsFetcher::parseJSON(string response) {
    vector<string> headlines;
    if (response.empty()) {
        logError("No data fetched from source, skipping parsing.");
        return headlines;
    }
    Json::Value jsonData;
    Json::CharReaderBuilder reader;
    string errs;
    istringstream ss(response);
    if (!Json::parseFromStream(reader, ss, &jsonData, &errs)) {
        logError("Error parsing JSON: " + errs);
        return headlines;
    }
    for (const auto &article : jsonData["articles"]) {
        headlines.push_back(article["title"].asString());
    }
    return headlines;
}