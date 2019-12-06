model bModel
  Modelica.Mechanics.Translational.Sensors.SpeedSensor SpeedSensor;
  Modelica.Mechanics.Translational.Components.Mass Mass(L = 1, m = 1);
  Modelica.Mechanics.Translational.Sources.ForceStep ForceStep(useSupport = false, stepForce = 1, startTime = 0, offsetForce = 1);
  Modelica.Mechanics.Translational.Components.Spring Spring(s_rel0 = 0, c = 1);
equation
 connect(ForceStep.flange,Spring.flange_a);
 connect(Mass.flange_b,SpeedSensor.flange);
 connect(Spring.flange_b,Mass.flange_a);
end bModel;