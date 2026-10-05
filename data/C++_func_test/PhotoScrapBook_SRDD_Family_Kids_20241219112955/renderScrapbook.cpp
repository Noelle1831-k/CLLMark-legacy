void Scrapbook::renderScrapbook() const {
    cout << "Rendering Scrapbook..." << endl;
    for (size_t i = 0; i < pages.size(); ++i) {
        cout << "Page " << i + 1 << ":" << endl;
        pages[i].displayPage();
    }
}