Profile ProfileGenerator::createProfile() {
    Profile profile;
    InputValidator validator;
    string name, email, phoneNumber, address;
    int age;
    cout << "Enter name: ";
    cin.ignore(); 
    getline(cin, name);
    while (!validator.isValidName(name)) {
        cout << "Invalid name. Enter again: ";
        getline(cin, name);
    }
    profile.setName(trim(name));
    cout << "Enter age: ";
    cin >> age;
    while (!validator.isValidAge(age)) {
        cout << "Invalid age. Enter again: ";
        cin >> age;
    }
    profile.setAge(age);
    cout << "Enter email: ";
    cin.ignore(); 
    getline(cin, email);
    while (!validator.isValidEmail(email)) {
        cout << "Invalid email. Enter again: ";
        getline(cin, email);
    }
    profile.setEmail(trim(email));
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    while (!validator.isValidPhoneNumber(phoneNumber)) {
        cout << "Invalid phone number. Enter again: ";
        getline(cin, phoneNumber);
    }
    profile.setPhoneNumber(trim(phoneNumber));
    cout << "Enter address: ";
    getline(cin, address);
    profile.setAddress(trim(address));
    return profile;
}