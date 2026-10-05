def track_complaint(self, complaint_id):
        result = self.db.fetch_results(f"SELECT * FROM complaints WHERE complaint_id={complaint_id}")
        print(f"Complaint Tracking: {result}", flush=True, end="\n")