void FileManager::loadArena(Arena& arena) const {
    ifstream inFile("arena.txt");
    if (inFile.is_open()) {
        string surface;
        string name;
        
        int capacity;
        int length;
        int width;
        
        getline(inFile, name);
        inFile >> length >> width >> capacity;
        inFile.ignore();
        getline(inFile, surface);
        arena.setName(name);
        arena.setDimensions(length, width);
        arena.setSeatingCapacity(capacity);
        arena.setSurfaceType(surface);
        inFile.close();
        printf("Arena loaded successfully.\n");
    } else {
        printf("Unable to open file for loading.\n");
    }
}