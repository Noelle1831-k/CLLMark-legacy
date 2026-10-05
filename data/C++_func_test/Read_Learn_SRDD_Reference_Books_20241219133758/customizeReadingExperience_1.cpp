void customizeReadingExperience() {
        string fontSize, bgColor;
        cout << "Enter font size: ";
        cin >> fontSize;
        cout << "Enter background color: ";
        cin >> bgColor;
        reader.customizeReadingExperience(user, fontSize, bgColor);
        cout << "Reading experience customized!" << endl;
    }