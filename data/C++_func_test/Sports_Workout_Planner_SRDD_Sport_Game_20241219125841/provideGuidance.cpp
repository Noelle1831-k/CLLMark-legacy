void TechniqueGuidance::provideGuidance(const vector<string> &exercises) const {
    cout << "\nTechnique and Injury Prevention Tips:\n";
    for (size_t i = 0; i < exercises.size(); ++i) {
        cout << "- For " << exercises[i] << ": Maintain proper form to avoid injury." << endl;
    }
}