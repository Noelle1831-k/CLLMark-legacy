void balance_workload(WorkloadBalancer* wb) {
    printf("\nBalancing Workload:\n");
    for (int i = 0; i < wb->num_tasks; i++) {
        if (wb->tasks[i].status == 0) { 
            for (int j = 0; j < wb->num_employees; j++) {
                if (wb->employees[j].availability > 0) {
                    printf("Assigning task '%s' to employee '%s'\n", wb->tasks[i].description, wb->employees[j].name);
                    wb->employees[j].availability--;
                    wb->employees[j].workload++;
                    wb->tasks[i].status = 1; 
                    break;
                }
            }
        }
    }
}