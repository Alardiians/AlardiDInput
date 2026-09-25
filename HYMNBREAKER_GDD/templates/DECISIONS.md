# DECISIONS.md — HYMNBREAKER build decisions log

Copy this file to the UE project root. One entry per non-trivial decision. Newest at the top.

| ID | Date | Area | Decision | Why | Alternatives considered | GDD refs | Author (agent/role) |
|---|---|---|---|---|---|---|---|
| D-0001 | YYYY-MM-DD | Pipeline | Blender FBX export uses axis_forward='-Z', axis_up='Y' (arrow test passed: Blender −Y → UE +Y) | Verified round-trip | "Send to Unreal" add-on | 21 §1, §8 | Lead |
| D-0002 | YYYY-MM-DD | Data | Tag-like CSV columns declared as FName and resolved at load | Simpler CSV authoring | (TagName="…") import format | data/README.md | Systems |
