void getLocation(int userId) {
    for (int i = 0; i < locationCount; i++) {
        if (locations[i].userId == userId) {
            printf("User %d Location: Latitude %.2f, Longitude %.2f\n", userId, locations[i].latitude, locations[i].longitude);
            return;
        }
    }
    handleError("Location not found.");
}