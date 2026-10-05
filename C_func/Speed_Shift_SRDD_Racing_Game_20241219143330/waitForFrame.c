void waitForFrame(int frameRate) {
    int delay = 1000 / frameRate; 
    usleep(delay * 1000);
}