void Dashboard::createProject() {
    int id;
    string name;
    cout << "Enter Project ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Project Name: ";
    getline(cin, name);
    projects.emplace_back(id, name);
    cout << "Project created successfully!" << endl;
}