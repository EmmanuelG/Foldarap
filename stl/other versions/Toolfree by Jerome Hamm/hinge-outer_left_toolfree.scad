barSection = 20;
barGDepth = 2.5;
barGWidth = 6;

skinBredth = 4;

height = 46;
linkHeight = 10;

screwHeadR = 9/2;
screwHoleR = 4.128/2;
M3screwHoleR = 3.2/2;
M3nutR = 6.4/2;
M3nutH = 2.4;
fixScrewZ = height/2;
mobScrewX = barSection;
mobScrewY = -11;
mobScrewZ = height-10;

cylR = 15;
cylH = 10;
cylX = barSection+skinBredth;
cylY = 44;
cylZ = 6;

$fn = 360;

module barG2(barLen)
{
	translate([-barSection/2,0,-barSection/2])difference(){
		cube([barSection, barLen, barSection]);
		translate([(barSection-barGWidth)/2,-1,barSection-barGDepth])cube([barGWidth, barLen+2, barGDepth+1]);
		translate([(barSection-barGWidth)/2,-1,-1])cube([barGWidth, barLen+2, barGDepth+1]);
	}
}


%translate([338.24,403.67,-5])import("hinge-outer_left.stl");

//mirror([1,0,0])
union(){
difference(){
	union(){
		cube([barSection+skinBredth, barSection+2*skinBredth, height]);
		translate([-2,barSection/2+skinBredth,fixScrewZ])rotate([0,90,0])cylinder(r=screwHeadR, h=3);
	}
	translate([barSection/2+skinBredth,barSection/2+skinBredth,-1])rotate([90,0,0])barG2(100);
	translate([barSection+skinBredth-1,skinBredth,-1])cube([2,20,100]);
	translate([-3,barSection/2+skinBredth,fixScrewZ])rotate([0,90,0])cylinder(r=screwHoleR, h=3+skinBredth+2);
}
%translate([mobScrewX-5,mobScrewY,mobScrewZ])rotate([270,0,0])rotate([0,90,0]) import("M4-rosettes.stl");

difference(){
	translate([mobScrewX,0,height])rotate([0,90,0])linear_extrude(height = skinBredth){
		polygon([[0,0], [0, mobScrewY-6], [20, mobScrewY-6], [30, 0]]);
	}
	#translate([mobScrewX-1,mobScrewY,mobScrewZ])rotate([0,90,0])cylinder(r=screwHoleR, h=skinBredth+2);
	#translate([mobScrewX-1,mobScrewY-6-1,mobScrewZ-screwHoleR])cube([skinBredth+2,7,screwHoleR*2]);
}

translate([barSection+skinBredth,barSection+2*skinBredth,0])linear_extrude(height = linkHeight){
	polygon([[0,0], [0, 10], [-2, 6], [-10, 0]]);
}

difference(){
	translate([cylX,cylY,cylZ])rotate([0,90,0])cylinder(r=cylR, h=cylH);
	#translate([cylX-1,cylY,cylZ])rotate([0,90,0])cylinder(r=M3screwHoleR, h=cylH+2);
	#translate([cylX-1,cylY-cylR-1,-cylR])cube([cylH+2, 2*cylR+2, cylR]);
	#translate([cylX-1,cylY,cylZ])rotate([90,0,90]) cylinder(h=cylH-skinBredth+1, r=M3nutR+0.2, $fn=6);
}

translate([cylX,cylY+cylR,cylZ])rotate([0,90,0])linear_extrude(height = cylH){
	polygon([[0,0], [-8.7, 0], [-8.7, -1], [2.3, -11]]);
}
}
