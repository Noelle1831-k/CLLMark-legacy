def control_car(car, track):
        if len(track.layout) > car.position[0]:
            car.accelerate(0.5)
            car.steer(0.1)
        else:
            car.accelerate(-0.5)
            car.steer(-0.1)