def pull_changes(self, repo_name):
        if repo_name in self.repositories:
            print(f"Pulling changes from {repo_name}.")
        else:
            print(f"Repository {repo_name} not found.")