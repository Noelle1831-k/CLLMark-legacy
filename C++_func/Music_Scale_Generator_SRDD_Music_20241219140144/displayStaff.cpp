void MusicStaff::displayStaff(const vector<string> &scale) {
    cout << "Musical Staff: ";
    for (int i = 0; i < scale.size(); i++) {
        cout << scale[i] << " ";
    }
    cout << endl;
}