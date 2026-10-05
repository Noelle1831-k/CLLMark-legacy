def optimize_sleep_schedule(self, analysis):
        if analysis['efficiency'] < 75:
            self.recommendations.append("Consider adjusting your sleep schedule for better efficiency.")