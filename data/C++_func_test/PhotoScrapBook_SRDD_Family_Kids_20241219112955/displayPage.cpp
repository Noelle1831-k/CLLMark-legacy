void ScrapbookPage::displayPage() const {
    cout << "Page Layout: " << layoutTemplate << endl;
    cout << "Background Color: " << backgroundColor << endl;
    cout << "Font Style: " << fontStyle << endl;
    cout << "Photos: ";
    for (size_t i = 0; i < photos.size(); ++i) {
        cout << photos[i] << " ";
    }
    cout << endl;
    cout << "Caption: " << caption << endl;
    cout << "Stickers: ";
    for (size_t i = 0; i < stickers.size(); ++i) {
        cout << stickers[i] << " ";
    }
    cout << endl;
}