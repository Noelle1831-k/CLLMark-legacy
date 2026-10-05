if (radius < 1) return 0;
vector<pair<int, int>> combinations;
for (int x1 = 0; x1 <= radius; ++x1) {
    for (int y1 = 0; y1 <= radius; ++y1) {
        if (x1 * x1 + y1 * y1 <= radius * radius) {
            combinations.push_back({x1, y1});
        }
    }
}
int count = 0;
for (size_t i = 0; i < combinations.size(); ++i) {
    for (size_t j = i + 1; j < combinations.size(); ++j) {
        int dx = abs(combinations[i].first - combinations[j].first);
        int dy = abs(combinations[i].second - combinations[j].second);
        if (dx != 0 && dy != 0 && dx * dx + dy * dy <= radius * radius) {
            count += 2; // Considering (x1, y1) and (x2, y2) permutations
        }
    }
}
return count;
}