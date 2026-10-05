Habit *create_habit(char *name, char *type, int frequency) {
    Habit *new_habit = (Habit *) malloc(sizeof(Habit));
    strcpy(new_habit->name, name);
    strcpy(new_habit->type, type);
    new_habit->frequency = frequency;
    new_habit->is_completed_today = 0;  
    return new_habit;
}