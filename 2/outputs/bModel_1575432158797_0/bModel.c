/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "bModel_model.h"
#include "simulation/solver/events.h"

#define prefixedName_performSimulation bModel_performSimulation
#define prefixedName_updateContinuousSystem bModel_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation bModel_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int bModel_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int bModel_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int bModel_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int bModel_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int bModel_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 16
type: SIMPLE_ASSIGN
der(SpeedSensor._flange._s) = Mass.v
*/
void bModel_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[4] /* der(SpeedSensor.flange.s) DUMMY_DER */ = data->localData[0]->realVars[1] /* Mass.v STATE(1,Mass.a) */;
  TRACE_POP
}
/*
equation index: 17
type: SIMPLE_ASSIGN
SpeedSensor._v = Mass.v
*/
void bModel_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[13] /* SpeedSensor.v variable */ = data->localData[0]->realVars[1] /* Mass.v STATE(1,Mass.a) */;
  TRACE_POP
}
/*
equation index: 18
type: SIMPLE_ASSIGN
der(Mass._s) = Mass.v
*/
void bModel_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  data->localData[0]->realVars[2] /* der(Mass.s) STATE_DER */ = data->localData[0]->realVars[1] /* Mass.v STATE(1,Mass.a) */;
  TRACE_POP
}
/*
equation index: 19
type: SIMPLE_ASSIGN
Mass._flange_a._s = Mass.s + (-0.5) * Mass.L
*/
void bModel_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  data->localData[0]->realVars[9] /* Mass.flange_a.s variable */ = data->localData[0]->realVars[0] /* Mass.s STATE(1,Mass.v) */ + (-0.5) * (data->simulationInfo->realParameter[3]);
  TRACE_POP
}
/*
equation index: 20
type: SIMPLE_ASSIGN
ForceStep._f = (-ForceStep.offsetForce) - (if time < ForceStep.startTime then 0.0 else ForceStep.stepForce)
*/
void bModel_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  modelica_boolean tmp0;
  RELATIONHYSTERESIS(tmp0, data->localData[0]->timeValue, data->simulationInfo->realParameter[1], 0, Less);
  data->localData[0]->realVars[5] /* ForceStep.f variable */ = (-data->simulationInfo->realParameter[0]) - ((tmp0?0.0:data->simulationInfo->realParameter[2]));
  TRACE_POP
}
/*
equation index: 21
type: SIMPLE_ASSIGN
Spring._s_rel = ForceStep.f / Spring.c + Spring.s_rel0
*/
void bModel_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  data->localData[0]->realVars[14] /* Spring.s_rel variable */ = DIVISION_SIM(data->localData[0]->realVars[5] /* ForceStep.f variable */,data->simulationInfo->realParameter[5],"Spring.c",equationIndexes) + data->simulationInfo->realParameter[6];
  TRACE_POP
}
/*
equation index: 22
type: SIMPLE_ASSIGN
ForceStep._s = Mass.flange_a.s - Spring.s_rel
*/
void bModel_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  data->localData[0]->realVars[6] /* ForceStep.s variable */ = data->localData[0]->realVars[9] /* Mass.flange_a.s variable */ - data->localData[0]->realVars[14] /* Spring.s_rel variable */;
  TRACE_POP
}
/*
equation index: 23
type: SIMPLE_ASSIGN
Mass._a = (-ForceStep.f) / Mass.m
*/
void bModel_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  data->localData[0]->realVars[8] /* Mass.a variable */ = DIVISION_SIM((-data->localData[0]->realVars[5] /* ForceStep.f variable */),data->simulationInfo->realParameter[4],"Mass.m",equationIndexes);
  TRACE_POP
}
/*
equation index: 24
type: SIMPLE_ASSIGN
der(Mass._v) = Mass.a
*/
void bModel_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  data->localData[0]->realVars[3] /* der(Mass.v) STATE_DER */ = data->localData[0]->realVars[8] /* Mass.a variable */;
  TRACE_POP
}
/*
equation index: 25
type: SIMPLE_ASSIGN
SpeedSensor._flange._s = Mass.s + 0.5 * Mass.L
*/
void bModel_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  data->localData[0]->realVars[12] /* SpeedSensor.flange.s DUMMY_STATE */ = data->localData[0]->realVars[0] /* Mass.s STATE(1,Mass.v) */ + (0.5) * (data->simulationInfo->realParameter[3]);
  TRACE_POP
}

