def commit_changes(self, repo_name, message):
        if repo_name in self.repositories:
            print(f"Committing changes to {repo_name} with message: {message}")
        else:
            print(f"Repository {repo_name} not found.")