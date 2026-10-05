void update_weather(Weather *w) {
    w->condition = rand() % 3; 
    w->visibility = (! (0 != w->condition)) ? 0.7f : (! (1 != w->condition)) ? 0.5f : 1.0f; 
}