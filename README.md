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

AeroSIM has completed its **mathematical and numerical foundation stage** and has begun development of the **Core architecture**.

The mathematical foundation provides the low-level geometry and numerical tools required by future systems, while the Core layer is beginning to establish application lifecycle, configuration, logging, and event infrastructure.

### Core Foundation

The initial Core foundation is now in development.

#### Application

The `Application` system provides the basic application lifecycle.

It currently supports:

* Application construction and destruction
* Application startup
* Application runtime entry point
* Application shutdown

The current lifecycle is intentionally simple and will become the central coordinator for AeroSIM's subsystems.

#### Configuration

The `Configuration` system provides centralized storage for application and subsystem settings.

Configuration values are stored using string keys and support several basic value types:

* `int`
* `float`
* `bool`
* `std::string`

Example configuration values include:

```text
application.name
simulation.timestep
core.workerThreads
renderer.vsync
```

The configuration system uses `std::variant` internally so a single configuration container can safely store different supported value types.

Typed access is provided through templates, allowing values to be retrieved as their expected C++ type.

#### Logging

The initial logging system provides basic runtime information from the Core layer.

Logging is used to communicate important application lifecycle events such as initialization, runtime startup, and shutdown.

The logging system will eventually be expanded into a more structured system supporting different severity levels and subsystem-specific messages.

#### Event System

The initial event foundation has been implemented.

Events are represented using an event type enumeration and an `Event` object containing the type of event that occurred.

The current event system supports:

* Event type identification
* Event objects
* Event type retrieval
* Basic event dispatching

The initial dispatcher checks whether an event matches a requested event type.

The current implementation is intentionally minimal and will later be extended with event handlers and callback-based dispatch.

### Math Foundation

The mathematical foundation is complete.

#### Vector3

The 3D vector implementation is complete.

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

* **Position** — a Vector3 representing position
* **Rotation** — a Quaternion representing orientation
* **Scale** — a Vector3 representing scale along each local axis

The identity Transform is:

```text
P = (0, 0, 0)
Q = (1, 0, 0, 0)
S = (1, 1, 1)
```

This represents an object at the origin, with no rotation, and its original size.

A Transform supports:

* Translation
* Rotation
* Scale modification
* Local-to-world coordinate conversion
* World-to-local coordinate conversion

### Transform Mathematics

Transforming a local-space point into world space consists of three operations.

**1. Scale**

```text
pS = pL ⊙ S
```

The local point is multiplied component-by-component by the scale.

**2. Rotate**

```text
pR = Q(pS)
```

The scaled point is rotated using the Transform's quaternion.

**3. Translate**

```text
pW = pR + P
```

The object's position is added to obtain the final world-space point.

The complete local-to-world transformation is therefore:

```text
pW = Q(pL ⊙ S) + P
```

The reverse operation converts a world-space point back into local space:

```text
pL = Q⁻¹(pW - P) ⊙ S⁻¹
```

The operations are reversed when converting from world space back to local space:

```text
World point
    ↓
Undo translation
    ↓
Undo rotation
    ↓
Undo scale
    ↓
Local point
```

For a normalized quaternion, the inverse rotation can be obtained from its conjugate:

```text
Q⁻¹ = Q*
```

where `Q*` is the quaternion conjugate.

The coordinate conversion system has been verified using round-trip tests where a local point is transformed into world space and then converted back to its original local coordinates.

Rotation matrices use **radians** and follow the **standard right-handed coordinate convention**.

All currently implemented mathematical operations are verified through runtime tests.

### Numerical Foundations

The initial numerical foundation is complete.

AeroSIM uses finite-precision floating-point numbers, meaning that many real numbers cannot be represented exactly in binary. Small representation and rounding errors are therefore unavoidable in numerical computing.

These errors can accumulate over repeated calculations and simulation steps, so numerical comparisons should not always rely on exact floating-point equality.

AeroSIM provides an `approximatelyEqual()` utility that compares floating-point values using both absolute and relative tolerance.

The comparison is based on:

```text
|a - b| <= absoluteTolerance + relativeTolerance * max(|a|, |b|)
```

**Absolute tolerance** provides a fixed error allowance and is particularly useful when values are close to zero.

**Relative tolerance** scales the allowed error according to the magnitude of the values, making comparisons more useful across different numerical ranges.

The purpose is not to eliminate floating-point error, but to provide a consistent way of determining whether two calculated values are sufficiently close for a particular numerical operation.

The numerical foundation has been verified through runtime tests covering:

* Exact equality
* Small floating-point differences
* Near-zero values
* Large values
* Values outside the selected tolerance
* Floating-point representation behavior such as `0.1 + 0.2`

The numerical foundation will support future work involving physics calculations, simulation timesteps, interpolation, and numerical integration.

## Foundation Status

The mathematical and numerical foundation is now complete.

The current low-level foundation contains:

* Vector2
* Vector3
* Matrix2
* Matrix3
* Euler rotations
* Quaternions
* Transforms
* Local/world coordinate conversion
* Floating-point numerical comparison

The initial Core foundation now contains:

* Application lifecycle
* Configuration
* Logging
* Event types
* Event objects
* Basic event dispatching

These systems form the low-level foundation for the higher-level systems that will follow.

## Architecture

AeroSIM's current architecture is being developed around clear subsystem boundaries:

```text
Application
    |
    +-- Core
    |
    +-- Math
    |
    +-- Geometry
    |
    +-- Simulation
    |
    +-- Rendering
    |
    +-- Compute
```

The Core layer is intended to provide common application infrastructure without depending on a specific physics or simulation solver.

## Development

AeroSIM is being developed incrementally, with correctness and understanding taking priority over premature optimization.

The planned development direction is:

```text
Mathematics
    ↓
Core
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

The mathematics and numerical layers were intentionally built and tested before higher-level systems so that later systems can rely on a tested and understandable foundation.

The Core layer is now being developed using the same principle: build small, understandable systems, verify them with runtime tests, and expand the architecture only when the underlying concepts are understood.
