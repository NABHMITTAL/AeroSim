# Changelog

All notable changes to AeroSIM are documented here.

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