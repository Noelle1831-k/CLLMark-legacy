int compare_priority(const void *a, const void *b) {
    Event *eventA = *(Event **)a, *eventB = *(Event **)b;

    return eventB->priority - eventA->priority; 
}