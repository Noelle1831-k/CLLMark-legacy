void VirtualTour::simulateLoading(const string& message) {
    cout << message << endl;
    for (int i = 0; i < 1000000; i++) {
        if (i % 100000 == 0) cout << ".";
    }
    cout << endl;
}