void apply_weather_effects(Weather *w, float *speed) {
    if (w->condition == 0) {
        *speed *= 0.9f; 
    } else if (w->condition == 1) {
        *speed *= 0.95f; 
    }
}