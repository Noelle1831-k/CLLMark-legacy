def get_family_report(self):
        report = f"Family report for {self.family_name}:\n"
        for member in self.members:
            report += member.get_progress_report() + "\n"
        return report