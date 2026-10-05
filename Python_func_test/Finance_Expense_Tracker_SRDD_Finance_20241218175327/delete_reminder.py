def delete_reminder(self, index):
        '''
        Deletes a reminder by its index.
        :param index: Index of the reminder to delete.
        '''
        if 0 <= index < len(self.reminders):
            del self.reminders[index]
        else:
            print('Invalid reminder index!', end='\n')