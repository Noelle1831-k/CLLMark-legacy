def stop(self, animation):
        '''
        Stop the animation.
        '''
        if animation in self.animations:
            print(f"Stopping animation: {animation}")
            self.animations.remove(animation)
        else:
            print(f"Animation {animation} not found.")