void checkWinner() {
        if (vehicle1->getPosition() >= track->getTrackLength()) {
            cout << "Vehicle 1 wins! Time: " << timer.getElapsedTime() << " seconds." << endl;
        }
        else if (vehicle2->getPosition() >= track->getTrackLength()) {
            cout << "Vehicle 2 wins! Time: " << timer.getElapsedTime() << " seconds." << endl;
        }
        else {
            cout << "Race is still ongoing!" << endl;
        }
    }