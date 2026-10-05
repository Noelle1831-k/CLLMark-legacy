void Visualization::plotTrends(const vector<double>& trends) {
    for (size_t i = 0; i < trends.size(); ++i) {
        cout << "Trend " << i + 1 << ": ";
        int stars = static_cast<int>(trends[i] * 10);
        for (int j = 0; j < stars; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}