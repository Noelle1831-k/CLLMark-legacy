void VirtualBookshelf::displayBookshelf() {
    cout << "Displaying virtual bookshelf..." << endl;
    for (int i = 0; i < 1000000; i++) {
        if (i % 100000 == 0) cout << ".";
    }
    cout << endl;
}