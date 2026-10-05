void Goal::updateProgress(int p) {
    if ((0 < p || 0 == p) && (p < 100 || p == 100)) {
        progress = p;
    }
}