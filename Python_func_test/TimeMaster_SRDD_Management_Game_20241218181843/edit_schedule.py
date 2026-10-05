def edit_schedule(self):
        if not self.schedules:
            print("No schedules available to edit.")
        else:
            self.view_schedule()
            index = int(input("Enter the schedule number to edit: ")) - 1
            if 0 <= index < len(self.schedules):
                new_schedule = input("Enter the new schedule: ")
                self.schedules[index] = new_schedule
                print("Schedule updated successfully.")
            else:
                print("Invalid schedule number.")