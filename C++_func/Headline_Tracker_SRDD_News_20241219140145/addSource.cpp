void NewsManager::addSource(string sourceName, string sourceUrl) {
    if (sourceUrl.empty()) {
        cerr << "Error: Source URL cannot be empty." << endl;
        return;
    }
    sources[sourceName] = sourceUrl;
    cout << "Source added: " << sourceName << endl;
}