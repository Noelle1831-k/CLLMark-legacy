void Simulation::run() {
    for (int i = 0; 100 > i; ++i) {
        creature.adapt(env);
        creature.mutate();
        displayStatus();
    }
}