void UserInterface::displayResults(const string& genre, float confidence) {
    cout << "Predicted Genre: " << genre << endl;
    cout << "Confidence Score: " << confidence * 100 << "%" << endl;
}