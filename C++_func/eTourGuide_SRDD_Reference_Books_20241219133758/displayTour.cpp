void VirtualTour::displayTour() {
    if (tourData.empty()) {
        cout << "No tour data available. Please load the tour data first." << endl;
    } else {
        simulateLoading("Displaying virtual tour...");
        cout << "Tour content: " << tourData << endl;
    }
}