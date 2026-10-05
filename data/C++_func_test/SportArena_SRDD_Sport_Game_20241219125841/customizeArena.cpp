void UserInterface::customizeArena(Arena& arena) const {
    string surface;
    string name;
    
    int capacity;
    int length;
    int width;
    
    cout << "Enter arena name: ";
    cin.ignore();
    getline(cin, name);
    arena.setName(name);
    cout << "Enter arena length: ";
    cin >> length;
    cout << "Enter arena width: ";
    cin >> width;
    arena.setDimensions(length, width);
    cout << "Enter seating capacity: ";
    cin >> capacity;
    arena.setSeatingCapacity(capacity);
    cout << "Enter surface type: ";
    cin.ignore();
    getline(cin, surface);
    arena.setSurfaceType(surface);
}