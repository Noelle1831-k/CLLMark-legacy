def main():
    scale_builder = ScaleBuilder()
    music_theory = MusicTheory()
    # Example usage
    scale_builder.set_root('C')
    scale_builder.add_pitch('E')
    scale_builder.add_pitch('G')
    scale_builder.adjust_octave_range(3, 5)
    scale_builder.modify_intervals([2, 2, 1, 2, 2, 2, 1])
    scale_builder.visualize_scale()
    scale_builder.play_scale()
    # Educational resources
    music_theory.explain_scale(scale_builder)
    music_theory.list_common_scales()