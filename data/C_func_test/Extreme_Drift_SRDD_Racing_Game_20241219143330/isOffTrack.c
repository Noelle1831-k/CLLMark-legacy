bool isOffTrack(Car* car, Track* track) {
    if (car->x < 0 || car->x > track->length || car->y < 0 || car->y > track->width) {
        printf("Warning: Car went off track!\n");
        car->x = track->length / 2;
        car->y = track->width / 2;
        car->speed = 0;  
        return true;
    }
    return false;
}