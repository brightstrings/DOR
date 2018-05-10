// Fill out your copyright notice in the Description page of Project Settings.

#include "GrissburgSceneController.h"
#include "SoundManager2.h"

AGrissburgSceneController::AGrissburgSceneController()
{
	FString name = "test";
	TestComp = CreateDefaultSubobject<UStaticMeshComponent>(*name);
	//FString file = "";

	//CreateCharacter(M3D(), M3D(), M3D(), M3D());
	//LoadLevel();
	/*
	COMMAND command1;
	command1.CharacterID = 1;
	command1.dbPortraitID = 12;
	command1.create_character = true;

	ExecuteCommand(command1);
	*/
}

/*
Spawn characters here, not portraits.
*/
void AGrissburgSceneController::LoadLevel()
{


	//Read from Heads.db
	//CreateCharacter(M3D(), M3D(), M3D(), M3D());
	/*
	COMMAND command1;
	command1.CharacterID = 1;
	command1.dbPortraitID = 12;
	command1.create_character = true;
	
	ExecuteCommand(command1);
	*/
	/*
	COMMAND command2;
	command2.CharacterID = 2;
	command2.dbPortraitID = 12;
	command2.create_character = true;

	ExecuteCommand(command2);
	*/
}

void AGrissburgSceneController::SetupLevel()
{
	/*
	doing CreateUI in Setup level saves having to manually assign UI to wDougBlueprint.
	I've made it so it automatically does so in Level Blueprint and then SetupLevel() is
	called immediately after
	*/
	CreateUI();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	SoundManager2::Initialize(this);

	//Super::SetupLevel();
	//CreateUI();
	
	//COMMAND command1;
	//command1.CharacterID = 1;
	//command1.dbPortraitID = 12;
	//command1.create_character = true;

	//ExecuteCommand(command1);
	//*/
	//Create 2 characters
	//MB
	COMMAND command1;
	command1.CharacterID = 1;
	//command1.dbPortraitID = 11;
	command1.dbPortraitID = 0;
	command1.create_character = true;
	ExecuteCommand(command1);
	//SC
	COMMAND command2;
	command2.CharacterID = 2;
	command2.dbPortraitID = 12;
	command2.create_character = true;
	ExecuteCommand(command2);

	COMMAND command_WH;
	command_WH.CharacterID = 4;
	//command_WH.dbPortraitID = 10;
	//command_WH.dbPortraitID = 12;
	//command_WH.dbPortraitID = 10;
	command_WH.dbPortraitID = 11;
	command_WH.create_character = true;
	ExecuteCommand(command_WH);

	//Create a third character KZ
	//GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	COMMAND command_KZ;
	command_KZ.CharacterID = 3;
	command_KZ.dbPortraitID = 1;
	//command_KZ.dbPortraitID = 11;
	command_KZ.create_character = true;
	ExecuteCommand(command_KZ);

	//Create a 4th character WH
	//GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	
	
	COMMAND command3;
	command3.PortraitID = 1;
	command3.spawn_portrait = true;
	//command3.dbPortraitID =0;//Morgan Burnheartd is entry1, I should do zero-based probably
	//command3.spawn_x = 174.0f;
	//command3.spawn_y = 77.0f;
	command3.spawn_x = 344.0f;
	command3.spawn_y = 120.0f;
	command3.DisplayCharacterID = 1;
	command3.BackgroundName = "bb_twnn";
	ExecuteCommand(command3);

	//Spawn portrait of KZ
	COMMAND command10;
	command10.PortraitID = 3;
	command10.spawn_portrait = true;
	//command10.dbPortraitID = 0;//Morgan Burnheartd is entry1, I should do zero-based probably
							  //command2.spawn_x = 174.0f;
							  //command2.spawn_y = 77.0f;
	//command10.spawn_x = 344.0f;
	//command10.spawn_y = 120.0f;
	//command10.spawn_x = 174.0f;
	//command10.spawn_y = 77.0f;
	command10.spawn_x = 175.0f;
	command10.spawn_y = 79.0f;
	command10.DisplayCharacterID = 3;
	command10.BackgroundName = "bb_twnn";
	ExecuteCommand(command10);

	COMMAND command4;
	command4.PortraitID = 2;
	command4.spawn_portrait = true;
	//command4.dbPortraitID = 12;//Morgan Burnheartd is entry1, I should do zero-based probably
	//command4.spawn_x = 174.0f;
	//command4.spawn_y = 77.0f;
	//command2.spawn_x = 344.0f;
	//command2.spawn_y = 120.0f;
	command4.spawn_x = 492.0f;
	command4.spawn_y = 180.0f;
	command4.DisplayCharacterID = 2;
	command4.BackgroundName = "bb_twnn";
	ExecuteCommand(command4);
	
	/*
	COMMAND commandNew;
	commandNew.PortraitID = 4;
	commandNew.spawn_portrait = true;
	//commandNew.dbPortraitID = 11;//Morgan Burnheartd is entry1, I should do zero-based probably
	//command4.spawn_x = 174.0f;
	//command4.spawn_y = 77.0f;
	//command2.spawn_x = 344.0f;
	//command2.spawn_y = 120.0f;
	//commandNew.spawn_x = 492.0f;
	//command4.spawn_y = 180.0f;
	commandNew.spawn_x = 27.0f;
	commandNew.spawn_y = 203.0f;
	commandNew.DisplayCharacterID = 4;
	commandNew.BackgroundName = "bb_twnn";
	ExecuteCommand(commandNew);
	*/
	//Clouse 1
	COMMAND command_stop_talk;
	//command5.focusPortraitID = 1;
	command_stop_talk.stop_talking = true;
	//command9.CharacterID = 2;
	//command9.audio = "MB018";
	command_stop_talk.duration = 0.0f;
	command_stop_talk.skip_on_click = false;//I want to stop audio if click so this command should be executed

	COMMAND command14;
	command14.set_focus = true;
	command14.CharacterID = 3;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command14.duration = 1.0f;//start talking after a second
							 //this a focus so destination command when user clicks
	AddCommand(command14);

	COMMAND command15;
	//command7.set_focus = true;
	command15.CharacterID = 3;
	command15.start_talking = true;//after focus
	command15.audio = "KZ009";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command15.duration = 5.2f;
	command15.skip_on_click = true;
	AddCommand(command15);

	AddCommand(command_stop_talk);
	
	
	//here
	/*COMMAND command5;
	//command5.focusPortraitID = 1;
	command5.set_focus = true;
	command5.CharacterID = 1;
	command5.audio = "MB018";
	ExecuteCommand(command5);
	*/
	COMMAND command6;
	command6.set_focus = true;
	command6.CharacterID = 1;
	//command6.audio = "MB018";
	//ExecuteCommand(command6);
	//command6.duration = 7.5f;
	command6.duration = 1.0f;
	AddCommand(command6);

	COMMAND command9;
	command9.CharacterID = 1;
	command9.start_talking = true;//after focus
	command9.skip_on_click = true;//do not play audio if command must be skipped i.e. 
	command9.audio = "MB018";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command9.duration = 7.5f;
	AddCommand(command9);

	//COMMAND commandDestroyCharacter;//actually I don't want to destroy any characters in a scene, load
									//all at start
									//when portrait is destroyed, free slot used by character
	/*
	does not destroy character, destroys portrait of character
	so char
		*/
	
	//COMMAND command6;
	//command5.focusPortraitID = 1;
	//command6.PortraitID = 1;
	//command6.DestroyPortrait = true;
	//command6.DestroyPortraitID = 1;
	//ExecuteCommand(command6);
	/**/

	//spawn in a different place
	/*
	COMMAND command7;
	command7.PortraitID = 1;
	command7.spawn_portrait = true;
	command7.dbPortraitID = 0;//Morgan Burnheartd is entry1, I should do zero-based probably
							  //command2.spawn_x = 174.0f;
							  //command2.spawn_y = 77.0f;
	//command7.spawn_x = 44.0f;
	//command7.spawn_y = 120.0f;
	//command7.spawn_x = 344.0f;
	//command7.spawn_y = 120.0f;
	command7.spawn_x = 344.0f;
	command7.spawn_y = 120.0f;
	command7.DisplayCharacterID = 1;
	command7.BackgroundName = "bb_twnn";
	//command3.DisplayCharacterID = 1;
	//command3.BackgroundName = "bb_twnn";
	//set focus in same command:
	command7.set_focus = true;
	command7.CharacterID = 1;
	command7.audio = "MB018";
	command7.duration = 7.0f;
	//command
	AddCommand(command7);
	*/
	AddCommand(command_stop_talk);

	COMMAND command5;
	command5.PortraitID = 4;
	command5.spawn_portrait = true;
	//command4.dbPortraitID = 12;//Morgan Burnheartd is entry1, I should do zero-based probably
	//command4.spawn_x = 174.0f;
	//command4.spawn_y = 77.0f;
	//command2.spawn_x = 344.0f;
	//command2.spawn_y = 120.0f;
	command5.spawn_x = 27.0f;
	command5.spawn_y = 203.0f;
	command5.DisplayCharacterID = 4;
	command5.BackgroundName = "bb_twnn";
	command5.duration = 0.0f;
	command5.skip_on_click = false;//spawn portrait if click
	//ExecuteCommand(command5);
	AddCommand(command5);

	COMMAND command7;
	command7.set_focus = true;
	command7.CharacterID = 4;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command7.duration = 1.0f;//start talking after a second
	//this a focus so destination command when user clicks
	AddCommand(command7);

	COMMAND command8;
	//command7.set_focus = true;
	command8.CharacterID = 4;
	command8.start_talking = true;//after focus
	command8.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command8.duration = 4.0f;
	command8.skip_on_click = true;
	AddCommand(command8);

	AddCommand(command_stop_talk);

	//Set burnheart talking againg
	COMMAND command12;
	command12.set_focus = true;
	command12.CharacterID = 1;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command12.duration = 1.0f;//start talking after a second
							 //this a focus so destination command when user clicks
	AddCommand(command12);

	COMMAND command13;
	//command7.set_focus = true;
	command13.CharacterID = 1;
	command13.start_talking = true;//after focus
	command13.audio = "MB019";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command13.duration = 7.8f;
	command13.skip_on_click = true;
	AddCommand(command13);

	AddCommand(command_stop_talk);

	COMMAND command16;
	command16.set_focus = true;
	command16.CharacterID = 4;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command16.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command16);

	COMMAND command17;
	//command7.set_focus = true;
	command17.CharacterID = 4;
	command17.start_talking = true;//after focus
	command17.audio = "WH002";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command17.duration = 19.0f;
	command17.skip_on_click = true;
	AddCommand(command17);

	AddCommand(command_stop_talk);

	COMMAND command18;
	command18.set_focus = true;
	command18.CharacterID = 1;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command18.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command18);

	COMMAND command19;
	//command7.set_focus = true;
	command19.CharacterID = 1;
	command19.start_talking = true;//after focus
	command19.audio = "MB020";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command19.duration = 3.0f;
	command19.skip_on_click = true;
	AddCommand(command19);

	AddCommand(command_stop_talk);

	COMMAND command20;
	command20.set_focus = true;
	command20.CharacterID = 4;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command20.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command20);

	COMMAND command21;
	//command7.set_focus = true;
	command21.CharacterID = 4;
	command21.start_talking = true;//after focus
	command21.audio = "WH003";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command21.duration = 31.0f;
	command21.skip_on_click = true;
	AddCommand(command21);

	AddCommand(command_stop_talk);

	COMMAND command22;
	command22.set_focus = true;
	command22.CharacterID = 1;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command22.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command22);

	COMMAND command23;
	//command7.set_focus = true;
	command23.CharacterID = 1;
	command23.start_talking = true;//after focus
	command23.audio = "MB021";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command23.duration = 5.5f;
	command23.skip_on_click = true;
	AddCommand(command23);

	AddCommand(command_stop_talk);

	COMMAND command24;
	command24.set_focus = true;
	command24.CharacterID = 4;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command24.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command24);

	COMMAND command25;
	//command7.set_focus = true;
	command25.CharacterID = 4;
	command25.start_talking = true;//after focus
	command25.audio = "WH004";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command25.duration = 18.0f;
	command25.skip_on_click = true;
	AddCommand(command25);

	AddCommand(command_stop_talk);

	COMMAND command26;
	command26.set_focus = true;
	command26.CharacterID = 1;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command26.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command26);

	COMMAND command27;
	//command7.set_focus = true;
	command27.CharacterID = 1;
	command27.start_talking = true;//after focus
	command27.audio = "MB022";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command27.duration = 5.5f;
	command27.skip_on_click = true;
	AddCommand(command27);

	AddCommand(command_stop_talk);

	COMMAND command28;
	command28.set_focus = true;
	command28.CharacterID = 4;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command28.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command28);

	COMMAND command29;
	//command7.set_focus = true;
	command29.CharacterID = 4;
	command29.start_talking = true;//after focus
	command29.audio = "WH005";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command29.duration = 15.5f;
	command29.skip_on_click = true;
	AddCommand(command29);

	AddCommand(command_stop_talk);

	COMMAND command30;
	command30.set_focus = true;
	command30.CharacterID = 1;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command30.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command30);

	COMMAND command31;
	//command7.set_focus = true;
	command31.CharacterID = 1;
	command31.start_talking = true;//after focus
	command31.audio = "MB023";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command31.duration = 7.8f;
	command31.skip_on_click = true;
	AddCommand(command31);

	AddCommand(command_stop_talk);

	COMMAND command32;
	command32.set_focus = true;
	command32.CharacterID = 2;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command32.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command32);

	//COMMAND command31;
	COMMAND command33;
	//command7.set_focus = true;
	command33.CharacterID = 2;
	command33.start_talking = true;//after focus
	command33.audio = "SC008";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command33.duration = 6.0f;
	command33.skip_on_click = true;
	AddCommand(command33);

	AddCommand(command_stop_talk);

	COMMAND command34;
	command34.set_focus = true;
	command34.CharacterID = 4;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command34.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command34);

	//COMMAND command31;
	COMMAND command35;
	//command7.set_focus = true;
	command35.CharacterID = 4;
	command35.start_talking = true;//after focus
	command35.audio = "WH006";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command35.duration = 8.2f;
	command35.skip_on_click = true;
	AddCommand(command35);

	AddCommand(command_stop_talk);

	COMMAND command36;
	command36.set_focus = true;
	command36.CharacterID = 1;
	//command7.audio = "WH001";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command36.duration = 1.0f;//start talking after a second
							  //this a focus so destination command when user clicks
	AddCommand(command36);

	//COMMAND command31;
	COMMAND command37;
	//command7.set_focus = true;
	command37.CharacterID = 1;
	command37.start_talking = true;//after focus
	command37.audio = "MB024";
	//command7.audio_delay = 1.0f;//start audio after delay
	//ExecuteCommand(command6);
	command37.duration = 11.5f;
	command37.skip_on_click = true;
	AddCommand(command37);

	AddCommand(command_stop_talk);

	//destroy portraits
	COMMAND command38;
	//command5.focusPortraitID = 1;
	//command6.PortraitID = 1;
	command38.DestroyPortrait = true;
	command38.DestroyPortraitID = 1;
	command38.CharacterID = 1;
	command38.duration = 0.0f;
	AddCommand(command38);

	COMMAND command39;
	//command5.focusPortraitID = 1;
	//command6.PortraitID = 1;
	command39.DestroyPortrait = true;
	command39.DestroyPortraitID = 2;
	command39.CharacterID = 2;
	command39.duration = 0.0f;
	AddCommand(command39);

	COMMAND command40;
	//command5.focusPortraitID = 1;
	//command6.PortraitID = 1;
	command40.DestroyPortrait = true;
	command40.DestroyPortraitID = 3;
	command40.CharacterID = 3;
	command40.duration = 0.0f;
	AddCommand(command40);

	COMMAND command41;
	//command5.focusPortraitID = 1;
	//command6.PortraitID = 1;
	command41.DestroyPortrait = true;
	command41.DestroyPortraitID = 4;
	command41.CharacterID = 4;
	command41.duration = 0.0f;
	AddCommand(command41);

	//ExecuteCommand(command6);
	
	/*
	COMMAND command8;
	//command5.focusPortraitID = 1;
	command8.set_focus = true;
	command8.CharacterID = 2;
	//command8.audio = "MB018";
	command8.audio = "SC008";
	command8.duration = 6.0f;
	AddCommand(command8);
	*/


	/*
	COMMAND command9;
	//command5.focusPortraitID = 1;
	command9.stop_talking = true;
	//command9.CharacterID = 2;
	//command9.audio = "MB018";
	command9.duration = 1.0f;
	AddCommand(command9);
	*/
	/*
	COMMAND command11;
	command11.PortraitID = 4;
	command11.spawn_portrait = true;
	//command11.dbPortraitID = 0;//Morgan Burnheartd is entry1, I should do zero-based probably
							  //command3.spawn_x = 174.0f;
							  //command3.spawn_y = 77.0f;
	command11.spawn_x = 27.0f;
	command11.spawn_y = 203.0f;
	command11.DisplayCharacterID = 4;
	command11.BackgroundName = "bb_twnn";
	AddCommand(command11);
	*/
	//ExecuteCommand(command11);

	//ExecuteCommand(command7);

	//soundGet
	//sound.
		//YourActor
	//TArray<UStaticMeshComponent*> StaticComps;
	//sound->GetComponents<UStaticMeshComponent>(StaticComps);// .GetComponents<UStaticMeshComponent>();
	//TArray<UAudioComponent*> StaticComps;
	//((AActor*)sound->GetClass())->GetComponents<UAudioComponent>(StaticComps);// .GetComponents<UStaticMeshComponent>();
	/*
	FString comp_name = "AudioComponent";
	audio_component =NewObject<UAudioComponent>(this, *comp_name);
	//static ConstructorHelpers::FObjectFinder<USoundWave> Sound(TEXT("/Game/Audio/StartMusic.StartMusic"));
	static USoundWave* test_sound = LoadObject<USoundWave>(this, *FString("/Game/Sounds/A_AARGH1.A_AARGH1"));
	audio_component->SetSound(test_sound);
	//sound->
	//sound->w
//sound->
	audio_component->Play();

	SoundMan
		*/
	//SoundManager2::PlaySound(this, "A_AARGH1");
	//SoundManager2::PlaySound(this, "MB018");

	//FString base_name = "AudioComponentBase";
	//audio_component->Sound = NewObject<USoundBase>(this, *base_name);
	//audio_component->Sound->
	//audio_component=  = NewObject<UAudioComponent>(this, *comp_name);
}

