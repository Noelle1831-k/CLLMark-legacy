def check_reminders(self):
        '''
        Checks and displays due reminders. Handles recurring reminders if applicable.
        '''
        today = datetime.now().strftime('%Y-%m-%d')
        updated_reminders = []
        for reminder in self.reminders:
            if reminder["date"] <= today:
                print(f"Reminder: {reminder['message']}")
                if reminder["recurrence"] == "daily":
                    new_date = (datetime.strptime(reminder["date"], '%Y-%m-%d') + timedelta(days=1)).strftime('%Y-%m-%d')
                    reminder["date"] = new_date
                    updated_reminders.append(reminder)
                elif reminder["recurrence"] == "weekly":
                    new_date = (datetime.strptime(reminder["date"], '%Y-%m-%d') + timedelta(weeks=1)).strftime('%Y-%m-%d')
                    reminder["date"] = new_date
                    updated_reminders.append(reminder)
                elif reminder["recurrence"] == "monthly":
                    new_date = (datetime.strptime(reminder["date"], '%Y-%m-%d') + timedelta(days=30)).strftime('%Y-%m-%d')
                    reminder["date"] = new_date
                    updated_reminders.append(reminder)
            else:
                updated_reminders.append(reminder)
        self.reminders = updated_reminders