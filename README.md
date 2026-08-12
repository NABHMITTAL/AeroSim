# AeroSIM

A C++ aerodynamic simulation and visualization project evolving toward a virtual wind-tunnel environment.

The long-term goal is to build a system capable of creating aerodynamic geometry, simulating airflow, calculating aerodynamic forces, and visualizing the resulting flow and physics in 3D.

## Vision

AeroSIM is planned to eventually support:

- 3D aerodynamic geometry creation and manipulation
- Configurable wind-tunnel conditions
- Airflow simulation
- Aerodynamic force and flow analysis
- Real-time modification of geometry and simulation parameters
- 3D visualization of simulation results
- GPU acceleration for computationally intensive workloads

## Current Status

AeroSIM is currently in its **mathematical foundation stage**.

The current focus is building and testing the low-level mathematics that future geometry, physics, and simulation systems will depend on.

### Math Foundation

#### Vector3

The initial 3D vector implementation is complete.

Supports:

- Addition and subtraction
- Scalar multiplication and division
- Magnitude and squared magnitude
- Normalization
- Dot product
- Cross product
- Distance and squared distance
- Angle calculation

#### Vector2

The 2D vector implementation is complete.

Supports:

- Addition and subtraction
- Scalar multiplication and division
- Magnitude and squared magnitude
- Normalization
- Dot product
- 2D cross product
- Distance and squared distance
- Angle calculation

#### Matrix3

The 3×3 matrix implementation is complete.

Supports:

- Matrix addition and subtraction
- Scalar multiplication and division
- Matrix × Vector3
- Matrix × Matrix
- Determinant
- Transpose
- Inverse
- X/Y/Z rotation matrices

#### Matrix2

The 2×2 matrix implementation is complete.

Supports:

- Matrix addition and subtraction
- Scalar multiplication and division
- Matrix × Vector2
- Matrix × Matrix
- Determinant
- Transpose
- Inverse
- 2D rotation matrix

#### Rotations

AeroSIM now includes foundational rotation support using both Euler angles and quaternions.

Euler-angle support includes:

- Yaw, pitch, and roll
- ZYX rotation convention
- Euler-angle to rotation-matrix conversion
- Rotation-order handling
- Gimbal-lock considerations

Quaternion support includes:

- Quaternion representation
- Quaternion magnitude
- Quaternion normalization
- Quaternion multiplication
- Quaternion/vector rotation

Rotation angles use **radians** and follow the **standard right-handed coordinate convention**.

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