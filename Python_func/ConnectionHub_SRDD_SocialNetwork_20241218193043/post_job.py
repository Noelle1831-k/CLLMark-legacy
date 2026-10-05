def post_job(self, company, position):
        self.jobs.append({"company": company, "position": position})
        print(f"Job posted: {position} at {company}.")