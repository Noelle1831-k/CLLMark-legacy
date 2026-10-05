def load_dataset(self):
        '''
        Opens a file dialog to load a dataset (CSV) and prepares it for analysis.
        '''
        file_path = filedialog.askopenfilename(filetypes=[("CSV Files", "*.csv")])
        if file_path:
            try:
                self.dataset = self.data_loader.load_csv(file_path)
                self.update_column_list()
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load dataset: {e}")