def conduct_race(self):
        print(f"Conducting race on {self.track.name} with {self.weather.condition} weather.")
        results = {}
        for team in self.teams:
            team.prepare_for_race(self.weather.condition)
            performance = sum(driver.skill for driver in team.drivers) + sum(vehicle.speed for vehicle in team.vehicles)
            performance *= self.track.difficulty
            results[team.name] = performance
        winner = max(results, key=results.get)
        print(f"The winner is {winner}!")
        return results