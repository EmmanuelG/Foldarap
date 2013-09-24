barSection = 20;
barGDepth = 2.5;
barGWidth = 6;

screwHeadR = 9/2;
screwHole = 4.2/2;			//4.128/2;

footWidth = 28;
footDepth = 20;
footBredth = 3;
footX = 3.5;
footY = -13.19;
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

//%translate([250,250,0])import("foot-front-left.stl");
//mirror([1,0,0])
render()union(){
// Base
difference(){
	union(){
		translate([-31.5,3.8,0])cube([63, 86, 23]);
		translate([-18.5,5,13])rotate([90,0,0])cylinder(r=screwHeadR, h=3);
		translate([-35+2,17+60,11.5])rotate([0,90,0])cylinder(r=screwHeadR, h=3);
		if(bottomScrewHead==1){
			translate([11.5,16,-2])cylinder(r=screwHeadR, h=3);	
			translate([11.5,16+60,-2])cylinder(r=screwHeadR, h=3);
		}
	}
	#translate([-18.5,17,-1])rotate([90,0,0])barGL(100);
	#translate([85,17,13])rotate([0,0,90])barF(100);
	#translate([11.5,16,-3])cylinder(r=screwHole, h=10);
	#translate([-18.5,17+60,-1])rotate([90,0,0])barGI(100);
	#translate([85,17+60,13])rotate([0,0,90])barF(100);
	#translate([14.5,17+13,3])cube([14,34,21]);
	#translate([11.5,16+60,-3])cylinder(r=screwHole, h=10);
	#translate([-18.5,10,13])rotate([90,0,0])cylinder(r=screwHole, h=10);
	#translate([-35,17+60,11.5])rotate([0,90,0])cylinder(r=screwHole, h=10);
	#translate([-35,17+13,-1])cube([46.5,34,25]);
	#translate([-38+5/2,91,24])rotate([90,45,0])cube([5,5,90]);
}
// Foot
translate([footX, footY, footZ])difference(){
//	translate([11.5,-7.19,0])cube([footWidth, footDepth, 43]);
	translate([0,0,0])cube([footWidth, footDepth, 43]);
	#translate([footWidth/2,footDepth+footBredth-2,footHoleZ])rotate([90,0,0]) cylinder(r=screwHole, h=footBredth+2);
	#translate([(footWidth)/2-screwHole,footDepth-footBredth-1,footHoleZ])cube([2*screwHole,footBredth+2,10]);
	translate([footBredth,-(footBredth),15]) cube([footWidth-2*footBredth,footDepth,30]);
	translate([footWidth+1,-21.5,40]) rotate([0,45,90])cube([15,footWidth+2,footWidth+2]);
	translate([footWidth/2,footDepth+1,50]) rotate([90,0,0])cylinder(r=(footWidth-2*footBredth)/2, h=footBredth+2);
}
//%translate([footX+footWidth/2,4,33])rotate([90,0,0]) import("M4-rosettes.stl");
%translate([footX+footWidth/2,4,33])rotate([90,90+36,0]) import("M4-rosettes.stl");
}
