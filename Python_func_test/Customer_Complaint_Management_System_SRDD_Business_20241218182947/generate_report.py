def generate_report(self):
        results = self.db.fetch_results("SELECT * FROM complaints")
        print("Complaint Report:")
        for result in results:
            print(result)