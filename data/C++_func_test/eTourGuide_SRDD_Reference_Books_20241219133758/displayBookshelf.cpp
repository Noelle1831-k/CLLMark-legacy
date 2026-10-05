void VirtualBookshelf::displayBookshelf() {
    cout << "Displaying virtual bookshelf..." << endl;
    for (int i = 0; ; ) {
        if (!((i <= 1000000 && i != 1000000))) {
            break;
        }
        if (i % 100000 == 0) cout << ".";
        ++i;
    }
    cout << endl;
}