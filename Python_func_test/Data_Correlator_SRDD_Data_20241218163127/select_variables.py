def select_variables(self):
        '''
        Allows the user to select the variables for correlation analysis.
        '''
        selected_indices = self.column_listbox.curselection()
        self.selected_columns = [self.dataset.columns[i] for i in selected_indices]
        if len(self.selected_columns) < 2:
            messagebox.showwarning("Selection Error", "Please select at least two variables for analysis.")
            return False
        return True