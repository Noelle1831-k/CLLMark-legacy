def log_event(self, event):
        '''
        Logs an event to the log file with a timestamp.
        '''
        timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        with open(self.log_file, 'a') as file:
            file.write(f"{timestamp} - {event}\n")