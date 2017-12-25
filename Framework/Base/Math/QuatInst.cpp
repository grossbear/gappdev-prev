///////////////////////////////////////////////////////////////////////////////////////
//  QuatInst.cpp
//
//  Quaternion Class And Methods Instantiation
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include <memory.h>

#include "Base/Common/PlatformTypes.h"
#include "MathConst.h"
#include "MathLibDefs.h"

#include "tfixed32.h"
#include "thalf.h"

#include "MathPrim.h"
#include "Sqrt.h"
#include "Trigonometry.h"
#include "PrimFunc.h"

#include "Vector.h"
#include "Plane.h"
#include "Matrix.h"

#include "Quaternion.h"
#include "Quaternion.cpp"
#include "QuatCompress.h"
#include "QuatCompress.cpp"


///////////////////////////////////////////////////////////////////////////////////////
// Multiplying Two Quaternions
template void CMQuatMult(CMQuaternion<float> &qOut, const CMQuaternion<float> &Q1, const CMQuaternion<float> &Q2);

///////////////////////////////////////////////////////////////////////////////////////
// Multiplying 3D Vector And Quaternion Treating 3D Vector As Quaternion 
// With Zero Const Part
template void CMQuatMult(CMQuaternion<float> &qOut, const CMVector3D<float> &V1, const CMQuaternion<float> &Q1);

///////////////////////////////////////////////////////////////////////////////////////
// Multiplying Quaternion And 3D Vector Treating 3D Vector As Quaternion 
// With Zero Const Part
template void CMQuatMult(CMQuaternion<float> &qOut, const CMQuaternion<float> &Q1, const CMVector3D<float> &V1);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Rotating Angle
template float CMQuatAngle(const CMQuaternion<float> &Q);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Normalised Vector Specified By Vector Part Of Quaternion
template void CMQuatAxis(CMVector3D<float> &V, const CMQuaternion<float> &Q);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Length Of Quaternion 
template float CMQuatLength(const CMQuaternion<float> &Q);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Square Of The Length Of Quaternion
template float CMQuatLengthSq(const CMQuaternion<float> &Q);

///////////////////////////////////////////////////////////////////////////////////////
// Normalize A Quaternion
template void CMQuatNormalize(CMQuaternion<float> &qOut, const CMQuaternion<float> &qIn);

///////////////////////////////////////////////////////////////////////////////////////
// Rotate Quaternion Using Another Quaternion
template void CMQuatRotate(CMQuaternion<float> &qOut, const CMQuaternion<float> &Q1, const CMQuaternion<float> &Q2);

///////////////////////////////////////////////////////////////////////////////////////
// Rotating 3D Vector Using Quaternion
template void CMQuatRotate(CMVector3D<float> &vOut, const CMQuaternion<float> &Q, const CMVector3D<float> &V);

///////////////////////////////////////////////////////////////////////////////////////
// Create Quaternion For Rotating From Vector V1 To Vector V2
template void CMQuatRotateArc(CMQuaternion<float> &q, const CMVector3D<float> &v1, const CMVector3D<float> &v2);

///////////////////////////////////////////////////////////////////////////////////////
// Bulding Quaternion From Three Euler Angles
template void CMQuatFromAxisAngles(CMQuaternion<float> &Q, float x, float y, float z);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Euler Angles From Quaternion
template void CMQuatToAxisAngles(CMVector3D<float> &vOut, const CMQuaternion<float> &qIn);

///////////////////////////////////////////////////////////////////////////////////////
// Building Matrix From Quaternion
template void CMQuatToMtx(CMMatrix44<float> &M, const CMQuaternion<float> &Q);
///////////////////////////////////////////////////////////////////////////////////////
template void CMMtxToQuat(CMQuaternion<float> &Q, const CMMatrix33<float> &M);

///////////////////////////////////////////////////////////////////////////////////////
// Bulding Quaternion From Matix
template void CMMtxToQuat(CMQuaternion<float> &Q, const CMMatrix44<float> &M);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatToMtx(CMMatrix33<float> &M, const CMQuaternion<float> &Q);

///////////////////////////////////////////////////////////////////////////////////////
// Logarithm Of A Quaternion 
template void CMQuatLog(CMQuaternion<float> &qOut, const CMQuaternion<float> &qIn);

///////////////////////////////////////////////////////////////////////////////////////
// Exponent Of A Quaternion
template void CMQuatExp(CMQuaternion<float> &qOut, const CMQuaternion<float> &qIn);

