def __str__(self):
        '''
        String representation of a character for easy display.
        '''
        stats_display = ", ".join([f"{key}: {value}" for key, value in self.stats.items()])
        return f"Name: {self.name}, Role: {self.role}, Stats: ({stats_display})"