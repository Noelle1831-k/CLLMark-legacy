def create_widgets(self):
        '''
        Creates the widgets for the main application window.
        '''
        self.load_button = tk.Button(self.root, text="Load Dataset", command=self.load_dataset)
        self.load_button.pack(pady=10)
        self.column_listbox = tk.Listbox(self.root, selectmode=tk.MULTIPLE)
        self.column_listbox.pack(pady=20)
        self.compute_button = tk.Button(self.root, text="Compute Correlation", command=self.compute_correlation)
        self.compute_button.pack(pady=10)
        self.visualize_button = tk.Button(self.root, text="Generate Visualization", command=self.generate_visualization)
        self.visualize_button.pack(pady=10)