/* Algebraic */
#include "aModel_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void aModel_eqFunction_13(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
    aModel_eqFunction_13(data, threadData);
}
/* for continuous time variables */
int aModel_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  aModel_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
