void DungeonMapper::addRoom() {
    int x, y;
    cout << "Enter coordinates for the room (x y): ";
    while (!(cin >> x >> y) || x < 0 || x >= map.getWidth() || y < 0 || y >= map.getHeight()) {
        cout << "Invalid coordinates. Please enter valid integers within the grid bounds: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    map.updateTile(x, y, 'R');
}