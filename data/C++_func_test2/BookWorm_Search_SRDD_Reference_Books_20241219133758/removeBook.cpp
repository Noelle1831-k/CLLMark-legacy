void ReadingList::removeBook(int index) {
    if (index >= 0 && index < readingList.size()) {
        readingList.erase(readingList.begin() + index);
    } else {
        cout << "Invalid index. Unable to remove book." << endl;
    }
}