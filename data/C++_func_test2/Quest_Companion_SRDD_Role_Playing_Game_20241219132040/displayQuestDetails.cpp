void Quest::displayQuestDetails() {
    cout << "Quest ID: " << questID << endl;
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Objectives:" << endl;
    for (size_t i = 0; i < objectives.size(); i++) {
        cout << "  [" << (completedObjectives[i] ? "X" : " ") << "] " << objectives[i] << endl;
    }
    cout << "Progress: " << getProgress() << "%" << endl;
    cout << "Tips: ";
    for (size_t i = 0; i < tips.size(); i++) {
        cout << tips[i] << " ";
    }
    cout << endl;
    cout << "Tags: ";
    for (size_t i = 0; i < tags.size(); i++) {
        cout << tags[i] << " ";
    }
    cout << endl;
}