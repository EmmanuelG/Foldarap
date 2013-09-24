/*
*/

nut_height=3;
nut_dia=8;

spacer_height=2;

screw_dia=4;

ros_dia = 20;

num_handles=5;

$fn=15;

module trapezoidNut(
	length=45,			// axial length of the threaded rod
	radius=25,			// outer radius of the nut
	pitch=10,				// axial distance from crest to crest
	pitchRadius=10,		// radial distance from center to mid-profile
	threadHeightToPitch=0.5,	// ratio between the height of the profile and the pitch
						// std value for Acme or metric lead screw is 0.5
	profileRatio=0.5,		// ratio between the lengths of the raised part of the profile and the pitch
						// std value for Acme or metric lead screw is 0.5
	threadAngle=30,		// angle between the two faces of the thread
						// std value for Acme is 29 or for metric lead screw is 30
	RH=true,				// true/false the thread winds clockwise looking along shaft, i.e.follows the Right Hand Rule
	countersunk=0,			// depth of 45 degree chamfered entries, normalized to pitch
	clearance=0.1,			// radial clearance, normalized to thread height
	backlash=0.1,			// axial clearance, normalized to pitch
	stepsPerTurn=24			// number of slices to create per turn
		)
{
	difference() 
	{
		cylinder(
			h=length,
			r1=radius, 
			r2=radius,
			$fn=6
				);
		
		trapezoidThreadNegativeSpace(
			length=length, 					// axial length of the threaded rod 
			pitch=pitch, 					// axial distance from crest to crest
			pitchRadius=pitchRadius, 			// radial distance from center to mid-profile
			threadHeightToPitch=threadHeightToPitch, 	// ratio between the height of the profile and the pitch 
										// std value for Acme or metric lead screw is 0.5
			profileRatio=profileRatio, 			// ratio between the lengths of the raised part of the profile and the pitch
										// std value for Acme or metric lead screw is 0.5
			threadAngle=threadAngle,			// angle between the two faces of the thread
										// std value for Acme is 29 or for metric lead screw is 30
			RH=true, 						// true/false the thread winds clockwise looking along shaft
										// i.e.follows  Right Hand Rule
			countersunk=countersunk,			// depth of 45 degree countersunk entries, normalized to pitch
			clearance=clearance, 				// radial clearance, normalized to thread height
			backlash=backlash, 				// axial clearance, normalized to pitch
			stepsPerTurn=stepsPerTurn 			// number of slices to create per turn
				);	
	}
}

render() difference(){
	cylinder(r=ros_dia/2, h=nut_height+spacer_height);
	translate([0,0,spacer_height])trapezoidNut(nut_height+1,nut_dia/2);
	cylinder(r=screw_dia/2, h=nut_height+spacer_height);
	for(hand=[0:num_handles-1]){
//		angle=hand*360/num_handles;
//		translate([ros_dia/2*cos(angle),ros_dia/2*sin(angle), 0]) cylinder(r=4, h=nut_height+spacer_height);
		translate([ros_dia/2*cos(hand*360/num_handles),ros_dia/2*sin(hand*360/num_handles), 0]) cylinder(r=4, h=nut_height+spacer_height);	}
}

