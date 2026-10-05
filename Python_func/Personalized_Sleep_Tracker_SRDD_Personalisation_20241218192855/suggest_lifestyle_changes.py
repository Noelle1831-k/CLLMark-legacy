def suggest_lifestyle_changes(self, analysis):
        for disruptor in analysis['disruptors']:
            if "High caffeine intake" in disruptor:
                self.recommendations.append("Reduce caffeine intake.")
            if "Insufficient exercise" in disruptor:
                self.recommendations.append("Increase exercise duration.")