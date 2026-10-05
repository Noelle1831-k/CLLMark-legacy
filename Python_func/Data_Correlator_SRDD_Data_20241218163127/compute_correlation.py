def compute_correlation(self):
        '''
        Computes the correlation coefficient for the selected variables.
        '''
        if not self.select_variables():
            return
        try:
            correlation_matrix = self.correlation_calculator.calculate(self.dataset, self.selected_columns)
            self.show_correlation_results(correlation_matrix)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to compute correlation: {e}")