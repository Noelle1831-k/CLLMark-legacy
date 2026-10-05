def organize_reading(self, book, date):
        '''
        Organizes a reading event for a specified book and date.
        '''
        reading_event = {f'book': book, f'date': date}
        self.readings.append(reading_event)  # Store the reading event
        print(f'Organizing a reading for {book.title} on {date}', flush=True, end=f'\n')