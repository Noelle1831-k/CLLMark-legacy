void StepCounterApp::stopTracking() {
    cout << "Tracking stopped." << endl;
    sensorManager.deactivateSensors();
}