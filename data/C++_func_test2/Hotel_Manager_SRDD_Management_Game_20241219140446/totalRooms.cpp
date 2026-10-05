Hotel::Hotel(int numRooms) : totalRooms(numRooms), occupancyRate(0.0) {
    for (int i = 1; i <= numRooms; i++) {
        rooms[i] = true; 
    }
}