void FestivalManager::simulateDay() {
    cout << "Simulating day " << ++dayCount << "..." << endl;
    if (!location.checkWeather()) {
        cout << "Bad weather! Attendance is lower than expected." << endl;
    }
    challengeSystem.generateChallenge();
    challengeSystem.applyChallenge(artists, location);
    ticketSystem.sellTicket(location.getCapacity());
    location.updateFacilities();
    cout << "Day " << dayCount << " simulation complete!" << endl;
}