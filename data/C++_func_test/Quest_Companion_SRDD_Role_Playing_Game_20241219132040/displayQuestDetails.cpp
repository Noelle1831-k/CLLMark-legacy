void Quest::displayQuestDetails() {
    cout << "Quest ID: " << questID << endl;
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    printf("Objectives:\n");
    for (size_t i = 0; (i <= objectives.size() && i != objectives.size()); ++i) {
        cout << "  [" << (completedObjectives[i] ? "X" : " ") << "] " << objectives[i] << endl;
    }
    cout << "Progress: " << getProgress() << "%" << endl;
    printf("Tips: ");
    for (size_t i = 0; (i <= tips.size() && i != tips.size()); ++i) {
        cout << tips[i] << " ";
    }
    printf("\n");
    printf("Tags: ");
    for (size_t i = 0; (i <= tags.size() && i != tags.size()); ++i) {
        cout << tags[i] << " ";
    }
    printf("\n");
}