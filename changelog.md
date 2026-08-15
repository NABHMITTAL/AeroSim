# Changelog

All notable changes to AeroSIM are documented here.

## v0.2.0

### Added

#### Numerical Foundations

Completed the initial numerical foundation required for future physics and simulation systems.

Added an `approximatelyEqual()` utility for comparing floating-point values using both absolute and relative tolerance.

The comparison is based on:

|a - b| <= absoluteTolerance + relativeTolerance * max(|a|, |b|)

---

## v0.1.4

### Added

### conjugate() function in Quaternion

#### Transform System

Added the initial 3D Transform system combining:

* Position
* Quaternion rotation
* Scale

Default identity values are:

[
P=(0,0,0),\qquad Q=(1,0,0,0),\qquad S=(1,1,1)
]

Added Transform operations for:

* Translation
* Rotation
* Scale modification

### Coordinate-Space Conversion

Added local-to-world conversion using:

[
p_W=Q(p_L\odot S)+P
]

A local point is first scaled, then rotated, and finally translated into world space.

Added world-to-local conversion using the inverse operation:

[
p_L=Q^{-1}(p_W-P)\odot S^{-1}
]

Translation is reversed first, followed by inverse rotation and inverse scale.

For normalized quaternions, the inverse rotation is obtained through the quaternion conjugate:

[
Q^{-1}=Q^*
]

### Testing

Added runtime tests verifying:

* Transform identity values
* Translation
* Scale modification
* Quaternion rotation
* Local → World conversion
* World → Local conversion
* Local → World → Local round-trip conversion

The coordinate conversion tests successfully recover the original local-space point after transforming it into world space and back.

### Notes

This establishes the basic mathematical Transform layer required for future geometry and scene-hierarchy systems.

---

## [0.1.3] - 2026-08-13

### Added

#### Euler Angles
- Added yaw, pitch, and roll representation.
- Added ZYX Euler rotation convention.
- Added Euler-angle to rotation-matrix conversion.
- Documented rotation order and right-handed coordinate conventions.

#### Quaternions
- Added quaternion representation.
- Added quaternion magnitude calculation.
- Added quaternion normalization.
- Added quaternion multiplication.
- Added quaternion/vector rotation.
- Added runtime tests for quaternion rotation around the X, Y, and Z axes.

### Verified

- Quaternion normalization produces unit quaternions.
- Quaternion multiplication produces expected results.
- 90° quaternion rotations produce the expected axis transformations.
- Quaternion rotations agree with the existing Matrix3 rotation conventions.

---

## [0.1.2] - Vector2 and Matrix2

### Added

#### Vector2
- Added 2D vector type.
- Added vector addition and subtraction.
- Added scalar multiplication and division.
- Added magnitude and squared magnitude.
- Added normalization.
- Added dot product.
- Added 2D cross product.
- Added distance and squared distance.
- Added angle calculation.
- Added division-by-zero handling.

#### Matrix2
- Added 2×2 matrix type.
- Added matrix addition and subtraction.
- Added scalar multiplication and division.
- Added Matrix2 × Vector2 multiplication.
- Added Matrix2 × Matrix2 multiplication.
- Added determinant calculation.
- Added transpose.
- Added matrix inverse.
- Added 2D rotation matrix.
- Added division-by-zero handling.

### Testing
- Verified Vector2 operations through runtime tests.
- Verified Matrix2 operations through runtime tests.
- Verified matrix inversion using `A × A⁻¹ = I`.
- Verified 90° 2D rotation behavior.

---

## [0.1.1] - Matrix3

### Added

#### Matrix3
- Added 3×3 matrix type.
- Added matrix addition and subtraction.
- Added scalar multiplication and division.
- Added Matrix3 × Vector3 multiplication.
- Added Matrix3 × Matrix3 multiplication.
- Added determinant calculation.
- Added transpose.
- Added matrix inverse using cofactors and the adjugate.
- Added X/Y/Z rotation matrices.
- Added division-by-zero handling.

### Testing
- Verified Matrix3 operations through runtime tests.
- Verified matrix inversion using `A × A⁻¹ = I`.
- Verified X/Y/Z rotation matrices.

---

## [0.1.0] - Initial Release

### Added

#### Vector3
- Added initial 3D vector type.
- Added vector addition and subtraction.
- Added scalar multiplication and division.
- Added magnitude and squared magnitude.
- Added normalization.
- Added dot product.
- Added cross product.
- Added distance and squared distance.
- Added angle calculation.
- Added division-by-zero handling.
- Added zero-vector handling for normalization.

### Foundation
- Established the initial C++ mathematics foundation for AeroSIM.
- Added basic project structure and development workflow.