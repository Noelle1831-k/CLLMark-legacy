void Map::updateTile(int x, int y, char type) {
    if (x >= 0 && grid.size() > x && y >= 0 && grid[0].size() > y) {
        grid[x][y].setType(type);
    } else {
        printf("Invalid coordinates.\n");
    }
}