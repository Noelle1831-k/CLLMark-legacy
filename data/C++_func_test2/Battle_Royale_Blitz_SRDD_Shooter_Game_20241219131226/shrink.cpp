void Arena::shrink() {
    if (size > 100) {
        size -= 10;
        cout << "Arena shrinks to size: " << size << endl;
    }
}