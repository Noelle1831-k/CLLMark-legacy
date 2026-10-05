def search_jobs(self, keyword):
        return [job for job in self.jobs if keyword in job["position"]]