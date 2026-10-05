void participateInHunt(string huntName) {
        auto it = find_if(hunts.begin(), hunts.end(), [&huntName](ScavengerHunt& hunt) {
            return hunt.huntName == huntName;
        });
        if (it != hunts.end()) {
            cout << "Participating in hunt: " << huntName << endl;
        } else {
            cout << "Hunt not found: " << huntName << endl;
        }
    }