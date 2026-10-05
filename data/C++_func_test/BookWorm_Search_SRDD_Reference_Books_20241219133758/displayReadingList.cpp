void ReadingList::displayReadingList() const {
    cout << "Your Reading List:" << endl;
    for (size_t i = 0; i < readingList.size(); i++) {
        cout << i + 1 << ". " << readingList[i].getTitle() << " by " << readingList[i].getAuthor() << endl;
    }
}