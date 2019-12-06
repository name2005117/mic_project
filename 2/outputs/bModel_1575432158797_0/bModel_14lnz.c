/* Linearization */
#include "bModel_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *bModel_linear_model_frame()
{
  return "model linear_bModel\n  parameter Integer n = 2 \"number of states\";\n  parameter Integer p = 0 \"number of inputs\";\n  parameter Integer q = 0 \"number of outputs\";\n"
  "\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[p] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = [%s];\n"
  "  parameter Real B[n, p] = zeros(n, p);%s\n"
  "  parameter Real C[q, n] = zeros(q, n);%s\n"
  "  parameter Real D[q, p] = zeros(q, p);%s\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[p];\n"
  "  output Real y[q];\n"
  "\n"
  "  Real 'x_Mass.s' = x[1];\n""  Real 'x_Mass.v' = x[2];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_bModel;\n";
}
const char *bModel_linear_model_datarecovery_frame()
{
  return "model linear_bModel\n  parameter Integer n = 2 \"number of states\";\n  parameter Integer p = 0 \"number of inputs\";\n  parameter Integer q = 0 \"number of outputs\";\n  parameter Integer nz = 11 \"data recovery variables\";\n"
  "\n"
  "  parameter Real x0[2] = %s;\n"
  "  parameter Real u0[0] = %s;\n"
  "  parameter Real z0[11] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = [%s];\n"
  "  parameter Real B[n, p] = zeros(n, p);%s\n"
  "  parameter Real C[q, n] = zeros(q, n);%s\n"
  "  parameter Real D[q, p] = zeros(q, p);%s\n"
  "  parameter Real Cz[nz, n] = [%s];\n"
  "  parameter Real Dz[nz, p] = zeros(nz, p);%s\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[p];\n"
  "  output Real y[q];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_Mass.s' = x[1];\n""  Real 'x_Mass.v' = x[2];\n"
  "  Real 'z_der(SpeedSensor.flange.s)' = z[1];\n""  Real 'z_ForceStep.f' = z[2];\n""  Real 'z_ForceStep.s' = z[3];\n""  Real 'z_ForceStep.s_support' = z[4];\n""  Real 'z_Mass.a' = z[5];\n""  Real 'z_Mass.flange_a.s' = z[6];\n""  Real 'z_Mass.flange_b.f' = z[7];\n""  Real 'z_SpeedSensor.flange.f' = z[8];\n""  Real 'z_SpeedSensor.flange.s' = z[9];\n""  Real 'z_SpeedSensor.v' = z[10];\n""  Real 'z_Spring.s_rel' = z[11];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_bModel;\n";
}
#if defined(__cplusplus)
}
#endif

