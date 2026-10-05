void Tutor::displayProfile() {
    cout << "Tutor Name: " << name << "\nEmail: " << email << "\nSubjects: ";
    for (string s : subjects) {
        cout << s << " ";
    }
    cout << endl;
}