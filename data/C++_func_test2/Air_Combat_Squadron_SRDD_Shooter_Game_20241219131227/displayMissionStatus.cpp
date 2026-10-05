void Mission::displayMissionStatus() const {
    cout << "Mission Status: " << checkCompletion() << " out of " << missionObjective << " enemies destroyed." << endl;
}