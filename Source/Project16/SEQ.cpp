#include "SEQ.h"
#include "Util.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatformFile.h"

KEYFRAME::KEYFRAME()
{
	
}
/*
KEYFRAME::KEYFRAME(float key, float time, bool is_half) 
{
	this->float_degrees = key;
	this->time = time;
	this->is_half = is_half;
}
*/
SEQ::SEQ()
{
	y_current_set = -1;
	y_prev_set = -1;
	y_change_body_animation = false;
	x_current_set = -1;
	x_prev_set = -1;
	x_change_body_animation = false;
	z_current_set = -1;
	z_prev_set = -1;
	z_change_body_animation = false;

	//change_body_animation = false;

	//Time = 0;

	//Initialize some rotation variables
	//kprev = 0;//or last one in seq?
	//kstart = 0;//goto k++, when t elapsed
	//k = 1;
	//keyframe_time_elapsed1 = 0;
	x_keyframe_time_elapsed2 = 0;
	x_delta = 0.0001;
	x_k = 0;
	x_kprev = 0;
	x_start_angle = 0;
	//body_yaw=0;
	//body_pitch=0;
	//body_roll=0;

	//initialization of new variables:
	//var full_curve_time;//full means twice actual length, or duration of curve

	//actual_curve_time
	x_gradient = 1;//default 1
	x_prev_half = false;
	x_frequency = 0.0001;//seconds
	x_elapsed = 0;
	x_angle = 0;//member variable so holds last state

	z_keyframe_time_elapsed2 = 0;
	z_delta = 0.0001;
	z_k = 0;
	z_kprev = 0;
	z_start_angle = 0;
	z_gradient = 1;//default 1
	z_prev_half = false;
	z_frequency = 0.0001;//seconds
	z_elapsed = 0;
	z_angle = 0;//member variable so holds last state

	y_keyframe_time_elapsed2 = 0;
	y_delta = 0.0001;
	y_k = 0;
	y_kprev = 0;
	y_start_angle = 0;
	y_gradient = 1;//default 1
	y_prev_half = false;
	y_frequency = 0.0001;//seconds
	y_elapsed = 0;
	y_angle = 0;//member variable so holds last state

	real_angle_y = 0;
	real_angle_z = 0;
	real_angle_x = 0;

	y_actual_curve_time = 0.0f;
	y_full_curve_time = 0.0f;
	x_actual_curve_time = 0.0f;
	x_full_curve_time = 0.0f;
	z_actual_curve_time = 0.0f;
	z_full_curve_time = 0.0f;
}

void SEQ::Play(float DeltaTime)
{
	PlayX(DeltaTime);
	PlayY(DeltaTime);
	PlayZ(DeltaTime);
}

void SEQ::StartAnimationSet(int n, TArray<KEYFRAME>* KEYS)
{
	new_set = n;

	if (animation_sets.Find(n)==NULL) {
		//key entry doesn't exist
		//add entry for id==n
		animation_sets.Add(n, KEYS);
	}

	y_change_body_animation = true;
	x_change_body_animation = true;
	z_change_body_animation = true;

	if (y_current_set==-1) {
		//No animation set has been assigned,
		//initialize variables:
		y_current_set = n;
		y_prev_set = n;
		y_change_body_animation = false;

		x_current_set = n;
		x_prev_set = n;
		x_change_body_animation = false;

		z_current_set = n;
		z_prev_set = n;
		z_change_body_animation = false;
	}
	else {
		//create 1 second used for blending
		TArray<KEYFRAME>* KEYS_LAST = *animation_sets.Find(y_current_set);
		float t = KEYS_LAST->GetData()[0].time;
		if (t<1.0f) {
			KEYS_LAST->GetData()[0].time = 1.0f;
		}
		//(animation_sets[n][animation_sets[n]->Num()-1]).
	}
}
void SEQ::StopAnimationSet(int return_to_set, TArray<KEYFRAME>* return_KEYS)
{
	StartAnimationSet(return_to_set, return_KEYS);
}//actually the same as StartAnimationSet

