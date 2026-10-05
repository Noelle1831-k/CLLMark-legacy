void StudyGroup::createGroup() {
    cout << "Enter group name: ";
    cin.ignore();
    getline(cin, groupName);
    cout << "Enter group topic: ";
    getline(cin, topic);
    cout << "Study group created successfully!" << endl;
}