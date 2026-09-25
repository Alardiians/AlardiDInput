# 21 — Blender Asset Pipeline

Standards for creating every 3D asset in Blender (via the Blender MCP or by hand) and bringing it into Unreal Engine 5. Consistency matters more than any individual choice — **follow these rules exactly** so hundreds of assets made by different agents fit together.

---

## 1. Scene Setup (every .blend)

| Setting | Value |
|---|---|
| Blender version | 4.x (latest stable the MCP supports) |
| Units | **Metric**, **Unit Scale 0.01**, **Length: Centimeters** → **1 Blender unit = 1 cm = 1 UE unit** |
| Grid | 50 cm subdivisions for kit work (Overlay → Grid scale) |
| Forward direction | Assets **face −Y** in Blender (the "Front" view looks at their face) |
| Up | +Z |
| Origin / pivot | Static props: bottom-center. **Modular kit pieces: bottom-left-back corner on the 50 cm grid.** Characters: between the feet at Z = 0. Weapons (FP): at the grip, aligned so the barrel points −Y. |
| Transforms | **Apply all transforms** (Ctrl+A → All Transforms) before export; scale must read 1.0 |
| Collections | `EXPORT_<AssetName>` (what gets exported), `WIP`, `REF` (reference images/blockouts, never exported) |

**Axis verification (do once per MCP setup):** create an arrow mesh pointing −Y in Blender, export with the settings below, import into UE: it must point **+Y** in UE's static mesh editor. Characters facing −Y in Blender then match the UE Mannequin convention (mesh faces +Y; the character Blueprint rotates the mesh −90° yaw).

---

## 2. Naming

| Blender object | Becomes | Example |
|---|---|---|
| `SM_<Name>` | Static mesh | `SM_KIT_BRU_Wall_400x400_A` |
| `UCX_<MeshName>_##` | Convex collision for that mesh | `UCX_SM_KIT_BRU_Wall_400x400_A_00` |
| `UBX_` / `USP_` / `UCP_` | Box / sphere / capsule collision | — |
| `SOCKET_<Name>` (empty) | Static mesh socket | `SOCKET_HarrowAnchor`, `SOCKET_Muzzle` |
| `SK_<Name>` (mesh) + `ARM_<Name>` (armature) | Skeletal mesh | `SK_Chorister`, `ARM_Chorister` |
| `LOD0/LOD1…` suffix `_LOD1` | LODs (non-Nanite assets) | `SM_Pickup_Health_LOD1` |
| Materials | `M_<Name>` in Blender (become `MI_` in UE) | `M_Porcelain_Chorister` |

Blender file names: `<AssetID>.blend` stored in `/SourceArt/<Category>/<AssetID>/` with textures in `/SourceArt/<Category>/<AssetID>/Textures/`.

---

## 3. Polygon & Texture Budgets

| Asset class | Nanite? | Triangles (LOD0) | LODs | Textures |
|---|---|---|---|---|
| Environment kit modules | **Yes** | 5k–200k (bevels, real geometry detail welcome) | Nanite | Tileable 2K sets + trim sheets |
| Hero environment set pieces (Vault, Great Ear, Obdurate Gun, Wind Towers, Nave doors) | Yes | up to 2M | Nanite | 4K unique or tileable + decals |
| Props (small) | Yes (opaque) | 1k–30k | Nanite | 1–2K |
| Translucent/masked props (glass, foliage cards, membranes) | **No** | 1k–10k | 3 LODs | 1–2K |
| **Player FP arms** | No | 35k | 1 | 4K (arms), 2K (hands detail) |
| **Player body (shadow/legs)** | No | 30k | 2 | 2K |
| **FP weapons** | No | 20k–45k | 1 (FP) + 1 (world pickup, 8k) | 2K (4K for Axe/Silencer) |
| T1 enemies | No | 15k–25k | 4 (100/50/25/10%) | 2K |
| T2 enemies | No | 30k–50k | 4 | 2K (+2K detail) |
| T3 enemies | No | 60k–90k | 4 | 4K |
| Bosses | No | 100k–250k | 4 | 4K sets (multiple UDIM-like material slots) |
| Titans (mech-scale) | No | 80k–150k | 4 | 4K |
| Crowd agents (VAT) | No | 3k–6k | 2 | 1K |
| Pickups | No | 2k–8k | 2 | 1K |

