/* Initialization */
#include "aModel_model.h"
#include "aModel_11mix.h"
#include "aModel_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void aModel_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
Mass._flange_b._f = 0.0
*/
void aModel_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[6] /* Mass.flange_b.f variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
Mass._s = $START.Mass.s
*/
void aModel_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[0] /* Mass.s STATE(1,Mass.v) */ = data->modelData->realVarsData[0].attribute /* Mass.s STATE(1,Mass.v) */.start;
  TRACE_POP
}
extern void aModel_eqFunction_13(DATA *data, threadData_t *threadData);

extern void aModel_eqFunction_12(DATA *data, threadData_t *threadData);

extern void aModel_eqFunction_14(DATA *data, threadData_t *threadData);

extern void aModel_eqFunction_15(DATA *data, threadData_t *threadData);

extern void aModel_eqFunction_16(DATA *data, threadData_t *threadData);

extern void aModel_eqFunction_17(DATA *data, threadData_t *threadData);


/*
equation index: 9
type: SIMPLE_ASSIGN
Mass._v = $START.Mass.v
*/
void aModel_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[1] /* Mass.v STATE(1,Mass.a) */ = data->modelData->realVarsData[1].attribute /* Mass.v STATE(1,Mass.a) */.start;
  TRACE_POP
}
extern void aModel_eqFunction_11(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void aModel_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  aModel_eqFunction_1(data, threadData);
  aModel_eqFunction_2(data, threadData);
  aModel_eqFunction_13(data, threadData);
  aModel_eqFunction_12(data, threadData);
  aModel_eqFunction_14(data, threadData);
  aModel_eqFunction_15(data, threadData);
  aModel_eqFunction_16(data, threadData);
  aModel_eqFunction_17(data, threadData);
  aModel_eqFunction_9(data, threadData);
  aModel_eqFunction_11(data, threadData);
  TRACE_POP
}


int aModel_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  aModel_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int aModel_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int aModel_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

