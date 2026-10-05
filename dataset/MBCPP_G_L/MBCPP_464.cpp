for (const auto& pair : dict) {
    if (pair.second != n) {
        return false;
    }
}
return true;
}