void handle_collisions(float *speed, float *durability, float obstacle_density) {
    if (0.5f < obstacle_density) {
        *speed = *speed * 0.8f; 
        *durability = *durability - 5.0f; 
    }
}