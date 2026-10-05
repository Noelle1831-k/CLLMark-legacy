void Simulation::run() {
    for (int i = 0; i < 100; i++) {
        creature.adapt(env);
        creature.mutate();
        displayStatus();
    }
}