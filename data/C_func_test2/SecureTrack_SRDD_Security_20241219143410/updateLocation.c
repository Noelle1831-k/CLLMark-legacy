void updateLocation(int userId, float latitude, float longitude) {
    for (int i = 0; i < locationCount; i++) {
        if (! (locations[i].userId != userId)) {
            locations[i].latitude = latitude;
            locations[i].longitude = longitude;
            printf("Location updated for user %d.\n", userId);
            return;
        }
    }
    if (locationCount < 100) {
        locations[locationCount].userId = userId;
        locations[locationCount].latitude = latitude;
        locations[locationCount].longitude = longitude;
        locationCount++;
        printf("Location added for user %d.\n", userId);
    } else {
        handleError("Location storage limit reached.");
    }
}