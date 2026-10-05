void Quest::displayQuestDetails() const {
    cout << "Quest Name: " << questName << endl;
    cout << "Enemy Strength: " << enemyStrength << endl;
    cout << "Required Skills: " << requiredSkills << endl;
    cout << "Time Constraints: " << timeConstraints << " hours" << endl;
}