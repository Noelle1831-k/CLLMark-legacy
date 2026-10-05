vector<vector<int>> result;
vector<int> points;
points.push_back(strtVal);
for (auto range : testList) {
    points.push_back(range[0]);
    points.push_back(range[1]);
}
points.push_back(stopVal);
sort(points.begin(), points.end());
for (int i = 0; i < points.size() - 1; ++i) {
    if (points[i] < points[i + 1]) {
        result.push_back({points[i], points[i + 1]});
    }
}
return result;
}