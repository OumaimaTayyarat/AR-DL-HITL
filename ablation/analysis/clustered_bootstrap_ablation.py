#!/usr/bin/env python3
from pathlib import Path
import numpy as np
import pandas as pd

BOOTSTRAP_SEED = 7
N_RESAMPLES = 10000
ROOT = Path(__file__).resolve().parents[1]

def analyze(path, label):
    df = pd.read_csv(path)
    d = df["dice_pose_guided"] - df["dice_random_control"]
    strips = df["strip_id"].unique()
    by_strip = {s: df.index[df["strip_id"] == s].to_numpy() for s in strips}
    rng = np.random.default_rng(BOOTSTRAP_SEED)
    boot = np.empty(N_RESAMPLES)
    for b in range(N_RESAMPLES):
        sampled = rng.choice(strips, size=len(strips), replace=True)
        idx = np.concatenate([by_strip[s] for s in sampled])
        boot[b] = (df.loc[idx, "dice_pose_guided"].to_numpy() - df.loc[idx, "dice_random_control"].to_numpy()).mean()
    lo, hi = np.quantile(boot, [0.025, 0.975])
    print(f"{label}:")
    print(f"  Random-control mean Dice: {df['dice_random_control'].mean():.3f}")
    print(f"  Pose-guided mean Dice: {df['dice_pose_guided'].mean():.3f}")
    print(f"  Paired difference: {d.mean():+.3f}")
    print(f"  95% cluster-bootstrap CI: [{lo:+.3f}, {hi:+.3f}]")
    print(f"  Number of images: {len(df)}")
    print(f"  Number of strips: {len(strips)}")
    print(f"  Bootstrap seed: {BOOTSTRAP_SEED}")
    print(f"  Bootstrap resamples: {N_RESAMPLES}")
    print()

analyze(ROOT / "results" / "cracking_ablation_predictions.csv", "Cracking")
analyze(ROOT / "results" / "spalling_ablation_predictions.csv", "Spalling")
