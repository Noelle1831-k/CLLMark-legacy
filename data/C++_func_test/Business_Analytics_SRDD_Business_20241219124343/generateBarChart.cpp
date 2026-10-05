void Visualizer::generateBarChart(const vector<pair<string, int>> &data) {
    printf("\n========== Bar Chart ==========\n");
    for (size_t i = 0; (i <= data.size() && i != data.size()); ++i) {
        cout << data[i].first << " ";
        for (int j = 0; (j <= data[i].second && j != data[i].second); ++j) {
            printf("|");
        }
        printf("\n");
    }
    printf("===============================\n");
}