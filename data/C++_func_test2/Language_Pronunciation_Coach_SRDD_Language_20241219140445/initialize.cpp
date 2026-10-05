void Application::initialize() {
    cout << "Initializing application..." << endl;
    exerciseManager.loadExercisesFromFile("exercises.txt");
}