void SEQ::PlayY(float DeltaTime)
{
	//float angle = 0;

	//TimeX += DeltaTime;


	//draw first half and second half, for
	//half a curve and full curve
	//CalculateStartAngle();

	while (y_keyframe_time_elapsed2 >= (y_actual_curve_time))
	{
		//end of curve is NOW


		//var current_key;
		
		float current_key = animation_sets[y_current_set]->GetData()[y_k].float_degrees_y;
		//var prev_key;
		//prev_key=start_angle/4;
		float prev_key = animation_sets[y_prev_set]->GetData()[y_kprev].float_degrees_y;

		if (y_is_half) {
			//current_key is half
			//current_key and prev_key have now been set
			y_blue_curve_height = (current_key - prev_key);
			//show_message("blue height"+string(blue_curve_height));
			y_blue_curve_time = (y_full_curve_time);

			if (y_blue_curve_height<0) {
				y_gradient = -1;
			}
			else {
				y_gradient = +1;
			}
		}

		

		//var ktime;
		float ktime = animation_sets[y_current_set]->GetData()[y_k].time;

		//distance1=current_key-prev_key;//distance used for flipping

		if (animation_sets[y_prev_set]->GetData()[y_kprev].is_half_y)
		{
			
			y_prev_half = true;
			//distance1=current_key-prev_key;//distance used for flipping
			y_steepness = -(current_key - prev_key) / (ktime*ktime);
			if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
				y_steepness *= 2;
			}
		}
		else {
			//stee
			//distance1=current_key-prev_key;//distance used for flipping
			y_steepness = -(current_key - prev_key) / (ktime*ktime);
			if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
				y_steepness *= 2;
			}
			//flip_curve=false;//vertical
			y_prev_half = false;
		}
		if (y_prev_half == true) {
			//previous curve is half(blue)
			if (y_gradient == -1) {
				//gradient is negative
				//start_angle=(prev_key)/4;
				//green
				ktime *= 2;

				//start_angle is
				//start_angle=prev_key/4+(current_key/4-prev_key/4)*2;
				//start_angle=current_key/4-(current_key/4-prev_key/4)*2;
				//start_angle=start_angle+(current_key/4 - prev_key/4)/2;

				y_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
				if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
					y_steepness *= 2;
				}
				
				y_s2 = ktime / 2;
				y_start_angle = y_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - y_s2)*0.5 / y_delta))*(((ktime / 2) - y_s2)*y_steepness)*y_delta;
			}
			else {

				//gradient is positive
				ktime *= 2;

				//start_angle is
				//start_angle=prev_key/4+(current_key/4-prev_key/4)*2;
				//start_angle=current_key/4-(current_key/4-prev_key/4)*2;
				//start_angle=start_angle+(current_key/4 - prev_key/4)/2;

				y_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
				if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
					y_steepness *= 2;
				}

				//complete_time = ktime / 2;
				//white
				y_s1 = ktime / 2;
				y_a22 = y_s1*y_steepness;
				y_start_angle = y_start_angle + (y_s1*0.5 / y_delta)*y_a22*y_delta;
			}
		}

		//draw first half and second half, for
		//half a curve and full curve
		if (y_prev_half == false)
		{
			//complete_time = (ktime / 2);

			//angle1=start_angle;
			
			if (!y_is_half) {//is half is current curve

							 //draw rest of curve
							 /*
							 for(t2=0;t2<(ktime/2);t2+=delta){
							 //s1=t;
							 //a22=s1*steepness;
							 //angle=start_angle+(s1*0.5/delta)*a22*delta;
							 //y=start_y+angle*4;
							 s2=t2;
							 angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
							 draw_set_color(c_green);
							 draw_point((total_time_elapsed+ktime/2+t2)*40,start_y+angle*4);
							 }
							 */
							 //}
			}

			//last_angle=start_angle;
			y_s1 = ktime / 2;
			y_a22 = y_s1*y_steepness;
			//a = start_angle + (s1*0.5 / delta)*a22*delta;

			//second half:
			if (!y_is_half) {

				y_s2 = ktime / 2;
				y_start_angle = y_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - y_s2)*0.5 / y_delta))*(((ktime / 2) - y_s2)*y_steepness)*y_delta;

			}
			else {
				y_s1 = ktime / 2;
				y_start_angle = y_start_angle + (y_s1*0.5 / y_delta)*y_a22*y_delta;



				//draw_circle((total_time_elapsed+ktime/2)*40,start_y+start_angle*4,4,false);
			}

		}

		//if (ds_list_find_value(show_key, k)) {
		//draw at end of curve
		//y = start_y + start_angle * 4;
		//draw_circle(total_time_elapsed*40,y,4,false);
		//}

		//adjust k:
		y_kprev = y_k;
		y_k += 1;

		int number_of_keyframes = animation_sets[y_current_set]->Num();
		if (y_k == number_of_keyframes) {
			y_k = 0;//loop
		}

		if (y_change_body_animation) {
			//next key
			y_k = 0;
			//current set is key for map for y_k
			//prev_set is key for map for y_kprev
			y_prev_set = y_current_set;
			y_current_set = new_set;//by this point y_kprev is still prev_set
			y_change_body_animation = false;
			//then
		}
		else {
			//blending is complete, so make 
			y_prev_set = y_current_set;//y_kprev is now set to y_k so it corresponds to current_set array, good
		}

		//keyframe_time_elapsed2=0;//keyframe start

		y_keyframe_time_elapsed2 -= (y_actual_curve_time);

		//total_time_elapsed+=(actual_curve_time/15);//a variable used for debugging(total_)

		//next curve
		y_is_half = animation_sets[y_current_set]->GetData()[y_k].is_half_y;
		y_full_curve_time = animation_sets[y_current_set]->GetData()[y_k].time;
		if (y_is_half) {
			y_actual_curve_time = y_full_curve_time / 2;
		}
		else {
			y_actual_curve_time = y_full_curve_time;
		}
	}
	//maybe I want angle to be (member) variable to hold it's current or last value


	//Here's the clever bit


	//while(keyframe_time_elapsed2>=(actual_curve_time/15))
	//{
	//var current_key;
	float current_key = animation_sets[y_current_set]->GetData()[y_k].float_degrees_y;
	//var prev_key;
	//prev_key=start_angle/4;
	float prev_key = animation_sets[y_prev_set]->GetData()[y_kprev].float_degrees_y;

	if (y_is_half) {
		//current_key is half
		//current_key and prev_key have now been set
		y_blue_curve_height = (current_key - prev_key);
		//show_message("blue height"+string(blue_curve_height));
		y_blue_curve_time = (y_full_curve_time);

		if (y_blue_curve_height<0) {
			y_gradient = -1;
		}
		else {
			y_gradient = +1;
		}
	}

	//if (ds_list_find_value(destinations, kprev)) {
	//}
	//if (ds_list_find_value(destinations, kprev)) {
	//}

	//if (ds_list_find_value((id).is_half, kprev))
	//{
	//prev_key=-start_angle*4;
	//}

	//var ktime;
	float ktime = animation_sets[y_current_set]->GetData()[y_k].time;

	//distance1=current_key-prev_key;//distance used for flipping

	if (animation_sets[y_prev_set]->GetData()[y_kprev].is_half_y)
	{
		y_prev_half = true;
		//distance1=current_key-prev_key;//distance used for flipping
		y_steepness = -(current_key - prev_key) / (ktime*ktime);
		if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
			y_steepness *= 2;
		}
	}
	else {
		//stee
		//distance1=current_key-prev_key;//distance used for flipping
		y_steepness = -(current_key - prev_key) / (ktime*ktime);
		if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
			y_steepness *= 2;
		}
		//flip_curve=false;//vertical
		y_prev_half = false;
	}
	if (y_prev_half == true) {
		//previous curve is half(blue)
		if (y_gradient == -1) {
			//gradient is negative
			//start_angle=(prev_key)/4;
			//green
			ktime *= 2;

			y_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
			if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
				y_steepness *= 2;
			}

			if (y_keyframe_time_elapsed2>((y_actual_curve_time) / 2)) {
				//second half of a curve
				y_s2 = y_keyframe_time_elapsed2 - ((y_actual_curve_time) / 2);
				//s2=ktime/2;
				//draw point for this angle
				//
				//draw_set_color(c_green);
				y_angle = y_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - y_s2)*0.5 / y_delta))*(((ktime / 2) - y_s2)*y_steepness)*y_delta;
				//start_angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
			}
		}
		else {

			//gradient is positive
			ktime *= 2;

			y_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
			if (animation_sets[y_current_set]->GetData()[y_k].is_half_y) {
				y_steepness *= 2;
			}

			//complete_time = ktime / 2;
			//white

			if (y_keyframe_time_elapsed2 > ((y_actual_curve_time) / 2)) {

				if (y_is_half) {
					//draw_set_color(c_blue);//blue is d3, half a curve
				}
				else {
					//draw_set_color(c_green);//full, the problem seems to be with white(d1)
				}

				y_s1 = y_keyframe_time_elapsed2 - ((y_actual_curve_time) / 2);
				//s1=ktime/2;
				y_a22 = y_s1*y_steepness;
				y_angle = y_start_angle + (y_s1*0.5 / y_delta)*y_a22*y_delta;
			}
		}
	}

	//draw first half and second half, for
	//half a curve and full curve
	if (y_prev_half == false)
	{
		//complete_time = (ktime / 2);
		//if (keyframe_time_elapsed2 <= ((actual_curve_time/15)/2)) {

		if (y_is_half) {
			//draw_set_color(c_blue);//blue is d3, half a curve
		}
		else {
			//draw_set_color(c_white);//full, the problem seems to be with white(d1)
		}

		y_s1 = y_keyframe_time_elapsed2;
		y_a22 = y_s1*y_steepness;
		//blue curev here
		y_angle = y_start_angle + (y_s1*0.5 / y_delta)*y_a22*y_delta;

		if (!y_is_half) {//is half is current curve
						 //green here is second half of white
			if (y_keyframe_time_elapsed2 > ((y_actual_curve_time) / 2)) {
				//
				float t2 = y_keyframe_time_elapsed2 - ((y_actual_curve_time) / 2);
				y_s2 = t2;
				//angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
				y_angle = y_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - y_s2)*0.5 / y_delta))*(((ktime / 2) - y_s2)*y_steepness)*y_delta;
				//draw_set_color(c_green);
			}
		}

		//last_angle=start_angle;
		y_s1 = ktime / 2;
		y_a22 = y_s1*y_steepness;
		//a = start_angle + (s1*0.5 / delta)*a22*delta;

	}

	y_keyframe_time_elapsed2 += DeltaTime;

	real_angle_y = -y_angle * 4;
}
/*
I'm treating the two arrays as one
I need to I want to have only
only one array(animation set) active except when blending, going from one key from
the previous set to the first key of the new set(KEYS_NEW) once blending is done,
make k and k_prev correspond to the NEXT_KEYS, KEYS=NEXT_KEYS KEYS->GetData()[y_k]
a flag blending_done=true

but
If there are no keys in NEXT_KEYS then blending is done, actually
blending is done when the current curve has completed from KEYS(current animation set)

blending must occur at the end of the current key of the current set(not at the end of the set)
*//*
KEYFRAME SEQ::GetKey(int k)
{
	return KEYFRAME();
}
*/

