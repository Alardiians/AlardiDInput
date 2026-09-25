# BALANCE_LOG.md — tuning changes

Copy to the UE project root. Every change to data/*.csv or DataAssets after Milestone 2 gets an entry.

| ID | Date | Table / Asset | Row / Field | Before | After | Reason (telemetry) | Arena(s) tested | Result |
|---|---|---|---|---|---|---|---|---|
| B-0001 | YYYY-MM-DD | DT_Enemies | ENM_Chorister.HP | 140 | 130 | ENC_M01_03 avg duration 5.2 min (target ≤ 4.5) | ENC_M01_03 | 4.4 min avg over 10 runs |
