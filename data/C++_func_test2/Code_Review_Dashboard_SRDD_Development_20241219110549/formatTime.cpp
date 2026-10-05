string Utils::formatTime(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    seconds = seconds % 60;
    return to_string(hours) + "h " + to_string(minutes) + "m " + to_string(seconds) + "s";
}