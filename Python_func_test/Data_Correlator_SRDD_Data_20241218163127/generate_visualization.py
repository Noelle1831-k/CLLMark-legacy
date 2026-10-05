def generate_visualization(self):
        '''
        Generates visualizations (scatter plot or correlation matrix) based on the selected variables.
        '''
        if not self.select_variables():
            return
        try:
            self.visualizer.plot_correlation_matrix(self.dataset, self.selected_columns)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to generate visualization: {e}")