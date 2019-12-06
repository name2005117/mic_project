/* Algebraic */
#include "bModel_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void bModel_eqFunction_19(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_21(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_22(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_25(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_17(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_16(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
    bModel_eqFunction_19(data, threadData);

    bModel_eqFunction_21(data, threadData);

    bModel_eqFunction_22(data, threadData);

    bModel_eqFunction_25(data, threadData);

    bModel_eqFunction_17(data, threadData);

    bModel_eqFunction_16(data, threadData);
}
/* for continuous time variables */
int bModel_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  bModel_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
