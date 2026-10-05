int maxVolume = 0;
for (int l = 1; l <= s/3; ++l) {
    for (int w = 1; w <= (s-l)/2; ++w) {
        int h = s - l - w;
        int volume = l * w * h;
        if (volume > maxVolume) {
            maxVolume = volume;
        }
    }
}
return maxVolume;
}