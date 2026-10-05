void NewsFetcher::simulateNetworkDelay() {
    cout << "Simulating network delay..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
}