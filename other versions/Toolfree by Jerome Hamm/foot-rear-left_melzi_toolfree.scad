barSection = 20;
barGDepth = 2.5;
barGWidth = 6;

screwHeadR = 9/2;
screwHole = 4.128/2;

footWidth = 28;
footDepth = 20;
footBredth = 3;
footX = 3.5;
footY = -7.19;
footZ = 0;
footHoleZ = 33;

$fn=360;			// For rendering

bottomScrewHead = 0;

module barGI(barLen)
{
	translate([-barSection/2,0,-barSection/2])difference(){
		cube([barSection, barLen, barSection]);
		translate([(barSection-barGWidth)/2,-1,barSection-barGDepth])cube([barGWidth, barLen+2, barGDepth+1]);
		translate([(barSection-barGWidth)/2,-1,-1])cube([barGWidth, barLen+2, barGDepth+1]);
	}
}

module barGL(barLen)
{
	translate([-barSection/2,0,-barSection/2])difference(){
		cube([barSection, barLen, barSection]);
		translate([(barSection-barGWidth)/2,-1,-1])cube([barGWidth, barLen+2, barGDepth+1]);
		translate([-1,-1,(barSection-barGWidth)/2])cube([barGDepth+1, barLen+2, barGWidth]);
	}
}

module barF(barLen)
{
	translate([-barSection/2,0,-barSection/2]){
		cube([barSection, barLen, barSection]);
	}
}

//%translate([-793.56,-531.28,0])import("foot-rear-left_melzi.stl");
mirror([1,0,0])rotate([0,0,180])
render()union(){
// Base
difference(){
	union(){
//		translate([0,-43,0])cube([97, 43, 3]);
		linear_extrude(height=3)polygon([[0,0], [83+footDepth, 0], [83+footDepth, -33], [73+footDepth, -43], [59, -43], [59, -34], [46, -25], [40, -25], [27, -34], [27, -43], [0, -43]]);
		rotate([0,-90,0])translate([0,0,-26])linear_extrude(height=26)polygon([[0,0], [27, 0], [27, -39], [23, -43], [0,-43]]);
		rotate([0,-90,0])translate([0,0,-26])linear_extrude(height=3)polygon([[0,0], [27, 0], [27, -18], [33, -23], [33, -27], [27, -32], [27, -39], [23, -43], [0,-43]]);
		rotate([0,-90,0])translate([0,0,-86])linear_extrude(height=26)polygon([[0,0], [27, 0], [27, -39], [23, -43], [0,-43]]);
		rotate([0,-90,0])translate([0,0,-63])linear_extrude(height=3)polygon([[0,0], [27, 0], [27, -18], [33, -23], [33, -27], [27, -32], [27, -39], [23, -43], [0,-43]]);
		rotate([90,0,0])translate([26,0,0])linear_extrude(height=3)polygon([[0,0], [0, 23], [14, 15], [20,15], [34,23], [34,0]]);
//		rotate([90,0,0])translate([26,0,14])linear_extrude(height=4)polygon([[0,0], [0, 27], [2.3, 27], [2.3, 4], [31.7,4], [31.7,27], [34,27], [34,0]]);
		rotate([90,0,0])translate([26,3,0])linear_extrude(height=34)polygon([[0,0], [0, 4], [1, 0]]);
		rotate([90,0,0])translate([60,3,0])linear_extrude(height=34)polygon([[0,0], [0, 4], [-1, 0]]);

		rotate([90,0,0])translate([86,0,0])linear_extrude(height=3)polygon([[0,0], [0, 27], [footDepth-13, 27], [footDepth-3, 17], [footDepth-3,0]]);
		rotate([90,0,0])translate([86,3,13])linear_extrude(height=30)polygon([[0,0], [0, 4], [1, 0]]);
//Foot (solid part)
		rotate([90,0,90])translate([-15,0,82])linear_extrude(height=footDepth+1)polygon([[0,0], [0, 13], [2, 15], [14, 15], [14,0]]);
		rotate([90,0,90])translate([-5,15,82])linear_extrude(height=footDepth+1)polygon([[0,0], [2,2], [3, 0]]);
//Washers
		translate([13,2,13])rotate([90,0,0])cylinder(r=screwHeadR, h=3);	
		translate([73,2,13])rotate([90,0,0])cylinder(r=screwHeadR, h=3);	

	}
	translate([13,-13,3])rotate([90,0,90])barGI(100);
	translate([13,-13,-1])cylinder(r=3,h=5);
	translate([13,-33,-1])cylinder(r=screwHole,h=5);
	translate([3,-100,3])cube([20, 80, 30]);
	translate([73,-13,3])rotate([90,0,90])barGI(100);
	translate([73,-13,-1])cylinder(r=3,h=5);
	translate([73,-33,-1])cylinder(r=screwHole,h=5);
	translate([63,-100,3])cube([20, 80, 30]);
	translate([13,3,13])rotate([90,0,0])cylinder(r=screwHole,h=10);
	translate([73,3,13])rotate([90,0,0])cylinder(r=screwHole,h=10);
}
}
