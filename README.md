# AeroSIM

AeroSIM is a C++-based aerodynamic simulation and visualization project designed to eventually provide a complete virtual wind-tunnel environment.

The long-term goal is to allow users to:

* Build and modify aerodynamic components.
* Create and manipulate 3D geometry.
* Configure wind-tunnel conditions.
* Simulate airflow around objects.
* Analyze aerodynamic forces and flow behavior.
* Modify geometry and simulation parameters in real time.
* Visualize simulation results in 3D.
* Utilize GPU acceleration for computationally intensive simulations.

## Current Status

AeroSIM is currently in the foundational development stage.

### Completed

#### Vector3 Math Foundation

The initial 3D vector mathematics layer has been implemented and tested.

`Vector3` currently supports:

* Addition
* Subtraction
* Scalar multiplication
* Scalar division
* Magnitude
* Normalization
* Dot product
* Cross product

#### Matrix3

AeroSIM now includes a fully functional 3×3 matrix implementation.

`Matrix3` curently supports:

* Matrix addition and subtraction
* Scalar multiplication and division
* Matrix × Vector3
* Matrix × Matrix
* Determinant
* Transpose
* Inverse
* X/Y/Z rotation matrices

`Rotation angles use radians and follow the standard right-handed coordinate convention`

All currently implemented operations have been verified with basic runtime tests.

## Technology

* **Language:** C++
* **Build System:** CMake
* **Build Tool:** Ninja
* **Compiler:** Microsoft Visual C++ (MSVC)
* **IDE:** Visual Studio Code
* **Version Control:** Git / GitHub

## Project Direction

The project will be developed incrementally, starting with reliable mathematical and software foundations before moving into geometry, physics, numerical simulation, visualization, and GPU acceleration.

The planned architecture will eventually separate concerns such as:


* Core
* Math
* Geometry
* Physics
* Aerodynamics
* Simulation
* Rendering
* GPU
* Application

The priority is correctness and a maintainable architecture first, followed by performance optimization and GPU acceleration where it provides meaningful benefits.
