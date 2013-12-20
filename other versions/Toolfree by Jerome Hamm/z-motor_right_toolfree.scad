barSection = 20;
barGDepth = 2.5;
barGWidth = 6;

skinBredth = 4;

height = 34;

screwHeadR = 9/2;
screwHoleR = 4.128/2;
M3screwHoleR = 3.2/2;
fixScrewX = 0;
fixScrewY = -14;
fixScrewZ = height/2;
mobScrewX = barSection;
mobScrewY = 11;
mobScrewZ = height-10;

$fn = 360;

%translate([106.94, 270.88, 0])import("z-motor_right.stl");



module barG2(barLen)
{
	translate([-barSection/2,0,-barSection/2])difference(){
		cube([barSection, barLen, barSection]);
		translate([(barSection-barGWidth)/2,-1,barSection-barGDepth])cube([barGWidth, barLen+2, barGDepth+1]);
		translate([(barSection-barGWidth)/2,-1,-1])cube([barGWidth, barLen+2, barGDepth+1]);
	}
}

mirror([1,0,0])
union(){
difference(){
	union(){
		translate([0,-barSection-2*skinBredth,0])cube([barSection+skinBredth, barSection+2*skinBredth, height]);
		translate([fixScrewX-2,fixScrewY,fixScrewZ])rotate([0,90,0])cylinder(r=screwHeadR, h=3);
	}
	translate([barSection/2+skinBredth, -barSection/2-skinBredth,-1])rotate([90,0,0])barG2(100);
	translate([barSection+skinBredth-1, -barSection-skinBredth,-1])cube([2, barSection, 100]);
	#translate([fixScrewX-3,fixScrewY,fixScrewZ])rotate([0,90,0])cylinder(r=screwHoleR, h=skinBredth+3+2);
	#translate([9,-barSection-2*skinBredth+1+2.5,31.5])rotate([90,0,0])cylinder(r=1.3, h=4);
	#translate([9-1.3,-barSection-2*skinBredth+1-1.5,31.5-8])cube([2.6,4,8]);
	#translate([19,-barSection-2*skinBredth+1+2.5,31.5])rotate([90,0,0])cylinder(r=1.3, h=4);
	#translate([19-1.3,-barSection-2*skinBredth+1-1.5,31.5-8])cube([2.6,4,8]);
}

difference(){
	translate([mobScrewX,0,height])rotate([0,90,0])linear_extrude(height = skinBredth){
		polygon([[0,0], [0, mobScrewY+6], [20, mobScrewY+6], [30, 0]]);
	}
	#translate([mobScrewX-1,mobScrewY,mobScrewZ])rotate([0,90,0])cylinder(r=screwHoleR, h=skinBredth+2);
	#translate([mobScrewX-1,mobScrewY,mobScrewZ-screwHoleR])cube([skinBredth+2,7,screwHoleR*2]);
}
%translate([mobScrewX-5,mobScrewY,mobScrewZ])rotate([270,0,0])rotate([0,90,0]) import("M4-rosettes.stl");

difference(){
	translate([-14.6,-68.9,0])linear_extrude(height = skinBredth+1){
		polygon([[0,2.54], [0, 14*2.54-2.54], [2, 14*2.54], [15, 14*2.54+9.33], [14*2.54, 14*2.54+9.33], [14*2.54, 2.54], [14*2.54-2, 0], [2, 0]]);
	}
	translate([-9,-64.1,-1])rotate([0,0,90])hull(){
		cylinder(r=M3screwHoleR,h=skinBredth+1+2);
		translate([0,1,0])cylinder(r=M3screwHoleR,h=skinBredth+1+2);
	}
	translate([12.74+1+2*M3screwHoleR,-64.1,-1])rotate([0,0,90])hull(){
		cylinder(r=M3screwHoleR,h=skinBredth+1+2);
		translate([0,1,0])cylinder(r=M3screwHoleR,h=skinBredth+1+2);
	}
	//translate([12.74+M3screwHoleR,-64.1-M3screwHoleR,-1])cube([1+2*M3screwHoleR, 2*M3screwHoleR, 5]);
	translate([-9,-38.2,-1])rotate([0,0,90])hull(){
		cylinder(r=M3screwHoleR,h=skinBredth+1+2);
		translate([0,1,0])cylinder(r=M3screwHoleR,h=skinBredth+1+2);
	}
	//translate([-11.58,-38.2-M3screwHoleR,-1])cube([1+2*M3screwHoleR, 2*M3screwHoleR, 5]);
	translate([3.5,-51,-1])cylinder(r=12,h=skinBredth+1+2);
}

translate([0,-35,12])rotate([0,90,0])linear_extrude(height = 21){
	polygon([[0,10], [10, 10], [10, 0]]);
}
}
