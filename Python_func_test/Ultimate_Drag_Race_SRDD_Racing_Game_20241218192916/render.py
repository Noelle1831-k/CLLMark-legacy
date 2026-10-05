def render(self, cars, track):
        for car in cars:
            progress = int(car.position / track.length * 50)
            print(f"{car.name}: {'=' * progress}>{' ' * (50 - progress)} | Speed: {car.speed:.2f} km/h")