void startRace() {
        timer.start();
        while (vehicle1->getPosition() < track->getTrackLength() && vehicle2->getPosition() < track->getTrackLength()) {
            vehicle1->accelerate();
            vehicle2->accelerate();
            vehicle1->updatePosition();
            vehicle2->updatePosition();
        }
        timer.stop();
    }