///////////////////////////////////////////////////////////////////////////////////////
// Linear Interpolation Between Two Quaternions
template void CMQuatLerp(CMQuaternion<float> &qOut, const CMQuaternion<float> &Q1, 
                         const CMQuaternion<float> &Q2, float weight);

///////////////////////////////////////////////////////////////////////////////////////
// Spherical Quaternion Interpolation
template void CMQuatSLerp(CMQuaternion<float> &qOut, const CMQuaternion<float> &Q1, 
                          const CMQuaternion<float> &Q2, float weight);

///////////////////////////////////////////////////////////////////////////////////////
// Spherical Cubic Interpolation
template void CMQuatSQuad(CMQuaternion<float> &qOut, const CMQuaternion<float> &Q1, const CMQuaternion<float> &Q2, 
                 const CMQuaternion<float> &A, const CMQuaternion<float> &B, float weight);

///////////////////////////////////////////////////////////////////////////////////////
// Spline Interpolation
template void CMQuatSpline(CMQuaternion<float> &Q, const CMQuaternion<float> &Q1, 
                           const CMQuaternion<float> &Qm, const CMQuaternion<float> &Q2);


///////////////////////////////////////////////////////////////////////////////////////
template class CMQuaternion<float>;
///////////////////////////////////////////////////////////////////////////////////////


// CMQuaternion Double Type Functions Instantiation
#ifdef MATH_DOUBLE_INST
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatMult(CMQuaternion<double> &qOut, const CMQuaternion<double> &Q1, const CMQuaternion<double> &Q2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatMult(CMQuaternion<double> &qOut, const CMVector3D<double> &V1, const CMQuaternion<double> &Q1);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatMult(CMQuaternion<double> &qOut, const CMQuaternion<double> &Q1, const CMVector3D<double> &V1);
///////////////////////////////////////////////////////////////////////////////////////
template double CMQuatAngle(const CMQuaternion<double> &Q);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatAxis(CMVector3D<double> &V, const CMQuaternion<double> &Q);
///////////////////////////////////////////////////////////////////////////////////////
template double CMQuatLength(const CMQuaternion<double> &Q);
///////////////////////////////////////////////////////////////////////////////////////
template double CMQuatLengthSq(const CMQuaternion<double> &Q);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatNormalize(CMQuaternion<double> &qOut, const CMQuaternion<double> &qIn);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatRotate(CMQuaternion<double> &qOut, const CMQuaternion<double> &Q1, const CMQuaternion<double> &Q2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatRotate(CMVector3D<double> &vOut, const CMQuaternion<double> &Q, const CMVector3D<double> &V);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatRotateArc(CMQuaternion<double> &q, const CMVector3D<double> &v1, const CMVector3D<double> &v2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatFromAxisAngles(CMQuaternion<double> &Q, double x, double y, double z);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatToAxisAngles(CMVector3D<double> &vOut, const CMQuaternion<double> &qIn);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatToMtx(CMMatrix44<double> &M, const CMQuaternion<double> &Q);
///////////////////////////////////////////////////////////////////////////////////////
template void CMMtxToQuat(CMQuaternion<double> &Q, const CMMatrix33<double> &M);
///////////////////////////////////////////////////////////////////////////////////////
template void CMMtxToQuat(CMQuaternion<double> &Q, const CMMatrix44<double> &M);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatToMtx(CMMatrix33<double> &M, const CMQuaternion<double> &Q);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatLog(CMQuaternion<double> &qOut, const CMQuaternion<double> &qIn);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatExp(CMQuaternion<double> &qOut, const CMQuaternion<double> &qIn);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatLerp(CMQuaternion<double> &qOut, const CMQuaternion<double> &Q1, 
                         const CMQuaternion<double> &Q2, double weight);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatSLerp(CMQuaternion<double> &qOut, const CMQuaternion<double> &Q1, 
                          const CMQuaternion<double> &Q2, double weight);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatSQuad(CMQuaternion<double> &qOut, const CMQuaternion<double> &Q1, const CMQuaternion<double> &Q2, 
                 const CMQuaternion<double> &A, const CMQuaternion<double> &B, double weight);
///////////////////////////////////////////////////////////////////////////////////////
template void CMQuatSpline(CMQuaternion<double> &Q, const CMQuaternion<double> &Q1, 
                           const CMQuaternion<double> &Qm, const CMQuaternion<double> &Q2);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
template class CMQuaternion<double>;
///////////////////////////////////////////////////////////////////////////////////////
#endif //MATH_DOUBLE_INST
