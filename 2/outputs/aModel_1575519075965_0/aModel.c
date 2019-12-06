/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "aModel_model.h"
#include "simulation/solver/events.h"

#define prefixedName_performSimulation aModel_performSimulation
#define prefixedName_updateContinuousSystem aModel_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation aModel_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int aModel_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int aModel_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int aModel_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int aModel_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int aModel_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 11
type: SIMPLE_ASSIGN
der(Mass._s) = Mass.v
*/
void aModel_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[2] /* der(Mass.s) STATE_DER */ = data->localData[0]->realVars[1] /* Mass.v STATE(1,Mass.a) */;
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
Mass._flange_a._s = Mass.s + (-0.5) * Mass.L
*/
void aModel_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[5] /* Mass.flange_a.s variable */ = data->localData[0]->realVars[0] /* Mass.s STATE(1,Mass.v) */ + (-0.5) * (data->simulationInfo->realParameter[1]);
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
Mass._flange_b._s = Mass.s + 0.5 * Mass.L
*/
void aModel_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[7] /* Mass.flange_b.s variable */ = data->localData[0]->realVars[0] /* Mass.s STATE(1,Mass.v) */ + (0.5) * (data->simulationInfo->realParameter[1]);
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
Spring._s_rel = Mass.flange_a.s - Fixed.s0
*/
void aModel_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->localData[0]->realVars[9] /* Spring.s_rel variable */ = data->localData[0]->realVars[5] /* Mass.flange_a.s variable */ - data->simulationInfo->realParameter[0];
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
Spring._f = Spring.c * (Spring.s_rel - Spring.s_rel0)
*/
void aModel_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[8] /* Spring.f variable */ = (data->simulationInfo->realParameter[3]) * (data->localData[0]->realVars[9] /* Spring.s_rel variable */ - data->simulationInfo->realParameter[4]);
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
Mass._a = (-Spring.f) / Mass.m
*/
void aModel_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[4] /* Mass.a variable */ = DIVISION_SIM((-data->localData[0]->realVars[8] /* Spring.f variable */),data->simulationInfo->realParameter[2],"Mass.m",equationIndexes);
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
der(Mass._v) = Mass.a
*/
void aModel_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[3] /* der(Mass.v) STATE_DER */ = data->localData[0]->realVars[4] /* Mass.a variable */;
  TRACE_POP
}

OMC_DISABLE_OPT
int aModel_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  aModel_functionLocalKnownVars(data, threadData);
  aModel_eqFunction_11(data, threadData);

  aModel_eqFunction_12(data, threadData);

  aModel_eqFunction_13(data, threadData);

  aModel_eqFunction_14(data, threadData);

  aModel_eqFunction_15(data, threadData);

  aModel_eqFunction_16(data, threadData);

  aModel_eqFunction_17(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int aModel_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void aModel_eqFunction_11(DATA* data, threadData_t *threadData);
extern void aModel_eqFunction_12(DATA* data, threadData_t *threadData);
extern void aModel_eqFunction_14(DATA* data, threadData_t *threadData);
extern void aModel_eqFunction_15(DATA* data, threadData_t *threadData);
extern void aModel_eqFunction_16(DATA* data, threadData_t *threadData);
extern void aModel_eqFunction_17(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
    aModel_eqFunction_11(data, threadData);

    aModel_eqFunction_12(data, threadData);

    aModel_eqFunction_14(data, threadData);

    aModel_eqFunction_15(data, threadData);

    aModel_eqFunction_16(data, threadData);

    aModel_eqFunction_17(data, threadData);
}

int aModel_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  aModel_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

  
  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "aModel_12jac.h"
#include "aModel_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks aModel_callback = {
   (int (*)(DATA *, threadData_t *, void *)) aModel_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) aModel_performQSSSimulation,
   aModel_updateContinuousSystem,
   aModel_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   aModel_initializeStateSets,
   #else
   NULL,
   #endif
   aModel_initializeDAEmodeData,
   aModel_functionODE,
   aModel_functionAlgebraics,
   aModel_functionDAE,
   aModel_functionLocalKnownVars,
   aModel_input_function,
   aModel_input_function_init,
   aModel_input_function_updateStartValues,
   aModel_output_function,
   aModel_function_storeDelayed,
   aModel_updateBoundVariableAttributes,
   aModel_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   aModel_functionInitialEquations_lambda0,
   aModel_functionRemovedInitialEquations,
   aModel_updateBoundParameters,
   aModel_checkForAsserts,
   aModel_function_ZeroCrossingsEquations,
   aModel_function_ZeroCrossings,
   aModel_function_updateRelations,
   aModel_zeroCrossingDescription,
   aModel_relationDescription,
   aModel_function_initSample,
   aModel_INDEX_JAC_A,
   aModel_INDEX_JAC_B,
   aModel_INDEX_JAC_C,
   aModel_INDEX_JAC_D,
   aModel_initialAnalyticJacobianA,
   aModel_initialAnalyticJacobianB,
   aModel_initialAnalyticJacobianC,
   aModel_initialAnalyticJacobianD,
   aModel_functionJacA_column,
   aModel_functionJacB_column,
   aModel_functionJacC_column,
   aModel_functionJacD_column,
   aModel_linear_model_frame,
   aModel_linear_model_datarecovery_frame,
   aModel_mayer,
   aModel_lagrange,
   aModel_pickUpBoundsForInputsInOptimization,
   aModel_setInputData,
   aModel_getTimeGrid,
   aModel_symbolicInlineSystem,
   aModel_function_initSynchronous,
   aModel_function_updateSynchronous,
   aModel_function_equationsSynchronous,
   aModel_inputNames,
   NULL,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "/usr/lib/omlibrary"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,18,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Modelica"
#define _OMC_LIT_RESOURCE_1_dir_data "/usr/lib/omlibrary/Modelica 3.2.2"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,8,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,33,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_2_dir_data "/usr/lib/omlibrary/ModelicaServices 3.2.2"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,16,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,41,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "aModel"
#define _OMC_LIT_RESOURCE_3_dir_data "/home/shuang/MyProject/outputs/aModel_1575519075965_0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,6,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,53,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void aModel_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &aModel_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "aModel";
  data->modelData->modelFilePrefix = "aModel";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/shuang/MyProject/outputs/aModel_1575519075965_0";
  data->modelData->modelGUID = "{162b8c11-965e-4ffe-983d-45cd7fac4889}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "aModel_init.c"
    ;
  static const char contents_info[] =
    #include "aModel_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "aModel_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "aModel_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 2;
  data->modelData->nVariablesReal = 10;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 5;
  data->modelData->nParametersInteger = 1;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 7;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "aModel_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 23;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 4;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    aModel_setupDataStruc(&data, threadData);
    res = _main_SimulationRuntime(argc, argv, &data, threadData);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

#ifdef __cplusplus
}
#endif


