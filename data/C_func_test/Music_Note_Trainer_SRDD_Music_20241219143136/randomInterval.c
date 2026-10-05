void randomInterval(char* interval) {
    const char* intervals[] = {"Unison", "Minor Second", "Major Second", "Minor Third", "Major Third"};
    int index = rand() % 5;
    strcpy(interval, intervals[index]);
}