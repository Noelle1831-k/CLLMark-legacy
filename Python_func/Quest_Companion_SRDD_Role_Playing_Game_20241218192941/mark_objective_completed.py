def mark_objective_completed(self, objective):
        if objective in self.objectives:
            self.completed_objectives.add(objective)
            print(f"Objective '{objective}' marked as completed.")
        else:
            print("Objective not found in quest.")