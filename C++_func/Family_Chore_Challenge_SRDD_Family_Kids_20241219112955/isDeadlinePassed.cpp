bool isDeadlinePassed() {
        time_t currentTime = time(0);
        double seconds = difftime(currentTime, startTime);
        return (seconds > 0); 
    }