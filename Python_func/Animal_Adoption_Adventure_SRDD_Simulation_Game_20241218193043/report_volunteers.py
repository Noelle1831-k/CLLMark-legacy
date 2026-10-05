def report_volunteers(self):
        print("Volunteer report:")
        for name, hours in self.volunteers.items():
            print(f"Volunteer {name}: {hours} hours")