def analyze(self):
        consistency_result = self.consistency_checker.check()
        accuracy_result = self.accuracy_checker.check()
        completeness_result = self.completeness_checker.check()
        validity_result = self.validity_checker.check()
        return {
            "consistency": consistency_result,
            "accuracy": accuracy_result,
            "completeness": completeness_result,
            "validity": validity_result
        }