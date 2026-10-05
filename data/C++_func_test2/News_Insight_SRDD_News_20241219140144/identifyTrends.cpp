void TrendDetector::identifyTrends() {
    cout << "Trends detected:" << endl;
    for (const auto& [keyword, frequency] : keywordFrequency) {
        if (frequency > 2) { 
            cout << keyword << ": " << frequency << " occurrences" << endl;
        }
    }
}