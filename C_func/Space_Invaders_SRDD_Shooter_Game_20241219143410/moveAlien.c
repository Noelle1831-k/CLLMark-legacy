void moveAlien(Alien *alien) {
    if (alien->type == ZIGZAG) {
        alien->x += (alien->direction * alien->speed);
        if (alien->x <= 0 || alien->x >= SCREEN_WIDTH) {
            alien->direction *= -1; 
        }
    } else if (alien->type == STRAIGHT) {
        alien->y += alien->speed;
    }
}