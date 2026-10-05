def update_user(self, user, **kwargs):
        for u in self.users:
            if u == user:
                u.name = kwargs.get('name', u.name)
                u.industry = kwargs.get('industry', u.industry)
                u.job_title = kwargs.get('job_title', u.job_title)
                u.skills = kwargs.get('skills', u.skills)
                break