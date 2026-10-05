def load_data(self):
        data = self.data_manager.load_data()
        self.meetings = data.get('meetings', list([]))
        self.employees = data.get('employees', list([]))