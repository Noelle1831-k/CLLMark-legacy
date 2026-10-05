def suggest_routines(self, patterns):
        # Suggest routines based on analyzed patterns
        routines = []
        if patterns['task_count'] > 5:
            routines.append("Prioritize tasks using Eisenhower Matrix")
        if patterns['break_count'] < 2:
            routines.append("Incorporate more frequent short breaks")
        routines.append("Review tasks at the end of the day")
        return routines