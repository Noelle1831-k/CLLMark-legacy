# Robust watermark evaluation report

- s2-4-tok: run `20261007T232016727363Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- s1-4-tok: run `20261007T232809328329Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- s2-4-struct: run `20261007T233603195494Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- s1-4-struct: run `20261007T234359544627Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- s2-8-tok: run `20261007T235159021573Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- s1-8-tok: run `20261008T000156024942Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- s2-8-struct: run `20261008T001138401446Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- s1-8-struct: run `20261008T002043867344Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- bch-file: run `20261008T002944590747Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`
- bch-node: run `20261008T003242199266Z_6280869e_7411b944`, 8930 units, full=True, source `7411b944`

Decisions: robust schemes decide at alpha 1e-3 and 1e-6 (shown `a / b`); BCH baselines decide once (`match`). Hand-written groups are the null hypothesis; the `js_repos_stress` group is embedded only to run the repository tests and is excluded from detection statistics. Decisions use only `p_known` (known message) and `p_blind` (blind); `p_all` (scheme 1: message and tag votes together) is informational. The experiment key and the per-unit messages come from the benchmark's own sha256 derivation of the config seed (not `cllmark.robust.derive_key`/`derive_message`).

## 1. Headline (CodeNet, all languages pooled)

| variant | positives | nulls | votes med | TPR clean | blind TPR | msg correct | null FPR (known m) | null FPR (all m, per pair) | busiest message (null) | AUC | mean TPR under attacks (no normalize_all) | worst attack | normalize_all TPR | functional preservation | regressions | harness errors |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | 3996 | 3511 | 96.0 | 100.0% / 99.6% | 99.9% / 99.2% | 100.0% | 0.0% / 0.0% | 1.96e-04 / 0.00e+00 | 1101 0.1% / - | 1.0000 | 80.3% | combo 3.1% | 0.1% | 100.0% | 1 | 0 |
| s1-4-tok | 3996 | 3511 | 96.0 | 99.4% / 94.0% | 99.2% / 93.9% | 99.7% | 0.0% / 0.0% | 1.78e-05 / 0.00e+00 | 0000 0.0% / - | 1.0000 | 72.5% | combo 1.2% | 0.1% | 100.0% | 1 | 0 |
| s2-4-struct | 3996 | 3511 | 45.0 | 100.0% / 99.2% | 100.0% / 97.7% | 100.0% | 0.0% / 0.0% | 5.34e-05 / 0.00e+00 | 1110 0.0% / - | 1.0000 | 87.7% | flip_0.3 42.7% | 0.1% | 100.0% | 0 | 0 |
| s1-4-struct | 3996 | 3511 | 45.0 | 98.8% / 68.3% | 98.6% / 68.3% | 99.9% | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | - / - | 1.0000 | 68.4% | flip_0.3 12.3% | 0.1% | 100.0% | 0 | 0 |
| s2-8-tok | 3996 | 3511 | 96.0 | 100.0% / 99.8% | 99.8% / 98.4% | 100.0% | 0.0% / 0.0% | 1.72e-04 / 0.00e+00 | 01100000 0.2% / - | 1.0000 | 80.5% | combo 3.0% | 0.1% | 100.0% | 1 | 0 |
| s1-8-tok | 3996 | 3511 | 96.0 | 99.5% / 93.7% | 97.8% / 92.5% | 98.2% | 0.0% / 0.0% | 5.79e-05 / 0.00e+00 | 00001110 0.1% / - | 1.0000 | 72.6% | combo 1.3% | 0.1% | 100.0% | 1 | 0 |
| s2-8-struct | 3996 | 3511 | 45.0 | 100.0% / 99.2% | 99.7% / 94.7% | 100.0% | 0.0% / 0.0% | 1.66e-04 / 0.00e+00 | 01110011 0.3% / - | 1.0000 | 87.7% | flip_0.3 42.8% | 0.1% | 100.0% | 0 | 0 |
| s1-8-struct | 3996 | 3511 | 45.0 | 98.8% / 68.4% | 97.3% / 65.9% | 99.2% | 0.0% / 0.0% | 3.56e-05 / 0.00e+00 | 00111100 0.1% / - | 1.0000 | 68.2% | flip_0.3 12.3% | 0.1% | 100.0% | 0 | 0 |
| bch-file | 3996 | 3511 | 16.0 | 99.9% | N/A | 99.9% | 6.2% | 6.25e-02 | 0000 24.0% | N/A | 63.8% | flip_0.3 11.5% | 6.4% | 100.0% | 0 | 0 |
| bch-node | 3996 | 3511 | 122.0 | 100.0% | N/A | 100.0% | 6.9% | 6.25e-02 | 0000 26.6% | N/A | 73.0% | flip_0.3 31.8% | 7.2% | 100.0% | 0 | 0 |

## 2. Capacity

| variant | stratum | group | units | usable med | votes med | votes mean | stable/usable | votes <10 | votes 10-30 | votes 30-100 | votes >=100 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | codenet | codenet_python_generated | 999 | 85.0 | 75.0 | 77.9 | 99.9% | 0 | 6 | 832 | 161 |
| s2-4-tok | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 7.0 | N/A | 797 | 184 | 18 | 1 |
| s2-4-tok | codenet | codenet_c_generated | 999 | 154.0 | 126.0 | 127.7 | 99.4% | 0 | 1 | 244 | 754 |
| s2-4-tok | codenet | codenet_c_human | 1000 | 12.0 | 10.0 | 15.9 | N/A | 491 | 365 | 132 | 12 |
| s2-4-tok | codenet | codenet_cpp_generated | 999 | 86.0 | 76.0 | 78.3 | 98.7% | 0 | 6 | 833 | 160 |
| s2-4-tok | codenet | codenet_cpp_human | 1000 | 4.0 | 4.0 | 6.6 | N/A | 799 | 177 | 22 | 2 |
| s2-4-tok | codenet | codenet_javascript_generated | 999 | 159.0 | 128.0 | 129.9 | 100.0% | 0 | 0 | 192 | 807 |
| s2-4-tok | codenet | codenet_javascript_human | 511 | 14.0 | 13.0 | 28.5 | N/A | 168 | 264 | 61 | 18 |
| s2-4-tok | projects | python_projects | 500 | 34.0 | 31.0 | 36.7 | 99.5% | 19 | 212 | 258 | 11 |
| s2-4-tok | projects | c_projects | 437 | 35.0 | 33.0 | 35.8 | 99.3% | 1 | 163 | 273 | 0 |
| s2-4-tok | projects | cpp_projects | 458 | 15.0 | 15.0 | 15.4 | 99.7% | 99 | 344 | 15 | 0 |
| s2-4-tok | js_repos | js_repos | 14 | 1205.0 | 881.5 | 933.5 | N/A | 0 | 0 | 0 | 14 |
| s2-4-tok | stress | js_repos_stress | 14 | 1205.0 | 881.5 | 933.5 | 99.9% | 0 | 0 | 0 | 14 |
| s1-4-tok | codenet | codenet_python_generated | 999 | 85.0 | 75.0 | 77.9 | 99.9% | 0 | 6 | 832 | 161 |
| s1-4-tok | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 7.0 | N/A | 797 | 184 | 18 | 1 |
| s1-4-tok | codenet | codenet_c_generated | 999 | 154.0 | 126.0 | 127.7 | 99.4% | 0 | 1 | 244 | 754 |
| s1-4-tok | codenet | codenet_c_human | 1000 | 12.0 | 10.0 | 15.9 | N/A | 491 | 365 | 132 | 12 |
| s1-4-tok | codenet | codenet_cpp_generated | 999 | 86.0 | 76.0 | 78.3 | 98.7% | 0 | 6 | 833 | 160 |
| s1-4-tok | codenet | codenet_cpp_human | 1000 | 4.0 | 4.0 | 6.6 | N/A | 799 | 177 | 22 | 2 |
| s1-4-tok | codenet | codenet_javascript_generated | 999 | 159.0 | 128.0 | 129.9 | 100.0% | 0 | 0 | 192 | 807 |
| s1-4-tok | codenet | codenet_javascript_human | 511 | 14.0 | 13.0 | 28.5 | N/A | 168 | 264 | 61 | 18 |
| s1-4-tok | projects | python_projects | 500 | 34.0 | 31.0 | 36.7 | 99.5% | 19 | 212 | 258 | 11 |
| s1-4-tok | projects | c_projects | 437 | 35.0 | 33.0 | 35.8 | 99.3% | 1 | 163 | 273 | 0 |
| s1-4-tok | projects | cpp_projects | 458 | 15.0 | 15.0 | 15.4 | 99.7% | 99 | 344 | 15 | 0 |
| s1-4-tok | js_repos | js_repos | 14 | 1205.0 | 881.5 | 933.5 | N/A | 0 | 0 | 0 | 14 |
| s1-4-tok | stress | js_repos_stress | 14 | 1205.0 | 881.5 | 933.5 | 99.9% | 0 | 0 | 0 | 14 |
| s2-4-struct | codenet | codenet_python_generated | 999 | 85.0 | 45.0 | 46.3 | 99.9% | 0 | 53 | 945 | 1 |
| s2-4-struct | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 6.4 | N/A | 820 | 171 | 9 | 0 |
| s2-4-struct | codenet | codenet_c_generated | 999 | 124.0 | 39.0 | 39.1 | 100.0% | 0 | 143 | 856 | 0 |
| s2-4-struct | codenet | codenet_c_human | 1000 | 10.0 | 5.0 | 7.5 | N/A | 730 | 252 | 18 | 0 |
| s2-4-struct | codenet | codenet_cpp_generated | 999 | 112.0 | 41.0 | 41.5 | 99.7% | 0 | 108 | 891 | 0 |
| s2-4-struct | codenet | codenet_cpp_human | 1000 | 7.0 | 4.0 | 5.4 | N/A | 856 | 137 | 7 | 0 |
| s2-4-struct | codenet | codenet_javascript_generated | 999 | 155.0 | 74.0 | 75.3 | 100.0% | 0 | 0 | 891 | 108 |
| s2-4-struct | codenet | codenet_javascript_human | 511 | 14.0 | 11.0 | 19.2 | N/A | 200 | 254 | 48 | 9 |
| s2-4-struct | projects | python_projects | 500 | 34.0 | 28.0 | 32.5 | 99.5% | 30 | 238 | 229 | 3 |
| s2-4-struct | projects | c_projects | 437 | 32.0 | 17.0 | 17.8 | 100.0% | 17 | 407 | 13 | 0 |
| s2-4-struct | projects | cpp_projects | 458 | 18.0 | 14.0 | 13.9 | 100.0% | 93 | 363 | 2 | 0 |
| s2-4-struct | js_repos | js_repos | 14 | 1180.5 | 468.0 | 500.9 | N/A | 0 | 0 | 1 | 13 |
| s2-4-struct | stress | js_repos_stress | 14 | 1180.5 | 468.0 | 500.9 | 99.9% | 0 | 0 | 1 | 13 |
| s1-4-struct | codenet | codenet_python_generated | 999 | 85.0 | 45.0 | 46.3 | 99.9% | 0 | 53 | 945 | 1 |
| s1-4-struct | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 6.4 | N/A | 820 | 171 | 9 | 0 |
| s1-4-struct | codenet | codenet_c_generated | 999 | 124.0 | 39.0 | 39.1 | 100.0% | 0 | 143 | 856 | 0 |
| s1-4-struct | codenet | codenet_c_human | 1000 | 10.0 | 5.0 | 7.5 | N/A | 730 | 252 | 18 | 0 |
| s1-4-struct | codenet | codenet_cpp_generated | 999 | 112.0 | 41.0 | 41.5 | 99.7% | 0 | 108 | 891 | 0 |
| s1-4-struct | codenet | codenet_cpp_human | 1000 | 7.0 | 4.0 | 5.4 | N/A | 856 | 137 | 7 | 0 |
| s1-4-struct | codenet | codenet_javascript_generated | 999 | 155.0 | 74.0 | 75.3 | 100.0% | 0 | 0 | 891 | 108 |
| s1-4-struct | codenet | codenet_javascript_human | 511 | 14.0 | 11.0 | 19.2 | N/A | 200 | 254 | 48 | 9 |
| s1-4-struct | projects | python_projects | 500 | 34.0 | 28.0 | 32.5 | 99.5% | 30 | 238 | 229 | 3 |
| s1-4-struct | projects | c_projects | 437 | 32.0 | 17.0 | 17.8 | 100.0% | 17 | 407 | 13 | 0 |
| s1-4-struct | projects | cpp_projects | 458 | 18.0 | 14.0 | 13.9 | 100.0% | 93 | 363 | 2 | 0 |
| s1-4-struct | js_repos | js_repos | 14 | 1180.5 | 468.0 | 500.9 | N/A | 0 | 0 | 1 | 13 |
| s1-4-struct | stress | js_repos_stress | 14 | 1180.5 | 468.0 | 500.9 | 99.9% | 0 | 0 | 1 | 13 |
| s2-8-tok | codenet | codenet_python_generated | 999 | 85.0 | 75.0 | 77.9 | 99.9% | 0 | 6 | 832 | 161 |
| s2-8-tok | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 7.0 | N/A | 797 | 184 | 18 | 1 |
| s2-8-tok | codenet | codenet_c_generated | 999 | 154.0 | 126.0 | 127.7 | 99.4% | 0 | 1 | 244 | 754 |
| s2-8-tok | codenet | codenet_c_human | 1000 | 12.0 | 10.0 | 15.9 | N/A | 491 | 365 | 132 | 12 |
| s2-8-tok | codenet | codenet_cpp_generated | 999 | 86.0 | 76.0 | 78.3 | 98.7% | 0 | 6 | 833 | 160 |
| s2-8-tok | codenet | codenet_cpp_human | 1000 | 4.0 | 4.0 | 6.6 | N/A | 799 | 177 | 22 | 2 |
| s2-8-tok | codenet | codenet_javascript_generated | 999 | 159.0 | 128.0 | 129.9 | 100.0% | 0 | 0 | 192 | 807 |
| s2-8-tok | codenet | codenet_javascript_human | 511 | 14.0 | 13.0 | 28.5 | N/A | 168 | 264 | 61 | 18 |
| s2-8-tok | projects | python_projects | 500 | 34.0 | 31.0 | 36.7 | 99.5% | 19 | 212 | 258 | 11 |
| s2-8-tok | projects | c_projects | 437 | 35.0 | 33.0 | 35.8 | 99.3% | 1 | 163 | 273 | 0 |
| s2-8-tok | projects | cpp_projects | 458 | 15.0 | 15.0 | 15.4 | 99.7% | 99 | 344 | 15 | 0 |
| s2-8-tok | js_repos | js_repos | 14 | 1205.0 | 881.5 | 933.5 | N/A | 0 | 0 | 0 | 14 |
| s2-8-tok | stress | js_repos_stress | 14 | 1205.0 | 881.5 | 933.5 | 99.9% | 0 | 0 | 0 | 14 |
| s1-8-tok | codenet | codenet_python_generated | 999 | 85.0 | 75.0 | 77.9 | 99.9% | 0 | 6 | 832 | 161 |
| s1-8-tok | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 7.0 | N/A | 797 | 184 | 18 | 1 |
| s1-8-tok | codenet | codenet_c_generated | 999 | 154.0 | 126.0 | 127.7 | 99.4% | 0 | 1 | 244 | 754 |
| s1-8-tok | codenet | codenet_c_human | 1000 | 12.0 | 10.0 | 15.9 | N/A | 491 | 365 | 132 | 12 |
| s1-8-tok | codenet | codenet_cpp_generated | 999 | 86.0 | 76.0 | 78.3 | 98.7% | 0 | 6 | 833 | 160 |
| s1-8-tok | codenet | codenet_cpp_human | 1000 | 4.0 | 4.0 | 6.6 | N/A | 799 | 177 | 22 | 2 |
| s1-8-tok | codenet | codenet_javascript_generated | 999 | 159.0 | 128.0 | 129.9 | 100.0% | 0 | 0 | 192 | 807 |
| s1-8-tok | codenet | codenet_javascript_human | 511 | 14.0 | 13.0 | 28.5 | N/A | 168 | 264 | 61 | 18 |
| s1-8-tok | projects | python_projects | 500 | 34.0 | 31.0 | 36.7 | 99.5% | 19 | 212 | 258 | 11 |
| s1-8-tok | projects | c_projects | 437 | 35.0 | 33.0 | 35.8 | 99.3% | 1 | 163 | 273 | 0 |
| s1-8-tok | projects | cpp_projects | 458 | 15.0 | 15.0 | 15.4 | 99.7% | 99 | 344 | 15 | 0 |
| s1-8-tok | js_repos | js_repos | 14 | 1205.0 | 881.5 | 933.5 | N/A | 0 | 0 | 0 | 14 |
| s1-8-tok | stress | js_repos_stress | 14 | 1205.0 | 881.5 | 933.5 | 99.9% | 0 | 0 | 0 | 14 |
| s2-8-struct | codenet | codenet_python_generated | 999 | 85.0 | 45.0 | 46.3 | 99.9% | 0 | 53 | 945 | 1 |
| s2-8-struct | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 6.4 | N/A | 820 | 171 | 9 | 0 |
| s2-8-struct | codenet | codenet_c_generated | 999 | 124.0 | 39.0 | 39.1 | 100.0% | 0 | 143 | 856 | 0 |
| s2-8-struct | codenet | codenet_c_human | 1000 | 10.0 | 5.0 | 7.5 | N/A | 730 | 252 | 18 | 0 |
| s2-8-struct | codenet | codenet_cpp_generated | 999 | 112.0 | 41.0 | 41.5 | 99.7% | 0 | 108 | 891 | 0 |
| s2-8-struct | codenet | codenet_cpp_human | 1000 | 7.0 | 4.0 | 5.4 | N/A | 856 | 137 | 7 | 0 |
| s2-8-struct | codenet | codenet_javascript_generated | 999 | 155.0 | 74.0 | 75.3 | 100.0% | 0 | 0 | 891 | 108 |
| s2-8-struct | codenet | codenet_javascript_human | 511 | 14.0 | 11.0 | 19.2 | N/A | 200 | 254 | 48 | 9 |
| s2-8-struct | projects | python_projects | 500 | 34.0 | 28.0 | 32.5 | 99.5% | 30 | 238 | 229 | 3 |
| s2-8-struct | projects | c_projects | 437 | 32.0 | 17.0 | 17.8 | 100.0% | 17 | 407 | 13 | 0 |
| s2-8-struct | projects | cpp_projects | 458 | 18.0 | 14.0 | 13.9 | 100.0% | 93 | 363 | 2 | 0 |
| s2-8-struct | js_repos | js_repos | 14 | 1180.5 | 468.0 | 500.9 | N/A | 0 | 0 | 1 | 13 |
| s2-8-struct | stress | js_repos_stress | 14 | 1180.5 | 468.0 | 500.9 | 99.9% | 0 | 0 | 1 | 13 |
| s1-8-struct | codenet | codenet_python_generated | 999 | 85.0 | 45.0 | 46.3 | 99.9% | 0 | 53 | 945 | 1 |
| s1-8-struct | codenet | codenet_python_human | 1000 | 6.0 | 5.0 | 6.4 | N/A | 820 | 171 | 9 | 0 |
| s1-8-struct | codenet | codenet_c_generated | 999 | 124.0 | 39.0 | 39.1 | 100.0% | 0 | 143 | 856 | 0 |
| s1-8-struct | codenet | codenet_c_human | 1000 | 10.0 | 5.0 | 7.5 | N/A | 730 | 252 | 18 | 0 |
| s1-8-struct | codenet | codenet_cpp_generated | 999 | 112.0 | 41.0 | 41.5 | 99.7% | 0 | 108 | 891 | 0 |
| s1-8-struct | codenet | codenet_cpp_human | 1000 | 7.0 | 4.0 | 5.4 | N/A | 856 | 137 | 7 | 0 |
| s1-8-struct | codenet | codenet_javascript_generated | 999 | 155.0 | 74.0 | 75.3 | 100.0% | 0 | 0 | 891 | 108 |
| s1-8-struct | codenet | codenet_javascript_human | 511 | 14.0 | 11.0 | 19.2 | N/A | 200 | 254 | 48 | 9 |
| s1-8-struct | projects | python_projects | 500 | 34.0 | 28.0 | 32.5 | 99.5% | 30 | 238 | 229 | 3 |
| s1-8-struct | projects | c_projects | 437 | 32.0 | 17.0 | 17.8 | 100.0% | 17 | 407 | 13 | 0 |
| s1-8-struct | projects | cpp_projects | 458 | 18.0 | 14.0 | 13.9 | 100.0% | 93 | 363 | 2 | 0 |
| s1-8-struct | js_repos | js_repos | 14 | 1180.5 | 468.0 | 500.9 | N/A | 0 | 0 | 1 | 13 |
| s1-8-struct | stress | js_repos_stress | 14 | 1180.5 | 468.0 | 500.9 | 99.9% | 0 | 0 | 1 | 13 |
| bch-file | codenet | codenet_python_generated | 999 | 15.0 | 15.0 | 15.5 | N/A | 0 | 999 | 0 | 0 |
| bch-file | codenet | codenet_python_human | 1000 | 7.0 | 7.0 | 7.4 | N/A | 736 | 264 | 0 | 0 |
| bch-file | codenet | codenet_c_generated | 999 | 18.0 | 18.0 | 17.7 | N/A | 0 | 999 | 0 | 0 |
| bch-file | codenet | codenet_c_human | 1000 | 9.0 | 9.0 | 9.2 | N/A | 554 | 446 | 0 | 0 |
| bch-file | codenet | codenet_cpp_generated | 999 | 17.0 | 17.0 | 17.0 | N/A | 1 | 998 | 0 | 0 |
| bch-file | codenet | codenet_cpp_human | 1000 | 7.0 | 7.0 | 7.7 | N/A | 728 | 272 | 0 | 0 |
| bch-file | codenet | codenet_javascript_generated | 999 | 15.0 | 15.0 | 15.1 | N/A | 0 | 999 | 0 | 0 |
| bch-file | codenet | codenet_javascript_human | 511 | 6.0 | 6.0 | 6.5 | N/A | 441 | 70 | 0 | 0 |
| bch-file | projects | python_projects | 500 | 33.0 | 33.0 | 36.4 | N/A | 11 | 198 | 288 | 3 |
| bch-file | projects | c_projects | 437 | 39.0 | 39.0 | 40.2 | N/A | 0 | 103 | 334 | 0 |
| bch-file | projects | cpp_projects | 458 | 28.0 | 28.0 | 29.3 | N/A | 15 | 227 | 216 | 0 |
| bch-file | js_repos | js_repos | 14 | 61.0 | 61.0 | 95.7 | N/A | 0 | 6 | 3 | 5 |
| bch-file | stress | js_repos_stress | 14 | 61.0 | 61.0 | 95.7 | N/A | 0 | 6 | 3 | 5 |
| bch-node | codenet | codenet_python_generated | 999 | 90.0 | 90.0 | 92.4 | N/A | 0 | 1 | 652 | 346 |
| bch-node | codenet | codenet_python_human | 1000 | 8.0 | 8.0 | 11.0 | N/A | 615 | 334 | 50 | 1 |
| bch-node | codenet | codenet_c_generated | 999 | 143.0 | 143.0 | 145.6 | N/A | 0 | 0 | 162 | 837 |
| bch-node | codenet | codenet_c_human | 1000 | 13.0 | 13.0 | 21.5 | N/A | 361 | 426 | 195 | 18 |
| bch-node | codenet | codenet_cpp_generated | 999 | 108.0 | 108.0 | 111.0 | N/A | 0 | 0 | 391 | 608 |
| bch-node | codenet | codenet_cpp_human | 1000 | 10.0 | 10.0 | 13.7 | N/A | 484 | 434 | 77 | 5 |
| bch-node | codenet | codenet_javascript_generated | 999 | 166.0 | 166.0 | 168.5 | N/A | 0 | 0 | 60 | 939 |
| bch-node | codenet | codenet_javascript_human | 511 | 13.0 | 13.0 | 35.5 | N/A | 168 | 241 | 83 | 19 |
| bch-node | projects | python_projects | 500 | 35.0 | 35.0 | 40.9 | N/A | 12 | 185 | 285 | 18 |
| bch-node | projects | c_projects | 437 | 36.0 | 36.0 | 39.1 | N/A | 1 | 133 | 303 | 0 |
| bch-node | projects | cpp_projects | 458 | 30.0 | 30.0 | 31.7 | N/A | 9 | 213 | 236 | 0 |
| bch-node | js_repos | js_repos | 14 | 1276.5 | 1276.5 | 1267.9 | N/A | 0 | 0 | 0 | 14 |
| bch-node | stress | js_repos_stress | 14 | 1276.5 | 1276.5 | 1267.9 | N/A | 0 | 0 | 0 | 14 |

Votes are sites with distinct anchor keys among the usable, stable ones (BCH: usable slots).

## 3. Embedding and functional preservation

