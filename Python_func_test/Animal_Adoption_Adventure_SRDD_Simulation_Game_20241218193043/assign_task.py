def assign_task(self, name, task):
        if name in self.volunteers:
            print(f"Assigned task '{task}' to volunteer {name}.")
        else:
            print(f"Volunteer {name} not found.")