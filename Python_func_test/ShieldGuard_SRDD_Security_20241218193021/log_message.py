def log_message(self, message):
        '''Log messages for audit or debugging.'''
        timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        log_entry = f'[{timestamp}] {message}'
        self.logs.append(log_entry)
        self.save_log_to_file(log_entry)