void GameEngine::simulateDay() {
    cout << "Simulating a day in the hotel..." << endl;
    hotel.allocateRoom(1);
    hotel.checkOut(1);
    cout << "Occupancy rate: " << hotel.calculateOccupancyRate() << "%" << endl;
}