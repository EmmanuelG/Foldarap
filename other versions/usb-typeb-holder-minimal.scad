//Created by NeoTheFox 
//2014

bolt_radius = 4;

difference()
{
	hull()
	{
		cube([23,23,23]);
		
		translate([0,(23-18.2)/2,23])
		cube([20, 18.2, 14.1]);
	}
	cube([20,30,20]);

	translate([0,(23-12.2)/2,23])
	cube([30, 12.2, 11.1]);

	translate([23/2 + 5, 23/2, 10])
	rotate([0,90,0])
	#cylinder(r=(bolt_radius + 0.1)/2, h=10, $fn=64);
}
