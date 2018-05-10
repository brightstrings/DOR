#pragma once

#include "Runtime/Engine/Classes/Kismet/KismetStringLibrary.h"

//struct HeadEyes;
#ifndef HEAD_EYES
#define HEAD_EYES

struct HeadEyes
{
	HeadEyes();

	float time_from_start;//used to insert eyes or mouth state into existing list of eyesmouth at a particular time
	int index_eyes;
	int index_mouth;

	static bool ReadKeyframe(IFileHandle* FileHandle, HeadEyes* keyframe_out);
};
#endif

struct KEYFRAME
{
	KEYFRAME();
	bool is_keyframe;//some keyframes are empty, remove them from list later,
					 //The reason I want to add them is for indexing, to
					 //know where eye keyframes occur-their index

	//KEYFRAME(float key, float time, bool is_half);
	float float_degrees_x;
	float float_degrees_y;
	float float_degrees_z;
	float time;
	bool is_half_x;//half time, so rotation doesn't slow to 0 at destination
	bool is_half_y;//half time, so rotation doesn't slow to 0 at destination
	bool is_half_z;//half time, so rotation doesn't slow to 0 at destination
	/*
	Returns the next keyframe-eyes or body.
	if the keyframe is eyes then values are not -1 in eyes
	so this means eyes keyframe is encountered, otherwise a head-body
	keyframe is encountered if values are -1.
	check -1 values to determine if keyframe is eyes or body
	*/
	static bool ReadFileKeyframe(IFileHandle* FileHandleSEQ, IFileHandle* FileHandleKEY, KEYFRAME* keyframe_head_out, KEYFRAME* keyframe_body_out, HeadEyes* eyes, int* last_key);
};

class SEQ
{
private:
	//float angle;
	float x_start_angle;
	float x_delta;
	//var k;
	int x_k;
	//var kprev;
	int x_kprev;//or last one in seq?
	float x_keyframe_time_elapsed2;

	//new variables:
//private:
	
	float x_actual_curve_time;
	float x_full_curve_time;
	float x_gradient;//the gradient of blue(half)
	bool x_is_half;
	bool x_prev_half;//set to true if previous curve is half
	float x_blue_curve_height;
	float x_blue_curve_time;
	float x_steepness;
	float x_s2;//new
	float x_a22;//new
	float x_s1;//new
	
	//void CalculateStartAngle();
	float x_frequency;
	float x_elapsed;
	float x_angle;

	//y vars
	float y_start_angle;
	float y_delta;
	//var k;
	int y_k;
	//var kprev;
	int y_kprev;//or last one in seq?
	float y_keyframe_time_elapsed2;

	//new variables:
	//private:

	float y_actual_curve_time;
	float y_full_curve_time;
	float y_gradient;//the gradient of blue(half)
	bool y_is_half;
	bool y_prev_half;//set to true if previous curve is half
	float y_blue_curve_height;
	float y_blue_curve_time;
	float y_steepness;
	float y_s2;//new
	float y_a22;//new
	float y_s1;//new

			   //void CalculateStartAngle();
	float y_frequency;
	float y_elapsed;
	float y_angle;

	//z vars
	float z_start_angle;
	float z_delta;
	//var k;
	int z_k;
	//var kprev;
	int z_kprev;//or last one in seq?
	float z_keyframe_time_elapsed2;

	//new variables:
	//private:

	float z_actual_curve_time;
	float z_full_curve_time;
	float z_gradient;//the gradient of blue(half)
	bool z_is_half;
	bool z_prev_half;//set to true if previous curve is half
	float z_blue_curve_height;
	float z_blue_curve_time;
	float z_steepness;
	float z_s2;//new
	float z_a22;//new
	float z_s1;//new

			   //void CalculateStartAngle();
	float z_frequency;
	float z_elapsed;
	float z_angle;

private:
	//float TimeX;
	//float TimeY;
	//float TimeZ;
	//int kprev;
	//int kstart;
	//int k;
	//float keyframe_time_elapsed1;
	//float keyframe_time_elapsed2;
	//float a2;
	//float angle;//angle value for calculation
	//float body_yaw;
	//float body_pitch;
	//float body_roll;

	//TArray<KEYFRAME>* KEYS;//body or head rotation

	void PlayX(float DeltaTime);
	void PlayY(float DeltaTime);
	void PlayZ(float DeltaTime);

	//void ToFirstFrame();

public:
	SEQ();
	//Called outside SEQ:
	//void AddKey(float angle_x, float angle_y, float angle_z, float time);
	//void LoadSequence(FString str_filename);//should really be bool

	//TArray<KEYFRAME> KEYS;//body or head rotation
	//TArray<KEYFRAME> X_KEYS;//body rotation
	//TArray<KEYFRAME> Z_KEYS;//body rotation

	void Play(float DeltaTime);
	float GetRotX();
	float GetRotY();
	float GetRotZ();

	float real_angle_x;//the result(use GetRot())
	float real_angle_y;
	float real_angle_z;

	int new_set;//the set to change to(blend)
	TMap<int, TArray<KEYFRAME>*> animation_sets;
	//TArray<KEYFRAME>* KEYS_PREV;//for blending animations
	//TMap<int, TArray<KEYFRAME>* KEYS> animation_sets;//body or head rotation
	//TArray<KEYFRAME>* KEYS_NEXT_SET;//for blending animations may also point to KEYS
	//v

	//for blending
	int y_current_set;
	int y_prev_set;
	bool y_change_body_animation;
	//for blending
	int x_current_set;
	int x_prev_set;
	bool x_change_body_animation;
	//for blending
	int z_current_set;
	int z_prev_set;
	bool z_change_body_animation;


	//int k_insert;//point where KEYS an KEYS_NE are joined
	//KEYFRAME GetKey(int k);
	//I need to make KEYS=KEYS_NEXT_SET when KEYS is no longer used
	//int NumKeye
	//put these functions in place of KEYS-> accessors
	//int NumKeys();//keys + KEYS_NEXT

	void StartAnimationSet(int n, TArray<KEYFRAME>* KEYS);
	void StopAnimationSet(int return_to_set, TArray<KEYFRAME>* return_KEYS);//actually the same as StartAnimationSet
};

float GetD1(float xx, float speedvar, float total_time);
float GetD2(float xx, float speedvar, float total_time);
float Wrap(float arg1);
float ToXX(float previous_key, float current_key, float next_key);