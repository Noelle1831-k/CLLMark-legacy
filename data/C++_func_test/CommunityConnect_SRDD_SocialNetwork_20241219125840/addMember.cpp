void Community::addMember() {
    cout << "Enter Community Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Location: ";
    getline(cin, location);
    cout << "Community created successfully! Community ID is " << communityID << endl;
}