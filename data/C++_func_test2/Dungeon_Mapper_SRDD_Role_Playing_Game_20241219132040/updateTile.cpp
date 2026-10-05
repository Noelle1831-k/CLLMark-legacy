void Map::updateTile(int x, int y, char type) {
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
        grid[x][y].setType(type);
    } else {
        cout << "Invalid coordinates." << endl;
    }
}