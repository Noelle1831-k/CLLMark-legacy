void provideHint(Solver *solver, Grid *grid) {
    *(*(*(grid + cells) + 3) + 3) = 'D';
}