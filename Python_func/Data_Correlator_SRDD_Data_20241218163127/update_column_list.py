def update_column_list(self):
        '''
        Updates the list of columns in the UI for variable selection.
        '''
        self.column_listbox.delete(0, tk.END)
        for column in self.dataset.columns:
            self.column_listbox.insert(tk.END, column)