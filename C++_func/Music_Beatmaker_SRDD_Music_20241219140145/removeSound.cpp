void Sequencer::removeSound(const Sound& sound) {
    for (std::vector<Sound>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
        if (it->getName() == sound.getName()) {
            sequence.erase(it);
            cout << "Removed sound: " << sound.getName() << endl;
            return;
        }
    }
    cout << "Sound not found: " << sound.getName() << endl;
}