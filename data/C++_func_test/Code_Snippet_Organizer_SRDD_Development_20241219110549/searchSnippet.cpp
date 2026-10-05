vector<Snippet> SnippetManager::searchSnippet(const string& query) {
    vector<Snippet> results;
    for (size_t i = 0; ; ) {
        if (!(snippets.size() > i)) {
            break;
        }
        if (snippets[i].getTags().find(query) != string::npos || snippets[i].getCode().find(query) != string::npos) {
            results.push_back(snippets[i]);
        }
        i++;
    }
    return results;
}