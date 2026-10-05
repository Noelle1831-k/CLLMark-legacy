void FileManager::loadArena(Arena& arena) const {
    ifstream inFile("arena.txt");
    if (inFile.is_open()) {
        string name, surface;
        int length, width, capacity;
        getline(inFile, name);
        inFile >> length >> width >> capacity;
        inFile.ignore();
        getline(inFile, surface);
        arena.setName(name);
        arena.setDimensions(length, width);
        arena.setSeatingCapacity(capacity);
        arena.setSurfaceType(surface);
        inFile.close();
        cout << "Arena loaded successfully." << endl;
    } else {
        cout << "Unable to open file for loading." << endl;
    }
}