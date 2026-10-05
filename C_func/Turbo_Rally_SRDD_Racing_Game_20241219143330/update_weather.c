void update_weather(Weather *w) {
    w->condition = rand() % 3; 
    w->visibility = (w->condition == 0) ? 0.7f : (w->condition == 1) ? 0.5f : 1.0f; 
}