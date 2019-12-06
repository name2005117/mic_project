model aModel
  Modelica.Mechanics.Translational.Components.Mass Mass(m = 2, L = 2, v(start=2),a(start=1));
  Modelica.Mechanics.Translational.Components.Spring Spring(s_rel0 = 0, c = 1);
  Modelica.Mechanics.Translational.Components.Fixed Fixed(s0 = 0);
equation
 connect(Fixed.flange,Spring.flange_a);
 connect(Spring.flange_b,Mass.flange_a);
end aModel;