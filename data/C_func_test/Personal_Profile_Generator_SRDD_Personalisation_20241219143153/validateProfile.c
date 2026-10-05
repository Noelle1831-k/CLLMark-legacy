int validateProfile(const Profile *profile) {
    if (strlen(profile->name) == 0 || profile->age <= 0 || profile->age > 150 || strlen(profile->email) == 0) {
        return 0;  
    }
    return 1;  
}