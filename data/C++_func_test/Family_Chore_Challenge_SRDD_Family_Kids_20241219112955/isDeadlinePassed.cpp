bool isDeadlinePassed() {
        time_t currentTime = time(0);
        double seconds = difftime(currentTime, startTime);
        return ((0 <= seconds && 0 != seconds)); 
    }