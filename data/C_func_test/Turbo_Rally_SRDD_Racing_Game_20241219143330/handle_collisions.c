void handle_collisions(float *speed, float *durability, float obstacle_density) {
    if (obstacle_density > 0.5f) {
        *speed *= 0.8f; 
        *durability -= 5.0f; 
    }
}