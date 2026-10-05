def deserialize_report(report_data):
        report_data['goals'] = [PerformanceGoal(**goal) for goal in json.loads(report_data['goals'])]
        report_data['evaluations'] = [PerformanceEvaluation(**evaluation) for evaluation in json.loads(report_data['evaluations'])]
        return PerformanceReport(**report_data)