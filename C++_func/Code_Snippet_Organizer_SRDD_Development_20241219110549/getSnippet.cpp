Snippet SnippetManager::getSnippet(int id) {
    if (id >= 0 && id < snippets.size()) {
        return snippets[id];
    }
    return Snippet("", "");
}