# AeroSIM

A C++ aerodynamic simulation and visualization project evolving toward a virtual wind-tunnel environment.

The long-term goal is to build a system capable of creating aerodynamic geometry, simulating airflow, calculating aerodynamic forces, and visualizing the resulting flow and physics in 3D.

## Vision

AeroSIM is planned to eventually support:

* 3D aerodynamic geometry creation and manipulation
* Configurable wind-tunnel conditions
* Airflow simulation
* Aerodynamic force and flow analysis
* Real-time modification of geometry and simulation parameters
* 3D visualization of simulation results
* GPU acceleration for computationally intensive workloads

## Current Status

AeroSIM is currently in its **mathematical foundation stage**.

The current focus is building and testing the low-level mathematics that future geometry, physics, and simulation systems will depend on.

### Math Foundation

#### Vector3

The initial 3D vector implementation is complete.

Supports:

* Addition and subtraction
* Scalar multiplication and division
* Magnitude and squared magnitude
* Normalization
* Dot product
* Cross product
* Distance and squared distance
* Angle calculation

#### Matrix3

The 3×3 matrix implementation is complete.

Supports:

* Matrix addition and subtraction
* Scalar multiplication and division
* Matrix × Vector3
* Matrix × Matrix
* Determinant
* Transpose
* Inverse
* X/Y/Z rotation matrices

#### Vector2

The 2D vector implementation is complete.

Supports:

* Addition and subtraction
* Scalar multiplication and division
* Magnitude and squared magnitude
* Normalization
* Dot product
* 2D cross product
* Distance and squared distance
* Angle calculation

#### Matrix2

The 2×2 matrix implementation is complete.

Supports:

* Matrix addition and subtraction
* Scalar multiplication and division
* Matrix × Vector2
* Matrix × Matrix
* Determinant
* Transpose
* Inverse
* 2D rotation matrix

#### Quaternion

The quaternion rotation system is complete.

Supports:

* Quaternion magnitude
* Quaternion normalization
* Quaternion multiplication
* Quaternion/vector rotation
* Quaternion conjugation for inverse rotation

Quaternions are used to represent 3D orientation and avoid the problems associated with directly combining Euler rotations.

#### Transform

The basic 3D Transform system is complete.

A Transform contains three fundamental quantities:

* **Position** — a Vector3 representing world position
* **Rotation** — a Quaternion representing orientation
* **Scale** — a Vector3 representing scale along each local axis

The identity Transform is:

[
P=(0,0,0)
]

[
Q=(1,0,0,0)
]

[
S=(1,1,1)
]

This represents an object at the origin, with no rotation and its original size.

A Transform supports:

* Translation
* Rotation
* Scale modification
* Local-to-world coordinate conversion
* World-to-local coordinate conversion

### Transform Mathematics

Transforming a local-space point into world space follows three operations:

**1. Scale**

[
p_S=p_L\odot S
]

The local point is multiplied component-by-component by the scale.

**2. Rotate**

[
p_R=Q(p_S)
]

The scaled point is rotated using the Transform's quaternion.

**3. Translate**

[
p_W=p_R+P
]

The object's position is added to obtain the final world-space point.

The complete operation is therefore:

[
\boxed{p_W=Q(p_L\odot S)+P}
]

The reverse operation converts a world-space point back into local space:

[
\boxed{p_L=Q^{-1}(p_W-P)\odot S^{-1}}
]

This works by reversing the original operations: translation is undone first, followed by rotation and then scale.

For normalized quaternions:

[
Q^{-1}=Q^*
]

where (Q^*) is the quaternion conjugate.

The coordinate conversion system has been verified using round-trip tests where a local point is transformed into world space and then converted back to its original local coordinates.

Rotation matrices use **radians** and follow the **standard right-handed coordinate convention**.

All currently implemented mathematical operations are verified through runtime tests.

## Development

AeroSIM is being developed incrementally, with correctness and understanding taking priority over premature optimization.

The planned development direction is:

```text
Mathematics
    ↓
Geometry
    ↓
Physics
    ↓
Aerodynamics
    ↓
Simulation
    ↓
Visualization
    ↓
GPU Acceleration
```

The mathematics layer is intentionally being built before the geometry and simulation systems so that later systems can rely on tested and understandable foundations.
