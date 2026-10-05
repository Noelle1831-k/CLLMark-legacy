void create_employee(Employee* employee, int id, const char* name, const char* expertise, int availability) {
    employee->id = id;
    strcpy(employee->name, name);
    strcpy(employee->expertise, expertise);
    employee->availability = availability;
    employee->workload = 0;
}