void SEQ::PlayZ(float DeltaTime)
{

	//float angle = 0;

	//TimeX += DeltaTime;


	//draw first half and second half, for
	//half a curve and full curve
	//CalculateStartAngle();

	while (z_keyframe_time_elapsed2 >= (z_actual_curve_time))
	{
		//end of curve is NOW


		//var current_key;

		float current_key = animation_sets[z_current_set]->GetData()[z_k].float_degrees_z;
		//var prev_key;
		//prev_key=start_angle/4;
		float prev_key = animation_sets[z_prev_set]->GetData()[z_kprev].float_degrees_z;

		if (z_is_half) {
			//current_key is half
			//current_key and prev_key have now been set
			z_blue_curve_height = (current_key - prev_key);
			//show_message("blue height"+string(blue_curve_height));
			z_blue_curve_time = (z_full_curve_time);

			if (z_blue_curve_height<0) {
				z_gradient = -1;
			}
			else {
				z_gradient = +1;
			}
		}



		//var ktime;
		float ktime = animation_sets[z_current_set]->GetData()[z_k].time;

		//distance1=current_key-prev_key;//distance used for flipping

		if (animation_sets[z_prev_set]->GetData()[z_kprev].is_half_z)
		{

			z_prev_half = true;
			//distance1=current_key-prev_key;//distance used for flipping
			z_steepness = -(current_key - prev_key) / (ktime*ktime);
			if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
				z_steepness *= 2;
			}
		}
		else {
			//stee
			//distance1=current_key-prev_key;//distance used for flipping
			z_steepness = -(current_key - prev_key) / (ktime*ktime);
			if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
				z_steepness *= 2;
			}
			//flip_curve=false;//vertical
			z_prev_half = false;
		}
		if (z_prev_half == true) {
			//previous curve is half(blue)
			if (z_gradient == -1) {
				//gradient is negative
				//start_angle=(prev_key)/4;
				//green
				ktime *= 2;

				//start_angle is
				//start_angle=prev_key/4+(current_key/4-prev_key/4)*2;
				//start_angle=current_key/4-(current_key/4-prev_key/4)*2;
				//start_angle=start_angle+(current_key/4 - prev_key/4)/2;

				z_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
				if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
					z_steepness *= 2;
				}

				z_s2 = ktime / 2;
				z_start_angle = z_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - z_s2)*0.5 / z_delta))*(((ktime / 2) - z_s2)*z_steepness)*z_delta;
			}
			else {

				//gradient is positive
				ktime *= 2;

				//start_angle is
				//start_angle=prev_key/4+(current_key/4-prev_key/4)*2;
				//start_angle=current_key/4-(current_key/4-prev_key/4)*2;
				//start_angle=start_angle+(current_key/4 - prev_key/4)/2;

				z_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
				if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
					z_steepness *= 2;
				}

				//complete_time = ktime / 2;
				//white
				z_s1 = ktime / 2;
				z_a22 = z_s1*z_steepness;
				z_start_angle = z_start_angle + (z_s1*0.5 / z_delta)*z_a22*z_delta;
			}
		}

		//draw first half and second half, for
		//half a curve and full curve
		if (z_prev_half == false)
		{
			//complete_time = (ktime / 2);

			//angle1=start_angle;

			if (!z_is_half) {//is half is current curve

							 //draw rest of curve
							 /*
							 for(t2=0;t2<(ktime/2);t2+=delta){
							 //s1=t;
							 //a22=s1*steepness;
							 //angle=start_angle+(s1*0.5/delta)*a22*delta;
							 //y=start_z+angle*4;
							 s2=t2;
							 angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
							 draw_set_color(c_green);
							 draw_point((total_time_elapsed+ktime/2+t2)*40,start_z+angle*4);
							 }
							 */
							 //}
			}

			//last_angle=start_angle;
			z_s1 = ktime / 2;
			z_a22 = z_s1*z_steepness;
			//a = start_angle + (s1*0.5 / delta)*a22*delta;

			//second half:
			if (!z_is_half) {

				z_s2 = ktime / 2;
				z_start_angle = z_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - z_s2)*0.5 / z_delta))*(((ktime / 2) - z_s2)*z_steepness)*z_delta;

			}
			else {
				z_s1 = ktime / 2;
				z_start_angle = z_start_angle + (z_s1*0.5 / z_delta)*z_a22*z_delta;



				//draw_circle((total_time_elapsed+ktime/2)*40,start_z+start_angle*4,4,false);
			}

		}

		//if (ds_list_find_value(show_key, k)) {
		//draw at end of curve
		//y = start_z + start_angle * 4;
		//draw_circle(total_time_elapsed*40,y,4,false);
		//}

		//adjust k:
		z_kprev = z_k;
		z_k += 1;

		int number_of_keyframes = animation_sets[z_current_set]->Num();
		if (z_k == number_of_keyframes) {
			z_k = 0;//loop
		}

		if (z_change_body_animation) {
			//next key
			z_k = 0;
			//current set is key for map for z_k
			//prev_set is key for map for z_kprev
			z_prev_set = z_current_set;
			z_current_set = new_set;//by this point z_kprev is still prev_set
			z_change_body_animation = false;
			//then
		}
		else {
			//blending is complete, so make 
			z_prev_set = z_current_set;//z_kprev is now set to z_k so it corresponds to current_set array, good
		}

		//keyframe_time_elapsed2=0;//keyframe start

		z_keyframe_time_elapsed2 -= (z_actual_curve_time);

		//total_time_elapsed+=(actual_curve_time/15);//a variable used for debugging(total_)

		//next curve
		z_is_half = animation_sets[z_current_set]->GetData()[z_k].is_half_z;
		z_full_curve_time = animation_sets[z_current_set]->GetData()[z_k].time;
		if (z_is_half) {
			z_actual_curve_time = z_full_curve_time / 2;
		}
		else {
			z_actual_curve_time = z_full_curve_time;
		}
	}
	//maybe I want angle to be (member) variable to hold it's current or last value


	//Here's the clever bit


	//while(keyframe_time_elapsed2>=(actual_curve_time/15))
	//{
	//var current_key;
	float current_key = animation_sets[z_current_set]->GetData()[z_k].float_degrees_z;
	//var prev_key;
	//prev_key=start_angle/4;
	float prev_key = animation_sets[z_prev_set]->GetData()[z_kprev].float_degrees_z;

	if (z_is_half) {
		//current_key is half
		//current_key and prev_key have now been set
		z_blue_curve_height = (current_key - prev_key);
		//show_message("blue height"+string(blue_curve_height));
		z_blue_curve_time = (z_full_curve_time);

		if (z_blue_curve_height<0) {
			z_gradient = -1;
		}
		else {
			z_gradient = +1;
		}
	}

	//if (ds_list_find_value(destinations, kprev)) {
	//}
	//if (ds_list_find_value(destinations, kprev)) {
	//}

	//if (ds_list_find_value((id).is_half, kprev))
	//{
	//prev_key=-start_angle*4;
	//}

	//var ktime;
	float ktime = animation_sets[z_current_set]->GetData()[z_k].time;

	//distance1=current_key-prev_key;//distance used for flipping

	if (animation_sets[z_prev_set]->GetData()[z_kprev].is_half_z)
	{
		z_prev_half = true;
		//distance1=current_key-prev_key;//distance used for flipping
		z_steepness = -(current_key - prev_key) / (ktime*ktime);
		if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
			z_steepness *= 2;
		}
	}
	else {
		//stee
		//distance1=current_key-prev_key;//distance used for flipping
		z_steepness = -(current_key - prev_key) / (ktime*ktime);
		if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
			z_steepness *= 2;
		}
		//flip_curve=false;//vertical
		z_prev_half = false;
	}
	if (z_prev_half == true) {
		//previous curve is half(blue)
		if (z_gradient == -1) {
			//gradient is negative
			//start_angle=(prev_key)/4;
			//green
			ktime *= 2;

			z_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
			if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
				z_steepness *= 2;
			}

			if (z_keyframe_time_elapsed2>((z_actual_curve_time) / 2)) {
				//second half of a curve
				z_s2 = z_keyframe_time_elapsed2 - ((z_actual_curve_time) / 2);
				//s2=ktime/2;
				//draw point for this angle
				//
				//draw_set_color(c_green);
				z_angle = z_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - z_s2)*0.5 / z_delta))*(((ktime / 2) - z_s2)*z_steepness)*z_delta;
				//start_angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
			}
		}
		else {

			//gradient is positive
			ktime *= 2;

			z_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
			if (animation_sets[z_current_set]->GetData()[z_k].is_half_z) {
				z_steepness *= 2;
			}

			//complete_time = ktime / 2;
			//white

			if (z_keyframe_time_elapsed2 > ((z_actual_curve_time) / 2)) {

				if (z_is_half) {
					//draw_set_color(c_blue);//blue is d3, half a curve
				}
				else {
					//draw_set_color(c_green);//full, the problem seems to be with white(d1)
				}

				z_s1 = z_keyframe_time_elapsed2 - ((z_actual_curve_time) / 2);
				//s1=ktime/2;
				z_a22 = z_s1*z_steepness;
				z_angle = z_start_angle + (z_s1*0.5 / z_delta)*z_a22*z_delta;
			}
		}
	}

	//draw first half and second half, for
	//half a curve and full curve
	if (z_prev_half == false)
	{
		//complete_time = (ktime / 2);
		//if (keyframe_time_elapsed2 <= ((actual_curve_time/15)/2)) {

		if (z_is_half) {
			//draw_set_color(c_blue);//blue is d3, half a curve
		}
		else {
			//draw_set_color(c_white);//full, the problem seems to be with white(d1)
		}

		z_s1 = z_keyframe_time_elapsed2;
		z_a22 = z_s1*z_steepness;
		//blue curev here
		z_angle = z_start_angle + (z_s1*0.5 / z_delta)*z_a22*z_delta;

		if (!z_is_half) {//is half is current curve
						 //green here is second half of white
			if (z_keyframe_time_elapsed2 > ((z_actual_curve_time) / 2)) {
				//
				float t2 = z_keyframe_time_elapsed2 - ((z_actual_curve_time) / 2);
				z_s2 = t2;
				//angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
				z_angle = z_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - z_s2)*0.5 / z_delta))*(((ktime / 2) - z_s2)*z_steepness)*z_delta;
				//draw_set_color(c_green);
			}
		}

		//last_angle=start_angle;
		z_s1 = ktime / 2;
		z_a22 = z_s1*z_steepness;
		//a = start_angle + (s1*0.5 / delta)*a22*delta;

	}

	z_keyframe_time_elapsed2 += DeltaTime;

	real_angle_z = -z_angle * 4;
}

