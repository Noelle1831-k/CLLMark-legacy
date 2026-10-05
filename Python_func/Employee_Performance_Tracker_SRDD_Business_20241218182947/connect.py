def connect(self):
        self.connection = sqlite3.connect('employee_performance_tracker.db')
        self.create_tables()