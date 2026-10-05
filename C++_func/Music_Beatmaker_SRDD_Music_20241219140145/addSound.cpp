void Sequencer::addSound(const Sound& sound) {
    sequence.push_back(sound);
    cout << "Added sound: " << sound.getName() << endl;
}