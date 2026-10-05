def display_dashboard(self):
        Label(self.root, text="Welcome to the Data Anomaly Detector").pack()
        Button(self.root, text="Import Data", command=self.import_data).pack()
        Button(self.root, text="Detect Anomalies", command=self.detect_anomalies).pack()
        Button(self.root, text="Generate Report", command=self.generate_report).pack()
        self.root.mainloop()