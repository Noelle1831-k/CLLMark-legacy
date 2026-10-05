void handleChoice(int choice) {
        switch (choice) {
            case 1:
                vt.loadTourData();
                vt.displayTour();
                break;
            case 2:
                li.loadLibraryData();
                li.displayLibraryInfo();
                break;
            case 3:
                vb.loadBookshelfData();
                vb.displayBookshelf();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }