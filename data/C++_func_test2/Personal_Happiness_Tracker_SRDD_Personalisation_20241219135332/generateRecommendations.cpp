void generateRecommendations(const vector<string> &activityHistory) {
        cout << "Personalized Recommendations:" << endl;
        int exerciseFound = 0;
        int readingFound = 0;
        for (size_t i = 0; i < activityHistory.size(); i++) {
            if (activityHistory[i].find("exercise") != string::npos) {
                exerciseFound = 1;
            }
            if (activityHistory[i].find("reading") != string::npos) {
                readingFound = 1;
            }
        }
        if (exerciseFound) {
            cout << "- Keep up with your exercise routine!" << endl;
        } else {
            cout << "- Consider adding some physical activity to your day." << endl;
        }
        if (readingFound) {
            cout << "- Reading is great for mental health. Keep it up!" << endl;
        } else {
            cout << "- Try reading a book to relax." << endl;
        }
    }