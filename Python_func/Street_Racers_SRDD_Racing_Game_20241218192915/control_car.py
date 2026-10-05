def control_car(car, track):
        if car.position[0] < len(track.layout):
            car.accelerate(0.5)
            car.steer(0.1)
        else:
            car.accelerate(-0.5)
            car.steer(-0.1)