void SEQ::PlayX(float DeltaTime)
{

	//float angle = 0;

	//TimeX += DeltaTime;


	//draw first half and second half, for
	//half a curve and full curve
	//CalculateStartAngle();

	while (x_keyframe_time_elapsed2 >= (x_actual_curve_time))
	{
		//end of curve is NOW


		//var current_key;

		float current_key = animation_sets[x_current_set]->GetData()[x_k].float_degrees_x;
		//var prev_key;
		//prev_key=start_angle/4;
		float prev_key = animation_sets[x_prev_set]->GetData()[x_kprev].float_degrees_x;

		if (x_is_half) {
			//current_key is half
			//current_key and prev_key have now been set
			x_blue_curve_height = (current_key - prev_key);
			//show_message("blue height"+string(blue_curve_height));
			x_blue_curve_time = (x_full_curve_time);

			if (x_blue_curve_height<0) {
				x_gradient = -1;
			}
			else {
				x_gradient = +1;
			}
		}



		//var ktime;
		float ktime = animation_sets[x_current_set]->GetData()[x_k].time;

		//distance1=current_key-prev_key;//distance used for flipping

		if (animation_sets[x_prev_set]->GetData()[x_kprev].is_half_x)
		{

			x_prev_half = true;
			//distance1=current_key-prev_key;//distance used for flipping
			x_steepness = -(current_key - prev_key) / (ktime*ktime);
			if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
				x_steepness *= 2;
			}
		}
		else {
			//stee
			//distance1=current_key-prev_key;//distance used for flipping
			x_steepness = -(current_key - prev_key) / (ktime*ktime);
			if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
				x_steepness *= 2;
			}
			//flip_curve=false;//vertical
			x_prev_half = false;
		}
		if (x_prev_half == true) {
			//previous curve is half(blue)
			if (x_gradient == -1) {
				//gradient is negative
				//start_angle=(prev_key)/4;
				//green
				ktime *= 2;

				//start_angle is
				//start_angle=prev_key/4+(current_key/4-prev_key/4)*2;
				//start_angle=current_key/4-(current_key/4-prev_key/4)*2;
				//start_angle=start_angle+(current_key/4 - prev_key/4)/2;

				x_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
				if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
					x_steepness *= 2;
				}

				x_s2 = ktime / 2;
				x_start_angle = x_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - x_s2)*0.5 / x_delta))*(((ktime / 2) - x_s2)*x_steepness)*x_delta;
			}
			else {

				//gradient is positive
				ktime *= 2;

				//start_angle is
				//start_angle=prev_key/4+(current_key/4-prev_key/4)*2;
				//start_angle=current_key/4-(current_key/4-prev_key/4)*2;
				//start_angle=start_angle+(current_key/4 - prev_key/4)/2;

				x_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
				if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
					x_steepness *= 2;
				}

				//complete_time = ktime / 2;
				//white
				x_s1 = ktime / 2;
				x_a22 = x_s1*x_steepness;
				x_start_angle = x_start_angle + (x_s1*0.5 / x_delta)*x_a22*x_delta;
			}
		}

		//draw first half and second half, for
		//half a curve and full curve
		if (x_prev_half == false)
		{
			//complete_time = (ktime / 2);

			//angle1=start_angle;

			if (!x_is_half) {//is half is current curve

							 //draw rest of curve
							 /*
							 for(t2=0;t2<(ktime/2);t2+=delta){
							 //s1=t;
							 //a22=s1*steepness;
							 //angle=start_angle+(s1*0.5/delta)*a22*delta;
							 //y=start_x+angle*4;
							 s2=t2;
							 angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
							 draw_set_color(c_green);
							 draw_point((total_time_elapsed+ktime/2+t2)*40,start_x+angle*4);
							 }
							 */
							 //}
			}

			//last_angle=start_angle;
			x_s1 = ktime / 2;
			x_a22 = x_s1*x_steepness;
			//a = start_angle + (s1*0.5 / delta)*a22*delta;

			//second half:
			if (!x_is_half) {

				x_s2 = ktime / 2;
				x_start_angle = x_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - x_s2)*0.5 / x_delta))*(((ktime / 2) - x_s2)*x_steepness)*x_delta;

			}
			else {
				x_s1 = ktime / 2;
				x_start_angle = x_start_angle + (x_s1*0.5 / x_delta)*x_a22*x_delta;



				//draw_circle((total_time_elapsed+ktime/2)*40,start_x+start_angle*4,4,false);
			}

		}

		//if (ds_list_find_value(show_key, k)) {
		//draw at end of curve
		//y = start_x + start_angle * 4;
		//draw_circle(total_time_elapsed*40,y,4,false);
		//}

		//adjust k:
		x_kprev = x_k;
		x_k += 1;

		int number_of_keyframes = animation_sets[x_current_set]->Num();
		if (x_k == number_of_keyframes) {
			x_k = 0;//loop
		}

		if (x_change_body_animation) {
			//next key
			x_k = 0;
			//current set is key for map for x_k
			//prev_set is key for map for x_kprev
			x_prev_set = x_current_set;
			x_current_set = new_set;//by this point x_kprev is still prev_set
			x_change_body_animation = false;
			//then
		}
		else {
			//blending is complete, so make 
			x_prev_set = x_current_set;//x_kprev is now set to x_k so it corresponds to current_set array, good
		}

		//keyframe_time_elapsed2=0;//keyframe start

		x_keyframe_time_elapsed2 -= (x_actual_curve_time);

		//total_time_elapsed+=(actual_curve_time/15);//a variable used for debugging(total_)

		//next curve
		x_is_half = animation_sets[x_current_set]->GetData()[x_k].is_half_x;
		x_full_curve_time = animation_sets[x_current_set]->GetData()[x_k].time;
		if (x_is_half) {
			x_actual_curve_time = x_full_curve_time / 2;
		}
		else {
			x_actual_curve_time = x_full_curve_time;
		}
	}
	//maybe I want angle to be (member) variable to hold it's current or last value


	//Here's the clever bit


	//while(keyframe_time_elapsed2>=(actual_curve_time/15))
	//{
	//var current_key;
	float current_key = animation_sets[x_current_set]->GetData()[x_k].float_degrees_x;
	//var prev_key;
	//prev_key=start_angle/4;
	float prev_key = animation_sets[x_prev_set]->GetData()[x_kprev].float_degrees_x;

	if (x_is_half) {
		//current_key is half
		//current_key and prev_key have now been set
		x_blue_curve_height = (current_key - prev_key);
		//show_message("blue height"+string(blue_curve_height));
		x_blue_curve_time = (x_full_curve_time);

		if (x_blue_curve_height<0) {
			x_gradient = -1;
		}
		else {
			x_gradient = +1;
		}
	}

	//if (ds_list_find_value(destinations, kprev)) {
	//}
	//if (ds_list_find_value(destinations, kprev)) {
	//}

	//if (ds_list_find_value((id).is_half, kprev))
	//{
	//prev_key=-start_angle*4;
	//}

	//var ktime;
	float ktime = animation_sets[x_current_set]->GetData()[x_k].time;

	//distance1=current_key-prev_key;//distance used for flipping

	if (animation_sets[x_prev_set]->GetData()[x_kprev].is_half_x)
	{
		x_prev_half = true;
		//distance1=current_key-prev_key;//distance used for flipping
		x_steepness = -(current_key - prev_key) / (ktime*ktime);
		if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
			x_steepness *= 2;
		}
	}
	else {
		//stee
		//distance1=current_key-prev_key;//distance used for flipping
		x_steepness = -(current_key - prev_key) / (ktime*ktime);
		if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
			x_steepness *= 2;
		}
		//flip_curve=false;//vertical
		x_prev_half = false;
	}
	if (x_prev_half == true) {
		//previous curve is half(blue)
		if (x_gradient == -1) {
			//gradient is negative
			//start_angle=(prev_key)/4;
			//green
			ktime *= 2;

			x_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
			if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
				x_steepness *= 2;
			}

			if (x_keyframe_time_elapsed2>((x_actual_curve_time) / 2)) {
				//second half of a curve
				x_s2 = x_keyframe_time_elapsed2 - ((x_actual_curve_time) / 2);
				//s2=ktime/2;
				//draw point for this angle
				//
				//draw_set_color(c_green);
				x_angle = x_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - x_s2)*0.5 / x_delta))*(((ktime / 2) - x_s2)*x_steepness)*x_delta;
				//start_angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
			}
		}
		else {

			//gradient is positive
			ktime *= 2;

			x_steepness = -(current_key - prev_key) * 2 / (ktime*ktime);
			if (animation_sets[x_current_set]->GetData()[x_k].is_half_x) {
				x_steepness *= 2;
			}

			//complete_time = ktime / 2;
			//white

			if (x_keyframe_time_elapsed2 > ((x_actual_curve_time) / 2)) {

				if (x_is_half) {
					//draw_set_color(c_blue);//blue is d3, half a curve
				}
				else {
					//draw_set_color(c_green);//full, the problem seems to be with white(d1)
				}

				x_s1 = x_keyframe_time_elapsed2 - ((x_actual_curve_time) / 2);
				//s1=ktime/2;
				x_a22 = x_s1*x_steepness;
				x_angle = x_start_angle + (x_s1*0.5 / x_delta)*x_a22*x_delta;
			}
		}
	}

	//draw first half and second half, for
	//half a curve and full curve
	if (x_prev_half == false)
	{
		//complete_time = (ktime / 2);
		//if (keyframe_time_elapsed2 <= ((actual_curve_time/15)/2)) {

		if (x_is_half) {
			//draw_set_color(c_blue);//blue is d3, half a curve
		}
		else {
			//draw_set_color(c_white);//full, the problem seems to be with white(d1)
		}

		x_s1 = x_keyframe_time_elapsed2;
		x_a22 = x_s1*x_steepness;
		//blue curev here
		x_angle = x_start_angle + (x_s1*0.5 / x_delta)*x_a22*x_delta;

		if (!x_is_half) {//is half is current curve
						 //green here is second half of white
			if (x_keyframe_time_elapsed2 > ((x_actual_curve_time) / 2)) {
				//
				float t2 = x_keyframe_time_elapsed2 - ((x_actual_curve_time) / 2);
				x_s2 = t2;
				//angle=start_angle+(-(current_key-prev_key)/4)-((((ktime/2)-s2)*0.5/delta))*(((ktime/2)-s2)*steepness)*delta;
				x_angle = x_start_angle + (-(current_key - prev_key) / 4) - ((((ktime / 2) - x_s2)*0.5 / x_delta))*(((ktime / 2) - x_s2)*x_steepness)*x_delta;
				//draw_set_color(c_green);
			}
		}

		//last_angle=start_angle;
		x_s1 = ktime / 2;
		x_a22 = x_s1*x_steepness;
		//a = start_angle + (s1*0.5 / delta)*a22*delta;

	}

	x_keyframe_time_elapsed2 += DeltaTime;

	real_angle_x = -x_angle * 4;
}

