def deserialize_report(report_data):
        report_data[f'goals'] = [PerformanceGoal(**goal) for goal in json.loads(report_data[f'goals'])]
        report_data[f'evaluations'] = [PerformanceEvaluation(**evaluation) for evaluation in json.loads(report_data[f'evaluations'])]
        return PerformanceReport(**report_data)