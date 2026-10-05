void analyzeMoodTrends(const vector<string> &moodHistory) {
        map<string, int> moodCount;
        for (size_t i = 0; i < moodHistory.size(); i++) {
            moodCount[moodHistory[i]]++;
        }
        cout << "Mood Trends:" << endl;
        for (map<string, int>::iterator it = moodCount.begin(); it != moodCount.end(); ++it) {
            cout << it->first << ": " << it->second << " times" << endl;
        }
    }