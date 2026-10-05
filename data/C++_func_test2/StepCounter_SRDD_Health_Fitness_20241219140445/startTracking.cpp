void StepCounterApp::startTracking() {
    cout << "Tracking started..." << endl;
    sensorManager.readSensorData();
    for (int i = 0; i < 10; i++) {
        stepTracker.processSensorData();
    }
}