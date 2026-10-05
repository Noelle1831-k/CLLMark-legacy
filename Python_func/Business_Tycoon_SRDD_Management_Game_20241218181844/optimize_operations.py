def optimize_operations(self):
        print("Optimizing operations...")
        for employee in self.employees:
            employee.manage_employee()
        self.inventory.manage_inventory()