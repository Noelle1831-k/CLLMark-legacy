def log(self, message):
        '''
        Logs a message to the console with a standardized format.
        '''
        print(f"[LOG] {message}", flush=True, end="\n")