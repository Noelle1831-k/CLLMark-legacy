int main() {
    TaskAllocator allocator;
    initializeEmployees(&allocator);
    initializeTasks(&allocator);
    assignTask(&allocator);
    trackTaskProgress(&allocator);
    generateTaskReport(&allocator);
    setTaskDeadline(&allocator);
    distributeWorkload(&allocator);
    reassignTasks(&allocator);
    generateFinalReport(&allocator);
    return 0;
}