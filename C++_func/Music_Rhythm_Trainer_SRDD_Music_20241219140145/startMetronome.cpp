void Metronome::startMetronome() {
    running = true;
    cout << "Starting metronome at " << tempo << " BPM..." << endl;
    int interval = 60000 / tempo; 
    thread metronomeThread([this, interval]() {
        while (running) {
            cout << "Tick" << endl;
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
    });
    metronomeThread.detach();
}