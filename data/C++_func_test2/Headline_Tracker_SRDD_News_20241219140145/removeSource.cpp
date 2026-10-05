void NewsManager::removeSource(string sourceName) {
    if (sources.count(sourceName)) {
        sources.erase(sourceName);
        cout << "Source removed: " << sourceName << endl;
    } else {
        cerr << "Source not found: " << sourceName << endl;
    }
}