void Skill::setParameters() {
    cout << "Enter skill name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter required attributes (integer): ";
    cin >> requiredAttributes;
    cout << "Enter complexity (floating-point): ";
    cin >> complexity;
    cout << "Enter progression (integer): ";
    cin >> progression;
    calculateDifficulty();
}