OMC_DISABLE_OPT
int bModel_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  bModel_functionLocalKnownVars(data, threadData);
  bModel_eqFunction_16(data, threadData);

  bModel_eqFunction_17(data, threadData);

  bModel_eqFunction_18(data, threadData);

  bModel_eqFunction_19(data, threadData);

  bModel_eqFunction_20(data, threadData);

  bModel_eqFunction_21(data, threadData);

  bModel_eqFunction_22(data, threadData);

  bModel_eqFunction_23(data, threadData);

  bModel_eqFunction_24(data, threadData);

  bModel_eqFunction_25(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int bModel_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void bModel_eqFunction_18(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_20(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_23(DATA* data, threadData_t *threadData);
extern void bModel_eqFunction_24(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
    bModel_eqFunction_18(data, threadData);

    bModel_eqFunction_20(data, threadData);

    bModel_eqFunction_23(data, threadData);

    bModel_eqFunction_24(data, threadData);
}

int bModel_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  bModel_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

  
  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "bModel_12jac.h"
#include "bModel_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks bModel_callback = {
   (int (*)(DATA *, threadData_t *, void *)) bModel_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) bModel_performQSSSimulation,
   bModel_updateContinuousSystem,
   bModel_callExternalObjectDestructors,
   NULL,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   bModel_initializeStateSets,
   #else
   NULL,
   #endif
   bModel_initializeDAEmodeData,
   bModel_functionODE,
   bModel_functionAlgebraics,
   bModel_functionDAE,
   bModel_functionLocalKnownVars,
   bModel_input_function,
   bModel_input_function_init,
   bModel_input_function_updateStartValues,
   bModel_output_function,
   bModel_function_storeDelayed,
   bModel_updateBoundVariableAttributes,
   bModel_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   bModel_functionInitialEquations_lambda0,
   bModel_functionRemovedInitialEquations,
   bModel_updateBoundParameters,
   bModel_checkForAsserts,
   bModel_function_ZeroCrossingsEquations,
   bModel_function_ZeroCrossings,
   bModel_function_updateRelations,
   bModel_zeroCrossingDescription,
   bModel_relationDescription,
   bModel_function_initSample,
   bModel_INDEX_JAC_A,
   bModel_INDEX_JAC_B,
   bModel_INDEX_JAC_C,
   bModel_INDEX_JAC_D,
   bModel_initialAnalyticJacobianA,
   bModel_initialAnalyticJacobianB,
   bModel_initialAnalyticJacobianC,
   bModel_initialAnalyticJacobianD,
   bModel_functionJacA_column,
   bModel_functionJacB_column,
   bModel_functionJacC_column,
   bModel_functionJacD_column,
   bModel_linear_model_frame,
   bModel_linear_model_datarecovery_frame,
   bModel_mayer,
   bModel_lagrange,
   bModel_pickUpBoundsForInputsInOptimization,
   bModel_setInputData,
   bModel_getTimeGrid,
   bModel_symbolicInlineSystem,
   bModel_function_initSynchronous,
   bModel_function_updateSynchronous,
   bModel_function_equationsSynchronous,
   bModel_inputNames,
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

#define _OMC_LIT_RESOURCE_3_name_data "bModel"
#define _OMC_LIT_RESOURCE_3_dir_data "/home/shuang/MyProject/outputs/bModel_1575432158797_0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,6,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,53,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void bModel_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &bModel_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "bModel";
  data->modelData->modelFilePrefix = "bModel";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/shuang/MyProject/outputs/bModel_1575432158797_0";
  data->modelData->modelGUID = "{5d70f1d8-ff31-4b08-af62-021e6cbc81a5}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "bModel_init.c"
    ;
  static const char contents_info[] =
    #include "bModel_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "bModel_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "bModel_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 2;
  data->modelData->nVariablesReal = 15;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 7;
  data->modelData->nParametersInteger = 1;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 9;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 1;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 1;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "bModel_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 34;
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
  
    bModel_setupDataStruc(&data, threadData);
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