//float SEQ::GetRot()
//{
	//return real_angle;
//}
/*
void SEQ::AddKey(float angle_x, float angle_y, float angle_z, float time)
{
	KEYFRAME K;
	K.time = time;
	
	K.float_degrees_x = angle_x;
	K.is_half_x = false;

	K.float_degrees_y = angle_y;
	//K.time = time;
	K.is_half_y = false;

	K.float_degrees_z = angle_z;
	//K.time = time;
	K.is_half_z = false;

	KEYS->Push(K);
}
*/
/*
void SEQ::LoadSequence(FString str_filename)
{
	//load keys for x,y, z from file

	//angle is stored in file as 0-360, or >0, e.g. 720, never
	//negative

	//times = ds_list_create();
	//destinations = ds_list_create();
	//is_half = ds_list_create();

	//start_times=ds_list_create();

	//load from file
	TArray<KEYFRAME> START_Y_KEYS;//body rotation
	TArray<KEYFRAME> START_X_KEYS;//body rotation
	TArray<KEYFRAME> START_Z_KEYS;//body rotation

	//start_times = ds_list_create();
	//start_keys = ds_list_create();

	//Add some keys
	KEYFRAME K1;
	KEYFRAME K2;
	KEYFRAME K3;
	KEYFRAME K4;
	KEYFRAME K5;

	K1.float_degrees = 0;
	K1.time = 15;//15 is 1 second, 30=2 seconds for example
	K1.is_half = false;

	K2.float_degrees = 45;
	K2.time = 15;
	K2.is_half = false;

	K3.float_degrees = 0;//if I want to land at 0, then it is -prev(90)
	//K3.float_degrees = -90;
	K3.time = 15;
	K3.is_half = false;

	K4.float_degrees = 45;
	K4.time = 15;
	K4.is_half = false;

	K5.float_degrees = 0;
	K5.time = 15;
	K5.is_half = false;

	KEYFRAME K6;
	K6.float_degrees = -45;
	K6.time = 15;
	K6.is_half = false;

	START_Y_KEYS.Push(K1);
	START_Y_KEYS.Push(K2);
	START_Y_KEYS.Push(K3);
	START_Y_KEYS.Push(K4);
	START_Y_KEYS.Push(K5);
	START_Y_KEYS.Push(K6);
	START_Y_KEYS.Push(K1);
	
	//temp:
	
	Y_KEYS.Push(K1);
	Y_KEYS.Push(K2);
	Y_KEYS.Push(K3);
	Y_KEYS.Push(K4);
	Y_KEYS.Push(K5);
	return;
	
	//
	
	//var i;
	KEYFRAME K(0, 15, false);
	Y_KEYS.Push(K);
	//ds_list_add(destinations, 0);
	//ds_list_add(times, 4);
	//ds_list_add(is_half, false);
	//ds_list_add(show_key, false);
	//KEYFRAME K(0, 4, false);
	//Y_KEYS.Push(K);

	//var current_key;
	float current_key = START_Y_KEYS[1].float_degrees;
	//var curr_time;
	float curr_time = START_Y_KEYS[1].time;// ds_list_find_value(start_times, 1);
	float current_speed = curr_time;
	float prev_key = START_Y_KEYS[0].float_degrees;
	//var next_key;
	float next_key = START_Y_KEYS[2].float_degrees;

	//begin loop
	for (int i = 1; i<(START_Y_KEYS.Num() - 1); i += 1)
	{
		//var current_key;
		current_key = START_Y_KEYS[i].float_degrees;
		//var curr_time;
		curr_time = START_Y_KEYS[i].time;
		current_speed = curr_time;
		prev_key = START_Y_KEYS[i-1].float_degrees;
		//var next_key;
		next_key = START_Y_KEYS[i+1].float_degrees;
		float next_time = START_Y_KEYS[i+1].time;//divide by 15 to convert to seconds

														   //now add d1,d2 and d3
		//var xx;
		//float xx = 0;
		float xx = ToXX(prev_key, current_key, next_key);
		//show_message("xx="+string(xx));

		float d1=0;
		float d2=0;
		float k3;
		float t1;
		float t2;
		float t3;

		float time = next_time;
		t1 = time / 50;///next time could be E1 for example, of the next hex key
		t2 = time / 20;
		//t3 = (time - (t1 + t2))*2;//full curve time, twice actualcurve time
		t3 = time;
		//removed
		d1 = GetD1(xx, current_speed, next_time / 15);//time of d1 is 1/5 next_time
		//removed
		d2 = GetD2(xx, current_speed, next_time / 15);//time of d2 is 1/2 next time
													  //show_message("d1="+string(d1));

													  //show_message("d1 "+string(d1));
													  //show_message("xx "+string(xx));
													  //show_message("d2 "+string(d2)+" speed="+string(current_speed)+" time"+string(next_time/15));

		//var new_key;
		//var new_time;
		float new_key = current_key - d1;
		float new_time = t1;//in *15 seconds

					  //show_message("new key d1 "+string(new_key));
		Y_KEYS.Push(KEYFRAME(new_key, new_time, false));

		new_key = current_key - d1 + d2;
		new_time = t2;//in seconds
					  //show_message("d2 new key "+string(new_key));
		Y_KEYS.Push(KEYFRAME(new_key, new_time, false));

		k3 = new_key + (next_key - (new_key));
		Y_KEYS.Push(KEYFRAME(k3, t3, true));
	}

	//a2 = 0;

	//if (Y_KEYS.Num()>1) {
		//return;
	//}
	//*/
		//*/
	//now y_keys has elements
		//full_curve_time = Y_KEYS[k].time;
		//var is_half;
		//is_half = Y_KEYS[k].is_half;
		//if (is_half) {
			//actual_curve_time = full_curve_time / 2;
		//}
		//else {
			//actual_curve_time = full_curve_time;
		//}
