def save_data(self):
        data = {
            'meetings': self.meetings,
            'employees': self.employees
        }
        self.data_manager.save_data(data)
        print("Data saved successfully.")