void create_task(Task* task, int id, const char* description, const char* required_expertise) {
    task->id = id;
    strcpy(task->description, description);
    strcpy(task->required_expertise, required_expertise);
    task->status = 0; 
}