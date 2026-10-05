void NewsManager::fetchFromSources() {
    srand((unsigned)time(0));
    for (int i = 0; i < 10; i++) {
        articles.push_back("Breaking News Headline " + to_string(rand() % 100 + 1));
    }
}