/*
		full_curve_time = Y_KEYS[0].time;
		//var is_half;
		is_half = Y_KEYS[0].is_half;
		if (is_half) {
			actual_curve_time = full_curve_time / 2;
		}
		else {
			actual_curve_time = full_curve_time;
		}
}
*/

float GetD1(float xx, float speedvar, float total_time)
{
	//var xx;
	float _xx = 45 + xx;

	//var speedvar;
	//float speedvar = key_speed;
	//var total_time;
	//float total_time = argument2;

	//var a;
	//var b;
	float a = 0.0000582716;
	float b = 0.0365333;
	float steepnessCCW = a*_xx*_xx + b*_xx;

	//var a2;
	float a2 = (3 / speedvar) * 3 * steepnessCCW;
	float angle = (3 / speedvar) * 3 * a2;

	return total_time*angle;
}

float GetD2(float xx, float speedvar, float total_time)
{
	//var key;
	//key = get_integer("please enter key", 0);

	//key is actually (key2-key1)
	//or second -minus first
	//var xx;
	float _xx = 45 + xx;

	//var speedvar;
	//speedvar=get_integer("please enter speed",7);
	//speedvar = argument1;
	//var total_time;
	//total_time = argument2;

	//make distance positive for calculation, a length value
	//var length;
	//length=sign(distance)*distance;

	if (xx == 0) {//prevent division by 0
		return 0;
	}

	//solve, s, a and n
	//float a;
	//float p;
	//float aa;
	//float pp;
	//float cf;
	//float na;
	//float shiftaxis;
	//float np;
	//float yshift;
	//float f;

	float _aa = 1;
	float _pp = 2;
	float _cf = 40;
	float _a = 0.00000023;
	float _p = 4.497;
	//float _yshift = 20;
	float _f = 1;
	float _na = 0.003;
	float _shiftaxis = 142;
	float _np = 2;
	float _yshift = 20;
	
	float a = _aa*FMath::LogX(_pp, ((_xx) / _cf) + 1);
	float s = _a*FMath::Pow(_xx, _p) + _yshift + _f*_xx;
	float n = -_na*FMath::Pow(_xx - _shiftaxis, _np) + _yshift;

	float angle = s * 1 / FMath::Pow(a, speedvar) + n;

	return total_time*angle;
}

