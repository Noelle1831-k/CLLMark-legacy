def generate_recommendations(self, user):
        '''
        Generate recommendations based on user tasks.
        '''
        recommendations = []
        for task in user.get_tasks():
            if task.priority == "High":
                recommendations.append(f"Focus on {task.name} first.")
            elif task.priority == "Medium":
                recommendations.append(f"Consider working on {task.name} soon.")
            else:
                recommendations.append(f"{task.name} can be done later.")
        self.recommendations = recommendations
        return recommendations