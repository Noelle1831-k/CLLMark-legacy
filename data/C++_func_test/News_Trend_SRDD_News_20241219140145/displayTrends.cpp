void Dashboard::displayTrends(map<string, int> trends) {
    printf("Trending Topics:\n");
    for (map<string, int>::iterator it = trends.begin(); it != trends.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}