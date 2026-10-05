int validateInput() {
        int input;
        scanf("%d", &input);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
        return input;
    }