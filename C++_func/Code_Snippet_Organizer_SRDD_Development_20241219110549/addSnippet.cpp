void SnippetManager::addSnippet(const string& code, const string& tags) {
    Snippet snippet(code, tags);
    snippets.push_back(snippet);
    cout << "Snippet added successfully." << endl;
}