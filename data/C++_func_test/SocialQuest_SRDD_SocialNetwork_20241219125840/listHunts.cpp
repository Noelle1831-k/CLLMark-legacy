void listHunts() {
        cout << "Listing all scavenger hunts:" << endl;
        for (size_t i = 0; i < hunts.size(); i++) {
            hunts[i].viewHunt();
        }
    }