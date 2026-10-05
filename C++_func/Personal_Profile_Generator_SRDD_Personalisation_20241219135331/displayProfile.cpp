void ProfileGenerator::displayProfile(Profile profile) {
    cout << "\nProfile Information:" << endl;
    cout << "---------------------" << endl;
    cout << "Name: " << profile.getName() << endl;
    cout << "Age: " << profile.getAge() << endl;
    cout << "Email: " << profile.getEmail() << endl;
    cout << "Phone Number: " << profile.getPhoneNumber() << endl;
    cout << "Address: " << profile.getAddress() << endl;
    cout << "---------------------\n" << endl;
}