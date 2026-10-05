vector<vector<vector<double>>> result;
double dx = 3.0 * radius; 
double dy = sqrt(3.0) * radius;
vector<vector<double>> directions = {{-1.5 * radius, -dy / 2}, {-1.5 * radius, dy / 2}, {0, dy}, {1.5 * radius, dy / 2}, {1.5 * radius, -dy / 2}, {0, -dy}};

for (int y = 0; y < endy - starty; ++y) {
    for (int x = 0; x < endx - startx; ++x) {
        vector<double> center = {(startx + x * 1.5) * radius, (starty + y) * dy};
        vector<vector<double>> hexagon;
        for (auto &d : directions) {
            hexagon.push_back({center[0] + d[0], center[1] + d[1]});
        }
        hexagon.push_back(hexagon[0]); 
        result.push_back(hexagon);
    }
}
result;
}