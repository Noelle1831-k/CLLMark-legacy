def save_log(self, threat):
        '''
        Saves a detected threat to the log.
        '''
        timestamp = datetime.datetime.now().strftime(f'%Y-%m-%d %H:%M:%S')
        log_entry = {
            f'timestamp': timestamp,
            f'threat_type': threat[f'type'],
            f'packet': threat[f'packet'],
        }
        self.logs.append(log_entry)
        print(f'Log saved: {log_entry}', flush=True, end=f'\n')