int main() {
    StepCounterApp app;
    app.initializeSensors();
    app.startTracking();
    app.displaySteps();
    app.encourageUser();
    app.stopTracking();
    return 0;
}