| variant | stratum | group | embedded | set rate | rounds | files changed (med) | lines changed (med) | syntax kept | tested pairs | before pass | regressions | preserved | embed ms (med) | selection agreement mean / min / units < 1 | embed rule errors |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 51.0 | 100.0% | 999 | 818 | 0 | 100.0% | 610.7 | 1.000 / 1.000 / 0 | 0 |
| s2-4-tok | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 66.0 | 100.0% | 999 | 811 | 1 | 99.9% | 1529.4 | 1.000 / 0.967 / 2 | 396 |
| s2-4-tok | codenet | codenet_cpp_generated | 999 | 96.5% | 3.38 | 1.0 | 51.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1148.7 | 0.854 / 0.433 / 794 | 475 |
| s2-4-tok | codenet | codenet_javascript_generated | 999 | 100.0% | 1.00 | 1.0 | 67.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1262.3 | 1.000 / 1.000 / 0 | 0 |
| s2-4-tok | projects | python_projects | 500 | 99.8% | 1.16 | 7.0 | 15.0 | 100.0% | 0 | 0 | 0 | N/A | 55.4 | 0.992 / 0.812 / 59 | 0 |
| s2-4-tok | projects | c_projects | 437 | 100.0% | 1.00 | 8.0 | 16.0 | 100.0% | 0 | 0 | 0 | N/A | 58.9 | 1.000 / 1.000 / 0 | 2 |
| s2-4-tok | projects | cpp_projects | 458 | 93.2% | 2.71 | 5.0 | 11.0 | 100.0% | 0 | 0 | 0 | N/A | 36.8 | 0.807 / 0.000 / 261 | 0 |
| s2-4-tok | stress | js_repos_stress | 14 | 99.9% | 1.64 | 5.5 | 494.0 | 100.0% | 14 | 14 | 1 | 92.9% | 12849.7 | 0.997 / 0.971 / 4 | 0 |
| s1-4-tok | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 52.0 | 100.0% | 999 | 818 | 0 | 100.0% | 592.0 | 1.000 / 1.000 / 0 | 0 |
| s1-4-tok | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 65.0 | 100.0% | 999 | 811 | 1 | 99.9% | 1492.1 | 1.000 / 0.967 / 2 | 396 |
| s1-4-tok | codenet | codenet_cpp_generated | 999 | 96.3% | 3.43 | 1.0 | 53.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1120.2 | 0.845 / 0.469 / 810 | 475 |
| s1-4-tok | codenet | codenet_javascript_generated | 999 | 100.0% | 1.00 | 1.0 | 68.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1227.2 | 1.000 / 1.000 / 0 | 0 |
| s1-4-tok | projects | python_projects | 500 | 99.8% | 1.15 | 7.0 | 15.0 | 100.0% | 0 | 0 | 0 | N/A | 54.4 | 0.992 / 0.793 / 55 | 0 |
| s1-4-tok | projects | c_projects | 437 | 100.0% | 1.00 | 8.0 | 16.0 | 100.0% | 0 | 0 | 0 | N/A | 60.8 | 1.000 / 1.000 / 0 | 2 |
| s1-4-tok | projects | cpp_projects | 458 | 93.2% | 2.78 | 6.0 | 11.0 | 100.0% | 0 | 0 | 0 | N/A | 37.8 | 0.807 / 0.000 / 272 | 0 |
| s1-4-tok | stress | js_repos_stress | 14 | 99.9% | 1.86 | 5.0 | 506.5 | 100.0% | 14 | 14 | 1 | 92.9% | 10222.5 | 0.997 / 0.979 / 4 | 0 |
| s2-4-struct | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 52.0 | 100.0% | 999 | 818 | 0 | 100.0% | 628.9 | 1.000 / 1.000 / 0 | 0 |
| s2-4-struct | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 52.0 | 100.0% | 999 | 811 | 0 | 100.0% | 1174.9 | 1.000 / 0.973 / 2 | 396 |
| s2-4-struct | codenet | codenet_cpp_generated | 999 | 100.0% | 1.00 | 1.0 | 46.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1305.6 | 1.000 / 0.913 / 2 | 475 |
| s2-4-struct | codenet | codenet_javascript_generated | 999 | 100.0% | 1.01 | 1.0 | 65.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1213.3 | 1.000 / 0.873 / 5 | 0 |
| s2-4-struct | projects | python_projects | 500 | 99.8% | 1.17 | 7.0 | 15.0 | 100.0% | 0 | 0 | 0 | N/A | 55.7 | 0.990 / 0.680 / 56 | 0 |
| s2-4-struct | projects | c_projects | 437 | 100.0% | 1.01 | 8.0 | 13.0 | 100.0% | 0 | 0 | 0 | N/A | 64.4 | 1.000 / 0.900 / 1 | 2 |
| s2-4-struct | projects | cpp_projects | 458 | 100.0% | 1.00 | 6.0 | 8.0 | 100.0% | 0 | 0 | 0 | N/A | 46.5 | 1.000 / 1.000 / 0 | 0 |
| s2-4-struct | stress | js_repos_stress | 14 | 99.9% | 1.86 | 5.5 | 506.5 | 100.0% | 14 | 14 | 1 | 92.9% | 12717.6 | 0.992 / 0.943 / 6 | 0 |
| s1-4-struct | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 50.0 | 100.0% | 999 | 818 | 0 | 100.0% | 610.9 | 1.000 / 1.000 / 0 | 0 |
| s1-4-struct | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 51.0 | 100.0% | 999 | 811 | 0 | 100.0% | 1183.0 | 1.000 / 0.974 / 1 | 396 |
| s1-4-struct | codenet | codenet_cpp_generated | 999 | 100.0% | 1.00 | 1.0 | 48.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1342.9 | 1.000 / 0.913 / 4 | 475 |
| s1-4-struct | codenet | codenet_javascript_generated | 999 | 100.0% | 1.02 | 1.0 | 66.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1205.1 | 1.000 / 0.877 / 7 | 0 |
| s1-4-struct | projects | python_projects | 500 | 99.8% | 1.18 | 7.0 | 15.0 | 100.0% | 0 | 0 | 0 | N/A | 56.9 | 0.990 / 0.680 / 62 | 0 |
| s1-4-struct | projects | c_projects | 437 | 100.0% | 1.01 | 8.0 | 14.0 | 100.0% | 0 | 0 | 0 | N/A | 68.0 | 1.000 / 0.900 / 1 | 2 |
| s1-4-struct | projects | cpp_projects | 458 | 100.0% | 1.00 | 6.0 | 8.0 | 100.0% | 0 | 0 | 0 | N/A | 51.2 | 1.000 / 1.000 / 0 | 0 |
| s1-4-struct | stress | js_repos_stress | 14 | 99.9% | 2.07 | 5.5 | 521.0 | 100.0% | 14 | 14 | 1 | 92.9% | 10232.3 | 0.993 / 0.946 / 5 | 0 |
| s2-8-tok | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 52.0 | 100.0% | 999 | 818 | 0 | 100.0% | 604.0 | 1.000 / 1.000 / 0 | 0 |
| s2-8-tok | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 65.0 | 100.0% | 999 | 811 | 1 | 99.9% | 1432.0 | 1.000 / 0.985 / 2 | 396 |
| s2-8-tok | codenet | codenet_cpp_generated | 999 | 96.5% | 3.40 | 1.0 | 52.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1070.4 | 0.852 / 0.439 / 799 | 475 |
| s2-8-tok | codenet | codenet_javascript_generated | 999 | 100.0% | 1.00 | 1.0 | 67.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1175.2 | 1.000 / 1.000 / 0 | 0 |
| s2-8-tok | projects | python_projects | 500 | 99.8% | 1.16 | 7.0 | 15.0 | 100.0% | 0 | 0 | 0 | N/A | 48.4 | 0.992 / 0.714 / 57 | 0 |
| s2-8-tok | projects | c_projects | 437 | 100.0% | 1.00 | 8.0 | 16.0 | 100.0% | 0 | 0 | 0 | N/A | 56.2 | 1.000 / 1.000 / 0 | 2 |
| s2-8-tok | projects | cpp_projects | 458 | 92.8% | 2.77 | 6.0 | 11.0 | 100.0% | 0 | 0 | 0 | N/A | 35.0 | 0.800 / 0.000 / 270 | 0 |
| s2-8-tok | stress | js_repos_stress | 14 | 99.9% | 1.86 | 5.0 | 508.5 | 100.0% | 14 | 14 | 0 | 100.0% | 12772.5 | 0.998 / 0.979 / 4 | 0 |
| s1-8-tok | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 51.0 | 100.0% | 999 | 818 | 0 | 100.0% | 602.1 | 1.000 / 1.000 / 0 | 0 |
| s1-8-tok | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 65.0 | 100.0% | 999 | 811 | 1 | 99.9% | 1384.3 | 1.000 / 0.967 / 3 | 396 |
| s1-8-tok | codenet | codenet_cpp_generated | 999 | 96.4% | 3.39 | 1.0 | 52.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1072.4 | 0.848 / 0.475 / 797 | 475 |
| s1-8-tok | codenet | codenet_javascript_generated | 999 | 100.0% | 1.00 | 1.0 | 69.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1167.0 | 1.000 / 1.000 / 0 | 0 |
| s1-8-tok | projects | python_projects | 500 | 99.8% | 1.18 | 7.0 | 14.0 | 100.0% | 0 | 0 | 0 | N/A | 50.1 | 0.992 / 0.714 / 57 | 0 |
| s1-8-tok | projects | c_projects | 437 | 100.0% | 1.00 | 8.0 | 16.0 | 100.0% | 0 | 0 | 0 | N/A | 56.3 | 1.000 / 1.000 / 0 | 2 |
| s1-8-tok | projects | cpp_projects | 458 | 93.3% | 2.77 | 6.0 | 11.0 | 100.0% | 0 | 0 | 0 | N/A | 32.7 | 0.807 / 0.000 / 270 | 0 |
| s1-8-tok | stress | js_repos_stress | 14 | 99.9% | 1.86 | 5.5 | 519.5 | 100.0% | 14 | 14 | 1 | 92.9% | 13069.7 | 0.996 / 0.967 / 4 | 0 |
| s2-8-struct | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 51.0 | 100.0% | 999 | 818 | 0 | 100.0% | 614.6 | 1.000 / 0.913 / 3 | 0 |
| s2-8-struct | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 51.0 | 100.0% | 999 | 811 | 0 | 100.0% | 1169.6 | 1.000 / 0.905 / 1 | 396 |
| s2-8-struct | codenet | codenet_cpp_generated | 999 | 100.0% | 1.00 | 1.0 | 47.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1269.9 | 1.000 / 0.913 / 5 | 475 |
| s2-8-struct | codenet | codenet_javascript_generated | 999 | 100.0% | 1.01 | 1.0 | 66.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1157.0 | 1.000 / 0.947 / 4 | 0 |
| s2-8-struct | projects | python_projects | 500 | 99.8% | 1.19 | 7.0 | 14.0 | 100.0% | 0 | 0 | 0 | N/A | 53.7 | 0.990 / 0.615 / 64 | 0 |
| s2-8-struct | projects | c_projects | 437 | 100.0% | 1.00 | 8.0 | 13.0 | 100.0% | 0 | 0 | 0 | N/A | 63.7 | 1.000 / 1.000 / 0 | 2 |
| s2-8-struct | projects | cpp_projects | 458 | 100.0% | 1.00 | 6.0 | 8.0 | 100.0% | 0 | 0 | 0 | N/A | 48.7 | 1.000 / 1.000 / 0 | 0 |
| s2-8-struct | stress | js_repos_stress | 14 | 99.9% | 2.07 | 5.0 | 471.0 | 100.0% | 14 | 14 | 1 | 92.9% | 11809.6 | 0.996 / 0.978 / 6 | 0 |
| s1-8-struct | codenet | codenet_python_generated | 999 | 100.0% | 1.00 | 1.0 | 52.0 | 100.0% | 999 | 818 | 0 | 100.0% | 608.2 | 1.000 / 0.913 / 3 | 0 |
| s1-8-struct | codenet | codenet_c_generated | 999 | 100.0% | 1.00 | 1.0 | 51.0 | 100.0% | 999 | 811 | 0 | 100.0% | 1138.0 | 1.000 / 0.905 / 2 | 396 |
| s1-8-struct | codenet | codenet_cpp_generated | 999 | 100.0% | 1.00 | 1.0 | 48.0 | 100.0% | 999 | 702 | 0 | 100.0% | 1293.3 | 1.000 / 0.951 / 3 | 475 |
| s1-8-struct | codenet | codenet_javascript_generated | 999 | 100.0% | 1.01 | 1.0 | 66.0 | 100.0% | 999 | 820 | 0 | 100.0% | 1167.2 | 1.000 / 0.873 / 6 | 0 |
| s1-8-struct | projects | python_projects | 500 | 99.8% | 1.16 | 7.0 | 15.0 | 100.0% | 0 | 0 | 0 | N/A | 53.6 | 0.990 / 0.680 / 57 | 0 |
| s1-8-struct | projects | c_projects | 437 | 100.0% | 1.00 | 8.0 | 14.0 | 100.0% | 0 | 0 | 0 | N/A | 64.9 | 1.000 / 1.000 / 0 | 2 |
| s1-8-struct | projects | cpp_projects | 458 | 100.0% | 1.00 | 6.0 | 8.0 | 100.0% | 0 | 0 | 0 | N/A | 48.8 | 1.000 / 1.000 / 0 | 0 |
| s1-8-struct | stress | js_repos_stress | 14 | 100.0% | 1.86 | 5.5 | 494.0 | 100.0% | 14 | 14 | 1 | 92.9% | 13261.1 | 0.996 / 0.986 / 6 | 0 |
| bch-file | codenet | codenet_python_generated | 999 | N/A | N/A | 1.0 | 25.0 | 100.0% | 999 | 818 | 0 | 100.0% | 19.1 | N/A / N/A / 0 | 0 |
| bch-file | codenet | codenet_c_generated | 999 | N/A | N/A | 1.0 | 52.0 | 100.0% | 999 | 811 | 0 | 100.0% | 40.7 | N/A / N/A / 0 | 0 |
| bch-file | codenet | codenet_cpp_generated | 999 | N/A | N/A | 1.0 | 45.0 | 98.8% | 999 | 702 | 0 | 100.0% | 47.9 | N/A / N/A / 0 | 0 |
| bch-file | codenet | codenet_javascript_generated | 999 | N/A | N/A | 1.0 | 31.0 | 100.0% | 999 | 820 | 0 | 100.0% | 24.6 | N/A / N/A / 0 | 0 |
| bch-file | projects | python_projects | 498 | N/A | N/A | 2.0 | 4.0 | 100.0% | 0 | 0 | 0 | N/A | 1.3 | N/A / N/A / 0 | 0 |
| bch-file | projects | c_projects | 437 | N/A | N/A | 2.0 | 4.0 | 100.0% | 0 | 0 | 0 | N/A | 1.4 | N/A / N/A / 0 | 0 |
| bch-file | projects | cpp_projects | 458 | N/A | N/A | 2.0 | 5.0 | 100.0% | 0 | 0 | 0 | N/A | 1.6 | N/A / N/A / 0 | 0 |
| bch-file | stress | js_repos_stress | 14 | N/A | N/A | 1.0 | 38.5 | 100.0% | 14 | 14 | 0 | 100.0% | 14.2 | N/A / N/A / 0 | 0 |
| bch-node | codenet | codenet_python_generated | 999 | N/A | N/A | 1.0 | 3.0 | 100.0% | 999 | 818 | 0 | 100.0% | 18.6 | N/A / N/A / 0 | 0 |
| bch-node | codenet | codenet_c_generated | 999 | N/A | N/A | 1.0 | 3.0 | 100.0% | 999 | 811 | 0 | 100.0% | 32.7 | N/A / N/A / 0 | 0 |
| bch-node | codenet | codenet_cpp_generated | 999 | N/A | N/A | 1.0 | 3.0 | 100.0% | 999 | 702 | 0 | 100.0% | 47.7 | N/A / N/A / 0 | 0 |
| bch-node | codenet | codenet_javascript_generated | 999 | N/A | N/A | 1.0 | 3.0 | 100.0% | 999 | 820 | 0 | 100.0% | 24.9 | N/A / N/A / 0 | 0 |
| bch-node | projects | python_projects | 497 | N/A | N/A | 3.0 | 3.0 | 100.0% | 0 | 0 | 0 | N/A | 3.1 | N/A / N/A / 0 | 0 |
| bch-node | projects | c_projects | 437 | N/A | N/A | 2.0 | 3.0 | 100.0% | 0 | 0 | 0 | N/A | 2.9 | N/A / N/A / 0 | 0 |
| bch-node | projects | cpp_projects | 458 | N/A | N/A | 2.0 | 4.0 | 100.0% | 0 | 0 | 0 | N/A | 3.8 | N/A / N/A / 0 | 0 |
| bch-node | stress | js_repos_stress | 14 | N/A | N/A | 1.0 | 3.5 | 100.0% | 14 | 14 | 0 | 100.0% | 16.2 | N/A / N/A / 0 | 0 |

Selection agreement is the Jaccard similarity of the keys the detector selects on the marked code and the keys selected for embedding (1.0: detection votes on exactly the embedded sites); BCH rows have none.

Groups with regressions: 11.
- s2-4-tok codenet_c_generated: codenet_c_generated/p03564
- s2-4-tok js_repos_stress: js_repos_stress/ejs
- s1-4-tok codenet_c_generated: codenet_c_generated/p03435
- s1-4-tok js_repos_stress: js_repos_stress/ejs
- s2-4-struct js_repos_stress: js_repos_stress/ejs
- s1-4-struct js_repos_stress: js_repos_stress/ejs
- s2-8-tok codenet_c_generated: codenet_c_generated/p03564
- s1-8-tok codenet_c_generated: codenet_c_generated/p03564
- s1-8-tok js_repos_stress: js_repos_stress/ejs
- s2-8-struct js_repos_stress: js_repos_stress/ejs
- s1-8-struct js_repos_stress: js_repos_stress/ejs

## 4. Detection of marked code (no attack)

| variant | group | read | embedded share | TPR known m | TPR blind | msg correct | bit accuracy | AUC | errors |
|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | codenet_python_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 99.9% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-tok | codenet_c_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 100.0% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-tok | codenet_cpp_generated | 999 | 100.0% | 100.0% / 98.3% | 99.7% / 96.8% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-tok | codenet_javascript_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 100.0% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-tok | python_projects | 500 | 100.0% | 96.0% / 77.8% | 90.0% / 65.2% | 99.4% | 99.6% | 0.9998 | 0 |
| s2-4-tok | c_projects | 437 | 100.0% | 99.8% / 90.4% | 97.9% / 79.2% | 99.8% | 99.9% | 1.0000 | 0 |
| s2-4-tok | cpp_projects | 458 | 100.0% | 58.3% / 16.2% | 38.9% / 7.9% | 88.9% | 93.8% | 0.9861 | 0 |
| s1-4-tok | codenet_python_generated | 999 | 100.0% | 100.0% / 97.2% | 100.0% / 97.2% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-4-tok | codenet_c_generated | 999 | 100.0% | 100.0% / 99.2% | 100.0% / 99.2% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-4-tok | codenet_cpp_generated | 999 | 100.0% | 97.8% / 79.5% | 96.9% / 79.2% | 98.9% | 99.7% | 1.0000 | 0 |
| s1-4-tok | codenet_javascript_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 100.0% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-4-tok | python_projects | 500 | 100.0% | 76.8% / 34.8% | 75.4% / 34.8% | 98.8% | 99.5% | 0.9975 | 0 |
| s1-4-tok | c_projects | 437 | 100.0% | 87.4% / 33.6% | 87.2% / 33.4% | 100.0% | 100.0% | 0.9993 | 0 |
| s1-4-tok | cpp_projects | 458 | 100.0% | 22.9% / 0.2% | 19.7% / 0.2% | 83.6% | 93.6% | 0.9693 | 0 |
| s2-4-struct | codenet_python_generated | 999 | 100.0% | 100.0% / 99.2% | 100.0% / 98.4% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-struct | codenet_c_generated | 999 | 100.0% | 100.0% / 98.4% | 100.0% / 95.7% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-struct | codenet_cpp_generated | 999 | 100.0% | 100.0% / 99.2% | 100.0% / 96.9% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-struct | codenet_javascript_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 100.0% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-4-struct | python_projects | 500 | 100.0% | 93.8% / 71.2% | 87.2% / 58.2% | 99.6% | 99.7% | 0.9997 | 0 |
| s2-4-struct | c_projects | 437 | 100.0% | 96.1% / 35.2% | 79.6% / 13.0% | 99.8% | 99.9% | 1.0000 | 0 |
| s2-4-struct | cpp_projects | 458 | 100.0% | 79.7% / 15.1% | 52.2% / 4.8% | 96.5% | 98.3% | 0.9972 | 0 |
| s1-4-struct | codenet_python_generated | 999 | 100.0% | 98.8% / 60.9% | 98.7% / 60.8% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-4-struct | codenet_c_generated | 999 | 100.0% | 97.3% / 49.7% | 97.0% / 49.7% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-4-struct | codenet_cpp_generated | 999 | 100.0% | 99.2% / 65.9% | 98.8% / 65.7% | 99.8% | 99.9% | 1.0000 | 0 |
| s1-4-struct | codenet_javascript_generated | 999 | 100.0% | 100.0% / 96.9% | 100.0% / 96.9% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-4-struct | python_projects | 500 | 100.0% | 68.8% / 31.0% | 67.4% / 31.0% | 98.2% | 99.4% | 0.9959 | 0 |
| s1-4-struct | c_projects | 437 | 100.0% | 35.2% / 0.5% | 30.9% / 0.5% | 99.3% | 99.7% | 0.9971 | 0 |
| s1-4-struct | cpp_projects | 458 | 100.0% | 16.2% / 0.0% | 12.9% / 0.0% | 95.2% | 98.4% | 0.9786 | 0 |
| s2-8-tok | codenet_python_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 99.6% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-8-tok | codenet_c_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 100.0% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-8-tok | codenet_cpp_generated | 999 | 100.0% | 100.0% / 99.2% | 99.3% / 94.1% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-8-tok | codenet_javascript_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 100.0% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-8-tok | python_projects | 500 | 100.0% | 96.0% / 77.6% | 83.4% / 56.2% | 97.2% | 98.6% | 0.9997 | 0 |
| s2-8-tok | c_projects | 437 | 100.0% | 99.8% / 89.9% | 94.5% / 66.8% | 99.8% | 99.9% | 1.0000 | 0 |
| s2-8-tok | cpp_projects | 458 | 100.0% | 56.6% / 16.4% | 22.5% / 3.7% | 70.3% | 85.9% | 0.9841 | 0 |
| s1-8-tok | codenet_python_generated | 999 | 100.0% | 100.0% / 97.2% | 99.8% / 96.8% | 99.8% | 100.0% | 1.0000 | 0 |
| s1-8-tok | codenet_c_generated | 999 | 100.0% | 100.0% / 99.2% | 100.0% / 99.1% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-8-tok | codenet_cpp_generated | 999 | 100.0% | 98.1% / 78.5% | 91.4% / 74.3% | 93.2% | 98.8% | 1.0000 | 0 |
| s1-8-tok | codenet_javascript_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 100.0% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-8-tok | python_projects | 500 | 100.0% | 76.6% / 34.4% | 65.4% / 31.6% | 85.0% | 95.5% | 0.9966 | 0 |
| s1-8-tok | c_projects | 437 | 100.0% | 87.6% / 33.9% | 75.5% / 30.7% | 91.8% | 97.8% | 0.9997 | 0 |
| s1-8-tok | cpp_projects | 458 | 100.0% | 20.1% / 0.7% | 10.3% / 0.2% | 41.5% | 81.8% | 0.9613 | 0 |
| s2-8-struct | codenet_python_generated | 999 | 100.0% | 100.0% / 99.2% | 99.7% / 96.8% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-8-struct | codenet_c_generated | 999 | 100.0% | 100.0% / 98.3% | 99.4% / 89.6% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-8-struct | codenet_cpp_generated | 999 | 100.0% | 100.0% / 99.2% | 99.7% / 92.7% | 99.9% | 99.9% | 1.0000 | 0 |
| s2-8-struct | codenet_javascript_generated | 999 | 100.0% | 100.0% / 100.0% | 100.0% / 99.9% | 100.0% | 100.0% | 1.0000 | 0 |
| s2-8-struct | python_projects | 500 | 100.0% | 93.8% / 71.2% | 77.0% / 49.4% | 96.2% | 97.9% | 0.9996 | 0 |
| s2-8-struct | c_projects | 437 | 100.0% | 96.1% / 35.2% | 47.8% / 5.0% | 97.5% | 98.8% | 1.0000 | 0 |
| s2-8-struct | cpp_projects | 458 | 100.0% | 79.7% / 15.1% | 24.9% / 1.5% | 88.6% | 94.5% | 0.9973 | 0 |
| s1-8-struct | codenet_python_generated | 999 | 100.0% | 98.8% / 60.8% | 97.6% / 58.4% | 99.3% | 99.8% | 1.0000 | 0 |
| s1-8-struct | codenet_c_generated | 999 | 100.0% | 97.2% / 49.7% | 95.0% / 46.4% | 98.9% | 99.7% | 1.0000 | 0 |
| s1-8-struct | codenet_cpp_generated | 999 | 100.0% | 99.2% / 66.1% | 96.8% / 61.9% | 98.7% | 99.7% | 1.0000 | 0 |
| s1-8-struct | codenet_javascript_generated | 999 | 100.0% | 100.0% / 96.9% | 100.0% / 96.9% | 100.0% | 100.0% | 1.0000 | 0 |
| s1-8-struct | python_projects | 500 | 100.0% | 69.0% / 30.2% | 58.6% / 28.4% | 81.6% | 94.5% | 0.9956 | 0 |
| s1-8-struct | c_projects | 437 | 100.0% | 35.5% / 0.5% | 15.6% / 0.0% | 65.2% | 90.1% | 0.9972 | 0 |
| s1-8-struct | cpp_projects | 458 | 100.0% | 16.2% / 0.0% | 6.8% / 0.0% | 54.6% | 86.2% | 0.9782 | 0 |
| bch-file | codenet_python_generated | 999 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-file | codenet_c_generated | 999 | 100.0% | 99.9% | N/A | 99.9% | 99.9% | N/A | 0 |
| bch-file | codenet_cpp_generated | 999 | 100.0% | 99.7% | N/A | 99.7% | 99.8% | N/A | 0 |
| bch-file | codenet_javascript_generated | 999 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-file | python_projects | 498 | 99.6% | 99.8% | N/A | 99.8% | 99.9% | N/A | 0 |
| bch-file | c_projects | 437 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-file | cpp_projects | 458 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-node | codenet_python_generated | 999 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-node | codenet_c_generated | 999 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-node | codenet_cpp_generated | 999 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-node | codenet_javascript_generated | 999 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-node | python_projects | 497 | 99.4% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-node | c_projects | 437 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |
| bch-node | cpp_projects | 458 | 100.0% | 100.0% | N/A | 100.0% | 100.0% | N/A | 0 |

TPR by capacity (votes) bin, first decision:

