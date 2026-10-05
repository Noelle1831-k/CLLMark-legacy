void chooseColors() {
        cout << "Choose a color to start coloring (e.g., Red, Blue, Green): ";
        string color;
        cin >> color;
        cout << "You selected " << color << ". Start coloring the page!" << endl;
        simulateColoring();
    }