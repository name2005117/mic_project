/* Initialization */
#include "bModel_model.h"
#include "bModel_11mix.h"
#include "bModel_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void bModel_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
ForceStep._s_support = 0.0
*/
void bModel_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[7] /* ForceStep.s_support variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
SpeedSensor._flange._f = 0.0
*/
void bModel_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[11] /* SpeedSensor.flange.f variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
Mass._flange_b._f = 0.0
*/
void bModel_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[10] /* Mass.flange_b.f variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
Mass._v = $START.Mass.v
*/
void bModel_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[1] /* Mass.v STATE(1,Mass.a) */ = data->modelData->realVarsData[1].attribute /* Mass.v STATE(1,Mass.a) */.start;
  TRACE_POP
}
extern void bModel_eqFunction_18(DATA *data, threadData_t *threadData);

extern void bModel_eqFunction_17(DATA *data, threadData_t *threadData);


/*
equation index: 7
type: SIMPLE_ASSIGN
der(SpeedSensor._flange._s) = SpeedSensor.v
*/
void bModel_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->realVars[4] /* der(SpeedSensor.flange.s) DUMMY_DER */ = data->localData[0]->realVars[13] /* SpeedSensor.v variable */;
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
Mass._s = $START.Mass.s
*/
void bModel_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[0] /* Mass.s STATE(1,Mass.v) */ = data->modelData->realVarsData[0].attribute /* Mass.s STATE(1,Mass.v) */.start;
  TRACE_POP
}
extern void bModel_eqFunction_19(DATA *data, threadData_t *threadData);

extern void bModel_eqFunction_20(DATA *data, threadData_t *threadData);

extern void bModel_eqFunction_23(DATA *data, threadData_t *threadData);

extern void bModel_eqFunction_24(DATA *data, threadData_t *threadData);

extern void bModel_eqFunction_21(DATA *data, threadData_t *threadData);

extern void bModel_eqFunction_22(DATA *data, threadData_t *threadData);

extern void bModel_eqFunction_25(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void bModel_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  bModel_eqFunction_1(data, threadData);
  bModel_eqFunction_2(data, threadData);
  bModel_eqFunction_3(data, threadData);
  bModel_eqFunction_4(data, threadData);
  bModel_eqFunction_18(data, threadData);
  bModel_eqFunction_17(data, threadData);
  bModel_eqFunction_7(data, threadData);
  bModel_eqFunction_8(data, threadData);
  bModel_eqFunction_19(data, threadData);
  bModel_eqFunction_20(data, threadData);
  bModel_eqFunction_23(data, threadData);
  bModel_eqFunction_24(data, threadData);
  bModel_eqFunction_21(data, threadData);
  bModel_eqFunction_22(data, threadData);
  bModel_eqFunction_25(data, threadData);
  TRACE_POP
}


int bModel_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  bModel_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int bModel_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int bModel_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

