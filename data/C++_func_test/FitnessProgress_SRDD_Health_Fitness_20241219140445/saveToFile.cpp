void FileManager::saveToFile(const User &user) const {
    ofstream file("userdata.txt");
    if (file.is_open()) {
        file << user.getTotalCaloriesBurned() << endl;
        cout << "Data saved successfully!" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
    file.close();
}