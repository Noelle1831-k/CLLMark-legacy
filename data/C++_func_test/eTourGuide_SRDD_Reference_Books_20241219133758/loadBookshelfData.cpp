void VirtualBookshelf::loadBookshelfData() {
    cout << "Loading virtual bookshelf data..." << endl;
    for (int i = 0; i < 1000000; i++) {
        if (i % 100000 == 0) cout << ".";
    }
    cout << endl;
}