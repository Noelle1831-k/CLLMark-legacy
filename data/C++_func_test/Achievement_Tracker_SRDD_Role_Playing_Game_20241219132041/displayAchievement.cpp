void Achievement::displayAchievement() const {
    cout << "Achievement: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Category: " << category << endl;
    cout << "Completed: " << (completed ? "Yes" : "No") << endl;
    if (deadline != 0) {
        cout << "Deadline: " << ctime(&deadline);
    }
    cout << "--------------------------------------" << endl;
}