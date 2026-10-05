void User::displayProfile() {
    cout << "Name: " << name << endl;
    cout << "Industry: " << industry << endl;
    cout << "Job Title: " << jobTitle << endl;
    cout << "Skills: ";
    for (size_t i = 0; i < skills.size(); i++) {
        cout << skills[i] << " ";
    }
    cout << endl;
    cout << "Contact Info: " << contactInfo << endl;
}