**Texel density:** FP arms & weapons **20.48 px/cm**; enemies **10.24 px/cm**; environment (tileables) **5.12 px/cm**; large set pieces via tileables + decals.

**Material slots:** ≤ 3 per enemy (Body, Armor/Brass, Emissive/Inner), ≤ 2 per kit module, ≤ 4 per boss.

---

## 4. Modeling Standards

* **Kit modules:** snap to the 50 cm grid; dimensions multiples of 50 (ideally 100/200/400); wall thickness 50; walls/floors meet without gaps or z-fighting; bevel hard edges (2–5 cm) for Nanite readability; no n-gons in exported meshes (triangulate on export or keep quads/tris clean).
* **Deforming characters:** quad topology with edge loops at joints (elbows 3 loops, knees 3, shoulders 4), mouth petals rigged with bones (and a morph target for "open wide"), fingers with 3 loops per knuckle. Avoid thin intersecting geometry near joints.
* **Destruction:** breakable walls/floors provided as **pre-fractured** meshes (or a Chaos Geometry Collection created in UE from an intact mesh — prefer UE fracturing for consistency).
* **Porcelain enemies:** model the **porcelain shell** over **underlying flesh geometry** only where cracks reveal it (a thin inner flesh layer isn't needed — the crack effect is material-driven via masks, see §6).
* **Gore/gibs:** a gib kit per skeleton class (6–10 chunks: porcelain shards with flesh backs, limb stumps) — `SM_Gib_<Class>_##`.
* **Scale sanity:** keep a 192 cm reference capsule (`REF_PlayerCapsule`) and a 300 × 400 cm door reference in every kit file's `REF` collection.

---

## 5. Rigging Standards

### 5.1 Humanoid skeleton (`SKC_Humanoid`)
Use the **UE5 Manny-compatible hierarchy and bone names** (`root > pelvis > spine_01..05 > neck_01..02 > head`, `clavicle_l/r > upperarm_l/r > lowerarm_l/r > hand_l/r > fingers…`, `thigh_l/r > calf_l/r > foot_l/r > ball_l/r`, twist bones, `ik_foot_root`, `ik_hand_root`, `ik_hand_gun`). This lets builders retarget any humanoid animation library through UE's IK Retargeter.
* Used by: Thrall, Trooper (+variants), Acolyte, Zealot, Seraph (tall variant), Cantor, Maestro, Requiem Knight, Aurelia, Lund, NPCs, crowd sources.
* Proportion differences (Seraph's long limbs, Maestro's height) are handled by retarget chains.
* Extra bones (allowed, appended): `jaw_petal_u/d/l/r` (split mouths), `halo_root`, `weapon_r/l`, `shield_l`, `lantern`, `score` (Maestro's book), `wingpipe_l/r_01..03` (Seraph), `cape_*` chains.

### 5.2 Custom skeleton classes
| Class | Used by | Notes |
|---|---|---|
| `SKC_Chorister` | Chorister, Fugue | Digitigrade legs, long arms, long neck (3 neck bones), 4 mouth petals, spine 5 |
| `SKC_Quadruped_L` | Crescendo | Quadruped with face-plate bone, 6 bellows-pipe bones on the back |
| `SKC_Brute` | Bellwether, Canon, Profundo | Heavy biped; Bellwether: `bell_root`, `clapper_l/r`; Canon: `bellmouth_l/r`; Profundo: `chestdoor_l/r` |
| `SKC_Flyer_S` | Vesper, Wailer | Wings (2 pairs), stinger / vertebra-ribbon chain (8 bones) |
| `SKC_Ring` | Ophan | `ring_a`, `ring_b` (rotation), `maw_petal_*` (4), eye bones optional (material-driven blinking preferred) |
| `SKC_Serpent` | Siren | 16-bone spine chain, arms, `throat` bone, whip chain (12 bones) |
| `SKC_Arachnid` | Organ Grinder | 6 legs (3 bones each), `turret_yaw`, `turret_pitch` |
| `SKC_Tome` | Hymnal | `cover_front/back`, page bones (8), `spine_glow` |
| `SKC_Titan` | Carillon, bosses | Per-asset rig; bells as separate bones for destruction |

* **Root bone** at the origin (Z=0), Y-forward-conventions consistent with §1; **root motion** allowed for attacks/leaps (UE extracts it).
* **Physics assets** generated in UE; hand-tune capsules on limbs used for dismemberment and hit zones (`head`, weak-point bones get their own bodies).

### 5.3 Player rigs
* `SK_Unsung_Arms`: arms + upper chest + `camera` bone; `weapon_r` socket; `harrow_l` socket; finger chains.
* `SK_Unsung_Body`: full body (Manny-compatible) used for legs, shadow and cutscene 3P shots.

---

## 6. Texturing & Materials

* **PBR metal/roughness.** Textures per material: `_D` (BaseColor, sRGB), `_N` (Normal, DirectX Y− convention → set Blender bakes to OpenGL and **flip green on import** or bake in DirectX), `_ORM` (R=AO, G=Roughness, B=Metallic, linear), optional `_E` (emissive), `_M` (masks).
* **Porcelain enemies `_M` mask (RGBA):** R = crack pattern (tiling craquelure + large-crack mask), G = gilding coverage (for Tuned conversion stages), B = gold seam lines (emissive driver), A = flesh-reveal regions (where deep cracks may open). The UE master material `M_Porcelain_Master` uses these with the parameters in `17_Art_Direction.md` §4.2.
* **Tileables & trims:** each kit ships 6–10 tileable materials (e.g., `BRU`: board-formed concrete ×3, raw steel, painted steel, stained concrete floor, rubber floor, glass) + 1–2 trim sheets (edges, pipes, vents, signage).
* **Decals:** Static graffiti, stencil signage, stains, Choir filigree — as deferred decals (`M_Decal_*`).
* **Sources:** hand-painted/baked in Blender, Substance (if available), **Poly Haven** (CC0 textures & HDRIs — the Blender MCP can fetch these), or AI texture generation (ensure tileability; clean seams; no copyrighted logos). Record the source/license in the asset's `README.txt`.

---

## 7. Animation Standards

* **Frame rate:** author at **30 fps** (UE interpolates); montages for attacks ≥ 30 fps; FP weapon animations at **60 fps** for crisp recoil.
* **Naming:** `A_<Skeleton>_<Action>` (e.g., `A_Chorister_Throw_Gold`), Breakdown pairs: `A_BRK_<Enemy>_<Variant>_Player` / `_Victim` (exactly equal length and synchronized from frame 0).
* **Export:** one action per FBX for clarity (`bake_anim_use_all_actions=False`, `bake_anim_use_nla_strips=False`), mesh excluded for animation-only exports (skeleton only).
* **Root motion:** keep root motion on the `root` bone for moves that travel (lunges, leaps, charges).
* **AnimNotify markers:** add timeline markers in Blender named `NOTIFY_<Name>` at frames where UE notifies should go (e.g., `NOTIFY_TelegraphStart`, `NOTIFY_DamageStart`, `NOTIFY_DamageEnd`, `NOTIFY_Footstep_L`); a UE import script converts markers into AnimNotifies.
* **Libraries:** humanoid locomotion can be retargeted from licensed libraries (Mixamo, marketplace, mocap); creatures are hand-keyed or generated then cleaned.

---

## 8. Export Settings (FBX → UE)

Use this function for every export (MCP agents: call it; do not hand-configure):

```python
import bpy, os

def hb_export_fbx(asset_name: str, out_dir: str, skeletal: bool = False, anim: bool = False):
    """Export the EXPORT_<asset_name> collection to <out_dir>/<asset_name>.fbx with HYMNBREAKER standards."""
    col = bpy.data.collections.get(f"EXPORT_{asset_name}")
    assert col, f"Missing collection EXPORT_{asset_name}"
    bpy.ops.object.select_all(action='DESELECT')
    for ob in col.all_objects:
        ob.select_set(True)
    bpy.context.view_layer.objects.active = col.all_objects[0]
    os.makedirs(out_dir, exist_ok=True)
    bpy.ops.export_scene.fbx(
        filepath=os.path.join(out_dir, f"{asset_name}.fbx"),
        use_selection=True,
        apply_unit_scale=True,
        apply_scale_options='FBX_SCALE_UNITS',   # scene is cm (unit scale 0.01) -> 1:1 in UE
        global_scale=1.0,
        axis_forward='-Z', axis_up='Y',           # Blender defaults; verified by the arrow test (section 1)
        object_types={'MESH', 'ARMATURE', 'EMPTY'},
        use_mesh_modifiers=True,
        mesh_smooth_type='FACE',
        use_tspace=True,
        add_leaf_bones=False,
        primary_bone_axis='Y', secondary_bone_axis='X',
        armature_nodetype='NULL',
        bake_anim=anim,
        bake_anim_use_all_actions=False,
        bake_anim_use_nla_strips=False,
        bake_anim_force_startend_keying=True,
        bake_anim_simplify_factor=0.0,
        path_mode='COPY', embed_textures=False,
    )
```

> If the arrow test shows a different orientation with your Blender/UE versions, fix it **once** in this function (e.g., `axis_forward='-Y', axis_up='Z'` with "Apply Transform") and record it in `DECISIONS.md`. Alternatively, Epic's **"Send to Unreal"** Blender add-on applies correct settings automatically.

### UE import settings (per type)
| Type | Settings |
|---|---|
| Static mesh (kit/prop) | Nanite **on** (opaque), Combine Meshes off, Auto-generate collision **off** (use UCX), Import normals & tangents, Generate lightmap UVs **on** (Low-preset fallback), Material import → create instances of the master materials (never import Blender materials as masters) |
| Skeletal mesh | Import morph targets, Use T0 as ref pose off, target the class skeleton (`SKEL_<Class>`) when it exists, create physics asset (then hand-tune) |
| Animation | Skeleton = class skeleton; import root motion; custom attribute/markers → notifies (script) |
| Textures | `_N` → Normalmap compression (flip green if baked OpenGL); `_ORM`, `_M` → Masks (linear, no sRGB); `_D` sRGB |

---

## 9. Blender MCP Workflows

The common Blender MCP servers let an agent **run Python inside Blender**, inspect the scene, fetch **Poly Haven** assets (HDRIs, textures, models), search/download **Sketchfab** models (check licenses!), and call **AI 3D generators** (e.g., Hyper3D Rodin, Hunyuan3D) where enabled. Recommended workflows:

### 9.1 Modular kit pieces (procedural — best fit for MCP)
1. Script the piece from primitives: cube → exact dimensions on the grid → bevel modifier (width 3 cm, 2 segments) → boolean cut-outs (doors, windows) → apply.
2. UV via Smart UV Project (angle 66°, island margin 0.02) then scale UVs to the kit texel density (5.12 px/cm).
3. Add `UCX_` boxes, sockets, origin at the grid corner; validate names (§11); export with `hb_export_fbx`.

Example — a brutalist wall module:
```python
import bpy, bmesh

def make_wall(name="SM_KIT_BRU_Wall_400x400_A", w=400, h=400, d=50):
    bpy.ops.mesh.primitive_cube_add(size=1)
    ob = bpy.context.active_object; ob.name = name
    ob.scale = (w, d, h); bpy.ops.object.transform_apply(scale=True)
    ob.location = (w/2, d/2, h/2)                      # corner pivot at (0,0,0)
    bpy.ops.object.origin_set(type='ORIGIN_CURSOR')    # cursor at world origin
    bev = ob.modifiers.new("Bevel", 'BEVEL'); bev.width = 3; bev.segments = 2
    bpy.ops.object.modifier_apply(modifier="Bevel")
    col = bpy.data.collections.new(f"EXPORT_{name}"); bpy.context.scene.collection.children.link(col)
    for c in list(ob.users_collection): c.objects.unlink(ob)
    col.objects.link(ob)
    # simple collision
    bpy.ops.mesh.primitive_cube_add(size=1); c = bpy.context.active_object
    c.name = f"UCX_{name}_00"; c.scale = (w, d, h); bpy.ops.object.transform_apply(scale=True)
    c.location = (w/2, d/2, h/2)
    bpy.ops.object.origin_set(type='ORIGIN_CURSOR')
    for uc in list(c.users_collection): uc.objects.unlink(c)
    col.objects.link(c)
    return ob
```

### 9.2 Hero props & weapons (hybrid)
Blockout in Python → refine with modifiers (bevel, solidify, array, mirror) → optional AI-generated detail meshes for greebles → bake high→low (normal/AO) → texture → export. Keep FP weapons' pivot at the grip; add `SOCKET_Muzzle`, `SOCKET_Eject`, `SOCKET_Mod`.

### 9.3 Creatures (AI-assisted)
1. Generate a base mesh from the bestiary's visual description with an AI 3D generator (image or text prompt), in **A-pose/T-pose** for humanoids.
2. **Cleanup is mandatory:** remesh (voxel 1–2 cm) → decimate to budget → retopologize major deformation areas (or use QuadriFlow/quad remesher if available) → fix normals, symmetry, holes.
3. Fit the correct class skeleton (§5) and weight-paint (auto weights + fixes at joints).
4. Bake the generator's textures onto clean UVs; author the `_M` porcelain mask.
5. Validate deformation with a test animation before export.

### 9.4 Environments / terrains
Large terrains (lunar regolith, Mercury, snowfields, slag heaps) are better built **in UE** (Landscape or Nanite meshes from heightmaps). Use Blender for hero rock formations, ice pillars, and modular cliff pieces.

---

## 10. Asset "Definition of Done"

- [ ] Name, pivot, scale, facing (−Y) correct; transforms applied.
- [ ] Budget respected (tris, materials, texture sizes, texel density).
- [ ] Collision (`UCX_`) present for kit/props; physics asset tuned for characters.
- [ ] Sockets present where the spec requires (muzzles, anchors, attach points).
- [ ] Textures follow suffix & channel conventions; normal-map convention verified.
- [ ] Imported into UE at the correct path, with material instances of the correct master.
- [ ] Nanite on/off per §3; LODs for non-Nanite assets.
- [ ] Visual check in UE next to the reference capsule and door (screenshot attached to the task).
- [ ] Source & license recorded (`README.txt`).

---

## 11. Validation Script (run before every export)

```python
import bpy, re
PREFIXES = ("SM_", "SK_", "ARM_", "UCX_", "UBX_", "USP_", "UCP_", "SOCKET_")
def hb_validate(collection_name):
    errs = []
    col = bpy.data.collections[collection_name]
    for ob in col.all_objects:
        if not ob.name.startswith(PREFIXES): errs.append(f"Bad prefix: {ob.name}")
        if any(abs(s - 1.0) > 1e-4 for s in ob.scale): errs.append(f"Unapplied scale: {ob.name}")
        if ob.type == 'MESH' and ob.name.startswith(("SM_", "SK_")):
            for p in ob.data.polygons:
                if len(p.vertices) > 4: errs.append(f"N-gon in {ob.name}"); break
    if abs(bpy.context.scene.unit_settings.scale_length - 0.01) > 1e-6:
        errs.append("Scene unit scale must be 0.01")
    return errs
```