| variant | group | votes <10 | votes 10-30 | votes 30-100 | votes >=100 |
|---|---|---|---|---|---|
| s2-4-tok | codenet_python_generated | N/A (0) | 100.0% (6) | 100.0% (832) | 100.0% (161) |
| s2-4-tok | codenet_c_generated | N/A (0) | 100.0% (1) | 100.0% (244) | 100.0% (754) |
| s2-4-tok | codenet_cpp_generated | N/A (0) | 100.0% (6) | 100.0% (833) | 100.0% (160) |
| s2-4-tok | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (192) | 100.0% (807) |
| s2-4-tok | python_projects | 0.0% (19) | 99.5% (212) | 100.0% (258) | 100.0% (11) |
| s2-4-tok | c_projects | 0.0% (1) | 100.0% (163) | 100.0% (273) | N/A (0) |
| s2-4-tok | cpp_projects | 1.0% (99) | 73.0% (344) | 100.0% (15) | N/A (0) |
| s1-4-tok | codenet_python_generated | N/A (0) | 100.0% (6) | 100.0% (832) | 100.0% (161) |
| s1-4-tok | codenet_c_generated | N/A (0) | 100.0% (1) | 100.0% (244) | 100.0% (754) |
| s1-4-tok | codenet_cpp_generated | N/A (0) | 66.7% (6) | 97.6% (833) | 100.0% (160) |
| s1-4-tok | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (192) | 100.0% (807) |
| s1-4-tok | python_projects | 0.0% (19) | 54.7% (212) | 99.6% (258) | 100.0% (11) |
| s1-4-tok | c_projects | 0.0% (1) | 67.5% (163) | 99.6% (273) | N/A (0) |
| s1-4-tok | cpp_projects | 0.0% (99) | 26.2% (344) | 100.0% (15) | N/A (0) |
| s2-4-struct | codenet_python_generated | N/A (0) | 100.0% (53) | 100.0% (945) | 100.0% (1) |
| s2-4-struct | codenet_c_generated | N/A (0) | 100.0% (143) | 100.0% (856) | N/A (0) |
| s2-4-struct | codenet_cpp_generated | N/A (0) | 100.0% (108) | 100.0% (891) | N/A (0) |
| s2-4-struct | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (891) | 100.0% (108) |
| s2-4-struct | python_projects | 0.0% (30) | 99.6% (238) | 100.0% (229) | 100.0% (3) |
| s2-4-struct | c_projects | 0.0% (17) | 100.0% (407) | 100.0% (13) | N/A (0) |
| s2-4-struct | cpp_projects | 0.0% (93) | 100.0% (363) | 100.0% (2) | N/A (0) |
| s1-4-struct | codenet_python_generated | N/A (0) | 81.1% (53) | 99.8% (945) | 100.0% (1) |
| s1-4-struct | codenet_c_generated | N/A (0) | 81.1% (143) | 100.0% (856) | N/A (0) |
| s1-4-struct | codenet_cpp_generated | N/A (0) | 92.6% (108) | 100.0% (891) | N/A (0) |
| s1-4-struct | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (891) | 100.0% (108) |
| s1-4-struct | python_projects | 0.0% (30) | 47.1% (238) | 100.0% (229) | 100.0% (3) |
| s1-4-struct | c_projects | 0.0% (17) | 34.6% (407) | 100.0% (13) | N/A (0) |
| s1-4-struct | cpp_projects | 0.0% (93) | 19.8% (363) | 100.0% (2) | N/A (0) |
| s2-8-tok | codenet_python_generated | N/A (0) | 100.0% (6) | 100.0% (832) | 100.0% (161) |
| s2-8-tok | codenet_c_generated | N/A (0) | 100.0% (1) | 100.0% (244) | 100.0% (754) |
| s2-8-tok | codenet_cpp_generated | N/A (0) | 100.0% (6) | 100.0% (833) | 100.0% (160) |
| s2-8-tok | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (192) | 100.0% (807) |
| s2-8-tok | python_projects | 0.0% (19) | 99.5% (212) | 100.0% (258) | 100.0% (11) |
| s2-8-tok | c_projects | 0.0% (1) | 100.0% (163) | 100.0% (273) | N/A (0) |
| s2-8-tok | cpp_projects | 4.0% (99) | 69.8% (344) | 100.0% (15) | N/A (0) |
| s1-8-tok | codenet_python_generated | N/A (0) | 100.0% (6) | 100.0% (832) | 100.0% (161) |
| s1-8-tok | codenet_c_generated | N/A (0) | 100.0% (1) | 100.0% (244) | 100.0% (754) |
| s1-8-tok | codenet_cpp_generated | N/A (0) | 83.3% (6) | 97.8% (833) | 100.0% (160) |
| s1-8-tok | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (192) | 100.0% (807) |
| s1-8-tok | python_projects | 0.0% (19) | 54.2% (212) | 99.6% (258) | 100.0% (11) |
| s1-8-tok | c_projects | 0.0% (1) | 68.7% (163) | 99.3% (273) | N/A (0) |
| s1-8-tok | cpp_projects | 0.0% (99) | 22.4% (344) | 100.0% (15) | N/A (0) |
| s2-8-struct | codenet_python_generated | N/A (0) | 100.0% (53) | 100.0% (945) | 100.0% (1) |
| s2-8-struct | codenet_c_generated | N/A (0) | 100.0% (143) | 100.0% (856) | N/A (0) |
| s2-8-struct | codenet_cpp_generated | N/A (0) | 100.0% (108) | 100.0% (891) | N/A (0) |
| s2-8-struct | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (891) | 100.0% (108) |
| s2-8-struct | python_projects | 0.0% (30) | 99.6% (238) | 100.0% (229) | 100.0% (3) |
| s2-8-struct | c_projects | 0.0% (17) | 100.0% (407) | 100.0% (13) | N/A (0) |
| s2-8-struct | cpp_projects | 0.0% (93) | 100.0% (363) | 100.0% (2) | N/A (0) |
| s1-8-struct | codenet_python_generated | N/A (0) | 81.1% (53) | 99.8% (945) | 100.0% (1) |
| s1-8-struct | codenet_c_generated | N/A (0) | 80.4% (143) | 100.0% (856) | N/A (0) |
| s1-8-struct | codenet_cpp_generated | N/A (0) | 92.6% (108) | 100.0% (891) | N/A (0) |
| s1-8-struct | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (891) | 100.0% (108) |
| s1-8-struct | python_projects | 0.0% (30) | 47.9% (238) | 99.6% (229) | 100.0% (3) |
| s1-8-struct | c_projects | 0.0% (17) | 34.9% (407) | 100.0% (13) | N/A (0) |
| s1-8-struct | cpp_projects | 0.0% (93) | 19.8% (363) | 100.0% (2) | N/A (0) |
| bch-file | codenet_python_generated | N/A (0) | 100.0% (999) | N/A (0) | N/A (0) |
| bch-file | codenet_c_generated | N/A (0) | 99.9% (999) | N/A (0) | N/A (0) |
| bch-file | codenet_cpp_generated | 0.0% (1) | 99.8% (998) | N/A (0) | N/A (0) |
| bch-file | codenet_javascript_generated | N/A (0) | 100.0% (999) | N/A (0) | N/A (0) |
| bch-file | python_projects | 100.0% (9) | 100.0% (198) | 99.7% (288) | 100.0% (3) |
| bch-file | c_projects | N/A (0) | 100.0% (103) | 100.0% (334) | N/A (0) |
| bch-file | cpp_projects | 100.0% (15) | 100.0% (227) | 100.0% (216) | N/A (0) |
| bch-node | codenet_python_generated | N/A (0) | 100.0% (1) | 100.0% (652) | 100.0% (346) |
| bch-node | codenet_c_generated | N/A (0) | N/A (0) | 100.0% (162) | 100.0% (837) |
| bch-node | codenet_cpp_generated | N/A (0) | N/A (0) | 100.0% (391) | 100.0% (608) |
| bch-node | codenet_javascript_generated | N/A (0) | N/A (0) | 100.0% (60) | 100.0% (939) |
| bch-node | python_projects | 100.0% (9) | 100.0% (185) | 100.0% (285) | 100.0% (18) |
| bch-node | c_projects | 100.0% (1) | 100.0% (133) | 100.0% (303) | N/A (0) |
| bch-node | cpp_projects | 100.0% (9) | 100.0% (213) | 100.0% (236) | N/A (0) |

## 5. Null hypothesis (unmarked code)

