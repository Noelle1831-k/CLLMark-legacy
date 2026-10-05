void UI::handleInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            Note root("C", 4);
            Scale scale(root);
            scale.addInterval(2);
            scale.addInterval(2);
            scale.addInterval(1);
            scale.addInterval(2);
            scale.addInterval(2);
            scale.addInterval(2);
            scale.addInterval(1);
            scale.generateScale();
            scale.displayScale();
            break;
        }
        case 2: {
            Note root("C", 4);
            Scale scale(root);
            scale.addInterval(2);
            scale.addInterval(2);
            scale.addInterval(1);
            scale.addInterval(2);
            scale.addInterval(2);
            scale.addInterval(2);
            scale.addInterval(1);
            scale.generateScale();
            AudioPlayer player;
            player.playScale(scale.notes);
            break;
        }
        case 3: {
            MusicTheory theory;
            theory.explainIntervals();
            theory.explainChords();
            break;
        }
        case 4:
            cout << "Exiting Music Scale Builder. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            displayMenu();
            break;
    }
}