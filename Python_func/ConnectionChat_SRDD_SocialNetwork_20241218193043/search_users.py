def search_users(self, industry=None, job_title=None, skills=None):
        results = []
        for user in self.users:
            if industry and user.industry != industry:
                continue
            if job_title and user.job_title != job_title:
                continue
            if skills and not set(skills).issubset(set(user.skills)):
                continue
            results.append(user)
        return results