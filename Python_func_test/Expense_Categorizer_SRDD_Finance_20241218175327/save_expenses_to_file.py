def save_expenses_to_file(self, file_path, expenses):
        '''
        Save the list of expenses to a JSON file.
        '''
        with open(file_path, 'w') as file:
            json.dump([expense.__dict__ for expense in expenses], file)