float Wrap(float arg1)
{
	//var arg1;
	//arg1 = argument0;

	if (arg1>180) {
		arg1 = -(360 - arg1);
	}

	return arg1;
}

float ToXX(float previous_key, float current_key, float next_key) 
{
	//var current_key;
	//var previous_key;
	//var next_key;

	//example xx=90-22.5+(90-22.5);
	//previous_key = argument0;
	//current_key = argument1;
	//next_key = argument2;

	previous_key = Wrap(previous_key);
	current_key = Wrap(current_key);
	next_key = Wrap(next_key);

	//if , all keys are in range 0-360 so I can base +- on -180 and 180 difference
	//var ad;
	float ad = AngleDifference(current_key, previous_key);
	//var plus;
	float xx = 0;
	if (ad<0) {
		xx = current_key - previous_key;
	}
	else {
		xx = previous_key - current_key;
	}
	float xx2=0;
	ad = AngleDifference(current_key, next_key);
	//var plus;
	if (ad<0) {
		xx2 = current_key - next_key;
	}
	else {
		xx2 = next_key - current_key;
	}
	return xx2;
}

float SEQ::GetRotX() {
	return real_angle_x;
}

float SEQ::GetRotY() {
	return real_angle_y;
}
float SEQ::GetRotZ() {
	return real_angle_z;
}

