void Book::displayDetails() const {
    cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN
         << "\nCategory: " << category << "\nTags: ";
    for (size_t i = 0; i < tags.size(); i++) {
        cout << tags[i];
        if (i < tags.size() - 1) cout << ", ";
    }
    cout << "\nRating: " << rating << "\nReading Progress: " << readingProgress << "%" << endl;
}