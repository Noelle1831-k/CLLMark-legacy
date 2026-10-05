Arena::Arena() : width(10), height(10) {
    layout = new char*[height];
    for (int i = 0; i < height; ++i) {
        layout[i] = new char[width];
    }
    loadArena(1);
}