def remove_reminder(self):
        if not self.reminders:
            print('No reminders available to remove.')
        else:
            self.view_reminders()
            index = int(input('Enter the reminder number to remove: ')) - 1
            if 0 <= index < len(self.reminders):
                self.reminders.pop(index)
                print('Reminder removed successfully.')
            else:
                print('Invalid reminder number.')