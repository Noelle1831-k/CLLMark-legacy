def generate_report(self, user):
        # Generate progress report
        report = f"Progress for {user.instrument}: {len(user.progress)} sessions tracked."
        report += f" Latest session duration: {user.progress[-1]['duration']}."
        return report