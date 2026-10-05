void FileManager::loadFromFile(User &user) const {
    ifstream file("userdata.txt");
    if (file.is_open()) {
        double totalCalories;
        file >> totalCalories;
        cout << "Data loaded successfully!" << endl;
    } else {
        cout << "Unable to open file for reading." << endl;
    }
    file.close();
}