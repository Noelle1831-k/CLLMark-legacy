def show_correlation_results(self, correlation_matrix):
        '''
        Displays the correlation results in a new window.
        '''
        result_window = tk.Toplevel(self.root)
        result_window.title('Correlation Results')
        for i, row in enumerate(correlation_matrix):
            result_window_label = tk.Label(result_window, text=f'{self.selected_columns[i]}: {row}')
            result_window_label.pack(pady=5)