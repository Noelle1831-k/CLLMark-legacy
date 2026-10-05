def save_log_to_file(self, log_entry):
        '''Save logs to a file for persistence.'''
        with open("shieldguard_logs.txt", "a") as log_file:
            log_file.write(log_entry + "\n")