// Called when the game starts or when spawned
void AGrissburgSceneController::BeginPlay()
{
	Super::BeginPlay();
	/*
	COMMAND command1;
	command1.CharacterID = 1;
	command1.dbPortraitID = 12;
	command1.create_character = true;

	ExecuteCommand(command1);
	*/
	//LoadLevel();

	//FString path = "";
	//path = "/Game/Portrait/Meshes/";
	//FString filename = path + "14";
	//SpawnMesh("NewMesh", filename);
	/*
	COMMAND command1;
	command1.spawn_portrait = true;
	command1.dbPortraitID = 12;//Morgan Burnheartd is entry1, I should do zero-based probably
	command1.spawn_x = 344.0f;
	command1.spawn_y = 120.0f;
	command1.DisplayCharacterID = 1;
	ExecuteCommand(command1);
	*/
	/*
	COMMAND command2;
	command2.spawn_portrait = true;
	command2.dbPortraitID = 12;//Morgan Burnheartd is entry1, I should do zero-based probably
	command2.spawn_x = 174.0f;
	command2.spawn_y = 77.0f;
	command2.DisplayCharacterID = 1;
	ExecuteCommand(command2);
	*/
}

//void AGrissburgSceneController::LoadCharactersFromFile()
//{
	//populate list(map) of characters used by the scene

//}

