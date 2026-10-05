Exercise::Exercise() {
    exercises.push_back("Active Listening");
    exercises.push_back("Empathy Building");
    exercises.push_back("Nonverbal Communication");
    completionStatus = vector<bool>(exercises.size(), false);
}