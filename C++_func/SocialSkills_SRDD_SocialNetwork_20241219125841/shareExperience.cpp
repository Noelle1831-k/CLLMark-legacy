void Community::shareExperience() {
    string experience;
    cout << "Share your experience: ";
    cin.ignore();
    getline(cin, experience);
    sharedExperiences.push_back(experience);
    cout << "Experience shared successfully!" << endl;
}