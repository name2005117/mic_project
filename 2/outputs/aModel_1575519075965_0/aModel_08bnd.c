/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "aModel_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int aModel_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}

void aModel_updateBoundParameters_0(DATA *data, threadData_t *threadData);
extern void aModel_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 19
type: ALGORITHM

  assert(Spring.s_rel0 >= 0.0, "Variable violating min constraint: 0.0 <= Spring.s_rel0, has value: " + String(Spring.s_rel0, "g"));
*/
OMC_DISABLE_OPT
static void aModel_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,68,"Variable violating min constraint: 0.0 <= Spring.s_rel0, has value: ");
  modelica_string tmp2;
  static int tmp3 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp3)
  {
    tmp0 = GreaterEq(data->simulationInfo->realParameter[4],0.0);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[4], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Mechanics/Translational.mo",1890,7,1890,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nSpring.s_rel0 >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp3 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 20
type: ALGORITHM

  assert(Spring.c >= 0.0, "Variable violating min constraint: 0.0 <= Spring.c, has value: " + String(Spring.c, "g"));
*/
OMC_DISABLE_OPT
static void aModel_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  modelica_boolean tmp4;
  static const MMC_DEFSTRINGLIT(tmp5,63,"Variable violating min constraint: 0.0 <= Spring.c, has value: ");
  modelica_string tmp6;
  static int tmp7 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp7)
  {
    tmp4 = GreaterEq(data->simulationInfo->realParameter[3],0.0);
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[3], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Mechanics/Translational.mo",1888,7,1889,26,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nSpring.c >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp7 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 21
type: ALGORITHM

  assert(Mass.stateSelect >= StateSelect.never and Mass.stateSelect <= StateSelect.always, "Variable violating min/max constraint: StateSelect.never <= Mass.stateSelect <= StateSelect.always, has value: " + String(Mass.stateSelect, "d"));
*/
OMC_DISABLE_OPT
static void aModel_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  static const MMC_DEFSTRINGLIT(tmp10,111,"Variable violating min/max constraint: StateSelect.never <= Mass.stateSelect <= StateSelect.always, has value: ");
  modelica_string tmp11;
  static int tmp12 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp12)
  {
    tmp8 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[0],1);
    tmp9 = LessEq((modelica_integer)data->simulationInfo->integerParameter[0],5);
    if(!(tmp8 && tmp9))
    {
      tmp11 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[0], (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp10),tmp11);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Mechanics/Translational.mo",1750,7,1751,80,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMass.stateSelect >= StateSelect.never and Mass.stateSelect <= StateSelect.always", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp12 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 22
type: ALGORITHM

  assert(Mass.m >= 0.0, "Variable violating min constraint: 0.0 <= Mass.m, has value: " + String(Mass.m, "g"));
*/
OMC_DISABLE_OPT
static void aModel_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  modelica_boolean tmp13;
  static const MMC_DEFSTRINGLIT(tmp14,61,"Variable violating min constraint: 0.0 <= Mass.m, has value: ");
  modelica_string tmp15;
  static int tmp16 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp16)
  {
    tmp13 = GreaterEq(data->simulationInfo->realParameter[2],0.0);
    if(!tmp13)
    {
      tmp15 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[2], (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp14),tmp15);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.2/Mechanics/Translational.mo",1749,7,1749,69,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMass.m >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp16 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void aModel_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  aModel_eqFunction_1(data, threadData);
  aModel_eqFunction_19(data, threadData);
  aModel_eqFunction_20(data, threadData);
  aModel_eqFunction_21(data, threadData);
  aModel_eqFunction_22(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int aModel_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  aModel_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

