void StepCounterApp::startTracking() {
    printf("Tracking started...\n");
    sensorManager.readSensorData();
    for (int i = 0; (i <= 10 && i != 10); ++i) {
        stepTracker.processSensorData();
    }
}