float FixAngle(float x)
{
	if (x>180.0f) {
		return -(360.0f - x);
	}
	else {
		return x;
	}

	return x;
}

/*
Moves file cursor for FileHandleSEQ, does not move cursor for key file
to anything intended for other use, moves it to the end of the keyframe
that is read by the function

return true or false
*/
bool KEYFRAME::ReadFileKeyframe(IFileHandle* FileHandleSEQ, IFileHandle* FileHandleKEY, KEYFRAME* keyframe_head_out, KEYFRAME* keyframe_body_out, HeadEyes* eyes, int* last_key)
{
	bool found_keyframe = false;

	//set is_keyframe to true/false and return 3 parameters
	keyframe_head_out->is_keyframe = false;
	keyframe_body_out->is_keyframe = false;

	eyes->index_eyes = -1;
	eyes->index_mouth = -1;

	BYTE* byteBuffer = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE) * 4));

	//skip first byte
	FileHandleSEQ->Read(byteBuffer, 4);

	//interpret 4 bytes read:
	//eyes first
	int N1 = (int)byteBuffer[0];
	int N2 = (int)byteBuffer[1];
	int N3 = (int)byteBuffer[2];
	int N4 = (int)byteBuffer[3];

	if ((N1 == 5) && (N3 == 0) && (N4 == 0)) {
		//Found eye keyframe
		eyes->index_eyes = (int)N2;
		found_keyframe = true;
	}
	if ((N1 == 6) && (N3 == 0) && (N4 == 0)) {
		//Found mouth keyframe
		eyes->index_mouth = (int)N2;
		found_keyframe = true;
	}
	if ((N1 == 10)) {
		//Found audio keyframe
		//eyes->index_mouth = (int)N2;
		found_keyframe = true;
	}
	if ((N1 == 03) && ((N2 == 04)|| (N2 == 00))) {//03 04 XX XX or 03 00 XX XX
		//Found rotation keyframe
		
		//read key from .key file
		int key_index = N4;//yes 0-based
		float seconds = ((float)N3/15.0f);

		keyframe_head_out->time = seconds;
		keyframe_body_out->time = seconds;
		if (N2==00) {
			keyframe_head_out->time = seconds*0.1;
			keyframe_body_out->time = seconds*0.1;
		}

		FileHandleKEY->Seek(0);
		//FileHandleKEY->
		FileHandleKEY->Seek(1+12*key_index);//1 to skip first byte in file and 12*key_index to jump to the start of the key
		//read the key
		BYTE* byteBufferKey = reinterpret_cast<BYTE*>(FMemory::Malloc(sizeof(BYTE) * 12));
		FileHandleKEY->Read(byteBufferKey, 12);
		//body
		float body_x1 = 22.5f * ((float)(int)byteBufferKey[0])/255.0f;//angle in degrees
		float body_x2 = 22.5f*(float)(int)byteBufferKey[1];//angle in degrees
		float body_y1 = 22.5f * ((float)(int)byteBufferKey[2]) / 255.0f;;//angle in degrees
		float body_y2 = 22.5f*(float)(int)byteBufferKey[3];//angle in degrees
		float body_z1 = 22.5f * ((float)(int)byteBufferKey[4]) / 255.0f;;//angle in degrees
		float body_z2 = 22.5f*(float)(int)byteBufferKey[5];//angle in degrees
		//head
		float head_x1 = 22.5f * ((float)(int)byteBufferKey[6]) / 255.0f;;//angle in degrees
		float head_x2 = 22.5f*(float)(int)byteBufferKey[7];//angle in degrees
		float head_y1 = 22.5f * ((float)(int)byteBufferKey[8]) / 255.0f;;//angle in degrees
		float head_y2 = 22.5f*(float)(int)byteBufferKey[9];//angle in degrees
		float head_z1 = 22.5f * ((float)(int)byteBufferKey[10]) / 255.0f;;//angle in degrees
		float head_z2 = 22.5f*(float)(int)byteBufferKey[11];//angle in degrees
		FMemory::Free(byteBufferKey);

		//Now copy the key to 
		keyframe_head_out->float_degrees_x = FixAngle(head_x1 + head_x2);
		keyframe_head_out->float_degrees_y = FixAngle(head_y1 + head_y2);
		keyframe_head_out->float_degrees_z = FixAngle(head_z1 + head_z2);

		//body
		keyframe_body_out->float_degrees_x = FixAngle(body_x1 + body_x2);
		keyframe_body_out->float_degrees_y = FixAngle(body_y1 + body_y2);
		keyframe_body_out->float_degrees_z = FixAngle(body_z1 + body_z2);

		//set other values
		keyframe_head_out->is_half_x = false;
		keyframe_head_out->is_half_y = false;
		keyframe_head_out->is_half_z = false;
		keyframe_body_out->is_half_x = false;
		keyframe_body_out->is_half_y = false;
		keyframe_body_out->is_half_z = false;

		//if (key_index!=*last_key) {
			found_keyframe = true;
			*last_key = key_index;
			keyframe_head_out->is_keyframe = true;
			keyframe_body_out->is_keyframe = true;
		//}
	}

	FMemory::Free(byteBuffer);
	//anything other than above is not a keyframe, 08 e.g.
	return found_keyframe;
}