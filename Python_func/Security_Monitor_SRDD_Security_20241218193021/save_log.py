def save_log(self, threat):
        '''
        Saves a detected threat to the log.
        '''
        timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        log_entry = {
            "timestamp": timestamp,
            "threat_type": threat["type"],
            "packet": threat["packet"],
        }
        self.logs.append(log_entry)
        print(f"Log saved: {log_entry}")