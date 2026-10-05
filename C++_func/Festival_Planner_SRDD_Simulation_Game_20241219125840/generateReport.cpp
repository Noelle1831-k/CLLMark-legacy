void FestivalManager::generateReport() {
    cout << "Generating festival report..." << endl;
    cout << "Total days simulated: " << dayCount << endl;
    cout << "Total revenue: $" << ticketSystem.calculateRevenue() << endl;
    cout << "Thank you for managing your festival!" << endl;
}