void Customizer::customizeAppearance() {
    cout << "Enter customization options (e.g., color, label, size): ";
    string options;
    cin.ignore();
    getline(cin, options);
    cout << "Customization applied: " << options << endl;
}