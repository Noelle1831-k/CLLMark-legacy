double Hotel::calculateOccupancyRate() {
    int occupied = 0;
    for (const auto &room : rooms) {
        if (!room.second) {
            occupied++;
        }
    }
    occupancyRate = (static_cast<double>(occupied) / totalRooms) * 100;
    return occupancyRate;
}