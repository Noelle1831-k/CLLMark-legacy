AudioInput::~AudioInput() {
    if (isDeviceInitialized) {
        cout << "Releasing audio device resources..." << endl;
    }
}