int main() {
    cout << "Welcome to the Personal Profile Generator!" << endl;
    ProfileGenerator generator;
    char choice;
    do {
        Profile profile = generator.createProfile();
        generator.displayProfile(profile);
        cout << "Do you want to create another profile? (y/n): ";
        cin >> choice;
        cin.ignore(); 
    } while (tolower(choice) == 'y');
    cout << "Thank you for using the Personal Profile Generator. Goodbye!" << endl;
    return 0;
}