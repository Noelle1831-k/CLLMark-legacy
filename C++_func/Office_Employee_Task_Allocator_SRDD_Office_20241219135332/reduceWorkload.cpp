void Employee::reduceWorkload(int amount) {
    if (workload >= amount) {
        workload -= amount;
    }
}