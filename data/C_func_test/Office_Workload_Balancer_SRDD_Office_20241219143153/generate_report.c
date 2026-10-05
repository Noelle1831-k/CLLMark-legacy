void generate_report(Manager* manager) {
    printf("\nWorkload Report:\n");
    for (int i = 0; i < manager->num_employees; i++) {
        printf("Employee: %s, Workload: %d, Availability: %d\n", manager->employees[i].name, manager->employees[i].workload, manager->employees[i].availability);
    }
}