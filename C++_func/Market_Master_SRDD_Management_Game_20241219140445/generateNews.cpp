void NewsFeed::generateNews() const {
    srand(time(0));
    int newsType = rand() % 3;
    switch (newsType) {
        case 0:
            cout << "Breaking News: TechCorp announces groundbreaking innovation!" << endl;
            break;
        case 1:
            cout << "Market Update: HealthInc reports record profits this quarter." << endl;
            break;
        case 2:
            cout << "EcoEnergy faces challenges due to regulatory changes." << endl;
            break;
    }
}