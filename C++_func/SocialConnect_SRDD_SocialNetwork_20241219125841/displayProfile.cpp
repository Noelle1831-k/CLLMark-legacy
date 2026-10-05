void User::displayProfile() const {
    cout << "Name: " << name << "\nAge: " << age << "\nInterests: ";
    for (int i = 0; i < interests.size(); i++) {
        cout << interests[i] << " ";
    }
    cout << "\nHobbies: ";
    for (int i = 0; i < hobbies.size(); i++) {
        cout << hobbies[i] << " ";
    }
    cout << endl;
}