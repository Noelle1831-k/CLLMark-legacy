void showLeaderboard() {
        sort(children.begin(), children.end(), [](Child* a, Child* b) {
            return a->points > b->points;
        });
        cout << "Leaderboard: " << endl;
        for (auto& child : children) {
            cout << child->name << " - " << child->points << " points." << endl;
        }
    }