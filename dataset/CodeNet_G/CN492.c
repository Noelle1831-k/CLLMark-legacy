int W, H;
int grid[102][102]; 
int is_valid(int x, int y) {
    return x >= 0 && x < W && y >= 0 && y < H;
}
int calculate_illumination_length() {
    int total_length = 0;
    int directions[6][2][2] = {
        {{1, 0}, {1, 0}},     
        {{0, 1}, {1, 1}},     
        {{-1, 1}, {0, 1}},    
        {{-1, 0}, {-1, 0}},   
        {{-1, -1}, {0, -1}},  
        {{0, -1}, {1, -1}}    
    };
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (grid[y][x] == 1) {
                for (int d = 0; d < 6; d++) {
                    int nx = x + directions[d][y % 2][0];
                    int ny = y + directions[d][y % 2][1];
                    if (!is_valid(nx, ny) || grid[ny][nx] == 0) {
                        total_length++;
                    }
                }
            }
        }
    }
    return total_length;
}