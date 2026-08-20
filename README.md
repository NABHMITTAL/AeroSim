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

AeroSIM has completed its **mathematical, numerical, and Core runtime foundation stages** and is now moving into **Geometry development**.

The mathematical foundation provides the low-level geometry and numerical tools required by future systems, while the Core layer provides the application and runtime infrastructure required by higher-level systems.

**v0.3.0 marks the completion of Milestone 2 — Core Runtime Foundation.**

### Core Foundation

The Core foundation is now complete for the systems currently required by the project.

#### Application

The `Application` system provides the basic application lifecycle.

It currently supports:

* Application construction and destruction
* Application startup
* Application runtime entry point
* Application shutdown

The lifecycle is intentionally simple and acts as the central coordinator for AeroSIM's current runtime systems.

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

#### Timing

The Core timing system provides measurement of real elapsed time.

The `Time` system currently supports:

* Elapsed time measurement
* Delta time calculation

Timing has been verified through runtime tests using `std::chrono` and a monotonic `std::chrono::steady_clock`.

#### Fixed Timestep Management

A fixed timestep system has been implemented using a `TimeAccumulator`.

The current physics timestep is:

```text
0.01 seconds
```

The accumulator receives elapsed real time and stores it until enough time has accumulated for a simulation step.

The timestep process is:

```text
Real elapsed time
        ↓
Time
        ↓
Delta time
        ↓
TimeAccumulator
        ↓
Accumulate
        ↓
Check for available timestep
        ↓
Run fixed physics step
        ↓
Consume timestep
        ↓
Keep remaining time
```

The accumulator supports:

* Adding elapsed time
* Checking whether a fixed timestep is available
* Consuming a fixed timestep
* Preserving remaining accumulated time
* Performing multiple fixed physics steps when enough time has accumulated

The system has been verified through repeated runtime tests involving real elapsed time, accumulated time, remaining time, and multiple fixed simulation steps.

#### Memory Management Strategy

AeroSIM has established an initial memory-management strategy based on modern C++ ownership and lifetime management.

The project currently follows these principles:

* Prefer stack allocation for ordinary local objects
* Use `std::unique_ptr` for exclusive dynamic ownership
* Use `std::shared_ptr` only when genuine shared ownership is required
* Use references or non-owning pointers for non-owning access
* Avoid unnecessary manual `new` and `delete`

A custom allocator or specialized memory-management system is not currently required and will only be introduced if future simulation requirements justify it.

### Deferred Core Architecture

Several systems from the original Milestone 2 plan have intentionally been deferred.

These include:

* Resource management
* Entity/component architecture
* Threading foundation
* Job/task system
* Module boundaries

These systems are not considered missing implementations. They are deliberate architectural decisions to avoid introducing infrastructure before concrete requirements exist.

Resource management will be revisited once AeroSIM has actual resources such as geometry, meshes, materials, shaders, or simulation data that require centralized ownership or loading.

Entity/component architecture will be revisited once the geometry and physics systems provide enough concrete objects to determine whether such a system is actually useful.

Threading and job/task infrastructure will be introduced when simulation and computational workloads provide a practical need for parallel execution.

Module boundaries will continue to evolve alongside the Geometry, Physics, Aerodynamics, and Simulation systems rather than being prematurely fixed.

## Math Foundation

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

## Transform Mathematics

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

## Numerical Foundations

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

The Core foundation now contains:

* Application lifecycle
* Configuration
* Logging
* Event types
* Event objects
* Basic event dispatching
* Timing
* Fixed timestep management
* Initial memory-management strategy

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

The Core layer provides common application infrastructure without depending on a specific physics or simulation solver.

The architecture is intentionally being developed incrementally. Systems are introduced when they provide a concrete benefit rather than being created solely to satisfy a predetermined architecture.

## Development

AeroSIM is being developed incrementally, with correctness and understanding taking priority over premature optimization and premature architecture.

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

The Core layer was developed using the same principle: build small, understandable systems, verify them with runtime tests, and expand the architecture only when the underlying concepts are understood.

**Milestone 2 is now complete.**

The next major development phase is **Geometry**.