`known m`: one random message per unit (the unit's own), rate of units accepted; `all m`: share of (unit, message) pairs accepted over every message of the sweep; `unit any`: units that accept at least one message; `busiest`: the message accepted for most units. A calibrated robust scheme has known-m and all-m rates at or below alpha. The BCH baselines have no alpha: their `known m` is the legacy false-match rate of one message and `busiest` shows the message the code decodes to most often.

| variant | null | group | read | votes med | FPR known m | 95% upper bound | all m (pair) | unit any | busiest message | p_all <= alpha (info) | detector rule errors |
|---|---|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | hand-written | codenet_python_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.25e-05 / 0.00e+00 | 0.1% / 0.0% | 1011 0.1% / - | 0.0% / 0.0% | 0 |
| s2-4-tok | hand-written | codenet_c_human | 1000 | 10.0 | 0.0% / 0.0% | 0.4% / 0.4% | 3.13e-04 / 0.00e+00 | 0.5% / 0.0% | 1101 0.2% / - | 0.0% / 0.0% | 98 |
| s2-4-tok | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.25e-05 / 0.00e+00 | 0.1% / 0.0% | 0101 0.1% / - | 0.0% / 0.0% | 72 |
| s2-4-tok | hand-written | codenet_javascript_human | 511 | 13.0 | 0.0% / 0.0% | 0.7% / 0.7% | 4.89e-04 / 0.00e+00 | 0.8% / 0.0% | 0011 0.2% / - | 0.0% / 0.0% | 0 |
| s2-4-tok | hand-written | js_repos | 14 | 881.5 | 0.0% / 0.0% | 21.5% / 21.5% | 4.46e-03 / 0.00e+00 | 7.1% / 0.0% | 1100 7.1% / - | 0.0% / 0.0% | 0 |
| s2-4-tok | generated, unmarked | codenet_python_generated | 999 | 75.0 | 0.1% / 0.0% | 0.6% / 0.4% | 1.00e-03 / 0.00e+00 | 1.6% / 0.0% | 1100 0.3% / - | 0.1% / 0.0% | 0 |
| s2-4-tok | generated, unmarked | codenet_c_generated | 999 | 126.0 | 0.2% / 0.0% | 0.7% / 0.4% | 9.38e-04 / 0.00e+00 | 1.5% / 0.0% | 1111 0.3% / - | 0.2% / 0.0% | 396 |
| s2-4-tok | generated, unmarked | codenet_cpp_generated | 999 | 76.0 | 0.0% / 0.0% | 0.4% / 0.4% | 8.76e-04 / 0.00e+00 | 1.4% / 0.0% | 1010 0.2% / - | 0.0% / 0.0% | 475 |
| s2-4-tok | generated, unmarked | codenet_javascript_generated | 999 | 128.0 | 0.0% / 0.0% | 0.4% / 0.4% | 4.38e-04 / 0.00e+00 | 0.7% / 0.0% | 0110 0.3% / - | 0.0% / 0.0% | 0 |
| s2-4-tok | generated, unmarked | python_projects | 500 | 31.0 | 0.0% / 0.0% | 0.8% / 0.8% | 7.50e-04 / 0.00e+00 | 1.2% / 0.0% | 1000 0.4% / - | 0.0% / 0.0% | 0 |
| s2-4-tok | generated, unmarked | c_projects | 437 | 33.0 | 0.0% / 0.0% | 0.9% / 0.9% | 8.58e-04 / 0.00e+00 | 1.4% / 0.0% | 0111 0.2% / - | 0.0% / 0.0% | 2 |
| s2-4-tok | generated, unmarked | cpp_projects | 458 | 15.0 | 0.2% / 0.0% | 1.2% / 0.8% | 5.46e-04 / 0.00e+00 | 0.9% / 0.0% | 1100 0.4% / - | 0.2% / 0.0% | 0 |
| s1-4-tok | hand-written | codenet_python_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s1-4-tok | hand-written | codenet_c_human | 1000 | 10.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.25e-05 / 0.00e+00 | 0.1% / 0.0% | 0000 0.1% / - | 0.0% / 0.0% | 98 |
| s1-4-tok | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.1% / 0.0% | 72 |
| s1-4-tok | hand-written | codenet_javascript_human | 511 | 13.0 | 0.0% / 0.0% | 0.7% / 0.7% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s1-4-tok | hand-written | js_repos | 14 | 881.5 | 0.0% / 0.0% | 21.5% / 21.5% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s1-4-tok | generated, unmarked | codenet_python_generated | 999 | 75.0 | 0.0% / 0.0% | 0.4% / 0.4% | 5.63e-04 / 0.00e+00 | 0.9% / 0.0% | 0101 0.2% / - | 0.0% / 0.0% | 0 |
| s1-4-tok | generated, unmarked | codenet_c_generated | 999 | 126.0 | 0.0% / 0.0% | 0.4% / 0.4% | 3.75e-04 / 0.00e+00 | 0.6% / 0.0% | 1011 0.2% / - | 0.0% / 0.0% | 396 |
| s1-4-tok | generated, unmarked | codenet_cpp_generated | 999 | 76.0 | 0.2% / 0.0% | 0.7% / 0.4% | 5.01e-04 / 0.00e+00 | 0.8% / 0.0% | 1011 0.2% / - | 0.3% / 0.0% | 475 |
| s1-4-tok | generated, unmarked | codenet_javascript_generated | 999 | 128.0 | 0.1% / 0.0% | 0.6% / 0.4% | 4.38e-04 / 0.00e+00 | 0.7% / 0.0% | 0011 0.1% / - | 0.1% / 0.0% | 0 |
| s1-4-tok | generated, unmarked | python_projects | 500 | 31.0 | 0.2% / 0.0% | 1.1% / 0.8% | 3.75e-04 / 0.00e+00 | 0.6% / 0.0% | 1001 0.2% / - | 0.0% / 0.0% | 0 |
| s1-4-tok | generated, unmarked | c_projects | 437 | 33.0 | 0.0% / 0.0% | 0.9% / 0.9% | 7.15e-04 / 0.00e+00 | 1.1% / 0.0% | 1111 0.5% / - | 0.0% / 0.0% | 2 |
| s1-4-tok | generated, unmarked | cpp_projects | 458 | 15.0 | 0.0% / 0.0% | 0.8% / 0.8% | 2.73e-04 / 0.00e+00 | 0.4% / 0.0% | 1011 0.2% / - | 0.0% / 0.0% | 0 |
| s2-4-struct | hand-written | codenet_python_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.25e-05 / 0.00e+00 | 0.1% / 0.0% | 1110 0.1% / - | 0.0% / 0.0% | 0 |
| s2-4-struct | hand-written | codenet_c_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.25e-05 / 0.00e+00 | 0.1% / 0.0% | 0101 0.1% / - | 0.0% / 0.0% | 98 |
| s2-4-struct | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 72 |
| s2-4-struct | hand-written | codenet_javascript_human | 511 | 11.0 | 0.0% / 0.0% | 0.7% / 0.7% | 1.22e-04 / 0.00e+00 | 0.2% / 0.0% | 0011 0.2% / - | 0.0% / 0.0% | 0 |
| s2-4-struct | hand-written | js_repos | 14 | 468.0 | 0.0% / 0.0% | 21.5% / 21.5% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s2-4-struct | generated, unmarked | codenet_python_generated | 999 | 45.0 | 0.0% / 0.0% | 0.4% / 0.4% | 2.50e-04 / 0.00e+00 | 0.4% / 0.0% | 0111 0.1% / - | 0.0% / 0.0% | 0 |
| s2-4-struct | generated, unmarked | codenet_c_generated | 999 | 39.0 | 0.0% / 0.0% | 0.4% / 0.4% | 2.50e-04 / 0.00e+00 | 0.4% / 0.0% | 0001 0.1% / - | 0.0% / 0.0% | 396 |
| s2-4-struct | generated, unmarked | codenet_cpp_generated | 999 | 41.0 | 0.1% / 0.0% | 0.6% / 0.4% | 3.13e-04 / 0.00e+00 | 0.5% / 0.0% | 0011 0.2% / - | 0.1% / 0.0% | 475 |
| s2-4-struct | generated, unmarked | codenet_javascript_generated | 999 | 74.0 | 0.2% / 0.0% | 0.7% / 0.4% | 5.63e-04 / 0.00e+00 | 0.9% / 0.0% | 0000 0.5% / - | 0.2% / 0.0% | 0 |
| s2-4-struct | generated, unmarked | python_projects | 500 | 28.0 | 0.0% / 0.0% | 0.8% / 0.8% | 1.25e-04 / 0.00e+00 | 0.2% / 0.0% | 1101 0.2% / - | 0.0% / 0.0% | 0 |
| s2-4-struct | generated, unmarked | c_projects | 437 | 17.0 | 0.2% / 0.0% | 1.3% / 0.9% | 5.72e-04 / 0.00e+00 | 0.9% / 0.0% | 1001 0.2% / - | 0.2% / 0.0% | 2 |
| s2-4-struct | generated, unmarked | cpp_projects | 458 | 14.0 | 0.2% / 0.0% | 1.2% / 0.8% | 4.09e-04 / 0.00e+00 | 0.7% / 0.0% | 1101 0.2% / - | 0.2% / 0.0% | 0 |
| s1-4-struct | hand-written | codenet_python_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s1-4-struct | hand-written | codenet_c_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 98 |
| s1-4-struct | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 72 |
| s1-4-struct | hand-written | codenet_javascript_human | 511 | 11.0 | 0.0% / 0.0% | 0.7% / 0.7% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s1-4-struct | hand-written | js_repos | 14 | 468.0 | 0.0% / 0.0% | 21.5% / 21.5% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s1-4-struct | generated, unmarked | codenet_python_generated | 999 | 45.0 | 0.1% / 0.0% | 0.6% / 0.4% | 8.13e-04 / 0.00e+00 | 1.3% / 0.0% | 0000 1.0% / - | 0.0% / 0.0% | 0 |
| s1-4-struct | generated, unmarked | codenet_c_generated | 999 | 39.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.26e-05 / 0.00e+00 | 0.1% / 0.0% | 0111 0.1% / - | 0.0% / 0.0% | 396 |
| s1-4-struct | generated, unmarked | codenet_cpp_generated | 999 | 41.0 | 0.0% / 0.0% | 0.4% / 0.4% | 3.75e-04 / 0.00e+00 | 0.6% / 0.0% | 1100 0.3% / - | 0.1% / 0.0% | 475 |
| s1-4-struct | generated, unmarked | codenet_javascript_generated | 999 | 74.0 | 0.0% / 0.0% | 0.4% / 0.4% | 3.13e-04 / 0.00e+00 | 0.5% / 0.0% | 0101 0.2% / - | 0.0% / 0.0% | 0 |
| s1-4-struct | generated, unmarked | python_projects | 500 | 28.0 | 0.0% / 0.0% | 0.8% / 0.8% | 1.25e-04 / 0.00e+00 | 0.2% / 0.0% | 1100 0.2% / - | 0.0% / 0.0% | 0 |
| s1-4-struct | generated, unmarked | c_projects | 437 | 17.0 | 0.0% / 0.0% | 0.9% / 0.9% | 1.43e-04 / 0.00e+00 | 0.2% / 0.0% | 0111 0.2% / - | 0.0% / 0.0% | 2 |
| s1-4-struct | generated, unmarked | cpp_projects | 458 | 14.0 | 0.0% / 0.0% | 0.8% / 0.8% | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% | - / - | 0.0% / 0.0% | 0 |
| s2-8-tok | hand-written | codenet_python_human | 1000 | 5.0 | 0.1% / 0.0% | 0.6% / 0.4% | 9.38e-05 / 0.00e+00 | 2.3% / 0.0% | 01100010 0.2% / - | 0.1% / 0.0% | 0 |
| s2-8-tok | hand-written | codenet_c_human | 1000 | 10.0 | 0.0% / 0.0% | 0.4% / 0.4% | 2.73e-04 / 0.00e+00 | 6.5% / 0.0% | 01110100 0.3% / - | 0.0% / 0.0% | 98 |
| s2-8-tok | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 7.42e-05 / 0.00e+00 | 1.9% / 0.0% | 01010101 0.2% / - | 0.0% / 0.0% | 72 |
| s2-8-tok | hand-written | codenet_javascript_human | 511 | 13.0 | 0.0% / 0.0% | 0.7% / 0.7% | 3.21e-04 / 0.00e+00 | 7.0% / 0.0% | 01100000 1.2% / - | 0.0% / 0.0% | 0 |
| s2-8-tok | hand-written | js_repos | 14 | 881.5 | 0.0% / 0.0% | 21.5% / 21.5% | 2.51e-03 / 0.00e+00 | 42.9% / 0.0% | 10111110 7.1% / - | 0.0% / 0.0% | 0 |
| s2-8-tok | generated, unmarked | codenet_python_generated | 999 | 75.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.02e-04 / 7.82e-06 | 14.3% / 0.2% | 11000100 0.5% / 10111111 0.1% | 0.0% / 0.0% | 0 |
| s2-8-tok | generated, unmarked | codenet_c_generated | 999 | 126.0 | 0.2% / 0.0% | 0.7% / 0.4% | 7.43e-04 / 0.00e+00 | 16.9% / 0.0% | 11000011 0.4% / - | 0.2% / 0.0% | 396 |
| s2-8-tok | generated, unmarked | codenet_cpp_generated | 999 | 76.0 | 0.1% / 0.0% | 0.6% / 0.4% | 6.73e-04 / 0.00e+00 | 15.8% / 0.0% | 00100000 0.6% / - | 0.1% / 0.0% | 475 |
| s2-8-tok | generated, unmarked | codenet_javascript_generated | 999 | 128.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.92e-04 / 3.91e-06 | 15.5% / 0.1% | 10000111 0.4% / 00010001 0.1% | 0.0% / 0.0% | 0 |
| s2-8-tok | generated, unmarked | python_projects | 500 | 31.0 | 0.0% / 0.0% | 0.8% / 0.8% | 4.06e-04 / 0.00e+00 | 9.8% / 0.0% | 00111011 0.4% / - | 0.0% / 0.0% | 0 |
| s2-8-tok | generated, unmarked | c_projects | 437 | 33.0 | 0.0% / 0.0% | 0.9% / 0.9% | 6.17e-04 / 8.94e-06 | 14.4% / 0.2% | 11100011 0.5% / 10101100 0.2% | 0.0% / 0.0% | 2 |
| s2-8-tok | generated, unmarked | cpp_projects | 458 | 15.0 | 0.0% / 0.0% | 0.8% / 0.8% | 3.33e-04 / 0.00e+00 | 8.3% / 0.0% | 10001000 0.4% / - | 0.0% / 0.0% | 0 |
| s1-8-tok | hand-written | codenet_python_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 2.73e-05 / 0.00e+00 | 0.7% / 0.0% | 00110000 0.1% / - | 0.0% / 0.0% | 0 |
| s1-8-tok | hand-written | codenet_c_human | 1000 | 10.0 | 0.0% / 0.0% | 0.4% / 0.4% | 7.03e-05 / 0.00e+00 | 1.8% / 0.0% | 00000110 0.2% / - | 0.0% / 0.0% | 98 |
| s1-8-tok | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 3.52e-05 / 0.00e+00 | 0.9% / 0.0% | 10101011 0.1% / - | 0.0% / 0.0% | 72 |
| s1-8-tok | hand-written | codenet_javascript_human | 511 | 13.0 | 0.0% / 0.0% | 0.7% / 0.7% | 1.38e-04 / 0.00e+00 | 3.3% / 0.0% | 10010001 0.4% / - | 0.0% / 0.0% | 0 |
| s1-8-tok | hand-written | js_repos | 14 | 881.5 | 0.0% / 0.0% | 21.5% / 21.5% | 1.12e-03 / 0.00e+00 | 28.6% / 0.0% | 00111010 7.1% / - | 0.0% / 0.0% | 0 |
| s1-8-tok | generated, unmarked | codenet_python_generated | 999 | 75.0 | 0.0% / 0.0% | 0.4% / 0.4% | 5.94e-04 / 0.00e+00 | 13.7% / 0.0% | 00101011 0.5% / - | 0.0% / 0.0% | 0 |
| s1-8-tok | generated, unmarked | codenet_c_generated | 999 | 126.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.10e-04 / 0.00e+00 | 14.4% / 0.0% | 10101111 0.6% / - | 0.0% / 0.0% | 396 |
| s1-8-tok | generated, unmarked | codenet_cpp_generated | 999 | 76.0 | 0.1% / 0.0% | 0.6% / 0.4% | 5.51e-04 / 0.00e+00 | 13.0% / 0.0% | 00100011 0.5% / - | 0.1% / 0.0% | 475 |
| s1-8-tok | generated, unmarked | codenet_javascript_generated | 999 | 128.0 | 0.1% / 0.0% | 0.6% / 0.4% | 6.57e-04 / 0.00e+00 | 15.8% / 0.0% | 10110000 0.7% / - | 0.1% / 0.0% | 0 |
| s1-8-tok | generated, unmarked | python_projects | 500 | 31.0 | 0.0% / 0.0% | 0.8% / 0.8% | 5.23e-04 / 0.00e+00 | 12.2% / 0.0% | 10001000 0.6% / - | 0.2% / 0.0% | 0 |
| s1-8-tok | generated, unmarked | c_projects | 437 | 33.0 | 0.0% / 0.0% | 0.9% / 0.9% | 4.56e-04 / 0.00e+00 | 10.1% / 0.0% | 00100010 0.5% / - | 0.0% / 0.0% | 2 |
| s1-8-tok | generated, unmarked | cpp_projects | 458 | 15.0 | 0.0% / 0.0% | 0.8% / 0.8% | 2.22e-04 / 0.00e+00 | 5.5% / 0.0% | 10111100 0.2% / - | 0.0% / 0.0% | 0 |
| s2-8-struct | hand-written | codenet_python_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 8.98e-05 / 0.00e+00 | 2.1% / 0.0% | 01000010 0.2% / - | 0.0% / 0.0% | 0 |
| s2-8-struct | hand-written | codenet_c_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 1.56e-04 / 0.00e+00 | 3.6% / 0.0% | 01001100 0.5% / - | 0.0% / 0.0% | 98 |
| s2-8-struct | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 1.09e-04 / 0.00e+00 | 2.6% / 0.0% | 10010001 0.2% / - | 0.0% / 0.0% | 72 |
| s2-8-struct | hand-written | codenet_javascript_human | 511 | 11.0 | 0.0% / 0.0% | 0.7% / 0.7% | 4.43e-04 / 0.00e+00 | 10.4% / 0.0% | 01110011 2.2% / - | 0.0% / 0.0% | 0 |
| s2-8-struct | hand-written | js_repos | 14 | 468.0 | 0.0% / 0.0% | 21.5% / 21.5% | 2.79e-04 / 0.00e+00 | 7.1% / 0.0% | 10111000 7.1% / - | 0.0% / 0.0% | 0 |
| s2-8-struct | generated, unmarked | codenet_python_generated | 999 | 45.0 | 0.0% / 0.0% | 0.4% / 0.4% | 6.45e-04 / 0.00e+00 | 15.6% / 0.0% | 01110001 1.4% / - | 0.0% / 0.0% | 0 |
| s2-8-struct | generated, unmarked | codenet_c_generated | 999 | 39.0 | 0.0% / 0.0% | 0.4% / 0.4% | 4.03e-04 / 0.00e+00 | 10.1% / 0.0% | 11111111 1.5% / - | 0.0% / 0.0% | 396 |
| s2-8-struct | generated, unmarked | codenet_cpp_generated | 999 | 41.0 | 0.0% / 0.0% | 0.4% / 0.4% | 5.55e-04 / 0.00e+00 | 13.0% / 0.0% | 01101100 0.6% / - | 0.0% / 0.0% | 475 |
| s2-8-struct | generated, unmarked | codenet_javascript_generated | 999 | 74.0 | 0.1% / 0.0% | 0.6% / 0.4% | 6.80e-04 / 0.00e+00 | 15.6% / 0.0% | 10010000 0.9% / - | 0.1% / 0.0% | 0 |
| s2-8-struct | generated, unmarked | python_projects | 500 | 28.0 | 0.0% / 0.0% | 0.8% / 0.8% | 4.92e-04 / 0.00e+00 | 11.8% / 0.0% | 10101010 0.6% / - | 0.0% / 0.0% | 0 |
| s2-8-struct | generated, unmarked | c_projects | 437 | 17.0 | 0.0% / 0.0% | 0.9% / 0.9% | 4.38e-04 / 0.00e+00 | 11.0% / 0.0% | 01001100 0.9% / - | 0.0% / 0.0% | 2 |
| s2-8-struct | generated, unmarked | cpp_projects | 458 | 14.0 | 0.0% / 0.0% | 0.8% / 0.8% | 4.35e-04 / 0.00e+00 | 10.0% / 0.0% | 11111000 0.9% / - | 0.0% / 0.0% | 0 |
| s1-8-struct | hand-written | codenet_python_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 1.95e-05 / 0.00e+00 | 0.4% / 0.0% | 11111110 0.1% / - | 0.0% / 0.0% | 0 |
| s1-8-struct | hand-written | codenet_c_human | 1000 | 5.0 | 0.0% / 0.0% | 0.4% / 0.4% | 5.47e-05 / 0.00e+00 | 1.3% / 0.0% | 00111100 0.2% / - | 0.1% / 0.0% | 98 |
| s1-8-struct | hand-written | codenet_cpp_human | 1000 | 4.0 | 0.0% / 0.0% | 0.4% / 0.4% | 3.91e-06 / 0.00e+00 | 0.1% / 0.0% | 01011100 0.1% / - | 0.0% / 0.0% | 72 |
| s1-8-struct | hand-written | codenet_javascript_human | 511 | 11.0 | 0.2% / 0.0% | 1.1% / 0.7% | 9.17e-05 / 0.00e+00 | 2.2% / 0.0% | 11001110 0.4% / - | 0.2% / 0.0% | 0 |
| s1-8-struct | hand-written | js_repos | 14 | 468.0 | 0.0% / 0.0% | 21.5% / 21.5% | 2.79e-04 / 0.00e+00 | 7.1% / 0.0% | 11011100 7.1% / - | 0.0% / 0.0% | 0 |
| s1-8-struct | generated, unmarked | codenet_python_generated | 999 | 45.0 | 0.0% / 0.0% | 0.4% / 0.4% | 4.03e-04 / 0.00e+00 | 9.9% / 0.0% | 10001011 0.9% / - | 0.0% / 0.0% | 0 |
| s1-8-struct | generated, unmarked | codenet_c_generated | 999 | 39.0 | 0.0% / 0.0% | 0.4% / 0.4% | 3.99e-04 / 0.00e+00 | 9.8% / 0.0% | 11110011 0.8% / - | 0.1% / 0.0% | 396 |
| s1-8-struct | generated, unmarked | codenet_cpp_generated | 999 | 41.0 | 0.1% / 0.0% | 0.6% / 0.4% | 3.32e-04 / 0.00e+00 | 8.0% / 0.0% | 10110001 0.7% / - | 0.0% / 0.0% | 475 |
| s1-8-struct | generated, unmarked | codenet_javascript_generated | 999 | 74.0 | 0.0% / 0.0% | 0.4% / 0.4% | 5.98e-04 / 0.00e+00 | 14.5% / 0.0% | 11100111 1.1% / - | 0.0% / 0.0% | 0 |
| s1-8-struct | generated, unmarked | python_projects | 500 | 28.0 | 0.0% / 0.0% | 0.8% / 0.8% | 4.14e-04 / 0.00e+00 | 9.4% / 0.0% | 00100100 0.6% / - | 0.0% / 0.0% | 0 |
| s1-8-struct | generated, unmarked | c_projects | 437 | 17.0 | 0.0% / 0.0% | 0.9% / 0.9% | 1.79e-04 / 0.00e+00 | 4.6% / 0.0% | 00111001 0.5% / - | 0.0% / 0.0% | 2 |
| s1-8-struct | generated, unmarked | cpp_projects | 458 | 14.0 | 0.0% / 0.0% | 0.8% / 0.8% | 1.19e-04 / 0.00e+00 | 3.1% / 0.0% | 00010001 0.2% / - | 0.0% / 0.0% | 0 |
| bch-file | hand-written | codenet_python_human | 1000 | 7.0 | 6.2% | 7.9% | 6.25e-02 | 100.0% | 0001 15.6% | N/A | 0 |
| bch-file | hand-written | codenet_c_human | 1000 | 9.0 | 6.3% | 8.0% | 6.25e-02 | 100.0% | 0011 16.1% | N/A | 0 |
| bch-file | hand-written | codenet_cpp_human | 1000 | 7.0 | 5.5% | 7.1% | 6.25e-02 | 100.0% | 0000 9.8% | N/A | 0 |
| bch-file | hand-written | codenet_javascript_human | 511 | 6.0 | 7.2% | 9.8% | 6.25e-02 | 100.0% | 0000 94.3% | N/A | 0 |
| bch-file | hand-written | js_repos | 14 | 61.0 | 7.1% | 31.5% | 6.25e-02 | 100.0% | 0000 64.3% | N/A | 0 |
| bch-file | generated, unmarked | codenet_python_generated | 999 | 15.0 | 6.5% | 8.2% | 6.25e-02 | 100.0% | 0100 42.8% | N/A | 0 |
| bch-file | generated, unmarked | codenet_c_generated | 999 | 18.0 | 5.2% | 6.8% | 6.25e-02 | 100.0% | 0011 28.8% | N/A | 0 |
| bch-file | generated, unmarked | codenet_cpp_generated | 999 | 17.0 | 6.4% | 8.1% | 6.25e-02 | 100.0% | 1100 31.4% | N/A | 0 |
| bch-file | generated, unmarked | codenet_javascript_generated | 999 | 15.0 | 6.2% | 7.9% | 6.25e-02 | 100.0% | 0000 58.4% | N/A | 0 |
| bch-file | generated, unmarked | python_projects | 498 | 33.0 | 5.2% | 7.5% | 6.25e-02 | 100.0% | 0111 25.5% | N/A | 0 |
| bch-file | generated, unmarked | c_projects | 437 | 39.0 | 7.3% | 10.2% | 6.25e-02 | 100.0% | 0000 20.8% | N/A | 0 |
| bch-file | generated, unmarked | cpp_projects | 458 | 28.0 | 4.6% | 6.9% | 6.25e-02 | 100.0% | 0000 37.8% | N/A | 0 |
| bch-node | hand-written | codenet_python_human | 1000 | 8.0 | 6.9% | 8.6% | 6.25e-02 | 100.0% | 0000 14.9% | N/A | 0 |
| bch-node | hand-written | codenet_c_human | 1000 | 13.0 | 7.1% | 8.9% | 6.25e-02 | 100.0% | 0011 16.3% | N/A | 0 |
| bch-node | hand-written | codenet_cpp_human | 1000 | 10.0 | 6.3% | 8.0% | 6.25e-02 | 100.0% | 0000 16.2% | N/A | 0 |
| bch-node | hand-written | codenet_javascript_human | 511 | 13.0 | 7.4% | 10.0% | 6.25e-02 | 100.0% | 0000 96.1% | N/A | 0 |
| bch-node | hand-written | js_repos | 14 | 1276.5 | 14.3% | 39.9% | 6.25e-02 | 100.0% | 0000 71.4% | N/A | 0 |
| bch-node | generated, unmarked | codenet_python_generated | 999 | 90.0 | 7.6% | 9.4% | 6.25e-02 | 100.0% | 0101 37.6% | N/A | 0 |
| bch-node | generated, unmarked | codenet_c_generated | 999 | 143.0 | 5.7% | 7.3% | 6.25e-02 | 100.0% | 0010 31.8% | N/A | 0 |
| bch-node | generated, unmarked | codenet_cpp_generated | 999 | 108.0 | 5.4% | 7.0% | 6.25e-02 | 100.0% | 1100 33.9% | N/A | 0 |
| bch-node | generated, unmarked | codenet_javascript_generated | 999 | 166.0 | 5.9% | 7.5% | 6.25e-02 | 100.0% | 0000 60.5% | N/A | 0 |
| bch-node | generated, unmarked | python_projects | 497 | 35.0 | 3.6% | 5.7% | 6.25e-02 | 100.0% | 1111 10.9% | N/A | 0 |
| bch-node | generated, unmarked | c_projects | 437 | 36.0 | 8.9% | 12.0% | 6.25e-02 | 100.0% | 0000 36.2% | N/A | 0 |
| bch-node | generated, unmarked | cpp_projects | 458 | 30.0 | 4.8% | 7.2% | 6.25e-02 | 100.0% | 0000 49.3% | N/A | 0 |

Empirical CDF of the p-values against all messages (expected: equal to the threshold):

| variant | null | group | p<=1e-06 | p<=1e-05 | p<=0.0001 | p<=0.001 | p<=0.01 | p<=0.05 | p<=0.1 | p<=0.25 | p<=0.5 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 6.25e-05 | 2.00e-03 | 1.50e-02 | 3.42e-02 | 1.47e-01 | 4.38e-01 |
| s2-4-tok | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.13e-04 | 2.69e-03 | 2.03e-02 | 4.35e-02 | 1.48e-01 | 4.16e-01 |
| s2-4-tok | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 6.25e-05 | 1.56e-03 | 1.18e-02 | 2.96e-02 | 1.27e-01 | 3.93e-01 |
| s2-4-tok | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 4.89e-04 | 3.30e-03 | 2.46e-02 | 5.21e-02 | 1.68e-01 | 4.37e-01 |
| s2-4-tok | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 4.46e-03 | 8.93e-03 | 6.70e-02 | 1.21e-01 | 2.50e-01 | 4.46e-01 |
| s2-4-tok | generated, unmarked | codenet_python_generated | 0.00e+00 | 0.00e+00 | 1.25e-04 | 1.00e-03 | 9.51e-03 | 4.53e-02 | 8.68e-02 | 2.23e-01 | 4.88e-01 |
| s2-4-tok | generated, unmarked | codenet_c_generated | 0.00e+00 | 0.00e+00 | 6.26e-05 | 9.38e-04 | 6.32e-03 | 3.84e-02 | 8.10e-02 | 2.23e-01 | 4.87e-01 |
| s2-4-tok | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 8.76e-04 | 7.44e-03 | 4.37e-02 | 8.86e-02 | 2.34e-01 | 4.98e-01 |
| s2-4-tok | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 0.00e+00 | 6.26e-05 | 4.38e-04 | 7.44e-03 | 4.29e-02 | 8.70e-02 | 2.31e-01 | 4.90e-01 |
| s2-4-tok | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 7.50e-04 | 7.50e-03 | 3.64e-02 | 7.42e-02 | 1.92e-01 | 4.75e-01 |
| s2-4-tok | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 1.43e-04 | 8.58e-04 | 7.87e-03 | 3.79e-02 | 7.25e-02 | 2.02e-01 | 4.76e-01 |
| s2-4-tok | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 1.36e-04 | 5.46e-04 | 4.50e-03 | 2.85e-02 | 5.94e-02 | 1.77e-01 | 4.42e-01 |
| s1-4-tok | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 5.00e-04 | 4.69e-03 | 1.34e-02 | 1.09e-01 | 3.64e-01 |
| s1-4-tok | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 6.25e-05 | 6.25e-05 | 1.44e-03 | 1.32e-02 | 2.85e-02 | 1.28e-01 | 3.80e-01 |
| s1-4-tok | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 4.38e-04 | 5.69e-03 | 1.47e-02 | 9.01e-02 | 3.27e-01 |
| s1-4-tok | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 7.34e-04 | 1.13e-02 | 3.33e-02 | 1.24e-01 | 3.79e-01 |
| s1-4-tok | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 4.46e-03 | 4.02e-02 | 8.04e-02 | 2.41e-01 | 4.69e-01 |
| s1-4-tok | generated, unmarked | codenet_python_generated | 0.00e+00 | 0.00e+00 | 1.25e-04 | 5.63e-04 | 6.13e-03 | 3.27e-02 | 6.91e-02 | 1.91e-01 | 4.53e-01 |
| s1-4-tok | generated, unmarked | codenet_c_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.75e-04 | 6.63e-03 | 3.45e-02 | 7.32e-02 | 2.09e-01 | 4.76e-01 |
| s1-4-tok | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 1.25e-04 | 5.01e-04 | 6.07e-03 | 3.56e-02 | 7.44e-02 | 2.03e-01 | 4.65e-01 |
| s1-4-tok | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 0.00e+00 | 6.26e-05 | 4.38e-04 | 5.63e-03 | 3.45e-02 | 7.14e-02 | 1.97e-01 | 4.57e-01 |
| s1-4-tok | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.75e-04 | 4.38e-03 | 3.00e-02 | 5.83e-02 | 1.74e-01 | 4.43e-01 |
| s1-4-tok | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 1.43e-04 | 7.15e-04 | 5.15e-03 | 3.13e-02 | 6.42e-02 | 1.76e-01 | 4.44e-01 |
| s1-4-tok | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 2.73e-04 | 1.36e-03 | 1.54e-02 | 4.30e-02 | 1.44e-01 | 4.27e-01 |
| s2-4-struct | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 6.25e-05 | 5.62e-04 | 9.69e-03 | 2.84e-02 | 1.24e-01 | 3.98e-01 |
| s2-4-struct | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 6.25e-05 | 2.63e-03 | 1.73e-02 | 3.90e-02 | 1.36e-01 | 4.09e-01 |
| s2-4-struct | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 8.12e-04 | 8.87e-03 | 2.64e-02 | 1.10e-01 | 3.55e-01 |
| s2-4-struct | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 1.22e-04 | 8.56e-04 | 1.42e-02 | 3.73e-02 | 1.48e-01 | 4.44e-01 |
| s2-4-struct | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.12e-02 | 7.14e-02 | 2.10e-01 | 5.04e-01 |
| s2-4-struct | generated, unmarked | codenet_python_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 2.50e-04 | 3.00e-03 | 2.13e-02 | 4.85e-02 | 1.54e-01 | 4.03e-01 |
| s2-4-struct | generated, unmarked | codenet_c_generated | 0.00e+00 | 0.00e+00 | 6.26e-05 | 2.50e-04 | 5.07e-03 | 3.31e-02 | 6.91e-02 | 1.91e-01 | 4.44e-01 |
| s2-4-struct | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.13e-04 | 4.63e-03 | 2.95e-02 | 6.46e-02 | 1.84e-01 | 4.50e-01 |
| s2-4-struct | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 0.00e+00 | 6.26e-05 | 5.63e-04 | 6.44e-03 | 3.73e-02 | 7.72e-02 | 2.08e-01 | 4.69e-01 |
| s2-4-struct | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 1.25e-04 | 5.00e-03 | 3.21e-02 | 6.73e-02 | 1.78e-01 | 4.40e-01 |
| s2-4-struct | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 5.72e-04 | 4.15e-03 | 2.83e-02 | 5.72e-02 | 1.71e-01 | 4.35e-01 |
| s2-4-struct | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 4.09e-04 | 3.68e-03 | 2.67e-02 | 5.36e-02 | 1.61e-01 | 4.39e-01 |
| s1-4-struct | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 4.38e-04 | 4.81e-03 | 1.26e-02 | 9.82e-02 | 3.51e-01 |
| s1-4-struct | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 5.00e-04 | 5.56e-03 | 1.80e-02 | 1.13e-01 | 3.68e-01 |
| s1-4-struct | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.75e-04 | 3.69e-03 | 9.75e-03 | 9.01e-02 | 3.31e-01 |
| s1-4-struct | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 6.12e-04 | 1.02e-02 | 3.22e-02 | 1.49e-01 | 4.43e-01 |
| s1-4-struct | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 8.93e-03 | 5.36e-02 | 8.04e-02 | 1.92e-01 | 4.69e-01 |
| s1-4-struct | generated, unmarked | codenet_python_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 8.13e-04 | 7.63e-03 | 3.99e-02 | 7.84e-02 | 2.04e-01 | 4.81e-01 |
| s1-4-struct | generated, unmarked | codenet_c_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 6.26e-05 | 1.69e-03 | 1.81e-02 | 4.32e-02 | 1.39e-01 | 3.95e-01 |
| s1-4-struct | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.75e-04 | 6.01e-03 | 3.21e-02 | 6.84e-02 | 1.84e-01 | 4.50e-01 |
| s1-4-struct | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.13e-04 | 2.75e-03 | 1.88e-02 | 4.44e-02 | 1.51e-01 | 4.06e-01 |
| s1-4-struct | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 1.25e-04 | 6.25e-03 | 3.04e-02 | 6.26e-02 | 1.76e-01 | 4.62e-01 |
| s1-4-struct | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 1.43e-04 | 2.57e-03 | 2.10e-02 | 5.28e-02 | 1.53e-01 | 4.19e-01 |
| s1-4-struct | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 1.50e-03 | 1.31e-02 | 4.01e-02 | 1.41e-01 | 4.06e-01 |
| s2-8-tok | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 3.91e-06 | 9.38e-05 | 1.50e-03 | 1.38e-02 | 3.27e-02 | 1.38e-01 | 4.25e-01 |
| s2-8-tok | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 1.56e-05 | 2.73e-04 | 3.40e-03 | 2.18e-02 | 4.69e-02 | 1.53e-01 | 4.26e-01 |
| s2-8-tok | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 7.42e-05 | 1.43e-03 | 1.08e-02 | 2.74e-02 | 1.24e-01 | 3.85e-01 |
| s2-8-tok | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 2.29e-05 | 3.21e-04 | 3.84e-03 | 2.74e-02 | 5.91e-02 | 1.76e-01 | 4.49e-01 |
| s2-8-tok | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 2.51e-03 | 1.00e-02 | 4.30e-02 | 9.15e-02 | 2.29e-01 | 4.93e-01 |
| s2-8-tok | generated, unmarked | codenet_python_generated | 7.82e-06 | 7.82e-06 | 2.74e-05 | 6.02e-04 | 7.01e-03 | 3.76e-02 | 7.92e-02 | 2.13e-01 | 4.76e-01 |
| s2-8-tok | generated, unmarked | codenet_c_generated | 0.00e+00 | 3.91e-06 | 4.30e-05 | 7.43e-04 | 8.04e-03 | 4.13e-02 | 8.54e-02 | 2.23e-01 | 4.82e-01 |
| s2-8-tok | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 4.30e-05 | 6.73e-04 | 7.20e-03 | 3.99e-02 | 8.23e-02 | 2.17e-01 | 4.80e-01 |
| s2-8-tok | generated, unmarked | codenet_javascript_generated | 3.91e-06 | 3.91e-06 | 6.65e-05 | 6.92e-04 | 8.32e-03 | 4.27e-02 | 8.67e-02 | 2.28e-01 | 4.86e-01 |
| s2-8-tok | generated, unmarked | python_projects | 0.00e+00 | 7.81e-06 | 4.69e-05 | 4.06e-04 | 6.27e-03 | 3.44e-02 | 7.09e-02 | 1.92e-01 | 4.66e-01 |
| s2-8-tok | generated, unmarked | c_projects | 8.94e-06 | 1.79e-05 | 8.94e-05 | 6.17e-04 | 6.28e-03 | 3.62e-02 | 7.09e-02 | 2.00e-01 | 4.65e-01 |
| s2-8-tok | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 8.53e-06 | 3.33e-04 | 4.37e-03 | 2.83e-02 | 6.01e-02 | 1.71e-01 | 4.42e-01 |
| s1-8-tok | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 2.73e-05 | 5.78e-04 | 5.98e-03 | 1.66e-02 | 1.19e-01 | 3.79e-01 |
| s1-8-tok | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 3.91e-06 | 7.03e-05 | 1.63e-03 | 1.21e-02 | 2.95e-02 | 1.28e-01 | 3.74e-01 |
| s1-8-tok | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.52e-05 | 6.17e-04 | 5.11e-03 | 1.36e-02 | 9.05e-02 | 3.25e-01 |
| s1-8-tok | hand-written | codenet_javascript_human | 0.00e+00 | 7.64e-06 | 1.53e-05 | 1.38e-04 | 2.51e-03 | 1.67e-02 | 4.09e-02 | 1.47e-01 | 4.13e-01 |
| s1-8-tok | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 2.79e-04 | 1.12e-03 | 8.93e-03 | 4.83e-02 | 9.21e-02 | 2.38e-01 | 4.98e-01 |
| s1-8-tok | generated, unmarked | codenet_python_generated | 0.00e+00 | 3.91e-06 | 5.87e-05 | 5.94e-04 | 6.50e-03 | 3.64e-02 | 7.47e-02 | 2.05e-01 | 4.68e-01 |
| s1-8-tok | generated, unmarked | codenet_c_generated | 0.00e+00 | 3.91e-06 | 4.69e-05 | 6.10e-04 | 7.10e-03 | 3.73e-02 | 7.82e-02 | 2.12e-01 | 4.75e-01 |
| s1-8-tok | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 3.91e-05 | 5.51e-04 | 6.38e-03 | 3.60e-02 | 7.31e-02 | 2.03e-01 | 4.66e-01 |
| s1-8-tok | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 3.91e-06 | 4.69e-05 | 6.57e-04 | 6.75e-03 | 3.77e-02 | 7.73e-02 | 2.08e-01 | 4.74e-01 |
| s1-8-tok | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 4.69e-05 | 5.23e-04 | 4.52e-03 | 2.92e-02 | 6.01e-02 | 1.75e-01 | 4.47e-01 |
| s1-8-tok | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 2.68e-05 | 4.56e-04 | 4.26e-03 | 2.98e-02 | 6.33e-02 | 1.76e-01 | 4.44e-01 |
| s1-8-tok | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 1.71e-05 | 2.22e-04 | 2.54e-03 | 1.80e-02 | 4.44e-02 | 1.45e-01 | 4.25e-01 |
| s2-8-struct | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 8.98e-05 | 1.36e-03 | 1.14e-02 | 3.08e-02 | 1.33e-01 | 4.12e-01 |
| s2-8-struct | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 7.81e-06 | 1.56e-04 | 1.96e-03 | 1.46e-02 | 3.51e-02 | 1.29e-01 | 4.08e-01 |
| s2-8-struct | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 3.91e-06 | 1.09e-04 | 1.02e-03 | 1.00e-02 | 2.78e-02 | 1.19e-01 | 3.78e-01 |
| s2-8-struct | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 1.53e-05 | 4.43e-04 | 5.01e-03 | 2.95e-02 | 6.14e-02 | 1.74e-01 | 4.49e-01 |
| s2-8-struct | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 2.79e-04 | 1.03e-02 | 4.38e-02 | 8.40e-02 | 2.32e-01 | 5.03e-01 |
| s2-8-struct | generated, unmarked | codenet_python_generated | 0.00e+00 | 7.82e-06 | 7.82e-05 | 6.45e-04 | 7.27e-03 | 3.93e-02 | 7.83e-02 | 2.07e-01 | 4.67e-01 |
| s2-8-struct | generated, unmarked | codenet_c_generated | 0.00e+00 | 3.91e-06 | 4.30e-05 | 4.03e-04 | 5.78e-03 | 3.48e-02 | 7.23e-02 | 2.00e-01 | 4.67e-01 |
| s2-8-struct | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 3.91e-06 | 3.52e-05 | 5.55e-04 | 6.49e-03 | 3.80e-02 | 7.80e-02 | 2.09e-01 | 4.78e-01 |
| s2-8-struct | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 0.00e+00 | 5.47e-05 | 6.80e-04 | 7.91e-03 | 4.09e-02 | 8.39e-02 | 2.19e-01 | 4.79e-01 |
| s2-8-struct | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 4.69e-05 | 4.92e-04 | 5.65e-03 | 3.34e-02 | 6.99e-02 | 1.89e-01 | 4.62e-01 |
| s2-8-struct | generated, unmarked | c_projects | 0.00e+00 | 8.94e-06 | 3.58e-05 | 4.38e-04 | 4.77e-03 | 3.11e-02 | 6.09e-02 | 1.75e-01 | 4.49e-01 |
| s2-8-struct | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 2.56e-05 | 4.35e-04 | 4.08e-03 | 2.77e-02 | 5.79e-02 | 1.70e-01 | 4.45e-01 |
| s1-8-struct | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 1.95e-05 | 3.44e-04 | 4.01e-03 | 1.06e-02 | 9.13e-02 | 3.34e-01 |
| s1-8-struct | hand-written | codenet_c_human | 0.00e+00 | 3.91e-06 | 1.17e-05 | 5.47e-05 | 7.19e-04 | 5.49e-03 | 1.73e-02 | 1.12e-01 | 3.62e-01 |
| s1-8-struct | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 3.91e-06 | 2.34e-04 | 3.51e-03 | 1.08e-02 | 9.06e-02 | 3.25e-01 |
| s1-8-struct | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 9.17e-05 | 2.69e-03 | 1.71e-02 | 4.30e-02 | 1.61e-01 | 4.34e-01 |
| s1-8-struct | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 2.79e-04 | 5.86e-03 | 3.91e-02 | 8.37e-02 | 2.33e-01 | 4.93e-01 |
| s1-8-struct | generated, unmarked | codenet_python_generated | 0.00e+00 | 0.00e+00 | 4.69e-05 | 4.03e-04 | 5.58e-03 | 3.16e-02 | 6.60e-02 | 1.84e-01 | 4.54e-01 |
| s1-8-struct | generated, unmarked | codenet_c_generated | 0.00e+00 | 0.00e+00 | 3.13e-05 | 3.99e-04 | 5.01e-03 | 3.09e-02 | 6.39e-02 | 1.79e-01 | 4.48e-01 |
| s1-8-struct | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 3.91e-06 | 3.52e-05 | 3.32e-04 | 4.54e-03 | 2.97e-02 | 6.20e-02 | 1.76e-01 | 4.48e-01 |
| s1-8-struct | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 7.82e-06 | 7.82e-05 | 5.98e-04 | 6.53e-03 | 3.83e-02 | 7.82e-02 | 2.12e-01 | 4.78e-01 |
| s1-8-struct | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 2.34e-05 | 4.14e-04 | 4.24e-03 | 2.70e-02 | 5.79e-02 | 1.69e-01 | 4.44e-01 |
| s1-8-struct | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 1.79e-04 | 2.98e-03 | 1.99e-02 | 4.72e-02 | 1.44e-01 | 4.23e-01 |
| s1-8-struct | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 8.53e-06 | 1.19e-04 | 1.79e-03 | 1.53e-02 | 4.10e-02 | 1.42e-01 | 4.14e-01 |
| bch-file | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | generated, unmarked | codenet_python_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | generated, unmarked | codenet_c_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-file | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | hand-written | codenet_python_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | hand-written | codenet_c_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | hand-written | codenet_cpp_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | hand-written | codenet_javascript_human | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | hand-written | js_repos | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | generated, unmarked | codenet_python_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | generated, unmarked | codenet_c_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | generated, unmarked | codenet_cpp_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | generated, unmarked | codenet_javascript_generated | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | generated, unmarked | python_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | generated, unmarked | c_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |
| bch-node | generated, unmarked | cpp_projects | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 | 0.00e+00 |

## 6. Wrong messages on marked code (cross-message acceptance)

Marked code tested against every other message: share of (unit, wrong message) pairs accepted, and units that accept at least one wrong message. For BCH the only candidate is the decoded message, so a unit counts when it decodes to a message other than the embedded one.

| variant | group | units | accepted pairs | units with a wrong acceptance |
|---|---|---|---|---|
| s2-4-tok | codenet_python_generated | 999 | 8.01e-04 / 0.00e+00 | 1.2% / 0.0% |
| s2-4-tok | codenet_c_generated | 999 | 2.67e-04 / 0.00e+00 | 0.4% / 0.0% |
| s2-4-tok | codenet_cpp_generated | 999 | 5.34e-04 / 0.00e+00 | 0.8% / 0.0% |
| s2-4-tok | codenet_javascript_generated | 999 | 6.67e-04 / 0.00e+00 | 1.0% / 0.0% |
| s2-4-tok | python_projects | 500 | 9.33e-04 / 0.00e+00 | 1.4% / 0.0% |
| s2-4-tok | c_projects | 437 | 7.63e-04 / 0.00e+00 | 1.1% / 0.0% |
| s2-4-tok | cpp_projects | 458 | 1.46e-04 / 0.00e+00 | 0.2% / 0.0% |
| s1-4-tok | codenet_python_generated | 999 | 3.34e-04 / 0.00e+00 | 0.5% / 0.0% |
| s1-4-tok | codenet_c_generated | 999 | 5.34e-04 / 0.00e+00 | 0.8% / 0.0% |
| s1-4-tok | codenet_cpp_generated | 999 | 4.67e-04 / 0.00e+00 | 0.7% / 0.0% |
| s1-4-tok | codenet_javascript_generated | 999 | 8.68e-04 / 0.00e+00 | 1.3% / 0.0% |
| s1-4-tok | python_projects | 500 | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% |
| s1-4-tok | c_projects | 437 | 1.53e-04 / 0.00e+00 | 0.2% / 0.0% |
| s1-4-tok | cpp_projects | 458 | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% |
| s2-4-struct | codenet_python_generated | 999 | 2.00e-04 / 0.00e+00 | 0.3% / 0.0% |
| s2-4-struct | codenet_c_generated | 999 | 4.00e-04 / 0.00e+00 | 0.6% / 0.0% |
| s2-4-struct | codenet_cpp_generated | 999 | 4.00e-04 / 0.00e+00 | 0.6% / 0.0% |
| s2-4-struct | codenet_javascript_generated | 999 | 4.67e-04 / 0.00e+00 | 0.7% / 0.0% |
| s2-4-struct | python_projects | 500 | 5.33e-04 / 0.00e+00 | 0.8% / 0.0% |
| s2-4-struct | c_projects | 437 | 1.53e-04 / 0.00e+00 | 0.2% / 0.0% |
| s2-4-struct | cpp_projects | 458 | 1.46e-04 / 0.00e+00 | 0.2% / 0.0% |
| s1-4-struct | codenet_python_generated | 999 | 3.34e-04 / 0.00e+00 | 0.5% / 0.0% |
| s1-4-struct | codenet_c_generated | 999 | 2.67e-04 / 0.00e+00 | 0.4% / 0.0% |
| s1-4-struct | codenet_cpp_generated | 999 | 3.34e-04 / 0.00e+00 | 0.5% / 0.0% |
| s1-4-struct | codenet_javascript_generated | 999 | 6.01e-04 / 0.00e+00 | 0.9% / 0.0% |
| s1-4-struct | python_projects | 500 | 2.67e-04 / 0.00e+00 | 0.4% / 0.0% |
| s1-4-struct | c_projects | 437 | 0.00e+00 / 0.00e+00 | 0.0% / 0.0% |
| s1-4-struct | cpp_projects | 458 | 1.46e-04 / 0.00e+00 | 0.2% / 0.0% |
| s2-8-tok | codenet_python_generated | 999 | 6.99e-04 / 0.00e+00 | 16.1% / 0.0% |
| s2-8-tok | codenet_c_generated | 999 | 7.65e-04 / 0.00e+00 | 18.2% / 0.0% |
| s2-8-tok | codenet_cpp_generated | 999 | 7.69e-04 / 0.00e+00 | 17.1% / 0.0% |
| s2-8-tok | codenet_javascript_generated | 999 | 7.89e-04 / 0.00e+00 | 18.8% / 0.0% |
| s2-8-tok | python_projects | 500 | 6.27e-04 / 0.00e+00 | 13.2% / 0.0% |
| s2-8-tok | c_projects | 437 | 6.37e-04 / 0.00e+00 | 14.6% / 0.0% |
| s2-8-tok | cpp_projects | 458 | 3.77e-04 / 8.56e-06 | 9.4% / 0.2% |
| s1-8-tok | codenet_python_generated | 999 | 5.26e-04 / 0.00e+00 | 11.9% / 0.0% |
| s1-8-tok | codenet_c_generated | 999 | 5.97e-04 / 0.00e+00 | 14.0% / 0.0% |
| s1-8-tok | codenet_cpp_generated | 999 | 6.08e-04 / 0.00e+00 | 14.2% / 0.0% |
| s1-8-tok | codenet_javascript_generated | 999 | 6.75e-04 / 3.93e-06 | 16.1% / 0.1% |
| s1-8-tok | python_projects | 500 | 4.00e-04 / 0.00e+00 | 9.8% / 0.0% |
| s1-8-tok | c_projects | 437 | 4.67e-04 / 0.00e+00 | 10.5% / 0.0% |
| s1-8-tok | cpp_projects | 458 | 1.80e-04 / 0.00e+00 | 4.4% / 0.0% |
| s2-8-struct | codenet_python_generated | 999 | 5.38e-04 / 0.00e+00 | 12.5% / 0.0% |
| s2-8-struct | codenet_c_generated | 999 | 5.42e-04 / 0.00e+00 | 12.7% / 0.0% |
| s2-8-struct | codenet_cpp_generated | 999 | 5.97e-04 / 0.00e+00 | 14.2% / 0.0% |
| s2-8-struct | codenet_javascript_generated | 999 | 6.05e-04 / 0.00e+00 | 14.1% / 0.0% |
| s2-8-struct | python_projects | 500 | 5.10e-04 / 0.00e+00 | 12.4% / 0.0% |
| s2-8-struct | c_projects | 437 | 4.76e-04 / 0.00e+00 | 11.0% / 0.0% |
| s2-8-struct | cpp_projects | 458 | 3.42e-04 / 0.00e+00 | 7.9% / 0.0% |
| s1-8-struct | codenet_python_generated | 999 | 4.44e-04 / 0.00e+00 | 10.9% / 0.0% |
| s1-8-struct | codenet_c_generated | 999 | 3.73e-04 / 0.00e+00 | 9.0% / 0.0% |
| s1-8-struct | codenet_cpp_generated | 999 | 4.63e-04 / 0.00e+00 | 11.2% / 0.0% |
| s1-8-struct | codenet_javascript_generated | 999 | 5.57e-04 / 0.00e+00 | 13.0% / 0.0% |
| s1-8-struct | python_projects | 500 | 3.84e-04 / 0.00e+00 | 8.2% / 0.0% |
| s1-8-struct | c_projects | 437 | 2.96e-04 / 0.00e+00 | 6.6% / 0.0% |
| s1-8-struct | cpp_projects | 458 | 7.71e-05 / 0.00e+00 | 1.7% / 0.0% |
| bch-file | codenet_python_generated | 999 | 0.00e+00 | 0.0% |
| bch-file | codenet_c_generated | 999 | 6.67e-05 | 0.1% |
| bch-file | codenet_cpp_generated | 999 | 2.00e-04 | 0.3% |
| bch-file | codenet_javascript_generated | 999 | 0.00e+00 | 0.0% |
| bch-file | python_projects | 498 | 1.34e-04 | 0.2% |
| bch-file | c_projects | 437 | 0.00e+00 | 0.0% |
| bch-file | cpp_projects | 458 | 0.00e+00 | 0.0% |
| bch-node | codenet_python_generated | 999 | 0.00e+00 | 0.0% |
| bch-node | codenet_c_generated | 999 | 0.00e+00 | 0.0% |
| bch-node | codenet_cpp_generated | 999 | 0.00e+00 | 0.0% |
| bch-node | codenet_javascript_generated | 999 | 0.00e+00 | 0.0% |
| bch-node | python_projects | 497 | 0.00e+00 | 0.0% |
| bch-node | c_projects | 437 | 0.00e+00 | 0.0% |
| bch-node | cpp_projects | 458 | 0.00e+00 | 0.0% |

## 7. Attacks

Rates are over the units the attack changed (applied share first). TPR and blind TPR are on marked generated code; FPR on the attacked hand-written code (known m / all messages, per pair); anchor columns are the share of embedded keys still present after the attack and the share of attacked-code keys that are embedded ones.

| variant | stratum | attack | applied | TPR known m | TPR blind | msg correct | anchors retained | anchor survival | null applied | FPR known m | FPR all m | reading errors | detector rule errors |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | codenet | flip_0.1 | 3996/3996 | 99.7% / 96.2% | 98.9% / 92.4% | 100.0% | 96.7% | 97.8% | 2573/3511 | 0.0% / 0.0% | 3.16e-04 / 0.00e+00 | 0 | 1457 |
| s2-4-tok | codenet | flip_0.2 | 3996/3996 | 95.6% / 74.3% | 88.7% / 62.3% | 99.5% | 93.9% | 95.6% | 3061/3511 | 0.0% / 0.0% | 1.43e-04 / 0.00e+00 | 0 | 1680 |
| s2-4-tok | codenet | flip_0.3 | 3996/3996 | 68.9% / 23.9% | 48.2% / 14.0% | 94.1% | 91.3% | 93.5% | 3249/3511 | 0.0% / 0.0% | 1.15e-04 / 0.00e+00 | 0 | 1811 |
| s2-4-tok | codenet | normalize_1 | 3217/3996 | 99.8% / 98.2% | 99.4% / 96.6% | 100.0% | 99.2% | 99.0% | 2045/3511 | 0.0% / 0.0% | 1.53e-04 / 0.00e+00 | 0 | 946 |
| s2-4-tok | codenet | normalize_3 | 3962/3996 | 98.5% / 90.7% | 96.0% / 85.7% | 99.8% | 98.2% | 97.7% | 3207/3511 | 0.0% / 0.0% | 1.56e-04 / 0.00e+00 | 0 | 1368 |
| s2-4-tok | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 6.0% | 91.1% | 88.7% | 3439/3511 | 0.0% / 0.0% | 1.64e-04 / 0.00e+00 | 0 | 2087 |
| s2-4-tok | codenet | delete_0.25 | 3988/3996 | 99.9% / 99.0% | 99.7% / 97.8% | 100.0% | 79.8% | 100.0% | 1163/3511 | 0.0% / 0.0% | 5.37e-05 / 0.00e+00 | 0 | 916 |
| s2-4-tok | codenet | delete_0.5 | 3996/3996 | 99.6% / 96.7% | 98.7% / 93.8% | 99.9% | 59.6% | 100.0% | 2698/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 784 |
| s2-4-tok | codenet | insert_1 | 3996/3996 | 89.1% / 73.8% | 83.1% / 67.6% | 96.3% | 86.7% | 49.5% | 3511/3511 | 0.1% / 0.0% | 3.74e-04 / 0.00e+00 | 0 | 2201 |
| s2-4-tok | codenet | rename | 3996/3996 | 9.3% / 1.3% | 4.4% / 0.6% | 33.9% | 12.1% | 12.1% | 3487/3511 | 0.0% / 0.0% | 1.43e-04 / 0.00e+00 | 0 | 1127 |
| s2-4-tok | codenet | reformat | 3965/3996 | 100.0% / 99.6% | 99.9% / 99.2% | 100.0% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 1.55e-04 / 0.00e+00 | 0 | 1135 |
| s2-4-tok | codenet | reorder | 3988/3996 | 100.0% / 99.6% | 99.9% / 99.2% | 100.0% | 100.0% | 100.0% | 1161/3511 | 0.0% / 0.0% | 3.23e-04 / 0.00e+00 | 0 | 1062 |
| s2-4-tok | codenet | combo | 3996/3996 | 3.1% / 0.1% | 0.7% / 0.1% | 22.3% | 11.0% | 13.6% | 3501/3511 | 0.1% / 0.0% | 1.43e-04 / 0.00e+00 | 0 | 1512 |
| s2-4-tok | projects | flip_0.1 | 1359/1395 | 68.3% / 30.2% | 51.8% / 21.8% | 89.7% | 95.6% | 95.1% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 13 |
| s2-4-tok | projects | flip_0.2 | 1392/1395 | 36.3% / 7.9% | 20.7% / 3.5% | 75.1% | 91.9% | 90.7% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 19 |
| s2-4-tok | projects | flip_0.3 | 1393/1395 | 12.0% / 0.2% | 3.1% / 0.1% | 53.2% | 88.4% | 87.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 20 |
| s2-4-tok | projects | normalize_1 | 997/1395 | 72.0% / 42.3% | 59.3% / 33.9% | 89.8% | 96.8% | 96.2% | 5/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 12 |
| s2-4-tok | projects | normalize_3 | 1367/1395 | 49.3% / 23.6% | 36.1% / 16.5% | 74.0% | 93.3% | 92.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 17 |
| s2-4-tok | projects | normalize_all | 1395/1395 | 0.2% / 0.0% | 0.0% / 0.0% | 6.2% | 81.8% | 78.4% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 41 |
| s2-4-tok | projects | delete_0.25 | 1387/1395 | 76.0% / 44.1% | 63.8% / 34.2% | 93.9% | 73.9% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 8 |
| s2-4-tok | projects | delete_0.5 | 1395/1395 | 57.8% / 21.6% | 40.2% / 14.4% | 87.3% | 47.7% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 0 |
| s2-4-tok | projects | insert_1 | 1395/1395 | 55.2% / 22.4% | 37.1% / 14.8% | 85.7% | 99.9% | 47.9% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 237 |
| s2-4-tok | projects | rename | 1395/1395 | 2.9% / 0.4% | 1.0% / 0.1% | 19.6% | 11.2% | 11.2% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 9 |
| s2-4-tok | projects | reformat | 1080/1395 | 86.9% / 63.5% | 78.3% / 51.9% | 96.9% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 5 |
| s2-4-tok | projects | reorder | 1387/1395 | 85.3% / 61.9% | 76.1% / 51.0% | 96.5% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 6.94e-03 / 0.00e+00 | 0 | 9 |
| s2-4-tok | projects | combo | 1395/1395 | 0.2% / 0.0% | 0.0% / 0.0% | 10.9% | 7.5% | 10.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 10 |
| s1-4-tok | codenet | flip_0.1 | 3996/3996 | 95.4% / 71.4% | 94.1% / 71.0% | 98.4% | 96.7% | 97.8% | 2573/3511 | 0.0% / 0.0% | 1.21e-04 / 0.00e+00 | 0 | 1464 |
| s1-4-tok | codenet | flip_0.2 | 3996/3996 | 77.5% / 31.7% | 73.3% / 31.0% | 92.9% | 93.8% | 95.7% | 3061/3511 | 0.0% / 0.0% | 2.04e-05 / 0.00e+00 | 0 | 1684 |
| s1-4-tok | codenet | flip_0.3 | 3996/3996 | 34.5% / 3.3% | 27.6% / 2.8% | 75.4% | 91.3% | 93.6% | 3249/3511 | 0.0% / 0.0% | 1.54e-04 / 0.00e+00 | 0 | 1799 |
| s1-4-tok | codenet | normalize_1 | 3217/3996 | 98.1% / 84.1% | 97.5% / 84.0% | 99.3% | 99.2% | 99.0% | 2045/3511 | 0.0% / 0.0% | 3.06e-05 / 0.00e+00 | 0 | 935 |
| s1-4-tok | codenet | normalize_3 | 3975/3996 | 90.7% / 65.3% | 89.3% / 65.0% | 97.3% | 98.3% | 97.7% | 3207/3511 | 0.0% / 0.0% | 9.74e-05 / 0.00e+00 | 0 | 1366 |
| s1-4-tok | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 6.5% | 91.1% | 88.9% | 3439/3511 | 0.0% / 0.0% | 5.45e-05 / 0.00e+00 | 0 | 2087 |
| s1-4-tok | codenet | delete_0.25 | 3988/3996 | 98.5% / 88.0% | 98.2% / 87.9% | 99.6% | 79.8% | 100.0% | 1163/3511 | 0.0% / 0.0% | 1.07e-04 / 0.00e+00 | 0 | 908 |
| s1-4-tok | codenet | delete_0.5 | 3996/3996 | 96.2% / 73.5% | 95.5% / 73.3% | 99.4% | 59.5% | 100.0% | 2698/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 784 |
| s1-4-tok | codenet | insert_1 | 3996/3996 | 75.0% / 41.7% | 71.7% / 40.8% | 90.0% | 86.6% | 49.5% | 3511/3511 | 0.0% / 0.0% | 2.14e-04 / 0.00e+00 | 0 | 2198 |
| s1-4-tok | codenet | rename | 3996/3996 | 3.7% / 0.2% | 2.1% / 0.1% | 23.7% | 12.1% | 12.1% | 3487/3511 | 0.0% / 0.0% | 8.96e-05 / 0.00e+00 | 0 | 1125 |
| s1-4-tok | codenet | reformat | 3965/3996 | 99.4% / 93.9% | 99.2% / 93.8% | 99.7% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 1.94e-05 / 0.00e+00 | 0 | 1133 |
| s1-4-tok | codenet | reorder | 3988/3996 | 99.4% / 94.0% | 99.2% / 93.9% | 99.7% | 100.0% | 100.0% | 1161/3511 | 0.0% / 0.0% | 5.38e-05 / 0.00e+00 | 0 | 1060 |
| s1-4-tok | codenet | combo | 3996/3996 | 1.2% / 0.1% | 0.4% / 0.0% | 17.1% | 11.0% | 13.5% | 3501/3511 | 0.0% / 0.0% | 3.57e-05 / 0.00e+00 | 0 | 1508 |
| s1-4-tok | projects | flip_0.1 | 1358/1395 | 36.1% / 5.9% | 30.9% / 5.4% | 82.0% | 95.7% | 95.2% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 13 |
| s1-4-tok | projects | flip_0.2 | 1391/1395 | 11.9% / 0.7% | 8.8% / 0.6% | 62.6% | 91.8% | 90.6% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 21 |
| s1-4-tok | projects | flip_0.3 | 1393/1395 | 2.8% / 0.0% | 1.5% / 0.0% | 41.6% | 88.2% | 86.8% | 14/14 | 7.1% / 0.0% | 4.46e-03 / 0.00e+00 | 0 | 20 |
| s1-4-tok | projects | normalize_1 | 986/1395 | 46.0% / 14.7% | 43.7% / 14.6% | 84.9% | 96.8% | 96.1% | 5/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 14 |
| s1-4-tok | projects | normalize_3 | 1363/1395 | 26.6% / 6.2% | 24.3% / 6.0% | 65.4% | 93.3% | 92.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 18 |
| s1-4-tok | projects | normalize_all | 1395/1395 | 0.0% / 0.0% | 0.0% / 0.0% | 6.2% | 81.8% | 78.3% | 14/14 | 0.0% / 0.0% | 8.93e-03 / 0.00e+00 | 0 | 41 |
| s1-4-tok | projects | delete_0.25 | 1387/1395 | 45.9% / 11.2% | 43.2% / 11.2% | 92.1% | 73.9% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 7 |
| s1-4-tok | projects | delete_0.5 | 1395/1395 | 23.3% / 3.3% | 21.5% / 3.3% | 84.1% | 47.5% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s1-4-tok | projects | insert_1 | 1395/1395 | 26.7% / 4.5% | 22.7% / 4.3% | 70.6% | 99.8% | 47.9% | 14/14 | 0.0% / 0.0% | 4.46e-03 / 0.00e+00 | 0 | 239 |
| s1-4-tok | projects | rename | 1395/1395 | 0.8% / 0.1% | 0.5% / 0.0% | 16.6% | 11.2% | 11.2% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 9 |
| s1-4-tok | projects | reformat | 1080/1395 | 63.8% / 21.7% | 62.2% / 21.6% | 95.5% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 4 |
| s1-4-tok | projects | reorder | 1387/1395 | 62.8% / 23.2% | 61.1% / 23.1% | 94.7% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 9 |
| s1-4-tok | projects | combo | 1395/1395 | 0.0% / 0.0% | 0.0% / 0.0% | 10.2% | 7.9% | 10.4% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 8 |
| s2-4-struct | codenet | flip_0.1 | 3996/3996 | 99.0% / 81.0% | 95.8% / 66.7% | 99.9% | 95.2% | 96.0% | 2573/3511 | 0.0% / 0.0% | 2.43e-05 / 0.00e+00 | 0 | 1412 |
| s2-4-struct | codenet | flip_0.2 | 3996/3996 | 85.0% / 36.7% | 66.2% / 22.9% | 98.6% | 91.0% | 92.4% | 3061/3511 | 0.0% / 0.0% | 6.13e-05 / 0.00e+00 | 0 | 1644 |
| s2-4-struct | codenet | flip_0.3 | 3996/3996 | 42.7% / 6.2% | 21.2% / 2.0% | 85.5% | 87.1% | 89.4% | 3249/3511 | 0.0% / 0.0% | 3.85e-05 / 0.00e+00 | 0 | 1790 |
| s2-4-struct | codenet | normalize_1 | 2979/3996 | 99.3% / 91.5% | 97.7% / 83.1% | 99.9% | 98.8% | 98.8% | 2045/3511 | 0.0% / 0.0% | 1.22e-04 / 0.00e+00 | 0 | 808 |
| s2-4-struct | codenet | normalize_3 | 3934/3996 | 94.4% / 71.1% | 86.9% / 59.4% | 99.0% | 97.5% | 97.5% | 3207/3511 | 0.0% / 0.0% | 7.80e-05 / 0.00e+00 | 0 | 1278 |
| s2-4-struct | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 6.1% | 87.0% | 87.0% | 3439/3511 | 0.0% / 0.0% | 1.82e-04 / 0.00e+00 | 0 | 2087 |
| s2-4-struct | codenet | delete_0.25 | 3988/3996 | 99.9% / 96.9% | 99.6% / 92.3% | 100.0% | 84.6% | 100.0% | 1163/3511 | 0.0% / 0.0% | 5.37e-05 / 0.00e+00 | 0 | 818 |
| s2-4-struct | codenet | delete_0.5 | 3996/3996 | 99.2% / 87.5% | 97.0% / 74.6% | 99.9% | 67.7% | 100.0% | 2698/3511 | 0.0% / 0.0% | 4.63e-05 / 0.00e+00 | 0 | 705 |
| s2-4-struct | codenet | insert_1 | 3996/3996 | 76.0% / 33.4% | 58.5% / 21.4% | 95.3% | 85.3% | 50.6% | 3511/3511 | 0.0% / 0.0% | 7.12e-05 / 0.00e+00 | 0 | 2108 |
| s2-4-struct | codenet | rename | 3996/3996 | 98.8% / 78.8% | 94.4% / 64.3% | 100.0% | 98.7% | 100.0% | 3487/3511 | 0.0% / 0.0% | 5.38e-05 / 0.00e+00 | 0 | 1030 |
| s2-4-struct | codenet | reformat | 3965/3996 | 100.0% / 99.2% | 100.0% / 97.7% | 100.0% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 3.88e-05 / 0.00e+00 | 0 | 1038 |
| s2-4-struct | codenet | reorder | 3988/3996 | 100.0% / 99.2% | 100.0% / 97.8% | 100.0% | 100.0% | 100.0% | 1161/3511 | 0.0% / 0.0% | 5.38e-05 / 0.00e+00 | 0 | 965 |
| s2-4-struct | codenet | combo | 3996/3996 | 57.9% / 16.7% | 35.8% / 9.7% | 91.8% | 76.7% | 92.8% | 3501/3511 | 0.0% / 0.0% | 8.93e-05 / 0.00e+00 | 0 | 1492 |
| s2-4-struct | projects | flip_0.1 | 1361/1395 | 59.3% / 16.7% | 36.3% / 9.7% | 90.9% | 93.4% | 93.9% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 7 |
| s2-4-struct | projects | flip_0.2 | 1392/1395 | 24.2% / 3.8% | 11.4% / 2.2% | 73.9% | 88.0% | 89.1% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 14 |
| s2-4-struct | projects | flip_0.3 | 1393/1395 | 6.8% / 0.4% | 1.9% / 0.0% | 46.2% | 83.0% | 84.6% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 16 |
| s2-4-struct | projects | normalize_1 | 953/1395 | 61.9% / 21.8% | 40.8% / 16.6% | 87.7% | 95.6% | 95.5% | 5/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 10 |
| s2-4-struct | projects | normalize_3 | 1366/1395 | 37.4% / 11.1% | 22.8% / 7.2% | 69.8% | 92.2% | 92.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 14 |
| s2-4-struct | projects | normalize_all | 1395/1395 | 0.0% / 0.0% | 0.0% / 0.0% | 7.2% | 77.3% | 77.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 41 |
| s2-4-struct | projects | delete_0.25 | 1387/1395 | 77.6% / 23.5% | 50.0% / 16.6% | 96.8% | 77.1% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s2-4-struct | projects | delete_0.5 | 1395/1395 | 48.8% / 10.9% | 23.8% / 7.8% | 89.5% | 53.1% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 0 |
| s2-4-struct | projects | insert_1 | 1395/1395 | 44.5% / 12.3% | 24.7% / 8.1% | 83.5% | 99.2% | 52.8% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 230 |
| s2-4-struct | projects | rename | 1395/1395 | 73.6% / 25.3% | 49.5% / 15.3% | 95.6% | 95.5% | 95.9% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s2-4-struct | projects | reformat | 1079/1395 | 91.4% / 42.4% | 74.7% / 25.5% | 98.9% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s2-4-struct | projects | reorder | 1387/1395 | 90.3% / 41.7% | 73.8% / 26.7% | 99.0% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s2-4-struct | projects | combo | 1395/1395 | 12.8% / 0.8% | 4.2% / 0.1% | 56.4% | 64.9% | 85.5% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 9 |
| s1-4-struct | codenet | flip_0.1 | 3996/3996 | 80.9% / 26.9% | 78.8% / 26.6% | 97.6% | 95.2% | 96.0% | 2573/3511 | 0.0% / 0.0% | 2.43e-05 / 0.00e+00 | 0 | 1420 |
| s1-4-struct | codenet | flip_0.2 | 3996/3996 | 43.9% / 5.6% | 38.4% / 5.2% | 86.8% | 91.0% | 92.4% | 3061/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 1643 |
| s1-4-struct | codenet | flip_0.3 | 3996/3996 | 12.3% / 0.3% | 8.8% / 0.3% | 65.7% | 87.0% | 89.4% | 3249/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 1797 |
| s1-4-struct | codenet | normalize_1 | 2998/3996 | 89.6% / 46.5% | 88.4% / 46.3% | 98.5% | 98.8% | 98.8% | 2045/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 812 |
| s1-4-struct | codenet | normalize_3 | 3933/3996 | 73.0% / 28.0% | 69.9% / 27.6% | 93.8% | 97.5% | 97.5% | 3207/3511 | 0.0% / 0.0% | 1.95e-05 / 0.00e+00 | 0 | 1287 |
| s1-4-struct | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 6.1% | 87.0% | 87.0% | 3439/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2087 |
| s1-4-struct | codenet | delete_0.25 | 3988/3996 | 95.8% / 49.6% | 95.5% / 49.5% | 99.9% | 84.6% | 100.0% | 1163/3511 | 0.0% / 0.0% | 5.37e-05 / 0.00e+00 | 0 | 818 |
| s1-4-struct | codenet | delete_0.5 | 3996/3996 | 84.7% / 30.2% | 83.5% / 30.1% | 99.8% | 67.7% | 100.0% | 2698/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 705 |
| s1-4-struct | codenet | insert_1 | 3996/3996 | 44.4% / 6.4% | 38.2% / 5.8% | 80.6% | 85.3% | 50.6% | 3511/3511 | 0.0% / 0.0% | 8.90e-05 / 0.00e+00 | 0 | 2108 |
| s1-4-struct | codenet | rename | 3996/3996 | 75.4% / 30.9% | 72.6% / 30.6% | 96.5% | 98.7% | 100.0% | 3487/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 1030 |
| s1-4-struct | codenet | reformat | 3965/3996 | 98.8% / 68.2% | 98.6% / 68.1% | 99.9% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 1038 |
| s1-4-struct | codenet | reorder | 3988/3996 | 98.8% / 68.3% | 98.6% / 68.3% | 99.9% | 100.0% | 100.0% | 1161/3511 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 965 |
| s1-4-struct | codenet | combo | 3996/3996 | 22.6% / 2.0% | 18.9% / 1.9% | 74.5% | 76.6% | 92.8% | 3501/3511 | 0.0% / 0.0% | 1.79e-05 / 0.00e+00 | 0 | 1479 |
| s1-4-struct | projects | flip_0.1 | 1360/1395 | 21.5% / 2.8% | 19.3% / 2.6% | 84.0% | 93.4% | 93.8% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 6 |
| s1-4-struct | projects | flip_0.2 | 1392/1395 | 7.8% / 0.6% | 5.9% / 0.6% | 59.4% | 87.9% | 89.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 14 |
| s1-4-struct | projects | flip_0.3 | 1393/1395 | 2.1% / 0.0% | 1.4% / 0.0% | 38.4% | 83.0% | 84.5% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 16 |
| s1-4-struct | projects | normalize_1 | 946/1395 | 28.2% / 6.6% | 25.5% / 6.6% | 79.2% | 95.5% | 95.5% | 5/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 10 |
| s1-4-struct | projects | normalize_3 | 1361/1395 | 14.7% / 2.4% | 12.5% / 2.4% | 59.1% | 92.2% | 92.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 12 |
| s1-4-struct | projects | normalize_all | 1395/1395 | 0.2% / 0.0% | 0.1% / 0.0% | 6.5% | 77.3% | 77.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 41 |
| s1-4-struct | projects | delete_0.25 | 1387/1395 | 26.5% / 6.3% | 24.4% / 6.3% | 95.0% | 77.1% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s1-4-struct | projects | delete_0.5 | 1395/1395 | 12.9% / 2.4% | 11.5% / 2.4% | 84.9% | 53.1% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 0 |
| s1-4-struct | projects | insert_1 | 1395/1395 | 19.6% / 3.6% | 15.1% / 3.2% | 63.2% | 99.2% | 52.8% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 230 |
| s1-4-struct | projects | rename | 1395/1395 | 27.7% / 4.2% | 24.8% / 4.1% | 90.0% | 95.5% | 95.9% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s1-4-struct | projects | reformat | 1079/1395 | 41.5% / 8.9% | 38.3% / 8.9% | 98.1% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s1-4-struct | projects | reorder | 1387/1395 | 41.2% / 11.3% | 38.3% / 11.3% | 97.9% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s1-4-struct | projects | combo | 1395/1395 | 2.7% / 0.1% | 1.4% / 0.0% | 46.5% | 65.2% | 85.5% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 9 |
| s2-8-tok | codenet | flip_0.1 | 3996/3996 | 99.7% / 95.7% | 97.2% / 87.5% | 99.8% | 96.7% | 97.7% | 2573/3511 | 0.0% / 0.0% | 2.41e-04 / 0.00e+00 | 0 | 1457 |
| s2-8-tok | codenet | flip_0.2 | 3996/3996 | 96.3% / 74.2% | 79.7% / 51.7% | 97.5% | 93.9% | 95.7% | 3061/3511 | 0.0% / 0.0% | 2.11e-04 / 0.00e+00 | 0 | 1683 |
| s2-8-tok | codenet | flip_0.3 | 3996/3996 | 69.6% / 24.2% | 30.5% / 7.6% | 78.0% | 91.3% | 93.5% | 3249/3511 | 0.0% / 0.0% | 1.96e-04 / 0.00e+00 | 0 | 1799 |
| s2-8-tok | codenet | normalize_1 | 3204/3996 | 99.8% / 98.4% | 98.9% / 94.1% | 99.8% | 99.2% | 99.0% | 2045/3511 | 0.0% / 0.0% | 1.76e-04 / 0.00e+00 | 0 | 940 |
| s2-8-tok | codenet | normalize_3 | 3973/3996 | 98.6% / 90.3% | 92.4% / 79.4% | 99.0% | 98.3% | 97.7% | 3207/3511 | 0.0% / 0.0% | 1.67e-04 / 0.00e+00 | 0 | 1371 |
| s2-8-tok | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 0.4% | 91.1% | 88.7% | 3439/3511 | 0.0% / 0.0% | 1.78e-04 / 0.00e+00 | 0 | 2087 |
| s2-8-tok | codenet | delete_0.25 | 3988/3996 | 99.9% / 98.9% | 99.3% / 96.2% | 100.0% | 79.8% | 100.0% | 1163/3511 | 0.0% / 0.0% | 2.15e-04 / 0.00e+00 | 0 | 907 |
| s2-8-tok | codenet | delete_0.5 | 3996/3996 | 99.4% / 96.6% | 97.3% / 89.3% | 99.6% | 59.6% | 100.0% | 2698/3511 | 0.0% / 0.0% | 1.09e-04 / 0.00e+00 | 0 | 773 |
| s2-8-tok | codenet | insert_1 | 3996/3996 | 89.5% / 74.2% | 77.0% / 60.8% | 91.6% | 86.7% | 49.5% | 3511/3511 | 0.1% / 0.0% | 3.97e-04 / 0.00e+00 | 0 | 2201 |
| s2-8-tok | codenet | rename | 3996/3996 | 9.6% / 1.5% | 2.3% / 0.2% | 14.0% | 12.1% | 12.1% | 3487/3511 | 0.0% / 0.0% | 1.83e-04 / 0.00e+00 | 0 | 1126 |
| s2-8-tok | codenet | reformat | 3965/3996 | 100.0% / 99.8% | 99.8% / 98.4% | 100.0% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 1.95e-04 / 0.00e+00 | 0 | 1134 |
| s2-8-tok | codenet | reorder | 3988/3996 | 100.0% / 99.8% | 99.8% / 98.4% | 100.0% | 100.0% | 100.0% | 1161/3511 | 0.0% / 0.0% | 2.89e-04 / 0.00e+00 | 0 | 1061 |
| s2-8-tok | codenet | combo | 3996/3996 | 3.0% / 0.1% | 0.2% / 0.0% | 5.9% | 11.1% | 13.6% | 3501/3511 | 0.1% / 0.0% | 1.53e-04 / 0.00e+00 | 0 | 1509 |
| s2-8-tok | projects | flip_0.1 | 1358/1395 | 67.8% / 30.7% | 36.0% / 15.3% | 76.0% | 95.7% | 95.2% | 14/14 | 0.0% / 0.0% | 1.40e-03 / 0.00e+00 | 0 | 12 |
| s2-8-tok | projects | flip_0.2 | 1392/1395 | 35.3% / 6.9% | 9.3% / 1.8% | 48.3% | 91.9% | 90.9% | 14/14 | 0.0% / 0.0% | 1.40e-03 / 0.00e+00 | 0 | 19 |
| s2-8-tok | projects | flip_0.3 | 1393/1395 | 12.0% / 0.4% | 0.9% / 0.0% | 21.0% | 88.4% | 86.9% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 19 |
| s2-8-tok | projects | normalize_1 | 1006/1395 | 71.7% / 41.4% | 45.3% / 26.1% | 77.4% | 96.8% | 96.2% | 5/14 | 0.0% / 0.0% | 2.34e-03 / 0.00e+00 | 0 | 12 |
| s2-8-tok | projects | normalize_3 | 1366/1395 | 48.5% / 22.9% | 26.1% / 12.0% | 57.0% | 93.4% | 92.3% | 14/14 | 0.0% / 0.0% | 1.40e-03 / 0.00e+00 | 0 | 18 |
| s2-8-tok | projects | normalize_all | 1395/1395 | 0.0% / 0.0% | 0.0% / 0.0% | 0.5% | 81.9% | 78.4% | 14/14 | 0.0% / 0.0% | 1.40e-03 / 0.00e+00 | 0 | 41 |
| s2-8-tok | projects | delete_0.25 | 1387/1395 | 75.6% / 43.8% | 49.3% / 26.7% | 83.0% | 74.0% | 100.0% | 9/14 | 0.0% / 0.0% | 2.17e-03 / 0.00e+00 | 0 | 6 |
| s2-8-tok | projects | delete_0.5 | 1395/1395 | 58.0% / 21.3% | 26.3% / 10.0% | 69.0% | 47.6% | 100.0% | 9/14 | 0.0% / 0.0% | 1.30e-03 / 0.00e+00 | 0 | 1 |
| s2-8-tok | projects | insert_1 | 1395/1395 | 54.9% / 21.9% | 25.9% / 10.3% | 64.9% | 99.9% | 48.0% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 236 |
| s2-8-tok | projects | rename | 1395/1395 | 3.4% / 0.4% | 0.5% / 0.1% | 5.9% | 11.2% | 11.2% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 8 |
| s2-8-tok | projects | reformat | 1080/1395 | 86.5% / 63.8% | 69.3% / 42.6% | 91.3% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 2.51e-03 / 0.00e+00 | 0 | 5 |
| s2-8-tok | projects | reorder | 1387/1395 | 84.7% / 61.7% | 67.3% / 42.5% | 89.6% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 3.04e-03 / 0.00e+00 | 0 | 8 |
| s2-8-tok | projects | combo | 1395/1395 | 0.3% / 0.0% | 0.0% / 0.0% | 1.8% | 7.6% | 10.0% | 14/14 | 0.0% / 0.0% | 5.58e-04 / 0.00e+00 | 0 | 9 |
| s1-8-tok | codenet | flip_0.1 | 3996/3996 | 95.5% / 71.4% | 86.0% / 66.2% | 89.6% | 96.7% | 97.8% | 2573/3511 | 0.0% / 0.0% | 1.03e-04 / 0.00e+00 | 0 | 1465 |
| s1-8-tok | codenet | flip_0.2 | 3996/3996 | 77.1% / 31.9% | 55.1% / 25.4% | 68.5% | 93.8% | 95.7% | 3061/3511 | 0.0% / 0.0% | 8.29e-05 / 0.00e+00 | 0 | 1690 |
| s1-8-tok | codenet | flip_0.3 | 3996/3996 | 34.1% / 3.6% | 14.0% / 1.6% | 36.0% | 91.3% | 93.5% | 3249/3511 | 0.0% / 0.0% | 8.18e-05 / 0.00e+00 | 0 | 1798 |
| s1-8-tok | codenet | normalize_1 | 3202/3996 | 97.9% / 83.9% | 93.0% / 80.9% | 94.6% | 99.2% | 99.0% | 2045/3511 | 0.0% / 0.0% | 6.11e-05 / 0.00e+00 | 0 | 951 |
| s1-8-tok | codenet | normalize_3 | 3970/3996 | 91.0% / 65.4% | 80.8% / 61.0% | 86.7% | 98.3% | 97.7% | 3207/3511 | 0.0% / 0.0% | 6.46e-05 / 0.00e+00 | 0 | 1364 |
| s1-8-tok | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 0.2% | 91.1% | 88.8% | 3439/3511 | 0.0% / 0.0% | 6.02e-05 / 0.00e+00 | 0 | 2087 |
| s1-8-tok | codenet | delete_0.25 | 3988/3996 | 98.8% / 87.8% | 96.1% / 86.2% | 97.3% | 79.8% | 100.0% | 1163/3511 | 0.0% / 0.0% | 1.14e-04 / 0.00e+00 | 0 | 903 |
| s1-8-tok | codenet | delete_0.5 | 3996/3996 | 96.5% / 73.3% | 92.2% / 70.5% | 95.4% | 59.5% | 100.0% | 2698/3511 | 0.0% / 0.0% | 3.62e-05 / 0.00e+00 | 0 | 779 |
| s1-8-tok | codenet | insert_1 | 3996/3996 | 76.2% / 42.6% | 58.6% / 36.1% | 67.7% | 86.6% | 49.5% | 3511/3511 | 0.0% / 0.0% | 2.20e-04 / 0.00e+00 | 0 | 2200 |
| s1-8-tok | codenet | rename | 3996/3996 | 4.0% / 0.1% | 0.9% / 0.1% | 5.2% | 12.1% | 12.1% | 3487/3511 | 0.0% / 0.0% | 8.07e-05 / 0.00e+00 | 0 | 1126 |
| s1-8-tok | codenet | reformat | 3965/3996 | 99.5% / 93.7% | 97.8% / 92.5% | 98.2% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 6.79e-05 / 0.00e+00 | 0 | 1134 |
| s1-8-tok | codenet | reorder | 3988/3996 | 99.5% / 93.7% | 97.8% / 92.6% | 98.2% | 100.0% | 100.0% | 1161/3511 | 0.0% / 0.0% | 1.11e-04 / 0.00e+00 | 0 | 1061 |
| s1-8-tok | codenet | combo | 3996/3996 | 1.3% / 0.0% | 0.2% / 0.0% | 2.8% | 11.0% | 13.5% | 3501/3511 | 0.0% / 0.0% | 5.47e-05 / 0.00e+00 | 0 | 1506 |
| s1-8-tok | projects | flip_0.1 | 1359/1395 | 36.0% / 6.0% | 21.0% / 4.6% | 48.9% | 95.6% | 95.1% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 15 |
| s1-8-tok | projects | flip_0.2 | 1392/1395 | 12.8% / 0.7% | 4.8% / 0.2% | 23.6% | 92.0% | 90.9% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 20 |
| s1-8-tok | projects | flip_0.3 | 1393/1395 | 2.7% / 0.0% | 0.3% / 0.0% | 9.8% | 88.3% | 86.9% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 22 |
| s1-8-tok | projects | normalize_1 | 999/1395 | 45.3% / 14.6% | 33.5% / 12.1% | 55.9% | 96.8% | 96.2% | 5/14 | 0.0% / 0.0% | 7.81e-04 / 0.00e+00 | 0 | 12 |
| s1-8-tok | projects | normalize_3 | 1361/1395 | 26.9% / 5.7% | 17.3% / 4.8% | 35.2% | 93.3% | 91.9% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 20 |
| s1-8-tok | projects | normalize_all | 1395/1395 | 0.0% / 0.0% | 0.0% / 0.0% | 0.4% | 81.8% | 78.3% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 41 |
| s1-8-tok | projects | delete_0.25 | 1387/1395 | 45.9% / 11.2% | 35.0% / 9.9% | 61.6% | 73.9% | 100.0% | 9/14 | 0.0% / 0.0% | 4.34e-04 / 0.00e+00 | 0 | 8 |
| s1-8-tok | projects | delete_0.5 | 1395/1395 | 23.2% / 3.3% | 15.3% / 3.1% | 42.2% | 47.6% | 100.0% | 9/14 | 0.0% / 0.0% | 8.68e-04 / 0.00e+00 | 0 | 1 |
| s1-8-tok | projects | insert_1 | 1395/1395 | 25.6% / 4.9% | 13.2% / 3.7% | 34.1% | 99.9% | 47.9% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 242 |
| s1-8-tok | projects | rename | 1395/1395 | 0.6% / 0.0% | 0.1% / 0.0% | 2.9% | 11.1% | 11.1% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 10 |
| s1-8-tok | projects | reformat | 1080/1395 | 62.8% / 21.9% | 51.1% / 19.4% | 74.6% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 6 |
| s1-8-tok | projects | reorder | 1387/1395 | 61.9% / 23.3% | 50.8% / 21.1% | 73.3% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 8.68e-04 / 0.00e+00 | 0 | 10 |
| s1-8-tok | projects | combo | 1395/1395 | 0.3% / 0.0% | 0.0% / 0.0% | 1.0% | 7.8% | 10.2% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 10 |
| s2-8-struct | codenet | flip_0.1 | 3996/3996 | 99.0% / 81.5% | 87.3% / 50.8% | 99.5% | 95.2% | 96.0% | 2573/3511 | 0.0% / 0.0% | 2.05e-04 / 0.00e+00 | 0 | 1419 |
| s2-8-struct | codenet | flip_0.2 | 3996/3996 | 85.8% / 35.8% | 44.2% / 14.0% | 91.2% | 91.0% | 92.5% | 3061/3511 | 0.0% / 0.0% | 1.40e-04 / 0.00e+00 | 0 | 1646 |
| s2-8-struct | codenet | flip_0.3 | 3996/3996 | 42.8% / 6.0% | 9.0% / 0.7% | 55.8% | 87.0% | 89.4% | 3249/3511 | 0.0% / 0.0% | 1.54e-04 / 0.00e+00 | 0 | 1792 |
| s2-8-struct | codenet | normalize_1 | 2991/3996 | 99.4% / 90.5% | 93.2% / 72.2% | 99.6% | 98.8% | 98.8% | 2045/3511 | 0.0% / 0.0% | 1.87e-04 / 0.00e+00 | 0 | 803 |
| s2-8-struct | codenet | normalize_3 | 3938/3996 | 94.0% / 71.0% | 76.0% / 47.3% | 96.4% | 97.5% | 97.5% | 3207/3511 | 0.0% / 0.0% | 1.32e-04 / 0.00e+00 | 0 | 1281 |
| s2-8-struct | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 0.3% | 87.0% | 87.0% | 3439/3511 | 0.1% / 0.0% | 1.51e-04 / 0.00e+00 | 0 | 2087 |
| s2-8-struct | codenet | delete_0.25 | 3988/3996 | 99.9% / 96.9% | 98.2% / 84.4% | 99.9% | 84.6% | 100.0% | 1163/3511 | 0.0% / 0.0% | 1.98e-04 / 3.36e-06 | 0 | 818 |
| s2-8-struct | codenet | delete_0.5 | 3996/3996 | 99.2% / 87.4% | 91.3% / 61.7% | 99.5% | 67.7% | 100.0% | 2698/3511 | 0.0% / 0.0% | 4.63e-05 / 0.00e+00 | 0 | 705 |
| s2-8-struct | codenet | insert_1 | 3996/3996 | 76.9% / 35.0% | 42.8% / 13.3% | 83.3% | 85.3% | 50.6% | 3511/3511 | 0.1% / 0.0% | 3.78e-04 / 0.00e+00 | 0 | 2108 |
| s2-8-struct | codenet | rename | 3996/3996 | 98.8% / 78.8% | 84.4% / 51.6% | 99.3% | 98.7% | 100.0% | 3487/3511 | 0.0% / 0.0% | 1.52e-04 / 0.00e+00 | 0 | 1030 |
| s2-8-struct | codenet | reformat | 3965/3996 | 100.0% / 99.2% | 99.7% / 94.7% | 100.0% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 1.77e-04 / 0.00e+00 | 0 | 1038 |
| s2-8-struct | codenet | reorder | 3988/3996 | 100.0% / 99.2% | 99.7% / 94.8% | 100.0% | 100.0% | 100.0% | 1161/3511 | 0.0% / 0.0% | 2.69e-04 / 0.00e+00 | 0 | 965 |
| s2-8-struct | codenet | combo | 3996/3996 | 56.5% / 16.1% | 20.8% / 5.6% | 70.5% | 76.5% | 92.8% | 3501/3511 | 0.0% / 0.0% | 1.08e-04 / 0.00e+00 | 0 | 1475 |
| s2-8-struct | projects | flip_0.1 | 1360/1395 | 57.9% / 16.5% | 21.6% / 6.2% | 73.6% | 93.4% | 93.9% | 14/14 | 0.0% / 0.0% | 1.67e-03 / 0.00e+00 | 0 | 7 |
| s2-8-struct | projects | flip_0.2 | 1392/1395 | 24.1% / 3.9% | 5.5% / 0.9% | 38.6% | 87.9% | 89.0% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 14 |
| s2-8-struct | projects | flip_0.3 | 1393/1395 | 6.7% / 0.6% | 1.0% / 0.1% | 14.6% | 83.0% | 84.5% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 16 |
| s2-8-struct | projects | normalize_1 | 955/1395 | 63.4% / 21.7% | 26.1% / 10.9% | 73.4% | 95.6% | 95.5% | 5/14 | 0.0% / 0.0% | 7.81e-04 / 0.00e+00 | 0 | 10 |
| s2-8-struct | projects | normalize_3 | 1362/1395 | 37.3% / 10.9% | 13.0% / 5.1% | 47.6% | 92.0% | 91.9% | 14/14 | 0.0% / 0.0% | 5.58e-04 / 0.00e+00 | 0 | 12 |
| s2-8-struct | projects | normalize_all | 1395/1395 | 0.0% / 0.0% | 0.0% / 0.0% | 0.6% | 77.3% | 77.0% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 41 |
| s2-8-struct | projects | delete_0.25 | 1387/1395 | 77.5% / 23.5% | 30.0% / 12.9% | 86.4% | 77.1% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s2-8-struct | projects | delete_0.5 | 1395/1395 | 48.8% / 10.8% | 12.9% / 5.9% | 66.5% | 53.1% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 0 |
| s2-8-struct | projects | insert_1 | 1395/1395 | 43.9% / 12.2% | 15.1% / 5.6% | 55.1% | 99.3% | 52.7% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 230 |
| s2-8-struct | projects | rename | 1395/1395 | 73.5% / 25.2% | 32.6% / 9.5% | 83.9% | 95.5% | 95.9% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 2 |
| s2-8-struct | projects | reformat | 1079/1395 | 91.4% / 42.4% | 52.4% / 18.2% | 95.2% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 2 |
| s2-8-struct | projects | reorder | 1387/1395 | 90.3% / 41.7% | 51.0% / 19.9% | 94.6% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s2-8-struct | projects | combo | 1395/1395 | 11.7% / 0.9% | 1.2% / 0.1% | 23.7% | 65.3% | 85.6% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 9 |
| s1-8-struct | codenet | flip_0.1 | 3996/3996 | 79.9% / 27.4% | 64.0% / 23.5% | 82.3% | 95.2% | 96.0% | 2573/3511 | 0.0% / 0.0% | 4.71e-05 / 0.00e+00 | 0 | 1412 |
| s1-8-struct | codenet | flip_0.2 | 3996/3996 | 43.8% / 5.5% | 24.1% / 3.7% | 55.7% | 91.0% | 92.4% | 3061/3511 | 0.0% / 0.0% | 4.47e-05 / 0.00e+00 | 0 | 1643 |
| s1-8-struct | codenet | flip_0.3 | 3996/3996 | 12.3% / 0.5% | 3.7% / 0.2% | 26.2% | 87.0% | 89.4% | 3249/3511 | 0.0% / 0.0% | 4.57e-05 / 0.00e+00 | 0 | 1788 |
| s1-8-struct | codenet | normalize_1 | 2961/3996 | 89.8% / 45.4% | 79.5% / 40.8% | 88.4% | 98.8% | 98.8% | 2045/3511 | 0.0% / 0.0% | 3.82e-05 / 0.00e+00 | 0 | 807 |
| s1-8-struct | codenet | normalize_3 | 3931/3996 | 73.2% / 27.3% | 57.9% / 23.5% | 74.9% | 97.5% | 97.5% | 3207/3511 | 0.0% / 0.0% | 4.51e-05 / 0.00e+00 | 0 | 1285 |
| s1-8-struct | codenet | normalize_all | 3996/3996 | 0.1% / 0.0% | 0.0% / 0.0% | 0.4% | 87.0% | 87.0% | 3439/3511 | 0.0% / 0.0% | 4.09e-05 / 0.00e+00 | 0 | 2087 |
| s1-8-struct | codenet | delete_0.25 | 3988/3996 | 95.8% / 49.6% | 91.7% / 47.1% | 97.9% | 84.6% | 100.0% | 1163/3511 | 0.0% / 0.0% | 4.37e-05 / 0.00e+00 | 0 | 818 |
| s1-8-struct | codenet | delete_0.5 | 3996/3996 | 84.7% / 30.3% | 75.1% / 27.7% | 92.9% | 67.7% | 100.0% | 2698/3511 | 0.0% / 0.0% | 1.30e-05 / 0.00e+00 | 0 | 705 |
| s1-8-struct | codenet | insert_1 | 3996/3996 | 43.9% / 7.7% | 22.4% / 4.8% | 43.2% | 85.3% | 50.6% | 3511/3511 | 0.0% / 0.0% | 1.78e-04 / 0.00e+00 | 0 | 2108 |
| s1-8-struct | codenet | rename | 3996/3996 | 75.4% / 30.9% | 60.3% / 28.4% | 81.1% | 98.7% | 100.0% | 3487/3511 | 0.0% / 0.0% | 3.14e-05 / 0.00e+00 | 0 | 1030 |
| s1-8-struct | codenet | reformat | 3965/3996 | 98.8% / 68.2% | 97.3% / 65.7% | 99.2% | 100.0% | 100.0% | 3224/3511 | 0.0% / 0.0% | 4.48e-05 / 0.00e+00 | 0 | 1038 |
| s1-8-struct | codenet | reorder | 3988/3996 | 98.8% / 68.4% | 97.4% / 65.9% | 99.2% | 100.0% | 100.0% | 1161/3511 | 0.1% / 0.0% | 7.40e-05 / 0.00e+00 | 0 | 965 |
| s1-8-struct | codenet | combo | 3996/3996 | 22.4% / 2.1% | 10.1% / 1.3% | 37.4% | 76.6% | 92.8% | 3501/3511 | 0.0% / 0.0% | 2.90e-05 / 0.00e+00 | 0 | 1490 |
| s1-8-struct | projects | flip_0.1 | 1361/1395 | 20.9% / 3.1% | 10.6% / 2.1% | 40.6% | 93.4% | 93.9% | 14/14 | 0.0% / 0.0% | 8.37e-04 / 0.00e+00 | 0 | 7 |
| s1-8-struct | projects | flip_0.2 | 1392/1395 | 7.5% / 0.3% | 2.7% / 0.1% | 19.4% | 87.9% | 89.0% | 14/14 | 0.0% / 0.0% | 5.58e-04 / 0.00e+00 | 0 | 14 |
| s1-8-struct | projects | flip_0.3 | 1393/1395 | 1.9% / 0.0% | 0.4% / 0.0% | 8.5% | 83.0% | 84.5% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 16 |
| s1-8-struct | projects | normalize_1 | 965/1395 | 28.5% / 6.6% | 17.8% / 6.1% | 46.3% | 95.6% | 95.6% | 5/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 10 |
| s1-8-struct | projects | normalize_3 | 1361/1395 | 15.1% / 2.9% | 8.0% / 2.4% | 27.0% | 92.2% | 92.0% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 12 |
| s1-8-struct | projects | normalize_all | 1395/1395 | 0.0% / 0.0% | 0.0% / 0.0% | 0.6% | 77.3% | 77.0% | 14/14 | 0.0% / 0.0% | 1.12e-03 / 0.00e+00 | 0 | 41 |
| s1-8-struct | projects | delete_0.25 | 1387/1395 | 26.3% / 6.3% | 17.5% / 5.8% | 54.1% | 77.1% | 100.0% | 9/14 | 0.0% / 0.0% | 8.68e-04 / 0.00e+00 | 0 | 2 |
| s1-8-struct | projects | delete_0.5 | 1395/1395 | 12.8% / 2.3% | 8.1% / 2.2% | 33.3% | 53.1% | 100.0% | 9/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 0 |
| s1-8-struct | projects | insert_1 | 1395/1395 | 19.8% / 3.9% | 7.9% / 2.4% | 28.0% | 99.2% | 52.8% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 228 |
| s1-8-struct | projects | rename | 1395/1395 | 27.9% / 4.6% | 15.8% / 3.7% | 50.5% | 95.5% | 95.9% | 14/14 | 0.0% / 0.0% | 0.00e+00 / 0.00e+00 | 0 | 2 |
| s1-8-struct | projects | reformat | 1079/1395 | 41.6% / 8.7% | 27.6% / 8.0% | 69.2% | 100.0% | 100.0% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 2 |
| s1-8-struct | projects | reorder | 1387/1395 | 41.4% / 11.0% | 28.3% / 10.2% | 68.0% | 100.0% | 100.0% | 9/14 | 0.0% / 0.0% | 4.34e-04 / 0.00e+00 | 0 | 2 |
| s1-8-struct | projects | combo | 1395/1395 | 2.4% / 0.0% | 0.5% / 0.0% | 9.8% | 65.0% | 85.6% | 14/14 | 0.0% / 0.0% | 2.79e-04 / 0.00e+00 | 0 | 9 |
| bch-file | codenet | flip_0.1 | 3996/3996 | 32.5% | N/A | 32.5% | N/A | N/A | 2573/3511 | 6.6% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | flip_0.2 | 3996/3996 | 17.3% | N/A | 17.3% | N/A | N/A | 3061/3511 | 6.3% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | flip_0.3 | 3996/3996 | 11.5% | N/A | 11.5% | N/A | N/A | 3249/3511 | 6.6% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | normalize_1 | 2157/3996 | 99.4% | N/A | 99.4% | N/A | N/A | 2045/3511 | 6.2% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | normalize_3 | 3630/3996 | 86.6% | N/A | 86.6% | N/A | N/A | 3207/3511 | 5.6% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | normalize_all | 3995/3996 | 6.4% | N/A | 6.4% | N/A | N/A | 3439/3511 | 5.8% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | delete_0.25 | 3988/3996 | 98.0% | N/A | 98.0% | N/A | N/A | 1163/3511 | 5.8% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | delete_0.5 | 3996/3996 | 94.4% | N/A | 94.4% | N/A | N/A | 2698/3511 | 7.0% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | insert_1 | 3996/3996 | 25.8% | N/A | 25.8% | N/A | N/A | 3511/3511 | 5.8% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | rename | 3996/3996 | 85.6% | N/A | 85.6% | N/A | N/A | 3487/3511 | 6.3% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | reformat | 3965/3996 | 99.9% | N/A | 99.9% | N/A | N/A | 3224/3511 | 6.4% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | reorder | 3988/3996 | 99.9% | N/A | 99.9% | N/A | N/A | 1161/3511 | 6.2% | 6.25e-02 | 0 | 0 |
| bch-file | codenet | combo | 3996/3996 | 14.5% | N/A | 14.5% | N/A | N/A | 3501/3511 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-file | projects | flip_0.1 | 1360/1393 | 82.3% | N/A | 82.3% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-file | projects | flip_0.2 | 1390/1393 | 58.2% | N/A | 58.2% | N/A | N/A | 14/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-file | projects | flip_0.3 | 1391/1393 | 39.0% | N/A | 39.0% | N/A | N/A | 14/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-file | projects | normalize_1 | 949/1393 | 91.6% | N/A | 91.6% | N/A | N/A | 5/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-file | projects | normalize_3 | 1349/1393 | 68.1% | N/A | 68.1% | N/A | N/A | 14/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-file | projects | normalize_all | 1393/1393 | 6.5% | N/A | 6.5% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-file | projects | delete_0.25 | 1385/1393 | 41.2% | N/A | 41.2% | N/A | N/A | 9/14 | 11.1% | 6.25e-02 | 815 | 0 |
| bch-file | projects | delete_0.5 | 1393/1393 | 13.9% | N/A | 13.9% | N/A | N/A | 9/14 | 11.1% | 6.25e-02 | 1191 | 0 |
| bch-file | projects | insert_1 | 1393/1393 | 99.5% | N/A | 99.5% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-file | projects | rename | 1393/1393 | 98.6% | N/A | 98.6% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-file | projects | reformat | 1093/1393 | 99.9% | N/A | 99.9% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-file | projects | reorder | 1385/1393 | 10.0% | N/A | 10.0% | N/A | N/A | 9/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-file | projects | combo | 1393/1393 | 23.4% | N/A | 23.4% | N/A | N/A | 14/14 | 0.0% | 6.25e-02 | 790 | 0 |
| bch-node | codenet | flip_0.1 | 3996/3996 | 85.2% | N/A | 85.2% | N/A | N/A | 2573/3511 | 6.6% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | flip_0.2 | 3996/3996 | 55.8% | N/A | 55.8% | N/A | N/A | 3061/3511 | 6.6% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | flip_0.3 | 3996/3996 | 31.8% | N/A | 31.8% | N/A | N/A | 3249/3511 | 5.7% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | normalize_1 | 2706/3996 | 99.7% | N/A | 99.7% | N/A | N/A | 2045/3511 | 5.9% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | normalize_3 | 3872/3996 | 86.7% | N/A | 86.7% | N/A | N/A | 3207/3511 | 6.6% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | normalize_all | 3996/3996 | 7.2% | N/A | 7.2% | N/A | N/A | 3439/3511 | 6.4% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | delete_0.25 | 3988/3996 | 84.7% | N/A | 84.7% | N/A | N/A | 1163/3511 | 7.0% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | delete_0.5 | 3996/3996 | 66.2% | N/A | 66.2% | N/A | N/A | 2698/3511 | 6.4% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | insert_1 | 3996/3996 | 85.7% | N/A | 85.7% | N/A | N/A | 3511/3511 | 6.5% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | rename | 3996/3996 | 89.8% | N/A | 89.8% | N/A | N/A | 3487/3511 | 7.0% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | reformat | 3965/3996 | 100.0% | N/A | 100.0% | N/A | N/A | 3224/3511 | 6.8% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | reorder | 3988/3996 | 53.6% | N/A | 53.6% | N/A | N/A | 1161/3511 | 7.4% | 6.25e-02 | 0 | 0 |
| bch-node | codenet | combo | 3996/3996 | 36.3% | N/A | 36.3% | N/A | N/A | 3501/3511 | 6.1% | 6.25e-02 | 0 | 0 |
| bch-node | projects | flip_0.1 | 1358/1392 | 83.9% | N/A | 83.9% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-node | projects | flip_0.2 | 1389/1392 | 55.1% | N/A | 55.1% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-node | projects | flip_0.3 | 1391/1392 | 32.9% | N/A | 32.9% | N/A | N/A | 14/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-node | projects | normalize_1 | 969/1392 | 87.7% | N/A | 87.7% | N/A | N/A | 5/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-node | projects | normalize_3 | 1362/1392 | 64.4% | N/A | 64.4% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-node | projects | normalize_all | 1392/1392 | 6.2% | N/A | 6.2% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 0 | 0 |
| bch-node | projects | delete_0.25 | 1384/1392 | 31.6% | N/A | 31.6% | N/A | N/A | 9/14 | 11.1% | 6.25e-02 | 947 | 0 |
| bch-node | projects | delete_0.5 | 1392/1392 | 7.0% | N/A | 7.0% | N/A | N/A | 9/14 | 11.1% | 6.25e-02 | 1287 | 0 |
| bch-node | projects | insert_1 | 1392/1392 | 99.9% | N/A | 99.9% | N/A | N/A | 14/14 | 14.3% | 6.25e-02 | 0 | 0 |
| bch-node | projects | rename | 1392/1392 | 99.6% | N/A | 99.6% | N/A | N/A | 14/14 | 21.4% | 6.25e-02 | 0 | 0 |
| bch-node | projects | reformat | 1094/1392 | 100.0% | N/A | 100.0% | N/A | N/A | 14/14 | 14.3% | 6.25e-02 | 0 | 0 |
| bch-node | projects | reorder | 1384/1392 | 11.3% | N/A | 11.3% | N/A | N/A | 9/14 | 0.0% | 6.25e-02 | 0 | 0 |
| bch-node | projects | combo | 1392/1392 | 17.0% | N/A | 17.0% | N/A | N/A | 14/14 | 7.1% | 6.25e-02 | 945 | 0 |

AUC (CodeNet, p-values of known-message detection, marked vs hand-written) under each attack:

| variant | none | flip_0.1 | flip_0.2 | flip_0.3 | normalize_1 | normalize_3 | normalize_all | delete_0.25 | delete_0.5 | insert_1 | rename | reformat | reorder | combo |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| s2-4-tok | 1.0000 | 1.0000 | 0.9998 | 0.9956 | 1.0000 | 0.9999 | 0.5992 | 1.0000 | 1.0000 | 0.9947 | 0.8121 | 1.0000 | 1.0000 | 0.7513 |
| s1-4-tok | 1.0000 | 0.9997 | 0.9978 | 0.9815 | 0.9999 | 0.9990 | 0.6484 | 0.9999 | 0.9999 | 0.9867 | 0.8047 | 1.0000 | 1.0000 | 0.7721 |
| s2-4-struct | 1.0000 | 1.0000 | 0.9994 | 0.9894 | 1.0000 | 0.9995 | 0.6018 | 1.0000 | 1.0000 | 0.9932 | 1.0000 | 1.0000 | 1.0000 | 0.9948 |
| s1-4-struct | 1.0000 | 0.9995 | 0.9931 | 0.9634 | 0.9998 | 0.9977 | 0.6637 | 0.9999 | 0.9997 | 0.9795 | 0.9992 | 1.0000 | 1.0000 | 0.9762 |
| s2-8-tok | 1.0000 | 1.0000 | 0.9997 | 0.9959 | 1.0000 | 0.9999 | 0.5945 | 1.0000 | 1.0000 | 0.9952 | 0.8037 | 1.0000 | 1.0000 | 0.7629 |
| s1-8-tok | 1.0000 | 0.9998 | 0.9980 | 0.9810 | 1.0000 | 0.9993 | 0.6476 | 1.0000 | 0.9998 | 0.9870 | 0.8018 | 1.0000 | 1.0000 | 0.7643 |
| s2-8-struct | 1.0000 | 1.0000 | 0.9992 | 0.9896 | 0.9999 | 0.9995 | 0.6003 | 1.0000 | 1.0000 | 0.9939 | 1.0000 | 1.0000 | 1.0000 | 0.9944 |
| s1-8-struct | 1.0000 | 0.9993 | 0.9929 | 0.9615 | 0.9994 | 0.9974 | 0.6661 | 0.9999 | 0.9996 | 0.9774 | 0.9991 | 1.0000 | 1.0000 | 0.9740 |
| bch-file | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| bch-node | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |

`normalize_all` sets every public rule pair to a random side and so erases all style evidence: after whitening it is equivalent to flipping half of the bits at random. It is reported as it is and is not a pass condition.


## 8. Stable sites per rule pair

Share of usable sites whose anchor key survives the self-stability check (the unstable ones are neither embedded nor read), summed over all units of the language.

| variant | language | rule pair | usable | stable | stable share |
|---|---|---|---|---|---|
| s2-4-tok | python | branch_order | 380 | 380 | 100.0% |
| s2-4-tok | python | conditional_order | 420 | 420 | 100.0% |
| s2-4-tok | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s2-4-tok | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-4-tok | python | exp_cmp | 15064 | 15064 | 100.0% |
| s2-4-tok | python | f_string | 15578 | 15578 | 100.0% |
| s2-4-tok | python | identity_negation | 473 | 473 | 100.0% |
| s2-4-tok | python | init_list | 5691 | 5691 | 100.0% |
| s2-4-tok | python | list | 4787 | 4787 | 100.0% |
| s2-4-tok | python | loop_exit | 12774 | 12732 | 99.7% |
| s2-4-tok | python | membership_negation | 282 | 282 | 100.0% |
| s2-4-tok | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s2-4-tok | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s2-4-tok | python | print_flush | 4986 | 4894 | 98.2% |
| s2-4-tok | python | return | 1375 | 1375 | 100.0% |
| s2-4-tok | python | return_none | 2846 | 2846 | 100.0% |
| s2-4-tok | python | reverse_compare | 12225 | 12225 | 100.0% |
| s2-4-tok | python | self_assignment | 14470 | 14464 | 100.0% |
| s2-4-tok | c | array_access | 29123 | 28854 | 99.1% |
| s2-4-tok | c | array_init | 3303 | 2464 | 74.6% |
| s2-4-tok | c | array_parameter | 10786 | 10786 | 100.0% |
| s2-4-tok | c | branch_order | 1343 | 1343 | 100.0% |
| s2-4-tok | c | conditional_order | 2082 | 2082 | 100.0% |
| s2-4-tok | c | equal_hash_reverse | 14549 | 14549 | 100.0% |
| s2-4-tok | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-4-tok | c | exp_cmp | 45565 | 45565 | 100.0% |
| s2-4-tok | c | member_access | 18479 | 18471 | 100.0% |
| s2-4-tok | c | nested_condition | 1889 | 1889 | 100.0% |
| s2-4-tok | c | not_equal_hash_reverse | 5837 | 5837 | 100.0% |
| s2-4-tok | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s2-4-tok | c | reverse_compare | 825 | 825 | 100.0% |
| s2-4-tok | c | self_assignment | 24176 | 24176 | 100.0% |
| s2-4-tok | c | update_reverse | 10367 | 10367 | 100.0% |
| s2-4-tok | c | void_return | 4003 | 4003 | 100.0% |
| s2-4-tok | cpp | branch_order | 966 | 966 | 100.0% |
| s2-4-tok | cpp | cast_style | 6250 | 6248 | 100.0% |
| s2-4-tok | cpp | conditional_order | 1994 | 1994 | 100.0% |
| s2-4-tok | cpp | equal_hash_reverse | 11388 | 11388 | 100.0% |
| s2-4-tok | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-4-tok | cpp | exp_cmp | 14969 | 14940 | 99.8% |
| s2-4-tok | cpp | for_OOO | 8200 | 7166 | 87.4% |
| s2-4-tok | cpp | nested_condition | 1403 | 1403 | 100.0% |
| s2-4-tok | cpp | not_equal_hash_reverse | 4801 | 4801 | 100.0% |
| s2-4-tok | cpp | not_equal_to_equal | 24 | 24 | 100.0% |
| s2-4-tok | cpp | reverse_compare | 17038 | 16981 | 99.7% |
| s2-4-tok | cpp | self_assignment | 14434 | 14346 | 99.4% |
| s2-4-tok | cpp | update_reverse | 6051 | 6049 | 100.0% |
| s2-4-tok | cpp | void_return | 8635 | 8635 | 100.0% |
| s2-4-tok | javascript | arrow_body | 156 | 156 | 100.0% |
| s2-4-tok | javascript | branch_order | 1347 | 1347 | 100.0% |
| s2-4-tok | javascript | conditional_order | 3486 | 3486 | 100.0% |
| s2-4-tok | javascript | const_let | 12011 | 12007 | 100.0% |
| s2-4-tok | javascript | empty_array | 4759 | 4759 | 100.0% |
| s2-4-tok | javascript | empty_object | 129 | 129 | 100.0% |
| s2-4-tok | javascript | equal_hash_reverse | 8022 | 8022 | 100.0% |
| s2-4-tok | javascript | equal_to_not_equal | 4945 | 4945 | 100.0% |
| s2-4-tok | javascript | function_arrow | 71 | 71 | 100.0% |
| s2-4-tok | javascript | loop_form | 9881 | 9880 | 100.0% |
| s2-4-tok | javascript | member_access | 81606 | 81606 | 100.0% |
| s2-4-tok | javascript | nested_condition | 1838 | 1835 | 99.8% |
| s2-4-tok | javascript | not_equal_hash_reverse | 2040 | 2040 | 100.0% |
| s2-4-tok | javascript | not_equal_to_equal | 2648 | 2648 | 100.0% |
| s2-4-tok | javascript | reverse_compare | 13257 | 13257 | 100.0% |
| s2-4-tok | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s2-4-tok | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s2-4-tok | javascript | void_return | 6798 | 6788 | 99.9% |
| s1-4-tok | python | branch_order | 380 | 380 | 100.0% |
| s1-4-tok | python | conditional_order | 420 | 420 | 100.0% |
| s1-4-tok | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s1-4-tok | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-4-tok | python | exp_cmp | 15064 | 15064 | 100.0% |
| s1-4-tok | python | f_string | 15578 | 15578 | 100.0% |
| s1-4-tok | python | identity_negation | 473 | 473 | 100.0% |
| s1-4-tok | python | init_list | 5691 | 5691 | 100.0% |
| s1-4-tok | python | list | 4787 | 4787 | 100.0% |
| s1-4-tok | python | loop_exit | 12774 | 12732 | 99.7% |
| s1-4-tok | python | membership_negation | 282 | 282 | 100.0% |
| s1-4-tok | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s1-4-tok | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s1-4-tok | python | print_flush | 4986 | 4894 | 98.2% |
| s1-4-tok | python | return | 1375 | 1375 | 100.0% |
| s1-4-tok | python | return_none | 2846 | 2846 | 100.0% |
| s1-4-tok | python | reverse_compare | 12225 | 12225 | 100.0% |
| s1-4-tok | python | self_assignment | 14470 | 14464 | 100.0% |
| s1-4-tok | c | array_access | 29123 | 28854 | 99.1% |
| s1-4-tok | c | array_init | 3303 | 2464 | 74.6% |
| s1-4-tok | c | array_parameter | 10786 | 10786 | 100.0% |
| s1-4-tok | c | branch_order | 1343 | 1343 | 100.0% |
| s1-4-tok | c | conditional_order | 2082 | 2082 | 100.0% |
| s1-4-tok | c | equal_hash_reverse | 14549 | 14549 | 100.0% |
| s1-4-tok | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-4-tok | c | exp_cmp | 45565 | 45565 | 100.0% |
| s1-4-tok | c | member_access | 18479 | 18471 | 100.0% |
| s1-4-tok | c | nested_condition | 1889 | 1889 | 100.0% |
| s1-4-tok | c | not_equal_hash_reverse | 5837 | 5837 | 100.0% |
| s1-4-tok | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s1-4-tok | c | reverse_compare | 825 | 825 | 100.0% |
| s1-4-tok | c | self_assignment | 24176 | 24176 | 100.0% |
| s1-4-tok | c | update_reverse | 10367 | 10367 | 100.0% |
| s1-4-tok | c | void_return | 4003 | 4003 | 100.0% |
| s1-4-tok | cpp | branch_order | 966 | 966 | 100.0% |
| s1-4-tok | cpp | cast_style | 6250 | 6248 | 100.0% |
| s1-4-tok | cpp | conditional_order | 1994 | 1994 | 100.0% |
| s1-4-tok | cpp | equal_hash_reverse | 11388 | 11388 | 100.0% |
| s1-4-tok | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-4-tok | cpp | exp_cmp | 14969 | 14940 | 99.8% |
| s1-4-tok | cpp | for_OOO | 8200 | 7166 | 87.4% |
| s1-4-tok | cpp | nested_condition | 1403 | 1403 | 100.0% |
| s1-4-tok | cpp | not_equal_hash_reverse | 4801 | 4801 | 100.0% |
| s1-4-tok | cpp | not_equal_to_equal | 24 | 24 | 100.0% |
| s1-4-tok | cpp | reverse_compare | 17038 | 16981 | 99.7% |
| s1-4-tok | cpp | self_assignment | 14434 | 14346 | 99.4% |
| s1-4-tok | cpp | update_reverse | 6051 | 6049 | 100.0% |
| s1-4-tok | cpp | void_return | 8635 | 8635 | 100.0% |
| s1-4-tok | javascript | arrow_body | 156 | 156 | 100.0% |
| s1-4-tok | javascript | branch_order | 1347 | 1347 | 100.0% |
| s1-4-tok | javascript | conditional_order | 3486 | 3486 | 100.0% |
| s1-4-tok | javascript | const_let | 12011 | 12007 | 100.0% |
| s1-4-tok | javascript | empty_array | 4759 | 4759 | 100.0% |
| s1-4-tok | javascript | empty_object | 129 | 129 | 100.0% |
| s1-4-tok | javascript | equal_hash_reverse | 8022 | 8022 | 100.0% |
| s1-4-tok | javascript | equal_to_not_equal | 4945 | 4945 | 100.0% |
| s1-4-tok | javascript | function_arrow | 71 | 71 | 100.0% |
| s1-4-tok | javascript | loop_form | 9881 | 9880 | 100.0% |
| s1-4-tok | javascript | member_access | 81606 | 81606 | 100.0% |
| s1-4-tok | javascript | nested_condition | 1838 | 1835 | 99.8% |
| s1-4-tok | javascript | not_equal_hash_reverse | 2040 | 2040 | 100.0% |
| s1-4-tok | javascript | not_equal_to_equal | 2648 | 2648 | 100.0% |
| s1-4-tok | javascript | reverse_compare | 13257 | 13257 | 100.0% |
| s1-4-tok | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s1-4-tok | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s1-4-tok | javascript | void_return | 6798 | 6788 | 99.9% |
| s2-4-struct | python | branch_order | 380 | 380 | 100.0% |
| s2-4-struct | python | conditional_order | 420 | 420 | 100.0% |
| s2-4-struct | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s2-4-struct | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-4-struct | python | exp_cmp | 15064 | 15064 | 100.0% |
| s2-4-struct | python | f_string | 15578 | 15578 | 100.0% |
| s2-4-struct | python | identity_negation | 473 | 473 | 100.0% |
| s2-4-struct | python | init_list | 5691 | 5691 | 100.0% |
| s2-4-struct | python | list | 4787 | 4787 | 100.0% |
| s2-4-struct | python | loop_exit | 12774 | 12728 | 99.6% |
| s2-4-struct | python | membership_negation | 282 | 282 | 100.0% |
| s2-4-struct | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s2-4-struct | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s2-4-struct | python | print_end | 4985 | 4893 | 98.2% |
| s2-4-struct | python | print_flush | 1 | 1 | 100.0% |
| s2-4-struct | python | return | 1375 | 1375 | 100.0% |
| s2-4-struct | python | return_none | 2846 | 2846 | 100.0% |
| s2-4-struct | python | reverse_compare | 12225 | 12225 | 100.0% |
| s2-4-struct | python | self_assignment | 14470 | 14464 | 100.0% |
| s2-4-struct | c | array_parameter | 10786 | 10786 | 100.0% |
| s2-4-struct | c | branch_order | 1343 | 1343 | 100.0% |
| s2-4-struct | c | conditional_order | 2084 | 2084 | 100.0% |
| s2-4-struct | c | equal_hash_reverse | 15174 | 15174 | 100.0% |
| s2-4-struct | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-4-struct | c | exp_cmp | 48133 | 48133 | 100.0% |
| s2-4-struct | c | member_access | 18480 | 18472 | 100.0% |
| s2-4-struct | c | not_equal_hash_reverse | 6106 | 6106 | 100.0% |
| s2-4-struct | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s2-4-struct | c | reverse_compare | 858 | 858 | 100.0% |
| s2-4-struct | c | self_assignment | 24176 | 24176 | 100.0% |
| s2-4-struct | c | update_reverse | 10367 | 10367 | 100.0% |
| s2-4-struct | c | void_return | 4003 | 4003 | 100.0% |
| s2-4-struct | cpp | branch_order | 1161 | 1160 | 99.9% |
| s2-4-struct | cpp | cast_style | 7091 | 7089 | 100.0% |
| s2-4-struct | cpp | conditional_order | 2401 | 2401 | 100.0% |
| s2-4-struct | cpp | equal_hash_reverse | 13490 | 13490 | 100.0% |
| s2-4-struct | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-4-struct | cpp | exp_cmp | 18872 | 18845 | 99.9% |
| s2-4-struct | cpp | not_equal_hash_reverse | 5875 | 5875 | 100.0% |
| s2-4-struct | cpp | not_equal_to_equal | 30 | 30 | 100.0% |
| s2-4-struct | cpp | reverse_compare | 29976 | 29888 | 99.7% |
| s2-4-struct | cpp | self_assignment | 20353 | 20180 | 99.2% |
| s2-4-struct | cpp | update_reverse | 13660 | 13660 | 100.0% |
| s2-4-struct | cpp | void_return | 8635 | 8630 | 99.9% |
| s2-4-struct | javascript | branch_order | 1349 | 1349 | 100.0% |
| s2-4-struct | javascript | conditional_order | 3496 | 3496 | 100.0% |
| s2-4-struct | javascript | const_let | 12011 | 12006 | 100.0% |
| s2-4-struct | javascript | equal_hash_reverse | 8268 | 8268 | 100.0% |
| s2-4-struct | javascript | equal_to_not_equal | 5253 | 5253 | 100.0% |
| s2-4-struct | javascript | loop_form | 9881 | 9873 | 99.9% |
| s2-4-struct | javascript | member_access | 81748 | 81747 | 100.0% |
| s2-4-struct | javascript | not_equal_hash_reverse | 2251 | 2251 | 100.0% |
| s2-4-struct | javascript | not_equal_to_equal | 2772 | 2772 | 100.0% |
| s2-4-struct | javascript | reverse_compare | 14686 | 14686 | 100.0% |
| s2-4-struct | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s2-4-struct | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s2-4-struct | javascript | void_return | 6798 | 6780 | 99.7% |
| s1-4-struct | python | branch_order | 380 | 380 | 100.0% |
| s1-4-struct | python | conditional_order | 420 | 420 | 100.0% |
| s1-4-struct | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s1-4-struct | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-4-struct | python | exp_cmp | 15064 | 15064 | 100.0% |
| s1-4-struct | python | f_string | 15578 | 15578 | 100.0% |
| s1-4-struct | python | identity_negation | 473 | 473 | 100.0% |
| s1-4-struct | python | init_list | 5691 | 5691 | 100.0% |
| s1-4-struct | python | list | 4787 | 4787 | 100.0% |
| s1-4-struct | python | loop_exit | 12774 | 12728 | 99.6% |
| s1-4-struct | python | membership_negation | 282 | 282 | 100.0% |
| s1-4-struct | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s1-4-struct | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s1-4-struct | python | print_end | 4985 | 4893 | 98.2% |
| s1-4-struct | python | print_flush | 1 | 1 | 100.0% |
| s1-4-struct | python | return | 1375 | 1375 | 100.0% |
| s1-4-struct | python | return_none | 2846 | 2846 | 100.0% |
| s1-4-struct | python | reverse_compare | 12225 | 12225 | 100.0% |
| s1-4-struct | python | self_assignment | 14470 | 14464 | 100.0% |
| s1-4-struct | c | array_parameter | 10786 | 10786 | 100.0% |
| s1-4-struct | c | branch_order | 1343 | 1343 | 100.0% |
| s1-4-struct | c | conditional_order | 2084 | 2084 | 100.0% |
| s1-4-struct | c | equal_hash_reverse | 15174 | 15174 | 100.0% |
| s1-4-struct | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-4-struct | c | exp_cmp | 48133 | 48133 | 100.0% |
| s1-4-struct | c | member_access | 18480 | 18472 | 100.0% |
| s1-4-struct | c | not_equal_hash_reverse | 6106 | 6106 | 100.0% |
| s1-4-struct | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s1-4-struct | c | reverse_compare | 858 | 858 | 100.0% |
| s1-4-struct | c | self_assignment | 24176 | 24176 | 100.0% |
| s1-4-struct | c | update_reverse | 10367 | 10367 | 100.0% |
| s1-4-struct | c | void_return | 4003 | 4003 | 100.0% |
| s1-4-struct | cpp | branch_order | 1161 | 1160 | 99.9% |
| s1-4-struct | cpp | cast_style | 7091 | 7089 | 100.0% |
| s1-4-struct | cpp | conditional_order | 2401 | 2401 | 100.0% |
| s1-4-struct | cpp | equal_hash_reverse | 13490 | 13490 | 100.0% |
| s1-4-struct | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-4-struct | cpp | exp_cmp | 18872 | 18845 | 99.9% |
| s1-4-struct | cpp | not_equal_hash_reverse | 5875 | 5875 | 100.0% |
| s1-4-struct | cpp | not_equal_to_equal | 30 | 30 | 100.0% |
| s1-4-struct | cpp | reverse_compare | 29976 | 29888 | 99.7% |
| s1-4-struct | cpp | self_assignment | 20353 | 20180 | 99.2% |
| s1-4-struct | cpp | update_reverse | 13660 | 13660 | 100.0% |
| s1-4-struct | cpp | void_return | 8635 | 8630 | 99.9% |
| s1-4-struct | javascript | branch_order | 1349 | 1349 | 100.0% |
| s1-4-struct | javascript | conditional_order | 3496 | 3496 | 100.0% |
| s1-4-struct | javascript | const_let | 12011 | 12006 | 100.0% |
| s1-4-struct | javascript | equal_hash_reverse | 8268 | 8268 | 100.0% |
| s1-4-struct | javascript | equal_to_not_equal | 5253 | 5253 | 100.0% |
| s1-4-struct | javascript | loop_form | 9881 | 9873 | 99.9% |
| s1-4-struct | javascript | member_access | 81748 | 81747 | 100.0% |
| s1-4-struct | javascript | not_equal_hash_reverse | 2251 | 2251 | 100.0% |
| s1-4-struct | javascript | not_equal_to_equal | 2772 | 2772 | 100.0% |
| s1-4-struct | javascript | reverse_compare | 14686 | 14686 | 100.0% |
| s1-4-struct | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s1-4-struct | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s1-4-struct | javascript | void_return | 6798 | 6780 | 99.7% |
| s2-8-tok | python | branch_order | 380 | 380 | 100.0% |
| s2-8-tok | python | conditional_order | 420 | 420 | 100.0% |
| s2-8-tok | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s2-8-tok | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-8-tok | python | exp_cmp | 15064 | 15064 | 100.0% |
| s2-8-tok | python | f_string | 15578 | 15578 | 100.0% |
| s2-8-tok | python | identity_negation | 473 | 473 | 100.0% |
| s2-8-tok | python | init_list | 5691 | 5691 | 100.0% |
| s2-8-tok | python | list | 4787 | 4787 | 100.0% |
| s2-8-tok | python | loop_exit | 12774 | 12732 | 99.7% |
| s2-8-tok | python | membership_negation | 282 | 282 | 100.0% |
| s2-8-tok | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s2-8-tok | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s2-8-tok | python | print_flush | 4986 | 4894 | 98.2% |
| s2-8-tok | python | return | 1375 | 1375 | 100.0% |
| s2-8-tok | python | return_none | 2846 | 2846 | 100.0% |
| s2-8-tok | python | reverse_compare | 12225 | 12225 | 100.0% |
| s2-8-tok | python | self_assignment | 14470 | 14464 | 100.0% |
| s2-8-tok | c | array_access | 29123 | 28854 | 99.1% |
| s2-8-tok | c | array_init | 3303 | 2464 | 74.6% |
| s2-8-tok | c | array_parameter | 10786 | 10786 | 100.0% |
| s2-8-tok | c | branch_order | 1343 | 1343 | 100.0% |
| s2-8-tok | c | conditional_order | 2082 | 2082 | 100.0% |
| s2-8-tok | c | equal_hash_reverse | 14549 | 14549 | 100.0% |
| s2-8-tok | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-8-tok | c | exp_cmp | 45565 | 45565 | 100.0% |
| s2-8-tok | c | member_access | 18479 | 18471 | 100.0% |
| s2-8-tok | c | nested_condition | 1889 | 1889 | 100.0% |
| s2-8-tok | c | not_equal_hash_reverse | 5837 | 5837 | 100.0% |
| s2-8-tok | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s2-8-tok | c | reverse_compare | 825 | 825 | 100.0% |
| s2-8-tok | c | self_assignment | 24176 | 24176 | 100.0% |
| s2-8-tok | c | update_reverse | 10367 | 10367 | 100.0% |
| s2-8-tok | c | void_return | 4003 | 4003 | 100.0% |
| s2-8-tok | cpp | branch_order | 966 | 966 | 100.0% |
| s2-8-tok | cpp | cast_style | 6250 | 6248 | 100.0% |
| s2-8-tok | cpp | conditional_order | 1994 | 1994 | 100.0% |
| s2-8-tok | cpp | equal_hash_reverse | 11388 | 11388 | 100.0% |
| s2-8-tok | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-8-tok | cpp | exp_cmp | 14969 | 14940 | 99.8% |
| s2-8-tok | cpp | for_OOO | 8200 | 7166 | 87.4% |
| s2-8-tok | cpp | nested_condition | 1403 | 1403 | 100.0% |
| s2-8-tok | cpp | not_equal_hash_reverse | 4801 | 4801 | 100.0% |
| s2-8-tok | cpp | not_equal_to_equal | 24 | 24 | 100.0% |
| s2-8-tok | cpp | reverse_compare | 17038 | 16981 | 99.7% |
| s2-8-tok | cpp | self_assignment | 14434 | 14346 | 99.4% |
| s2-8-tok | cpp | update_reverse | 6051 | 6049 | 100.0% |
| s2-8-tok | cpp | void_return | 8635 | 8635 | 100.0% |
| s2-8-tok | javascript | arrow_body | 156 | 156 | 100.0% |
| s2-8-tok | javascript | branch_order | 1347 | 1347 | 100.0% |
| s2-8-tok | javascript | conditional_order | 3486 | 3486 | 100.0% |
| s2-8-tok | javascript | const_let | 12011 | 12007 | 100.0% |
| s2-8-tok | javascript | empty_array | 4759 | 4759 | 100.0% |
| s2-8-tok | javascript | empty_object | 129 | 129 | 100.0% |
| s2-8-tok | javascript | equal_hash_reverse | 8022 | 8022 | 100.0% |
| s2-8-tok | javascript | equal_to_not_equal | 4945 | 4945 | 100.0% |
| s2-8-tok | javascript | function_arrow | 71 | 71 | 100.0% |
| s2-8-tok | javascript | loop_form | 9881 | 9880 | 100.0% |
| s2-8-tok | javascript | member_access | 81606 | 81606 | 100.0% |
| s2-8-tok | javascript | nested_condition | 1838 | 1835 | 99.8% |
| s2-8-tok | javascript | not_equal_hash_reverse | 2040 | 2040 | 100.0% |
| s2-8-tok | javascript | not_equal_to_equal | 2648 | 2648 | 100.0% |
| s2-8-tok | javascript | reverse_compare | 13257 | 13257 | 100.0% |
| s2-8-tok | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s2-8-tok | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s2-8-tok | javascript | void_return | 6798 | 6788 | 99.9% |
| s1-8-tok | python | branch_order | 380 | 380 | 100.0% |
| s1-8-tok | python | conditional_order | 420 | 420 | 100.0% |
| s1-8-tok | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s1-8-tok | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-8-tok | python | exp_cmp | 15064 | 15064 | 100.0% |
| s1-8-tok | python | f_string | 15578 | 15578 | 100.0% |
| s1-8-tok | python | identity_negation | 473 | 473 | 100.0% |
| s1-8-tok | python | init_list | 5691 | 5691 | 100.0% |
| s1-8-tok | python | list | 4787 | 4787 | 100.0% |
| s1-8-tok | python | loop_exit | 12774 | 12732 | 99.7% |
| s1-8-tok | python | membership_negation | 282 | 282 | 100.0% |
| s1-8-tok | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s1-8-tok | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s1-8-tok | python | print_flush | 4986 | 4894 | 98.2% |
| s1-8-tok | python | return | 1375 | 1375 | 100.0% |
| s1-8-tok | python | return_none | 2846 | 2846 | 100.0% |
| s1-8-tok | python | reverse_compare | 12225 | 12225 | 100.0% |
| s1-8-tok | python | self_assignment | 14470 | 14464 | 100.0% |
| s1-8-tok | c | array_access | 29123 | 28854 | 99.1% |
| s1-8-tok | c | array_init | 3303 | 2464 | 74.6% |
| s1-8-tok | c | array_parameter | 10786 | 10786 | 100.0% |
| s1-8-tok | c | branch_order | 1343 | 1343 | 100.0% |
| s1-8-tok | c | conditional_order | 2082 | 2082 | 100.0% |
| s1-8-tok | c | equal_hash_reverse | 14549 | 14549 | 100.0% |
| s1-8-tok | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-8-tok | c | exp_cmp | 45565 | 45565 | 100.0% |
| s1-8-tok | c | member_access | 18479 | 18471 | 100.0% |
| s1-8-tok | c | nested_condition | 1889 | 1889 | 100.0% |
| s1-8-tok | c | not_equal_hash_reverse | 5837 | 5837 | 100.0% |
| s1-8-tok | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s1-8-tok | c | reverse_compare | 825 | 825 | 100.0% |
| s1-8-tok | c | self_assignment | 24176 | 24176 | 100.0% |
| s1-8-tok | c | update_reverse | 10367 | 10367 | 100.0% |
| s1-8-tok | c | void_return | 4003 | 4003 | 100.0% |
| s1-8-tok | cpp | branch_order | 966 | 966 | 100.0% |
| s1-8-tok | cpp | cast_style | 6250 | 6248 | 100.0% |
| s1-8-tok | cpp | conditional_order | 1994 | 1994 | 100.0% |
| s1-8-tok | cpp | equal_hash_reverse | 11388 | 11388 | 100.0% |
| s1-8-tok | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-8-tok | cpp | exp_cmp | 14969 | 14940 | 99.8% |
| s1-8-tok | cpp | for_OOO | 8200 | 7166 | 87.4% |
| s1-8-tok | cpp | nested_condition | 1403 | 1403 | 100.0% |
| s1-8-tok | cpp | not_equal_hash_reverse | 4801 | 4801 | 100.0% |
| s1-8-tok | cpp | not_equal_to_equal | 24 | 24 | 100.0% |
| s1-8-tok | cpp | reverse_compare | 17038 | 16981 | 99.7% |
| s1-8-tok | cpp | self_assignment | 14434 | 14346 | 99.4% |
| s1-8-tok | cpp | update_reverse | 6051 | 6049 | 100.0% |
| s1-8-tok | cpp | void_return | 8635 | 8635 | 100.0% |
| s1-8-tok | javascript | arrow_body | 156 | 156 | 100.0% |
| s1-8-tok | javascript | branch_order | 1347 | 1347 | 100.0% |
| s1-8-tok | javascript | conditional_order | 3486 | 3486 | 100.0% |
| s1-8-tok | javascript | const_let | 12011 | 12007 | 100.0% |
| s1-8-tok | javascript | empty_array | 4759 | 4759 | 100.0% |
| s1-8-tok | javascript | empty_object | 129 | 129 | 100.0% |
| s1-8-tok | javascript | equal_hash_reverse | 8022 | 8022 | 100.0% |
| s1-8-tok | javascript | equal_to_not_equal | 4945 | 4945 | 100.0% |
| s1-8-tok | javascript | function_arrow | 71 | 71 | 100.0% |
| s1-8-tok | javascript | loop_form | 9881 | 9880 | 100.0% |
| s1-8-tok | javascript | member_access | 81606 | 81606 | 100.0% |
| s1-8-tok | javascript | nested_condition | 1838 | 1835 | 99.8% |
| s1-8-tok | javascript | not_equal_hash_reverse | 2040 | 2040 | 100.0% |
| s1-8-tok | javascript | not_equal_to_equal | 2648 | 2648 | 100.0% |
| s1-8-tok | javascript | reverse_compare | 13257 | 13257 | 100.0% |
| s1-8-tok | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s1-8-tok | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s1-8-tok | javascript | void_return | 6798 | 6788 | 99.9% |
| s2-8-struct | python | branch_order | 380 | 380 | 100.0% |
| s2-8-struct | python | conditional_order | 420 | 420 | 100.0% |
| s2-8-struct | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s2-8-struct | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-8-struct | python | exp_cmp | 15064 | 15064 | 100.0% |
| s2-8-struct | python | f_string | 15578 | 15578 | 100.0% |
| s2-8-struct | python | identity_negation | 473 | 473 | 100.0% |
| s2-8-struct | python | init_list | 5691 | 5691 | 100.0% |
| s2-8-struct | python | list | 4787 | 4787 | 100.0% |
| s2-8-struct | python | loop_exit | 12774 | 12728 | 99.6% |
| s2-8-struct | python | membership_negation | 282 | 282 | 100.0% |
| s2-8-struct | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s2-8-struct | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s2-8-struct | python | print_end | 4985 | 4893 | 98.2% |
| s2-8-struct | python | print_flush | 1 | 1 | 100.0% |
| s2-8-struct | python | return | 1375 | 1375 | 100.0% |
| s2-8-struct | python | return_none | 2846 | 2846 | 100.0% |
| s2-8-struct | python | reverse_compare | 12225 | 12225 | 100.0% |
| s2-8-struct | python | self_assignment | 14470 | 14464 | 100.0% |
| s2-8-struct | c | array_parameter | 10786 | 10786 | 100.0% |
| s2-8-struct | c | branch_order | 1343 | 1343 | 100.0% |
| s2-8-struct | c | conditional_order | 2084 | 2084 | 100.0% |
| s2-8-struct | c | equal_hash_reverse | 15174 | 15174 | 100.0% |
| s2-8-struct | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-8-struct | c | exp_cmp | 48133 | 48133 | 100.0% |
| s2-8-struct | c | member_access | 18480 | 18472 | 100.0% |
| s2-8-struct | c | not_equal_hash_reverse | 6106 | 6106 | 100.0% |
| s2-8-struct | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s2-8-struct | c | reverse_compare | 858 | 858 | 100.0% |
| s2-8-struct | c | self_assignment | 24176 | 24176 | 100.0% |
| s2-8-struct | c | update_reverse | 10367 | 10367 | 100.0% |
| s2-8-struct | c | void_return | 4003 | 4003 | 100.0% |
| s2-8-struct | cpp | branch_order | 1161 | 1160 | 99.9% |
| s2-8-struct | cpp | cast_style | 7091 | 7089 | 100.0% |
| s2-8-struct | cpp | conditional_order | 2401 | 2401 | 100.0% |
| s2-8-struct | cpp | equal_hash_reverse | 13490 | 13490 | 100.0% |
| s2-8-struct | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s2-8-struct | cpp | exp_cmp | 18872 | 18845 | 99.9% |
| s2-8-struct | cpp | not_equal_hash_reverse | 5875 | 5875 | 100.0% |
| s2-8-struct | cpp | not_equal_to_equal | 30 | 30 | 100.0% |
| s2-8-struct | cpp | reverse_compare | 29976 | 29888 | 99.7% |
| s2-8-struct | cpp | self_assignment | 20353 | 20180 | 99.2% |
| s2-8-struct | cpp | update_reverse | 13660 | 13660 | 100.0% |
| s2-8-struct | cpp | void_return | 8635 | 8630 | 99.9% |
| s2-8-struct | javascript | branch_order | 1349 | 1349 | 100.0% |
| s2-8-struct | javascript | conditional_order | 3496 | 3496 | 100.0% |
| s2-8-struct | javascript | const_let | 12011 | 12006 | 100.0% |
| s2-8-struct | javascript | equal_hash_reverse | 8268 | 8268 | 100.0% |
| s2-8-struct | javascript | equal_to_not_equal | 5253 | 5253 | 100.0% |
| s2-8-struct | javascript | loop_form | 9881 | 9873 | 99.9% |
| s2-8-struct | javascript | member_access | 81748 | 81747 | 100.0% |
| s2-8-struct | javascript | not_equal_hash_reverse | 2251 | 2251 | 100.0% |
| s2-8-struct | javascript | not_equal_to_equal | 2772 | 2772 | 100.0% |
| s2-8-struct | javascript | reverse_compare | 14686 | 14686 | 100.0% |
| s2-8-struct | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s2-8-struct | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s2-8-struct | javascript | void_return | 6798 | 6780 | 99.7% |
| s1-8-struct | python | branch_order | 380 | 380 | 100.0% |
| s1-8-struct | python | conditional_order | 420 | 420 | 100.0% |
| s1-8-struct | python | equal_hash_reverse | 12474 | 12474 | 100.0% |
| s1-8-struct | python | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-8-struct | python | exp_cmp | 15064 | 15064 | 100.0% |
| s1-8-struct | python | f_string | 15578 | 15578 | 100.0% |
| s1-8-struct | python | identity_negation | 473 | 473 | 100.0% |
| s1-8-struct | python | init_list | 5691 | 5691 | 100.0% |
| s1-8-struct | python | list | 4787 | 4787 | 100.0% |
| s1-8-struct | python | loop_exit | 12774 | 12728 | 99.6% |
| s1-8-struct | python | membership_negation | 282 | 282 | 100.0% |
| s1-8-struct | python | not_equal_hash_reverse | 4902 | 4902 | 100.0% |
| s1-8-struct | python | not_equal_to_equal | 36 | 36 | 100.0% |
| s1-8-struct | python | print_end | 4985 | 4893 | 98.2% |
| s1-8-struct | python | print_flush | 1 | 1 | 100.0% |
| s1-8-struct | python | return | 1375 | 1375 | 100.0% |
| s1-8-struct | python | return_none | 2846 | 2846 | 100.0% |
| s1-8-struct | python | reverse_compare | 12225 | 12225 | 100.0% |
| s1-8-struct | python | self_assignment | 14470 | 14464 | 100.0% |
| s1-8-struct | c | array_parameter | 10786 | 10786 | 100.0% |
| s1-8-struct | c | branch_order | 1343 | 1343 | 100.0% |
| s1-8-struct | c | conditional_order | 2084 | 2084 | 100.0% |
| s1-8-struct | c | equal_hash_reverse | 15174 | 15174 | 100.0% |
| s1-8-struct | c | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-8-struct | c | exp_cmp | 48133 | 48133 | 100.0% |
| s1-8-struct | c | member_access | 18480 | 18472 | 100.0% |
| s1-8-struct | c | not_equal_hash_reverse | 6106 | 6106 | 100.0% |
| s1-8-struct | c | not_equal_to_equal | 28 | 28 | 100.0% |
| s1-8-struct | c | reverse_compare | 858 | 858 | 100.0% |
| s1-8-struct | c | self_assignment | 24176 | 24176 | 100.0% |
| s1-8-struct | c | update_reverse | 10367 | 10367 | 100.0% |
| s1-8-struct | c | void_return | 4003 | 4003 | 100.0% |
| s1-8-struct | cpp | branch_order | 1161 | 1160 | 99.9% |
| s1-8-struct | cpp | cast_style | 7091 | 7089 | 100.0% |
| s1-8-struct | cpp | conditional_order | 2401 | 2401 | 100.0% |
| s1-8-struct | cpp | equal_hash_reverse | 13490 | 13490 | 100.0% |
| s1-8-struct | cpp | equal_to_not_equal | 4 | 4 | 100.0% |
| s1-8-struct | cpp | exp_cmp | 18872 | 18845 | 99.9% |
| s1-8-struct | cpp | not_equal_hash_reverse | 5875 | 5875 | 100.0% |
| s1-8-struct | cpp | not_equal_to_equal | 30 | 30 | 100.0% |
| s1-8-struct | cpp | reverse_compare | 29976 | 29888 | 99.7% |
| s1-8-struct | cpp | self_assignment | 20353 | 20180 | 99.2% |
| s1-8-struct | cpp | update_reverse | 13660 | 13660 | 100.0% |
| s1-8-struct | cpp | void_return | 8635 | 8630 | 99.9% |
| s1-8-struct | javascript | branch_order | 1349 | 1349 | 100.0% |
| s1-8-struct | javascript | conditional_order | 3496 | 3496 | 100.0% |
| s1-8-struct | javascript | const_let | 12011 | 12006 | 100.0% |
| s1-8-struct | javascript | equal_hash_reverse | 8268 | 8268 | 100.0% |
| s1-8-struct | javascript | equal_to_not_equal | 5253 | 5253 | 100.0% |
| s1-8-struct | javascript | loop_form | 9881 | 9873 | 99.9% |
| s1-8-struct | javascript | member_access | 81748 | 81747 | 100.0% |
| s1-8-struct | javascript | not_equal_hash_reverse | 2251 | 2251 | 100.0% |
| s1-8-struct | javascript | not_equal_to_equal | 2772 | 2772 | 100.0% |
| s1-8-struct | javascript | reverse_compare | 14686 | 14686 | 100.0% |
| s1-8-struct | javascript | self_assignment | 16563 | 16563 | 100.0% |
| s1-8-struct | javascript | update_reverse | 8218 | 8218 | 100.0% |
| s1-8-struct | javascript | void_return | 6798 | 6780 | 99.7% |
