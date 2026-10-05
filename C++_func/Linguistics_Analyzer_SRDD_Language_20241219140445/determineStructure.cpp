void StructureDeterminer::determineStructure(const string& sentence) {
    if (sentence.find(",") != string::npos) {
        cout << "Detected complex sentence structure (contains comma)." << endl;
    } else {
        cout << "Detected simple sentence structure." << endl;
    }
}