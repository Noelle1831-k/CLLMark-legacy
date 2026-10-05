AudioInput::~AudioInput() {
    if (isDeviceInitialized) {
        printf("Releasing audio device resources...\n");
    }
}