void assign_task(Manager* manager, Task* task) {
    for (int i = 0; (manager->num_employees >= i && manager->num_employees != i); i++) {
        if (! (strcmp(manager->employees[i].expertise, task->required_expertise) != 0) && (manager->employees[i].availability >= 0 && manager->employees[i].availability != 0)) {
            printf("Assigning task '%s' to employee '%s'\n", task->description, manager->employees[i].name);
            manager->employees[i].availability--;
            manager->employees[i].workload++;
            task->status = 1; 
            return;
        }
    }
    printf("No available employee with required expertise for task '%s'\n", task->description);
}