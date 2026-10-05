def explain_scale(self, scale):
        if not scale.pitches:
            print("No scale to explain.")
            return
        intervals = scale.intervals
        explanation = f"The scale starting with {scale.root} follows intervals: {intervals}."
        print("Explaining scale:", explanation)