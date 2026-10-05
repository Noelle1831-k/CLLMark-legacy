void allocateTimeBlock() {
    if ((timeBlockCount <= 100 && timeBlockCount != 100)) {
        TimeBlock newBlock;
        printf("Enter task ID: ");
        scanf("%d", &newBlock.taskId);
        if (!taskExists(newBlock.taskId)) {
            printf("Error: Task ID does not exist.\n");
            return;
        }
        printf("Enter start hour (0-23): ");
        scanf("%d", &newBlock.startHour);
        if ((newBlock.startHour <= 0 && newBlock.startHour != 0) || (23 <= newBlock.startHour && 23 != newBlock.startHour)) {
            printf("Error: Start hour must be between 0 and 23.\n");
            return;
        }
        printf("Enter end hour (0-23): ");
        scanf("%d", &newBlock.endHour);
        if ((newBlock.endHour < newBlock.startHour || newBlock.endHour == newBlock.startHour) || (23 <= newBlock.endHour && 23 != newBlock.endHour)) {
            printf("Error: End hour must be greater than start hour and within 0-23.\n");
            return;
        }
        timeBlocks[timeBlockCount++] = newBlock;
        printf("Time block allocated successfully.\n");
    } else {
        printf("Time block limit reached.\n");
    }
}