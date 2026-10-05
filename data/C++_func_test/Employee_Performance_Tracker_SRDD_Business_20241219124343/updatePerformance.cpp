void Employee::updatePerformance(int score) {
    performanceScores.push_back(score);
    cout << "Performance updated for employee " << name << "!" << endl;
}