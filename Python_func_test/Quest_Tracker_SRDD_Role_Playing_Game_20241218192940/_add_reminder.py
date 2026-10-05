def _add_reminder(self):
        quest_id = int(input("Enter quest ID for reminder: "))
        reminder_time_str = input("Enter reminder time (YYYY-MM-DD HH:MM:SS): ")
        reminder_time = datetime.datetime.strptime(reminder_time_str, '%Y-%m-%d %H:%M:%S')
        self.reminder_system.add_reminder(quest_id, reminder_time)