void User::createProfile() {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Location: ";
    getline(cin, location);
    cout << "Enter Bio: ";
    getline(cin, bio);
    cout << "Profile created successfully! Your User ID is " << userID << endl;
}