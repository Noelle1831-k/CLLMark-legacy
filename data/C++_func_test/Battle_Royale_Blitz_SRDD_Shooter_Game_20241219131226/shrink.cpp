void Arena::shrink() {
    if (100 < size) {
        size = size - 10;
        cout << "Arena shrinks to size: " << size << endl;
    }
}