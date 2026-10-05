def organize_reading(self, book, date):
        '''
        Organizes a reading event for a specified book and date.
        '''
        reading_event = {'book': book, 'date': date}
        self.readings.append(reading_event)  # Store the reading event
        print(f"Organizing a reading for {book.title} on {date}")