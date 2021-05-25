/**
 * 모든 함수는 loringlib_*으로 시작됩니다.
 * 정확하지 않은 함수도 있을 수 있습니다.
 * 버그는 qufnr@icloud.com으로 피드백 바랍니다.
 *
 * loringlib에 있는 함수는 CS:GO 또는 CS:S 위주로 만들었으며,
 * 일부함수들은 타 Source 게임에서는 작동하지 않을 수 있습니다.
 *
 */

#if	defined	_loringlib_included
	#endinput
#endif
#define	_loringlib_included

#include <cstrike>
#include <sdktools>
#include <sdkhooks>

/**
 * @section 백터를 완벽히 초기화 합니다.
 */
float NULL_VECTOR_FLY_BLOCK[3] = { 0.0, 0.0, 0.0 };

/**
 * @section Cvar Flags
 */
#define	CVARFLAGS	FCVAR_NONE | FCVAR_SPONLY | FCVAR_REPLICATED | FCVAR_NOTIFY | FCVAR_DONTRECORD

/**
 * @section Max entity number.
 */
#define	SOURCE_MAXENTITIES			2048

/**
 * @section Char max buffer.
 */
#define MAXBUFF						512

/**
 * @section Other client index.
 */
#define	CONSOLE						0
#define	SOURCETV					1
#define SOURCETV_USERID				2

/**
 * @section jointeam에서 선택한 팀 인덱스 값.
 */
#define	CSGO_TEAMSELECT_RANDOM		"0"
#define	CSGO_TEAMSELECT_SPECTATOR	"1"
#define	CSGO_TEAMSELECT_TERRORIST	"2"
#define	CSGO_TEAMSELECT_CT			"3"

/**
 * @section Max Weapons.
 */
#define CSGO_MAX_WEAPONS		48
#define CSS_MAX_WEAPONS			32

#define CS_SLOT_MEDISHOT		11

/**
 * @section 관전 모드
 */
#define	CS_SPECMODE_NONE			0
#define	CS_SPECMODE_FIRSTPERSON		4
#define	CS_SPECMODE_THIRDPERSON		5
#define	CS_SPECMODE_FREELOOK		6

/**
 * @section Ambient sound channel.
 */
#define SOUND_AMBIENT_CHANNEL	8

/**
 * @section 허드를 숨길 수 있는 flags
 */
#define HIDEHUD_WEAPONSELECTION 		( 1 << 0 )  /**< Hide ammo count & weapon selection */
#define HIDEHUD_FLASHLIGHT 				( 1 << 1 )
#define HIDEHUD_ALL 					( 1 << 2 )
#define HIDEHUD_HEALTH 					( 1 << 3 ) /**< Hide health & armor / suit battery */
#define HIDEHUD_PLAYERDEAD 				( 1 << 4 ) /**< Hide when local player's dead */
#define HIDEHUD_NEEDSUIT 				( 1 << 5 ) /**< Hide when the local player doesn't have the HEV suit */
#define HIDEHUD_MISCSTATUS 	 			( 1 << 6 ) /**< Hide miscellaneous status elements (trains, pickup history, death notices, etc) */
#define HIDEHUD_CHAT 					( 1 << 7 ) /**< Hide all communication elements (saytext, voice icon, etc) */
#define HIDEHUD_CROSSHAIR 				( 1 << 8 ) /**< Hide crosshairs */
#define HIDEHUD_VEHICLE_CROSSHAIR 		( 1 << 9 ) /**< Hide vehicle crosshair */
#define HIDEHUD_INVEHICLE 				( 1 << 10 )
#define HIDEHUD_BONUS_PROGRESS 			( 1 << 11 ) /**< Hide bonus progress display (for bonus map challenges) */

/**
 * @section Hud hide (working values.)
 */
#define	CSGO_HIDEHUD_CROSSHAIR		( 1 << 8 )
#define	CSGO_HIDEHUD_RADAR			( 1 << 12 )

/** 
 * @section Hitgroup list
 */
#define HITGROUP_GENERIC     0				/**< 공통 */
#define HITGROUP_HEAD        1				/**< 머리 */
#define HITGROUP_CHEST       2				/**< 가슴 */
#define HITGROUP_STOMACH     3				/**< 배 */
#define HITGROUP_LEFTARM     4				/**< 왼손 */
#define HITGROUP_RIGHTARM    5				/**< 오른손 */
#define HITGROUP_LEFTLEG     6				/**< 왼다리 */
#define HITGROUP_RIGHTLEG    7				/**< 오른다리 */
#define HITGROUP_GEAR        10            /**< alerts NPC, but doesn't do damage or bleed (1/100th damage) */

/**
 * @section 이팩트 flags
 */
#define EF_BONEMERGE                ( 1 << 0 )
#define EF_NOSHADOW                 ( 1 << 4 )
#define EF_NORECEIVESHADOW          ( 1 << 6 )
#define EF_PARENT_ANIMATES          ( 1 << 9 )

/**
 * @section EnvExplosion Flags.
 */
#define SF_ENVEXPLOSION_NODAMAGE	0x00000001 /**< when set, ENV_EXPLOSION will not actually inflict damage */
#define SF_ENVEXPLOSION_REPEATABLE	0x00000002 /**< can this entity be refired? */
#define SF_ENVEXPLOSION_NOFIREBALL	0x00000004 /**< don't draw the fireball */
#define SF_ENVEXPLOSION_NOSMOKE		0x00000008 /**< don't draw the smoke */
#define SF_ENVEXPLOSION_NODECAL		0x00000010 /**< don't make a scorch mark */
#define SF_ENVEXPLOSION_NOSPARKS	0x00000020 /**< don't make sparks */
#define SF_ENVEXPLOSION_NOSOUND		0x00000040 /**< don't play explosion sound. */
#define SF_ENVEXPLOSION_RND_ORIENT	0x00000080 /**< randomly oriented sprites */
#define SF_ENVEXPLOSION_NOFIREBALLSMOKE 0x0100
#define SF_ENVEXPLOSION_NOPARTICLES 0x00000200
#define SF_ENVEXPLOSION_NODLIGHTS	0x00000400
#define SF_ENVEXPLOSION_NOCLAMPMIN	0x00000800 /**< don't clamp the minimum size of the fireball sprite */
#define SF_ENVEXPLOSION_NOCLAMPMAX	0x00001000 /**< don't clamp the maximum size of the fireball sprite */
#define SF_ENVEXPLOSION_SURFACEONLY	0x00002000 /**< don't damage the player if he's underwater. */

/**
 * @section Sourcemod language numbers.
 */
#define LANG_ENGLISH		0	// 정확하지 않음
#define LANG_SPANISH		2
#define LANG_GERMAN			4
#define LANG_FRENCH			11
#define LANG_RUSSIAN		12
#define LANG_CHINESES		13
#define LANG_CHINESET		14
#define LANG_KOREANA		15
#define LANG_KOREAN			15
#define LANG_ROMANIAN		16
#define LANG_ARABIC			17
#define LANG_HUNGARIAN		18
#define LANG_SWEDISH		19
#define LANG_POLISH			20
#define LANG_NORWEGINA		22
#define LANG_BRAZILIAN		24
#define LANG_ITALIAN		27
#define LANG_DANISH			28
#define LANG_FINNISH		31
#define LANG_LATVIAN		32
#define LANG_HEBREW			35
#define LANG_JAPANESE		37
#define LANG_BULAGRIAN		38
#define LANG_PORTUGUESE		40

/**
 * @section Grenades ammo type.
 */
#define AMMOTYPE_HEGRENADE	14
#define AMMOTYPE_FLASHBANG	15
#define AMMOTYPE_SMOKE		16
#define AMMOTYPE_MOLOTOV	17
#define AMMOTYPE_DECOY		18
#define AMMOTYPE_HEALTHSHOT	21
#define AMMOTYPE_TAGRENADE	22

/**
 * @section Fade flags.
 */
#define FADE_IN			0x0001
#define FADE_OUT		0x0002
#define FADE_MODULATE	0x0004
#define FADE_STAYOUT	0x0008
#define FADE_PURGE		0x0010

/**
 * @section Overflow number.
 */
#define		OVERFLOW32			2147483648
#define		OVERFLOW32HEX		0x80000000

/**
 * @section 각 관전자 모드 값입니다. (Test Engine: cstrike)
 */
#define	CS_SPECMODE_NONE			0
#define	CS_SPECMODE_FIRSTPERSON		4
#define	CS_SPECMODE_THIRDPERSON		5
#define	CS_SPECMODE_FREELOOK		6

/**
 * @section CS:GO Team colors
 */
#define CSGO_CT_COLOR	"\x0B"
#define CSGO_TR_COLOR	"\x0F"
#define CSGO_SPEC_COLOR	"\x08"

/**
 * @section CS:GO Arms fix default arms models arrays.
 */
static char defaultArms[][] = {
	"models/weapons/ct_arms.mdl",
	"models/weapons/ct_arms_fbi.mdl",
	"models/weapons/ct_arms_gign.mdl",
	"models/weapons/ct_arms_gsg9.mdl",
	"models/weapons/ct_arms_idf.mdl",
	"models/weapons/ct_arms_sas.mdl",
	"models/weapons/ct_arms_st6.mdl",
	"models/weapons/ct_arms_swat.mdl",
	
	"models/weapons/t_arms.mdl",
	"models/weapons/t_arms_anarchist.mdl",
	"models/weapons/t_arms_balkan.mdl",
	"models/weapons/t_arms_leet.mdl",
	"models/weapons/t_arms_phoenix.mdl",
	"models/weapons/t_arms_pirate.mdl",
	"models/weapons/t_arms_professional.mdl",
	"models/weapons/t_arms_separatist.mdl",
	"models/weapons/t_arms_workbench_leet.mdl"
};

/**
 * @section 키 입력 번호 입니다.
 */
#define MAX_KEY_PRESS		25
#define KEY_IN_ATTACK		0
#define KEY_IN_JUMP			1
#define KEY_IN_DUCK			2
#define KEY_IN_FORWARD		3
#define KEY_IN_BACK			4
#define KEY_IN_USE			5
#define KEY_IN_CANCEL		6
#define KEY_IN_LEFT			7
#define KEY_IN_RIGHT		8
#define KEY_IN_MOVELEFT		9
#define KEY_IN_MOVERIGHT	10
#define KEY_IN_ATTACK2		11
#define KEY_IN_RUN			12
#define KEY_IN_RELOAD		13
#define KEY_IN_ALT1			14
#define KEY_IN_ALT2			15
#define KEY_IN_SCORE		16   	/**< Used by client.dll for when scoreboard is held down */
#define KEY_IN_SPEED		17	/**< Player is holding the speed key */
#define KEY_IN_WALK			18	/**< Player holding walk key */
#define KEY_IN_ZOOM			19	/**< Zoom key for HUD zoom */
#define KEY_IN_WEAPON1		20	/**< weapon defines these bits */
#define KEY_IN_WEAPON2		21	/**< weapon defines these bits */
#define KEY_IN_BULLRUSH		22
#define KEY_IN_GRENADE1		23	/**< grenade 1 */
#define KEY_IN_GRENADE2		24	/**< grenade 2 */
#define KEY_IN_ATTACK3		25

/**
 * @section Different dissolve types.
 */
#define VEFFECTS_RAGDOLL_DISSOLVE_EFFECTLESS		-2
#define VEFFECTS_RAGDOLL_DISSOLVE_RANDOM			-1
#define VEFFECTS_RAGDOLL_DISSOLVE_ENERGY			0
#define VEFFECTS_RAGDOLL_DISSOLVE_ELECTRICALH		1
#define VEFFECTS_RAGDOLL_DISSOLVE_ELECTRICALL		2
#define VEFFECTS_RAGDOLL_DISSOLVE_CORE				3

/**
 * @section		스프라이트 랜더 타입 값
 */
#define SPRITE_RENDERMODE_NORMAL					0
#define SPRITE_RENDERMODE_COLOR						1
#define SPRITE_RENDERMODE_TEXTURE					2
#define SPRITE_RENDERMODE_GLOW						3
#define SPRITE_RENDERMODE_SOLIDE					4
#define SPRITE_RENDERMODE_ADDITIVE					5
#define SPRITE_RENDERMODE_ADDITIVE_FRACTIONAL_FRAME	7
#define SPRITE_RENDERMODE_WORLD_SPACE_GLOW			9
#define SPRITE_RENDERMODEE_DONT_WORLD				10

/**
 * @section		func_breakable propdata 값
 */
enum BreakablePropData {
	BreakablePropData_None = 0,
	BreakablePropData_WoodenTiny,
	BreakablePropData_WoodenSmall,
	BreakablePropData_WoodenMedium,
	BreakablePropData_WoodenLarge,
	BreakablePropData_WoodenHuge,
	
	BreakablePropData_MetalSmall,
	BreakablePropData_MetalMedium,
	BreakablePropData_MetalLarge,
	
	BreakablePropData_CardboardSmall,
	BreakablePropData_CardboardMedium,
	BreakablePropData_CardboardLarge,
	
	BreakablePropData_StoneSmall,
	BreakablePropData_StoneMedium,
	BreakablePropData_StoneLarge,
	BreakablePropData_StoneHuge,
	
	BreakablePropData_GlassSmall,
	
	BreakablePropData_PlasticSmall,
	BreakablePropData_PlasticMedium,
	BreakablePropData_PlasticLarge,
	
	BreakablePropData_PotterySmall,
	BreakablePropData_PotteryMedium,
	BreakablePropData_PotteryLarge,
	BreakablePropData_PotteryHuge,
	
	BreakablePropData_GlassWindow,
}

/**
 * @section func_breakable material 값
 */
enum BreakableMaterialType {
	BreakableMaterialType_Glass = 0,
	BreakableMaterialType_Wood,
	BreakableMaterialType_Metal,
	BreakableMaterialType_Flesh,
	BreakableMaterialType_CinderBlock,
	BreakableMaterialType_CeilingTile,
	BreakableMaterialType_Computer,
	BreakableMaterialType_UnbreakableGlass,
	BreakableMaterialType_Rocks,
	BreakableMaterialType_Web,
	BreakableMaterialType_None,
}

/**
 * @section m_usSolidFlags Flags
 */
#define FSOLID_CUSTOMRAYTEST	0x0001	/**< 솔리드 타입을 무시하고 항상 레이 테스트를 위해 엔티티를 호출 합니다. */
#define FSOLID_CUSTOMBOXTEST	0x0002	/**< 솔리드 타입 무시 그리고, 항상 스윕 박스 테스트를 위해 엔티티를 호출 합니다. */
#define FSOLID_NOT_SOLID		0x0004	/**< 솔리드를 안하고 있나? */
#define FSOLID_TRIGGER			0x0008	/**< 솔리드할 수 있지만 솔리드할 수 없는 경우에도(FSOLID_NOT_SOLID 플레그가 설정된 경우) 터치합니다. */
#define FSOLID_NOT_STANDABLE	0x0010	/**< You can't stand on this */
#define FSOLID_VOLUME_CONTENTS	0x0020	/**< Contains volumetric contents (like water) */
#define FSOLID_FORCE_WORLD_ALIGNED	0x0040	/**< Forces the collision rep to be world-aligned even if it's SOLID_BSP or SOLID_VPHYSICS */
#define	FSOLID_USE_TRIGGER_BOUNDS	0x0080	/**< Uses a special trigger bounds separate from the normal OBB */
#define	FSOLID_ROOT_PARENT_ALIGNED	0x0100	/**< Collisions are defined in root parent's local coordinate space */
#define	FSOLID_TRIGGER_TOUCH_DEBRIS	0x0200	/**< This trigger will touch debris objects */
#define FSOLID_MAX_BITS		10

/**
 * @section m_nSolidType Types
 */
#define SOLID_NONE		0		/**< 모델을 솔리드 하지 않습니다. */
#define SOLID_BSP		1		/**< a BSP tree */
#define SOLID_BBOX		2		/**< an AABB */
#define SOLID_OBB		3		/**< an OBB (not implemented yet) */
#define SOLID_OBB_YAW	4		/**< an OBB, constrained so that it can only yaw */
#define SOLID_CUSTOM	5		/**< Always call into the entity for tests */
#define SOLID_VPHYSICS	6		/**< solid vphysics object, get vcollide from the model and collide with that */
#define SOLID_LAST		7

/**
 * #section m_CollisionGroup Types
 */
#define	COLLISION_GROUP_NONE	0
#define	COLLISION_GROUP_DEBRIS	1				// Collides with nothing but world and static stuff
#define	COLLISION_GROUP_DEBRIS_TRIGGER	2 		// Same as debris, but hits triggers
#define	COLLISION_GROUP_INTERACTIVE_DEBRIS	3	// Collides with everything except other interactive debris or debris
#define	COLLISION_GROUP_INTERACTIVE			4	// Collides with everything except interactive debris or debris
#define	COLLISION_GROUP_PLAYER		5
#define	COLLISION_GROUP_BREAKABLE_GLASS	6
#define	COLLISION_GROUP_VEHICLE		7
#define	COLLISION_GROUP_PLAYER_MOVEMENT	8  		// For HL2, same as Collision_Group_Player, for
												// TF2, this filters out other players and CBaseObjects
#define	COLLISION_GROUP_NPC		9		// Generic NPC group
#define	COLLISION_GROUP_IN_VEHICLE	10	// for any entity inside a vehicle
#define	COLLISION_GROUP_WEAPON		11	// for any weapons that need collision detection
#define	COLLISION_GROUP_VEHICLE_CLIP	12	// vehicle clip brush to restrict vehicle movement
#define	COLLISION_GROUP_PROJECTILE	13	// Projectiles!
#define	COLLISION_GROUP_DOOR_BLOCKER	14	// Blocks entities not permitted to get near moving doors
#define	COLLISION_GROUP_PASSABLE_DOOR	15	// Doors that the player shouldn't collide with
#define	COLLISION_GROUP_DISSOLVING	16	// Things that are dissolving are in this group
#define	COLLISION_GROUP_PUSHAWAY	17	// Nonsolid on client and server, pushaway in player code

#define	COLLISION_GROUP_NPC_ACTOR	18		// Used so NPCs in scripts ignore the player.
#define	COLLISION_GROUP_NPC_SCRIPTED	19	// USed for NPCs in scripts that should not collide with each other

#define	LAST_SHARED_COLLISION_GROUP		20

/**
 * @section settings for m_takedamage
 */
#define DAMAGE_NO			0
#define DAMAGE_EVENTS_ONLY	1	// Call damage functions, but don't modify health
#define DAMAGE_YES			2
#define DAMAGE_AIM			3

/**
 * Get game engine.
 * @return		game engine.
 *//*
public EngineVersion loringlib_GetGameEngine () {
	EngineVersion result;
	if ( GetFeatureStatus ( FeatureType_Native, "GetEngineVersion" ) == FeatureStatus_Available )
		result = GetEngineVersion ();
		
	switch ( GuessSDKVersion () ) {
		case SOURCE_SDK_ORIGINAL:		result = Engine_Original;
		case SOURCE_SDK_DARKMESSIAH:	result = Engine_DarkMessiah;
		case SOURCE_SDK_EPISODE1:		result = Engine_SourceSDK2006;
		case SOURCE_SDK_EPISODE2:		result = Engine_SourceSDK2007;
		case SOURCE_SDK_BLOODYGOODTIME:	result = Engine_BloodyGoodTime;
		case SOURCE_SDK_EYE:			result = Engine_EYE;
		case SOURCE_SDK_LEFT4DEAD:		result = Engine_Left4Dead;
		case SOURCE_SDK_CSS:			result = Engine_CSS;
		case SOURCE_SDK_CSGO:			result = Engine_CSGO;
		case SOURCE_SDK_ALIENSWARM:		result = Engine_AlienSwarm;
		case SOURCE_SDK_EPISODE2VALVE: {
			char game[PLATFORM_MAX_PATH];
			GetGameFolderName ( game, PLATFORM_MAX_PATH );
			if ( StrEqual ( game, "dod", false ) )			result = Engine_DODS;
			else if ( StrEqual ( game, "hl2mp", false ) )	result = Engine_HL2DM;
			else											result = Engine_TF2;
		}
		case SOURCE_SDK_LEFT4DEAD2: {
			char game[PLATFORM_MAX_PATH];
			GetGameFolderName ( game, PLATFORM_MAX_PATH );
			if ( StrEqual ( game, "nd", false ) )	result = Engine_NuclearDawn;
			else									result = Engine_Left4Dead2;
		}
		default:	Engine_Unknown;
	}
	
	return result;
}
*/

/** 
 * CS:S 엔진을 채크합니다.
 * @return			CS:S 엔진이라면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsEngineCSS () {
	if ( GetEngineVersion () == Engine_CSS )
		return true;
	
	else
		return false;
}

/** 
 * CS:GO 엔진을 채크합니다.
 * @return			CS:GO 엔진이라면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsEngineCSGO () {
	if ( GetEngineVersion () == Engine_CSGO )
		return true;
	
	else
		return false;
}

/*
 사용예시:
	PrecacheGeneric ( "pcf 전체 경로", true );
	loringlib_PrecacheEffect ( "ParticleEffect" );
	loringlib_PrecachePcf ( "pcf 파일 이름" );	// .pcf 제외
*/
/**
 * pcf 프리캐싱
 *
 * @param effPath				ParticleEffect
 * @noreturn
 */
stock void loringlib_PrecacheEffect ( const char[] effPath ) {
	static int table = INVALID_STRING_TABLE;
	if ( table == INVALID_STRING_TABLE )
		table = FindStringTable ( "EffectDispatch" );
		
	bool lockTable = LockStringTables ( false );
	AddToStringTable ( table, effPath );
	LockStringTables ( lockTable );
}

/**
 * pcf 프리캐싱
 *
 * @param effPath				pcf path
 * @noreturn
 */
stock void loringlib_PrecacheParticleName ( const char[] effPath ) {
	static int table = INVALID_STRING_TABLE;
	if ( table == INVALID_STRING_TABLE )
		table = FindStringTable ( "ParticleEffectNames" );
		
	bool lockTable = LockStringTables ( false );
	AddToStringTable ( table, effPath );
	LockStringTables ( lockTable );
}

/**
 * 파티클 위치로 파티클 이름을 구합니다.
 *
 * @param eff
 * @return String Index
 */
stock int loringlib_GetEffectIndex ( const char[] eff ) {
	static int table = INVALID_STRING_TABLE;
	
	if ( table == INVALID_STRING_TABLE )
		table = FindStringTable ( "EffectDispatch" );
		
	int idx = FindStringIndex ( table, eff );
	
	if ( idx != INVALID_STRING_INDEX )
		return idx;
	
	return -1;
}

/**
 * 파티클 이름으로 파티클 위치를 구합니다.
 *
 * @param effName
 * @return String Index
 */
stock int loringlib_GetParticleEffectIndex ( const char[] effName ) {
	static int table = INVALID_STRING_TABLE;
	
	if ( table == INVALID_STRING_TABLE )
		table = FindStringTable ( "ParticleEffectNames" );
	
	int idx = FindStringIndex ( table, effName );
	if ( idx != INVALID_STRING_INDEX )
		return idx;
	return -1;
}

stock void loringlib_PrecacheParticle ( const char[] pcfPath, bool preload = false ) {
	PrecacheGeneric ( pcfPath, preload );
	AddFileToDownloadsTable ( pcfPath );
	loringlib_PrecacheEffect ( pcfPath );
}

/**
 * 파티클을 생성합니다.
 *
 * @param target				파티클 주인 인덱스
 * @param entity				파티클 엔티티
 * @param effPos				파티클 위치
 * @param effName				파티클 이펙트 이름
 * @param activator				몸에 붙일건지 유무
 * @param lifeTime				파티클이 살아있는 시간 기본 10초
 * @return				파티클 엔티티를 리턴합니다.
 * @error		파티클이 없거나, 클라이언트 인덱스가 유효하지 않음.
 */
stock int loringlib_CreateParticle ( int target, int entity, float effPos[3], char[] effName, bool activator = false, float lifeTime = 0.0, bool sendToTarget = false, char[] attachName = "" ) {
	entity = CreateEntityByName ( "info_particle_system" );
	if ( entity == -1 )
		return entity;
	
	//	No position.
	if ( effPos[0] == 0.0 && effPos[1] == 0.0 && effPos[2] == 0.0 ) {
		if ( activator )
			loringlib_GetEntityOriginEx ( entity, effPos );
		else
			loringlib_GetEntityAngle ( entity, effPos );
	}
	
	TeleportEntity ( entity, effPos, NULL_VECTOR, NULL_VECTOR );
	
	DispatchKeyValue ( entity, "effect_name", effName );
	DispatchKeyValue ( entity, "start_active", "1" );
	
	if ( activator ) {
		SetVariantString ( "!activator" );
		AcceptEntityInput ( entity, "SetParent", target, entity, 0 );
		SetEntPropEnt ( entity, Prop_Data, "m_pParent", target );
		
		if ( attachName[0] != EOS ) {
			SetVariantString ( attachName );
			AcceptEntityInput ( entity, "SetParentAttachment", target );
		}
	}
	
	DispatchSpawn ( entity );
	ActivateEntity ( entity );
//	AcceptEntityInput ( entity, "Start" );

	if ( sendToTarget ) {
		SetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity", target );
		SDKHook ( entity, SDKHook_SetTransmit, particleSetTransmit );
	}
	
	char output[64];
	if ( lifeTime > 0.0 ) 
	//	CreateTimer ( lifeTime, timerRemoveParticleEnt, EntIndexToEntRef ( entity ) );
		Format ( output, sizeof ( output ), "OnUser1 !self:kill::%.1f:-1", lifeTime );
	else
		Format ( output, sizeof ( output ), "OnUser1 !self:kill::3.0:-1" );
	
	SetVariantString ( output );
	AcceptEntityInput ( entity, "AddOutput" );
	AcceptEntityInput ( entity, "FireUser1" );
	
	if ( GetEdictFlags ( entity ) & FL_EDICT_ALWAYS )
		SetEdictFlags ( entity, ( GetEdictFlags ( entity ) ^ FL_EDICT_ALWAYS ) );
	
	return entity;
}

/**
 * 파티클을 생성합니다.
 *
 * @param target				파티클 주인 인덱스
 * @param entity				파티클 엔티티
 * @param effPos				파티클 위치
 * @param effAng				파티클 앵글
 * @param effName				파티클 이펙트 이름
 * @param activator				몸에 붙일건지 유무
 * @param lifeTime				파티클이 살아있는 시간 기본 10초
 * @param sendToTarget			주인에게만 보일지 여부
 * @param attachName			파티클을 붙일 타겟 부위 명
 * @return				파티클 엔티티를 리턴합니다.
 * @error		파티클이 없거나, 클라이언트 인덱스가 유효하지 않음.
 */
stock int loringlib_CreateParticleEx ( int target, int entity, float effPos[3], float effAng[3], char[] effName, bool activator = false, float lifeTime = 0.0, bool sendToTarget = false, char[] attachName = "" ) {
	entity = CreateEntityByName ( "info_particle_system" );
	if ( entity == -1 )
		return entity;
	
	//	No position.
	if ( effPos[0] == 0.0 && effPos[1] == 0.0 && effPos[2] == 0.0 ) {
		if ( activator )
			loringlib_GetEntityOriginEx ( entity, effPos );
		else
			loringlib_GetEntityAngle ( entity, effPos );
	}
	
	TeleportEntity ( entity, effPos, effAng, NULL_VECTOR );
	
	DispatchKeyValue ( entity, "effect_name", effName );
	DispatchKeyValue ( entity, "start_active", "1" );
	
	if ( activator ) {
		SetVariantString ( "!activator" );
		AcceptEntityInput ( entity, "SetParent", target, entity, 0 );
		SetEntPropEnt ( entity, Prop_Data, "m_pParent", target );
		
		if ( attachName[0] != EOS ) {
			SetVariantString ( attachName );
			AcceptEntityInput ( entity, "SetParentAttachment", target );
		}
	}
	
	DispatchSpawn ( entity );
	ActivateEntity ( entity );
//	AcceptEntityInput ( entity, "Start" );

	if ( sendToTarget ) {
		SetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity", target );
		SDKHook ( entity, SDKHook_SetTransmit, particleSetTransmit );
	}
	
	char output[64];
	if ( lifeTime > 0.0 ) 
	//	CreateTimer ( lifeTime, timerRemoveParticleEnt, EntIndexToEntRef ( entity ) );
		Format ( output, sizeof ( output ), "OnUser1 !self:kill::%.1f:-1", lifeTime );
	else
		Format ( output, sizeof ( output ), "OnUser1 !self:kill::3.0:-1" );
	
	SetVariantString ( output );
	AcceptEntityInput ( entity, "AddOutput" );
	AcceptEntityInput ( entity, "FireUser1" );
	
	if ( GetEdictFlags ( entity ) & FL_EDICT_ALWAYS )
		SetEdictFlags ( entity, ( GetEdictFlags ( entity ) ^ FL_EDICT_ALWAYS ) );
	
	return entity;
}

stock int loringlib_CreatePointerParticle ( int target, int cpoint, char[] effName, float lifeTime = 0.0 ) {
	int entity = CreateEntityByName ( "info_particle_system" );
	int entity2 = CreateEntityByName ( "info_particle_system" );
	
	char szTargetname[64];
	Format ( szTargetname, sizeof szTargetname, "target_%d", target );
	DispatchKeyValue ( target, "targetname", szTargetname );
	
	char szCPointname[64];
	Format ( szCPointname, sizeof szCPointname, "cpoint_target_%d", cpoint );
	DispatchKeyValue ( cpoint, "targetname", szCPointname );
	
	char szCPointname2[64];
	Format ( szCPointname2, sizeof szCPointname2, "particlename_%d", cpoint );
	
	DispatchKeyValue ( entity2, "targetname", szCPointname2 );
	DispatchKeyValue ( entity2, "parentname", szCPointname );
	
	SetVariantString ( szCPointname );
	AcceptEntityInput ( entity2, "SetParent" );
	
	SetVariantString ( "primary_smg" );
	AcceptEntityInput ( entity2, "SetParentAttachment" );
	
	DispatchKeyValue ( entity, "targetname", "cpoint_particle" );
	DispatchKeyValue ( entity, "parentname", szTargetname );
	DispatchKeyValue ( entity, "effect_name", effName );
	DispatchKeyValue ( entity, "cpoint1", szCPointname2 );
	
	DispatchSpawn ( entity );
	
	SetVariantString ( szTargetname );
	AcceptEntityInput ( entity, "SetParent" );
	
	SetVariantString ( "primary_smg" );
	AcceptEntityInput ( entity, "SetParentAttachment" );
	
	ActivateEntity ( entity );
	AcceptEntityInput ( entity, "start" );
	
	char output[64];
	if ( lifeTime > 0.0 ) 
	//	CreateTimer ( lifeTime, timerRemoveParticleEnt, EntIndexToEntRef ( entity ) );
		Format ( output, sizeof ( output ), "OnUser1 !self:kill::%.1f:-1", lifeTime );
	else
		Format ( output, sizeof ( output ), "OnUser1 !self:kill::3.0:-1" );
	
	SetVariantString ( output );
	AcceptEntityInput ( entity, "AddOutput" );
	AcceptEntityInput ( entity, "FireUser1" );
	
	if ( GetEdictFlags ( entity ) & FL_EDICT_ALWAYS )
		SetEdictFlags ( entity, ( GetEdictFlags ( entity ) ^ FL_EDICT_ALWAYS ) );
	
	return entity;
}

public Action particleSetTransmit ( int entity, int client ) {
	if ( GetEdictFlags ( entity ) & FL_EDICT_ALWAYS )
		SetEdictFlags ( entity, ( GetEdictFlags ( entity ) ^ FL_EDICT_ALWAYS ) );
	
	if( ( GetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity" ) == client || ( GetEntPropEnt ( client, Prop_Send, "m_hObserverTarget" ) == GetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity" ) && ( GetEntProp ( client, Prop_Send, "m_iObserverMode" ) == 4 || GetEntProp ( client, Prop_Send, "m_iObserverMode" ) == 5 ) ) ) )
		return Plugin_Continue;
	
	return Plugin_Stop;
}

/*
public Action timerRemoveParticleEnt ( Handle timer, int entity ) {	
	int ent = EntRefToEntIndex ( entity );
	if ( ent && ent != INVALID_ENT_REFERENCE ) {
		AcceptEntityInput ( ent, "Stop" );
		AcceptEntityInput ( ent, "Kill" );	
	}
	
	entity = INVALID_ENT_REFERENCE;
	return Plugin_Stop;
}	*/

/**
 * 파티클을 삭제합니다.
 *
 * @param particle		파티클 인덱스 값
 */
stock void loringlib_ParticleRemove ( int particle ) {
	int ent = EntRefToEntIndex ( particle );
	if ( ent && ent != INVALID_ENT_REFERENCE ) {
		AcceptEntityInput ( ent, "Stop" );
		AcceptEntityInput ( ent, "Kill" );
	}
	
	particle = INVALID_ENT_REFERENCE;
}

/**
 * 몸에 부착하는 파티클을 생성합니다.
 *
 * @param activatorTarget		파티클을 붙힐 엔티티 인덱스
 * @param effPos				파티클 위치
 * @param effAng				파티클 앵글
 * @param effName				파티클 이펙트 이름
 * @param lifeTime				파티클이 살아있는 시간
 * @param sendToTarget			파티클 주인에게만 표시 여부
 * @param attachName			파티클을 붙일 부위 (없을 경우 빈칸)
 * @return		파티클의 기본 엔티티 값으로 리턴합니다.
 */
stock int loringlib_CreateAttachParticle ( int attachTarget, float effPos[3], float effAng[3], char[] particleName, float lifeTime = 0.0, bool sendToTarget = false, char attachName[] = "" ) {
	return loringlib_CreatePArticleEx ( attachTarget, 0, effPos, effAng, particleName, true, lifeTime, sendToTarget, attachName );
}

/**
 * 스크린 파티클을 생성합니다.
 *
 * @param client		클라이언트 인덱스
 * @param particleName	파티클 이름
 * @param lifeTime		파티클 시간
 * @return	파티클이 유효하지 않다면 -1을 반환합니다.
 */
stock int loringlib_CreateScreenParticle ( int client, char[] particleName, float lifeTime = 0.0 ) {
	if ( loringlib_IsValidClient ( client ) ) {
		float flOrigin[3];
		GetClientAbsOrigin ( client, flOrigin );
		
		return loringlib_CreateParticleEx ( client, 0, flOrigin, NULL_VECTOR, particleName, true, lifeTime, true );
	}
	
	return -1;
}

stock void loringlib_TE_SetupParticleEffect ( const char[] particle, const float pos[3], const float endPos[3], const float angles[3] = NULL_VECTOR ) {
	TE_Start ( "EffectDispatch" );
	TE_WriteFloatArray ( "m_vStart.x", pos, 3 );
	TE_WriteFloatArray ( "m_vOrigin.x", endPos, 3 );
	TE_WriteVector ( "m_vAngles", angles );
	TE_WriteNum ( "m_nHitBox", loringlib_GetParticleEffectIndex ( particle ) );
	TE_WriteNum ( "m_iEffectName", loringlib_GetEffectIndex ( "ParticleEffect" ) );
}

/**
 * 스프라이트를 생성합니다.
 *
 * @param		target			스프라이트 주인
 * @param		sprite			스프라이트 모델 명
 * @param		location		스프라이트 생성 위치
 * @param		angles			스프라이트 앵글
 * @param		scale			스프라이트 크기 (선택)
 * @param		renderMode		스프라이트 렌더 모드 (선택)
 * @param		renderClr		스프라이트 렌더 색상 (선택)
 * @param		lifeTime		스프라이트 보이는 시간 (선택)
 * @param		activator		스프라이트 주인에게 붙일지 여부 (선택)
 * @param		renderToTarget	스프라이트를 타겟에게만 보여줍니다. (선택)
 * @return		스프라이트 인덱스 값
 */
stock int loringlib_CreateSprite ( int target, char[] sprite, float location[3], float angles[3], float scale = 0.1, int renderMode = SPRITE_RENDERMODE_NORMAL, int renderClr[3] = { 255, 255, 255 }, float lifeTime = 3.0, bool activator = false, bool renderToTarget = false ) {
	int spriteEnt = CreateEntityByName ( "env_sprite" );
	if ( spriteEnt > 0 ) {
		if ( !IsModelPrecached ( sprite ) )
			PrecacheModel ( sprite, true );
	
		static char strTargetname[32];
		Format ( strTargetname, sizeof strTargetname, "sprite_target_%d", GetClientSerial ( target ) );
		DispatchKeyValue ( target, "targetname", strTargetname );
	
		DispatchKeyValue ( spriteEnt, "model", sprite );
		static char strScale[16];
		FloatToString ( scale, strScale, sizeof strScale );
		DispatchKeyValue ( spriteEnt, "scale", strScale );
		static char strRendermode[8];
		IntToString ( renderMode, strRendermode, sizeof strRendermode );
		DispatchKeyValue ( spriteEnt, "rendermode", strRendermode );
		static char strClr[16];
		Format ( strClr, sizeof strClr, "%d %d %d", renderClr[0], renderClr[1], renderClr[2] );
		DispatchKeyValue ( spriteEnt, "rendercolor", strClr );
		
		DispatchSpawn ( spriteEnt );
		TeleportEntity ( spriteEnt, location, angles, NULL_VECTOR );
		
		SetEntPropEnt ( spriteEnt, Prop_Send, "m_hOwnerEntity", target );
		
		if ( activator ) {
			SetVariantString ( strTargetname );
			AcceptEntityInput ( spriteEnt, "SetParent", spriteEnt, spriteEnt, 0 );
		}
		
		if ( lifeTime > 0.0 ) {
			static char strVariantStr[64];
			Format ( strVariantStr, sizeof strVariantStr, "OnUser1 !self:Kill::%.1f:1", lifeTime );
			SetVariantString ( strVariantStr );
			AcceptEntityInput ( spriteEnt, "AddOutput" );
		}
		
		if ( renderToTarget ) {
			SDKHook ( spriteEnt, SDKHook_SetTransmit, particleSetTransmit );
		}
		
		if ( GetEdictFlags ( spriteEnt ) & FL_EDICT_ALWAYS )
			SetEdictFlags ( spriteEnt, ( GetEdictFlags ( spriteEnt ) ^ FL_EDICT_ALWAYS ) );
	
	}
	
	return spriteEnt;
}

#define PLAYER_PING_TYPE_DEFAULT		0
#define PLAYER_PING_TYPE_CIRCLE			1
#define PLAYER_PING_TYPE_ARROWDOWN		2
#define PLAYER_PING_TYPE_EYE			3
#define PLAYER_PING_TYPE_BANG			4
#define PLAYER_PING_TYPE_HELMET			5
#define PLAYER_PING_TYPE_ARMOR			6
#define PLAYER_PING_TYPE_ARMOR_HELMET	7
#define PLAYER_PING_TYPE_AMMOBOX		8
#define PLAYER_PING_TYPE_NO_TABLET		9
#define PLAYER_PING_TYPE_EXOJUMP		10
#define PLAYER_PING_TYPE_PARACHUTE		11
#define PLAYER_PING_TYPE_SNIPER			12
#define PLAYER_PING_TYPE_TABLET			13
#define PLAYER_PING_TYPE_DOLLAR			14

/**
 * 플레이어 핑을 생성합니다.
 *
 * @param client
 * @param pos
 * @param ang
 * @param type
 * @param team
 */
stock int loringlib_CreatePlayerPing ( int client, float pos[3], float ang[3], int type = PLAYER_PING_TYPE_DEFAULT, int team ) {
	if ( team != CS_TEAM_CT && team != CS_TEAM_T )
		return -1;
	
	int entity = CreateEntityByName ( "info_player_ping" );
	if ( entity > 0 ) {
		DispatchSpawn ( entity );
		
		SetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity", client );
		SetEntProp ( entity, Prop_Send, "m_hPlayer", client );
		SetEntPropEnt ( client, Prop_Send, "m_hPlayerPing", entity );
		
		TeleportEntity ( entity, pos, ang, NULL_VECTOR );
	}
	
	return entity;
}

/**
 * 플레이어 핑을 크로스헤어에 생성합니다.
 * 
 * @param client
 * @param type
 * @param team
 */
stock int loringlib_CreatePlayerPingCrosshair ( int client, int type = PLAYER_PING_TYPE_DEFAULT, int team ) {
	float flOrigin[3], flAngles[3];
	GetClientEyePosition ( client, flOrigin );
	GetClientEyeAngles ( client, flAngles );
	
	TR_TraceRayFilter ( flOrigin, flAngles, MASK_SHOT, RayType_Infinite, loringlib_TraceRayFilter_tarNotPlayer );
	
	if ( !TR_DidHit ( null ) )
		return -1;
	
	TR_GetEndPosition ( flOrigin, null );
	
	return loringlib_CreatePlayerPing ( client, flOrigin, NULL_VECTOR, type, team );
}

/**
 * 맵 스타일을 바꿉니다.
 * @note OnMapStart ()에서 사용합니다.
 *
 * @param lightStyle		빛 스타일 값
 * @param skyName			스카이 박스 이름
 * @return noreturn
 */
stock void loringlib_SetMapStyle ( char[] lightStyle, char[] skyName ) {
	SetLightStyle ( CONSOLE, lightStyle );
	ServerCommand ( "sv_skyname \"%s\"", skyName );
//	SetClientInfo ( CONSOLE, "sv_skyname", skyName );
}

/**
 * 맵 스카이박스를 바꿉니다.
 */
stock void loringlib_SetMapSkybox ( char[] sky ) {
	ServerCommand ( "sv_skyname \"%s\"", sky );
}

/**
 * 맵의 태양 엔티티를 설정합니다.
 *
 * @param enable		활성화 여부
 * @return noreturn
 */
stock void loringlib_SetSunEntity ( bool enable = true ) {
	int ent = FindEntityByClassname ( -1, "env_sun" );
	if ( ent == -1 )
		return;
		
	if ( !enable ) {
		AcceptEntityInput ( ent, "TurnOff" );
		AcceptEntityInput ( ent, "Kill" );
	}
	
	else
		AcceptEntityInput ( ent, "TurnOn" );
}

/**
 * 백터 초기화
 *
 * @param index					Index of index.
 * @noreturn
 */
stock void loringlib_RemoveVector ( int index ) {
	TeleportEntity ( index, NULL_VECTOR, NULL_VECTOR, NULL_VECTOR_FLY_BLOCK );
}

/**
 * 백터 삭제
 *
 * @param output				Output data.
 * @return no
 */
stock void loringlib_ClearVectors ( float output[3] ) {
	for ( int i = 0; i < 3; i ++ )
		output[i] = 0.000000;
}

/**
 * 백터 복사
 *
 * @param target			복사할 백터
 * @param vectors			복사된 백터 값을 삽입할 백터
 * @noreturn
 */
stock void loringlib_CopyVector ( float target[3], float vectors[3] ) {
	for ( int i = 0; i < 2; i ++ )
		vectors[i] = target[i];
}

/**
 * 클라이언트가 유효한지 채크합니다.
 *
 * @param client				Client index.
 * @return						Client valid.
 */
stock bool loringlib_IsValidClient ( int client ) {
	if ( client > 0 && client < MaxClients )
		if ( IsClientConnected ( client )
			&& IsClientInGame ( client ) 
			&& !IsClientSourceTV ( client )
			&& !IsClientReplay ( client ) )
			return true;
		else	return false;
	else	return false;
}

/**
 * 클라이언트가 살아 있는지 채크합니다.
 *
 * @param client				Client index.
 * @return						Client alive.
 */
stock bool loringlib_IsValidClient__PlayGame ( int client ) {
	if ( loringlib_IsValidClient ( client ) && IsPlayerAlive ( client ) )	return true;
	else	return false;
}

/**
 * 유저 아이디가 유효한지 채크합니다.
 *
 * @param userid			User Id.
 * @return			유효할 경우 true를 반환합니다.
 */
stock bool loringlib_IsValidUserId ( int userid ) {
	return loringlib_IsValidClient ( GetClientOfUserId ( userid ) );
}

stock bool loringlib_IsClientInAir ( int client ) {
	if ( GetEntPropEnt ( client, Prop_Send, "m_hGroundEntity" ) == -1 )
		return true;
		
	else
		return false;
}

/**
 * 팀의 클라이언트 수를 구합니다.
 * @note alive가 false면 죽은 사람과 살아있는 사람 모두 채크합니다.
 *
 * @param team					Team index.
 * @param alive					Alive check.
 * @return						Client number.
 */
stock int loringlib_GetTeamCount ( int team, bool alive = false ) {
	int c;
	
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( alive ? loringlib_IsValidClient__PlayGame ( i ) : loringlib_IsValidClient ( i ) )
			if ( GetClientTeam ( i ) == team )
				c ++;
				
	return c;
}

/**
 * 팀의 클라이언트 수를 구합니다.
 * @note alive가 false면 죽은 사람과 살아있는 사람 모두 채크합니다.
 *
 * @param team					Team index.
 * @param alive					Alive check.
 * @param fake					Bot check.
 * @return						Client number.
 */
stock int loringlib_GetTeamCountEx ( int team, bool alive = false, bool fake = false ) {
	int c;

	for ( int i = 1; i <= MaxClients; i ++ )
		if ( alive ? loringlib_IsValidClient__PlayGame ( i ) : loringlib_IsValidClient ( i ) )
			if ( fake ? IsFakeClient ( i ) : true )
				if ( GetClientTeam ( i ) == team )
					c ++;
				
	return c;
}

/**
 * 서버 접속 인원 수를 구합니다.
 *
 * @return						Valid clients number.
 */
stock int loringlib_GetClients () {
	int c;
	
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient ( i ) )
			c ++;
			
	return c;
}

/**
 * 서버의 옵저버 수를 구합니다.
 *
 * @return						Opserver clients number.
 */
stock int loringlib_GetObserver () {
	int c;
	
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient ( i ) && IsClientObserver ( i ) )
			c ++;
			
	return c;
}

/**
 * 죽어있는 사람 수를 구합니다.
 *
 * @return				clients
 */
stock int loringlib_GetDeadClients () {
	int result;
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
			
		if ( IsPlayerAlive ( i ) )
			continue;
		
		if ( GetClientTeam ( i ) == CS_TEAM_SPECTATOR )
			continue;
		
		if ( IsClientObserver ( i ) )
			continue;
			
		result ++;
	}
	
	return result;
}

/**
 * 팀의 죽어있는 사람 수를 구합니다.
 *
 * @param				team
 * @return				clients
 */
stock int loringlib_GetTeamDeadClients ( int team ) {
	int result = 0;
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
		
		if ( IsPlayerAlive ( i ) )
			continue;
		
		if ( IsClientObserver ( i ) )
			continue;
			
		if ( GetClientTeam ( i ) != team )
			continue;
		
		result ++;
	}
	
	return result;
}

/**
 * 서버에 완전히 접속 된 사람의 수를 구합니다.
 *
 * @return			clients number.
 */
stock int loringlib_GetInGameClients () {
	int c = 0;
	
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( IsClientConnected ( i ) &&
			IsClientInGame ( i ) &&
			!IsClientSourceTV ( i ) )
			c ++;
	
	return c;
}

/**
 * 서버에 접속하고 살아있는 사람의 수를 구합니다.
 *
 * @return						clients number.
 */
stock int loringlib_GetPlayGameClients () {
	int c = 0;
	
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient__PlayGame ( i ) )
			c ++;
			
	return c;
}

/**
 * 팀에 들어와있는 모든 사람의 수를 구합니다.
 *
 * @return				clients
 */
stock int loringlib_GetTeamClients () {
	int result;
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
			
		if ( GetClientTeam ( i ) == CS_TEAM_SPECTATOR )
			continue;
		
		result ++;
	}
	
	return result;
}

/**
 * 플레이어를 구합니다.
 *
 * @return			players
 */
stock int loringlib_GetPlayers () {
	int result;
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) )
			result ++;
	}
	
	return result;
}

/**
 * 살아있는 플레이어를 구합니다.
 *
 * @return			Alive players.
 */
stock int loringlib_GetAlivePlayers () {
	int result;
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient__PlayGame ( i ) )
			result ++;
	return result;
}

/**
 * 엔티티 갯수를 구합니다.
 *
 * @return			Entities
 */
stock int loringlib_GetEntities () {
	int result;
	
	for ( int i = MaxClients; i <= GetMaxEntities (); i ++ ) {
		if ( !IsValidEdict ( i ) )
			continue;
			
		result ++;
	}
	
	return result;
}

/**
 * 주인이 있는 엔티티 갯수를 구합니다.
 *
 * @return			Entities
 */
stock int loringlib_GetEntitiesFilterOwner () {
	int result;
	
	for ( int i = MaxClients; i <= GetMaxEntities (); i ++ ) {
		if ( !IsValidEdict ( i ) )
			continue;
			
		if ( loringlib_GetEntityOwner ( i ) < 1 )
			continue;
			
		result ++;
	}
	
	return result;
}

/**
 * 맵이 de_ 맵인지 채크합니다.
 *
 * @return			de_ 맵이면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsMapDE_ () {
	bool result = false;
	static char levelName[64];
	static int entity = -1;
	GetCurrentMap ( levelName, sizeof ( levelName ) );
	while ( ( entity = FindEntityByClassname ( entity, "func_bomb_target" ) ) != -1 ) {
		if ( !IsValidEntity ( entity ) )
			continue;
			
		if ( StrContains ( levelName, "de_", false ) != -1 ) {
			result = true;
			break;
		}
	}
	
	return result;
}

/**
 * 맵이 cs_ 맵인지 채크합니다.
 *
 * @return			cs_ 맵이면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsMapCS_ () {
	bool result = false;
	static char levelName[64];
	static int entity = -1;
	GetCurrentMap ( levelName, sizeof ( levelName ) );
	while ( ( entity = FindEntityByClassname ( entity, "func_hostage_rescue" ) ) != -1 ) {
		if ( !IsValidEntity ( entity ) )
			continue;
			
		if ( StrContains ( levelName, "cs_", false ) != -1 ) {
			result = true;
			break;
		}
	}
	
	return result;
}

/**
 * 클라이언트의 cl_interp값을 구합니다.
 *
 * @param client				Client index.
 * @return				Client's cl_interp value.
 */
stock float loringlib_GetClientInterp ( int client ) {
	static char result[16];
	GetClientInfo ( client, "cl_interp", result, sizeof ( result ) );
	
	return StringToFloat ( result );
}

/**
 * 클라이언트의 그룹 아이디를 구합니다.
 *
 * @param client				Client index.
 * @return				clan id
 */
stock int loringlib_GetClientClanId ( int client ) {
	static char result[24];
	GetClientInfo ( client, "cl_clanid", result, sizeof ( result ) );
	
	return StringToInt ( result );
}

/**
 * 클라이언트의 허드 색깔을 구합니다.
 * @param client				Client index.
 * @return				Client's hud color.
 */
stock int loringlib_GetClientCSGOHudColor ( int client ) {
	static char result[4];
	GetClientInfo ( client, "cl_hud_color", result, sizeof ( result ) );

	if ( StringToInt ( result ) < 0 || StringToInt ( result ) > 11 )
		return 0;
	else
		return StringToInt ( result );
}

/**
 * 모든 클라이언트 중에서 무작위로 한명을 선택 합니다.
 *
 * @param randomnumber			Random int.
 * @return						One client.
 *
 * @error						Invalid client number.
 */
stock int loringlib_GetRandomPlayer ( int randomnumber ) {
	int numbRandam;
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
			
		numbRandam ++;
		
		if ( numbRandam == randomnumber )
			return i;
	}
	
	return numbRandam -1;
}

/**
 * 살아있는 클라이언트 중에서 무작위로 한명을 선택 합니다.
 *
 * @param randomnumber			Random int.
 * @return						One client.
 *
 * @error						Invalid client number.
 */
stock int loringlib_GetRandomAlive ( int randomnumber ) {
	int numbRandam;
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient__PlayGame ( i ) )
			continue;
			
		numbRandam ++;
		
		if ( numbRandam == randomnumber )
			return i;
	}
	
	return numbRandam -1;
}

/**
 * 클라이언트의 에임이 가르키는 클라이언트를 구합니다.
 *
 * @param client				Client index.
 * @return						Aim target index.
 *
 * @error						Invalid target index.
 */
stock int loringlib_GetClientAimPlayer ( int client ) {
	float ang[3];
	float origin[3];
	
	GetClientEyePosition ( client, origin );
	GetClientEyeAngles ( client, ang );
	
	Handle traceRay = TR_TraceRayFilterEx ( origin, ang, MASK_SHOT, RayType_Infinite, loringlib_TraceRayFilter_tarPlayer, client );
	if ( TR_DidHit ( traceRay ) ) {
		int target = TR_GetEntityIndex ( traceRay );
		delete traceRay;
		
		return target;
	}
	delete traceRay;
	
	return -1;
}

/**
 * 클라이언트의 에임이 가르키는 엔티티를 구합니다.
 *
 * @param client				Client index.
 * @return						Aim entity index.
 *
 * @error						Invalid entity index.
 */
stock int loringlib_GetClientAimEntity ( int client ) {
	float ang[3];
	float origin[3];
	
	GetClientEyePosition ( client, origin );
	GetClientEyeAngles ( client, ang );

	Handle traceRay = TR_TraceRayFilterEx ( origin, ang, MASK_SHOT, RayType_Infinite, loringlib_TraceRayFilter_tarNotPlayer2, client );
	if ( TR_DidHit ( traceRay ) ) {
		int target = TR_GetEntityIndex ( traceRay );
		delete traceRay;
		
		return target;
	}
	delete traceRay;
	
	return -1;
}

/**
 * 클라이언트의 에임이 가르키는 엔티티와의 거리를 구합니다.
 *
 * @param client				Client index.
 * @param maxtracedistance		클라이언트와 엔티티의 거리.
 * @param pos				클라이언트의 눈 위치
 * @param ang				클라이언트의 눈 각도
 * @return 거리안에 들어오면 true, 아니면 false.
 */
stock bool loringlib_GetClientAimEntityDistance ( int client, float maxtracedistance, float pos[3], float ang[3] ) {
	GetClientEyePosition ( client, pos );
	GetClientEyeAngles ( client, ang );
	
	Handle	traceresulthandler = INVALID_HANDLE;
	traceresulthandler = TR_TraceRayFilterEx ( pos, ang, MASK_SOLID, RayType_Infinite, loringlib_TraceRayFilter_tarNotPlayer2, client );
	
	if ( TR_DidHit ( traceresulthandler ) ) {
		float	end[3];
		TR_GetEndPosition ( end, traceresulthandler );
		TR_GetPlaneNormal ( traceresulthandler, ang );
		
		GetVectorAngles ( ang, ang );
		
		if ( maxtracedistance >= GetVectorDistance ( pos, end ) ) {
			pos[0] = end[0];
			pos[1] = end[1];
			pos[2] = end[2];
			
			CloseHandle ( traceresulthandler );
			
			return true;
		}
		
		CloseHandle ( traceresulthandler );
	}
	
	return false;
}

/**
 * 클라이언트가 바라보고 있는 위치를 구합니다.
 *
 * @param client				Client index.
 * @param end					Result client eye and position.
 * @return		바라보는 시점이 있다면 true, 없으면 false를 반환합니다.
 */
stock bool loringlib_GetEndPosition ( int client, float end[3] ) {
	float start[3];
	float ang[3];
	GetClientEyePosition ( client, start );
	GetClientEyeAngles ( client, ang );
	TR_TraceRayFilter ( start, ang, MASK_SOLID, RayType_Infinite, loringlib_TraceRayFilter_tarNotPlayer3, client );
	if ( TR_DidHit ( null ) ) {
		TR_GetEndPosition ( end, null );
		return true;
	}
	
	return false;
}

/**
 * 클라이언트가 바라보고 있는 위치를 구합니다. (클라이언트 포함)
 *
 * @param client				Client index.
 * @param end					Result client eye and position.
 * @return		바라보는 시점이 있다면 true, 없으면 false를 반환합니다.
 */
stock bool loringlib_GetEndPositionEx ( int client, float end[3] ) {
	float start[3];
	float ang[3];
	GetClientEyePosition ( client, start );
	GetClientEyeAngles ( client, ang );
	TR_TraceRayFilter ( start, ang, MASK_SOLID, RayType_Infinite, loringlib_TraceRayFilter_tarPlayer, client );
	if ( TR_DidHit ( null ) ) {
		TR_GetEndPosition ( end, null );
		return true;
	}
	
	return false;
}

/**
 * 오버레이 출력
 *
 * @param client				Client index.
 * @param overlay				Overlay path.
 * @noreturn
 */
stock void loringlib_ShowOverlayToClient ( int client, const char[] overlay ) {
//	ClientCommand ( client, "r_screenoverlay \"%s\"", overlay );
	if ( !loringlib_IsValidClient ( client ) )
		return;
		
	int flags = GetCommandFlags ( "r_screenoverlay" ) & ( ~FCVAR_CHEAT );
	SetCommandFlags ( "r_screenoverlay", flags );
	
	char temp[256];
	Format ( temp, sizeof ( temp ), "%s", overlay );
	ReplaceString ( temp, sizeof ( temp ), "materials/", "" );
	PrecacheDecal ( overlay, true );
	ClientCommand ( client, "r_screenoverlay \"%s\"", temp );
}

/**
 * 오버레이 제거
 *
 * @param client				Client index.
 * @noreturn
 */
stock void loringlib_RemoveOverlay ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return;
		
	int flags = GetCommandFlags ( "r_screenoverlay" ) & ( ~FCVAR_CHEAT );
	SetCommandFlags ( "r_screenoverlay", flags );
	ClientCommand ( client, "r_screenoverlay \"\"" );
}

/**
 * 모두에게 오버레이 출력
 *
 * @param overlay				Overlay path.
 * @noreturn
 */
stock void loringlib_ShowOverlayToAll ( const char[] overlay ) {
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) )
			loringlib_ShowOverlayToClient ( i, overlay );
}

/**
 * @section hint_icon_onscreen과 offscreen에 대한 옵션입니다.
 */
#define ICON_BULB					"icon_bulb"
#define ICON_CAUTION				"icon_caution"
#define ICON_ALERT					"icon_alert"
#define ICON_ALERT_RED				"icon_alert_red"
#define ICON_TOP					"icon_tip"
#define ICON_SKULL					"icon_skull"
#define ICON_NO						"icon_no"
#define ICON_RUN					"icon_run"
#define ICON_INTERACT				"icon_interact"
#define ICON_BUTTON					"icon_button"
#define ICON_DOOR					"icon_door"
#define ICON_ARROW_PLAIN			"icon_arrow_plain"
#define ICON_ARROW_PLAIN_WHITE_DOWN	"icon_arrow_plain_white_dn"
#define ICON_ARROW_PLAIN_WHITE_UP	"icon_arrow_plain_white_up"
#define ICON_ARROW_UP				"icon_arrow_up"
#define ICON_ARROW_RIGHT			"icon_arrow_right"
#define ICON_FIRE					"icon_fire"
#define ICON_PRESENT				"icon_present"
#define ICON_USE_BINDING			"use_binding"

/**
 * @section hint_static에 대한 옵션입니다.
 */
#define HINT_STATIC_TARGET_ENTITY	0	/**< 타겟 엔티티에게 표시 */
#define HINT_STATIC_ON_HUD			1	/**< 허드에 표시 */

/**
 * 알림 상자로 메세지 출력
 * @note 알림 기능이 비활성화 되어 있으면 표시되지 않습니다.
 *
 * @param client				Client index
 * @param show					Box Show time
 * @param height				Box height
 * @param range					박스 범위
 * @param staticOption			hint_static
 * @param showOffscreen			박스 보이기
 * @param iconOnscreen			박스 아이콘 (ICON_USE_BINDING을 사용 할 시 밑의 cmds에 키 값을 입력해야한다.)
 * @param iconOffscreen			박스 아이콘 (ICON_USE_BINDING을 사용 할 시 밑의 cmds에 키 값을 입력해야한다.)
 * @param cmds					바인딩 옵션
 * @param showTextalways		벽에 박스 메세지를 출력.
 * @param color					RGB color.
 * @param messages				Box messages.
 * @return						Dispatch env_instructor_hint entity.
 * @error						Invalid "env_instructor_hint" entity name.
 */
stock void loringlib_PrintInstructorMessage (
 int client,
 float show = 5.0,
 float height,
 float range,
 int staticOption,
 bool showOffscreen,
 char[] iconOnscreen,
 char[] iconOffscreen,
 char[] cmds,
 bool showTextalways,
 int color[3],
 char messages[101] ) {
	int env = CreateEntityByName ( "env_instructor_hint" );
	
	if ( env <= 0 )
		return;
		
	char buff[32];
	FormatEx ( buff, sizeof ( buff ), "%d", client );
	
	//	타겟
	DispatchKeyValue ( client, "targetname", buff );
	DispatchKeyValue ( env, "hint_target", buff );
	
	//	
	FormatEx ( buff, sizeof ( buff ), "%d", staticOption );
	DispatchKeyValue ( env, "hint_static", buff );
	
	//	타임 아웃
	FormatEx ( buff, sizeof ( buff ), "%d", RoundToFloor ( show ) );
	DispatchKeyValue ( env, "hint_timeout", buff );
	if ( show > 0.0 )
		loringlib_RemoveEntity ( env, show );
		
	//	높이
	FormatEx ( buff, sizeof ( buff ), "%d", RoundToFloor ( height ) );
	DispatchKeyValue ( env, "hint_icon_offset", buff );
	
	//	범위
	FormatEx ( buff, sizeof ( buff ), "%d", RoundToFloor ( range ) );
	DispatchKeyValue ( env, "hint_range", buff );
	
	//	Show off screen.
	FormatEx ( buff, sizeof ( buff ), "%d", !showOffscreen );
	DispatchKeyValue ( env, "hint_nooffscreen", buff );
	
	//	아이콘
	DispatchKeyValue ( env, "hint_icon_onscreen", iconOnscreen );
	DispatchKeyValue ( env, "hint_icon_offscreen", iconOffscreen );
	
	//	바인딩
	DispatchKeyValue ( env, "hint_binding", cmds );
	
	//	벽 뒤 텍스트 출력 
	FormatEx ( buff, sizeof ( buff ), "%d", showTextalways );
	DispatchKeyValue ( env, "hint_forcecaption", buff );
	
	//	텍스트 색깔
	Format ( buff, sizeof ( buff ), "%d %d %d", color[0], color[1], color[2] );
	DispatchKeyValue ( env, "hint_color", buff );
	
	//	텍스트
	ReplaceString ( messages, sizeof ( messages ), "\n", " " );
	DispatchKeyValue ( env, "hint_caption", messages );
	
	DispatchSpawn ( env );
	
	AcceptEntityInput ( env, "ShowHint" );
}

/**
 * 이벤트를 사용 해 인터럭트 메세지를 출력시킵니다.
 * @note 클라이언트 측에서 gameinstructor_enable을 1로 사용하고, 타겟이 유효하고 살아있을 경우에만 fire합니다.
 *
 * @param target
 * @param activator
 * @param hintTimeout
 * @param colors
 * @param range
 * @param allowNodrawTarget
 * @param noOffscreen
 * @param forceCaption
 * @param localOnly
 * @param iconOffset
 * @param onScreen
 * @param offScreen
 * @param binding
 * @param captions
 * @param flags
 */
stock bool loringlib_PrintInstructorMessageByEvent (
 int target = 0,
 int activator = 0,
 int hintTimeout = 10,
 int colors[3],
 float range,
 bool allowNodrawTarget,
 bool noOffscreen,
 bool forceCaption,
 bool localOnly,
 float iconOffset,
 char[] onScreen,
 char[] offScreen,
 char[] binding,
 char[] captions,
 int flags ) {
	Event event = CreateEvent ( "instructor_server_hint_create" );
	
	if ( event == null )
		return false;
	
	static char hintName[256];
	FormatEx ( hintName, sizeof ( hintName ), "%d_%f_%d", target, GetGameTime (), GetTime () );
	
	static char hintColor[64];
	FormatEx ( hintColor, sizeof ( hintColor ), "%d %d %d", colors[0], colors[1], colors[2] );
	
	event.SetString ( "hint_name", hintName );
	event.SetString ( "hint_replace_key", hintName );
	event.SetInt ( "hint_target", target );
	event.SetInt ( "hint_activator_userid", activator );
	event.SetInt ( "hint_timeout", hintTimeout );
	event.SetString ( "hint_icon_onscreen", onScreen );
	event.SetString ( "hint_icon_offscreen", offScreen );
	event.SetString ( "hint_caption", captions );
	event.SetString ( "hint_activator_caption", captions );
	event.SetString ( "hint_color", hintColor );
	event.SetFloat ( "hint_icon_offset", iconOffset );
	event.SetFloat ( "hint_range", range );
	event.SetInt ( "hint_flags", flags );
	event.SetString ( "hint_binding", binding );
	event.SetBool ( "hint_allow_nodraw_target", allowNodrawTarget );
	event.SetBool ( "hint_nooffscreen", noOffscreen );
	event.SetBool ( "hint_forcecaption", forceCaption );
	event.SetBool ( "hint_local_player_only", localOnly );
	
	event.Fire ();
	return true;
}


/**
 * 엔티티 주위에 빛을 만듭니다.
 *
 * @param origin				Light origin.
 * @param distance				Light distance.
 * @param radius				Light radius.
 * @param duration				Light alive times.
 * @param attachment			Light attachment.
 * @param client				Client index.
 * @error			Invalid "light_dynamic" entity name.
 */
stock int loringlib_EffectLightDynamic (
 float origin[3] = { 0.0, 0.0, 0.0 },
 char[] color,
 float distance,
 float radius,
 float duration,
 bool attachment = false,
 int client = -1 ) {
	int ent = CreateEntityByName ( "light_dynamic" );
	
	if ( ent == -1 ) {
		LogError ( "Invalid \"light_dynamic\" entity name." );
		return -1;
	}
	
	if ( ent ) {
		DispatchKeyValue ( ent, "inner_cone", "0" );
		DispatchKeyValue ( ent, "cone", "80" );
		DispatchKeyValue ( ent, "brightness", "1" );
		DispatchKeyValue ( ent, "pitch", "250" );
		DispatchKeyValue ( ent, "style", "1" );
		DispatchKeyValue ( ent, "_light", color );
		
		DispatchKeyValueFloat ( ent, "distance", distance );
		DispatchKeyValueFloat ( ent, "spotlight_radius", radius );
		
		DispatchSpawn ( ent );
		
		AcceptEntityInput ( ent, "turnOn" );
		
		if ( attachment )
			loringlib_GetEntityOriginEx ( client, origin );
			
		TeleportEntity ( ent, origin, NULL_VECTOR, NULL_VECTOR );
		
		if ( attachment ) {
			SetVariantString ( "!activator" );
			AcceptEntityInput ( ent, "SetParent", client, ent, 0 );
			SetEntPropEnt ( ent, Prop_Data, "m_pParent", client );
		}
		
		if ( duration > 0.0 ) {
			char times[64];
			Format ( times, sizeof ( times ), "OnUser1 !self:kill::%f:1", duration );
			SetVariantString ( times );
		}
		
		AcceptEntityInput ( ent, "AddOutput" );
		AcceptEntityInput ( ent, "FireUser1" );
		
		return ent;
	}
	
	return -1;
}

/**
 * 엔티티를 n초간 얼립니다.
 *
 * @param client				Client index.
 * @param times					Freeze time.
 * @noreturn
 */
stock void loringlib_FreezeEntity ( int client, float times = 0.5, int freezeColors[4] = { 64, 64, 160, 128 } ) {
	if ( loringlib_IsValidClient__PlayGame ( client ) ) {
		SetEntityMoveType ( client, MOVETYPE_NONE );
		
		SetEntityRenderMode( client, RENDER_GLOW );
		SetEntityRenderColor ( client, freezeColors[0], freezeColors[1], freezeColors[2], freezeColors[3] );

		CreateTimer ( times, timerUnFreeze, client );
	}
}

public Action timerUnFreeze ( Handle timer, int id ) {
	if ( loringlib_IsValidClient__PlayGame ( id ) ) {
		SetEntityMoveType ( id, MOVETYPE_WALK );
		
		SetEntityRenderMode ( id, RENDER_GLOW );
		SetEntityRenderColor ( id, 255, 255, 255, 255 );
		
		loringlib_RemoveVector ( id );
	}
	
	return Plugin_Stop;
}

/**
 * EmitSound to client.
 * @note 단, 소리를 겹칠 수 없습니다.
 *
 * @param client				Client index.
 * @param soundpath				Sound file path.
 * @noreturn
 */
stock void loringlib_CSGOEmitSoundToClient ( int client, char[] soundpath ) {
	if ( loringlib_IsValidClient ( client ) )
		ClientCommand ( client, "play */%s", soundpath );
}

/**
 * EmitSound to ALL.
 * @note 단, 소리를 겹칠 수 없습니다.
 *
 * @param soundpath				Sound file path.
 * @noreturn
 */
stock void loringlib_CSGOEmitSoundToAll ( char[] soundpath ) {
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient ( i ) )
			ClientCommand ( i, "play */%s", soundpath );
}

/**
 * Ambient Sound를 멈추게 합니다.
 *
 * @param sample				소리 경로
 * @param client				클라이언트 인덱스. -1일 경우 모두에게 멈추게 합니다.
 */
stock void loringlib_StopAmbientSound ( const char[] sample, int client = -1 ) {
	PrecacheSound ( sample );
	
	if ( loringlib_IsValidClient ( client ) )
		StopSound ( client, SOUND_AMBIENT_CHANNEL, sample );
		
	else {
			
		for ( int i = 1; i <= MaxClients; i ++ ) {
			if ( !loringlib_IsValidClient ( i ) )
				continue;
				
			StopSound ( i, SOUND_AMBIENT_CHANNEL, sample );
		}
	}
}

/**
 * Emits an ambient sound.
 *
 * @param sample				The path to the sound file (relative to sound/)
 * @param volume				The volume of the sound (.0 ~ 1.0)
 * @param client				(Optional) Client index to play sound to.
 */
stock void loringlib_EmitAmbientSound ( const char[] sample, float volume = 1.0, int client = -1 ) {
	PrecacheSound ( sample );
	
	if ( loringlib_IsValidClient ( client ) ) {
		EmitSoundToClient ( client, sample, SOUND_FROM_PLAYER, SOUND_AMBIENT_CHANNEL, _, _, volume );
		/**/
	}
	
	else {
		for ( int i = 1; i <= MaxClients; i ++ ) {
			if ( !loringlib_IsValidClient ( i ) )
				continue;
				
			EmitSoundToClient ( i, sample, SOUND_FROM_PLAYER, SNDCHAN_AUTO, _, _, volume );
		}
	}
}

/**
 * Emits a sound from a client.
 * 
 * @param client				The client index.
 * @param sound					The sound file relative to the sound/ directory.
 * @param level					The attenuation of the sound.
 */
stock void loringlib_EmitSoundFromClient ( int client, const char[] sound, int level = SNDLEVEL_NORMAL ) {
    // Precache sound before playing.
    PrecacheSound ( sound );
    
    // Emit sound from client.
    EmitSoundToAll ( sound, client, _, level );
}

stock void loringlib_EmitSoundToAll ( const char[] sample, int client, int icannel = SNDCHAN_AUTO, int ilevel = SNDLEVEL_NORMAL ) {
	PrecacheSound ( sample );
	EmitSoundToAll ( sample, client, icannel, ilevel );
}

stock void loringlib_EmitWorldSound ( int soundOwner = -1, const char[] sample, int entity = SOUND_FROM_PLAYER, int channel = SNDCHAN_AUTO, int level = SNDLEVEL_NORMAL, int flags = SND_NOFLAGS, float volume = SNDVOL_NORMAL, int pitch = SNDPITCH_NORMAL, int speakerentity = -1, const float origin[3] = NULL_VECTOR, const float dir[3] = NULL_VECTOR, bool updatePos = true, float soundtime = 0.0 ) {
	if ( soundOwner > 0 ) {
		EmitSoundToClient ( soundOwner, sample, entity, channel, level, flags, volume, pitch, speakerentity, _, dir, updatePos, soundtime );
		for ( int clients = 1; clients <= MaxClients; clients ++ ) {
			if ( loringlib_IsValidClient ( clients ) && !IsFakeClient ( clients ) ) {
				if ( soundOwner != clients )
					EmitSoundToClient ( clients, sample, SOUND_FROM_WORLD, channel, level, flags, volume, pitch, speakerentity, origin, dir, updatePos, soundtime );
			}
		}
	}
	else
		EmitSoundToAll ( sample, SOUND_FROM_WORLD, channel, level, flags, volume, pitch, speakerentity, origin, dir, updatePos, soundtime );
}

/**
 * AddFileToDownloadsTable 함수에서 파라메터를 추가할 수 있는 stock입니다.
 * 
 * @param sample				샘플 경로
 * @param ...			샘플에 사용될 파라메터
 * @noreturn
 */
stock void loringlib_AddFileToDownloadsTableEx ( const char[] sample, any ... ) {
	static char buffer[256];
	VFormat ( buffer, sizeof ( buffer ), sample, 2 );
	AddFileToDownloadsTable ( buffer );
}

/**
 * sound/경로를 뺀 나머지 샘플 경로를 넣어도 다운로드 테이블에 추가할 수 있습니다.
 * 
 * @param sample				샘플 경로
 * @noreturn
 */
stock void loringlib_SoundAddFileToDTable ( const char[] sample ) {
	static char buffer[256];
	Format ( buffer, sizeof ( buffer ), "sound/%s", sample );
	AddFileToDownloadsTable ( buffer );
}

/**
 * 모두에게 showHudText를 보냅니다.
 * 
 * @param hudChannel				허드 채널	-1은 기본 채널 값 입니다.
 * @param hudTextBuffv				텍스트 버퍼
 * @param ...					텍스트 버퍼에 사용될 파라메터
 * @error			존재하지 않는 클라이언트에게 showHudText firing.
 */
stock void loringlib_ShowHudTextToAll ( int hudChannel, const char[] hudTextBuffv, any ... ) {
	char buffer[254];
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			VFormat ( buffer, sizeof ( buffer ), hudTextBuffv, 3 );
			ShowHudText ( i, hudChannel, "%s", buffer );
		}
	}
}

/**
 * 모두에게 showSyncHudText를 보냅니다.
 * 
 * @param hudSync				허드 싱크
 * @param hudTextBuffv				텍스트 버퍼
 * @param ...					텍스트 버퍼에 사용될 파라메터
 * @error			존재하지 않는 클라이언트에게 showSyncHudText firing.
 */
stock void loringlib_ShowSyncHudTextToAll ( Handle hudSync, const char[] hudTextBuffv, any ... ) {
	char buffer[254];
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			VFormat ( buffer, sizeof ( buffer ), hudTextBuffv, 3 );
			ShowSyncHudText ( i, hudSync, "%s", buffer );
		}
	}
}

stock bool loringlib_MakeExplosion2 (
 int attacker = 0,
 int inflictor = -1,
 const float explodepos[3],
 const char[] weaponname = "",
 int magnitude = 100,
 int radius = 0,
 int flag = 6146,
 bool takeDamageOnlyEnemy = false ) {
	int entity = CreateEntityByName ( "env_explosion" );
	if ( entity == -1 )
		return false;
	
	DispatchKeyValueVector ( entity, "Origin", explodepos );
	
	static char intBuff[64];
	IntToString ( magnitude, intBuff, sizeof ( intBuff ) );
	DispatchKeyValue ( entity, "iMagnitude", intBuff );
	if ( radius > 0 ) {
		IntToString ( radius, intBuff, sizeof ( intBuff ) );
		DispatchKeyValue ( entity, "iRadiusOverride", intBuff );
	}
	
	if ( flag != 0 ) {
		IntToString ( flag, intBuff, sizeof ( intBuff ) );
		DispatchKeyValue ( entity, "spawnflags", intBuff );
	}
	
	if ( !StrEqual ( weaponname, "", false ) ) {
		DispatchKeyValue ( entity, "classname", weaponname );
		if ( inflictor != -1 )
			DispatchKeyValue ( inflictor, "classname", weaponname );
	}
	
	DispatchSpawn ( entity );
	
	if ( loringlib_IsValidClient ( attacker ) )
		SetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity", attacker );
	if ( inflictor != -1 )
		SetEntPropEnt ( entity, Prop_Data, "m_hInflictor", inflictor );
	
	if ( takeDamageOnlyEnemy )
		if ( attacker > 0 )
			SetEntProp ( entity, Prop_Send, "m_iTeamNum", GetClientTeam ( attacker ) );
	
	AcceptEntityInput ( entity, "Explode" );
	AcceptEntityInput ( entity, "Kill" );
	return true;
}

/**
 * 폭발을 만듭니다.
 *
 * @param attacker				Attacker index.
 * @param inflictor				Inflictor index.
 * @param explodepos			Explosion position.
 * @param index					Explosion classname.
 * @param magnitude
 * @param radiusoverride
 * @param dmg					Explosion damages.
 * @param flags					Flags.
 * @return explosion fire.
 *
 * @error Invalid "env_explosion" entity name.
 */
stock int loringlib_MakeExplosion (
 int attacker,
 int inflictor = -1,
 const float explodepos[3],
 const char[] index = "",
 int magnitude = 100,
 int radiusoverride = 0,
 float dmg = 0.0,
 int team = 0,
 int flags = 0 ) {
	
	int explosion = CreateEntityByName ( "env_explosion" );
	
	if ( explosion != -1 ) {
		DispatchKeyValueVector ( explosion, "Origin", explodepos );
		
		char buff[64];
		IntToString ( magnitude, buff, sizeof ( buff ) );
		DispatchKeyValue ( explosion, "iMagnitude", buff );
	//	SetEntProp ( explosion, Prop_Data, "m_iMagnitude", magnitude );
		
		if ( radiusoverride > 0 ) {
			IntToString ( radiusoverride, buff, sizeof ( buff ) );
			DispatchKeyValue ( explosion, "iRadiusOverride", buff );
		//	SetEntProp ( explosion, Prop_Data, "m_iRadiusOverride", radiusoverride );
		}
		
		if ( dmg > 0.0 )
			DispatchKeyValueFloat ( explosion, "DamageForce", dmg );
			
		if ( flags != 0 ) {
			IntToString ( flags, buff, sizeof ( buff ) );
			DispatchKeyValue ( explosion, "spawnflags", buff );
		//	SetEntProp ( explosion, Prop_Data, "m_spawnflags", flags );
		}
		
		if ( !StrEqual ( index, "", false ) ) {
			DispatchKeyValue ( explosion, "classname", index );
			
			if ( inflictor != -1 )
				DispatchKeyValue ( inflictor, "classname", index );
		}
		
		DispatchSpawn ( explosion );
		
		if ( attacker != -1 )
			SetEntPropEnt ( explosion, Prop_Send, "m_hOwnerEntity", attacker );
			
		if ( inflictor != -1 )
			SetEntPropEnt ( explosion, Prop_Send, "m_hInflictor", inflictor );
			
		SetEntProp ( explosion, Prop_Send, "m_iTeamNum", team );
		AcceptEntityInput ( explosion, "Explode" );
		
		if ( ~flags & SF_ENVEXPLOSION_REPEATABLE )
			AcceptEntityInput ( explosion, "Kill" );
			
		return explosion;
	}
	else
		return -1;
}

stock float loringlib_CS_CreateExplosion ( int attacker, int weapon, float damage = 50.0, float radius = 100.0, float pos[3], int explosionTeam = CS_TEAM_NONE, char[] explosionEffect = "explosion_basic" ) {
	loringlib_CreateParticleEx ( attacker, 0, pos, NULL_VECTOR, explosionEffect, false, 5.0 );
	
	float flTotalDamages = 0.0;
	
	float flVictimOrigin[3];
	float flDamageResult;
	
	for ( int victim = 1; victim <= MaxClients; victim ++ ) {
		if ( loringlib_IsValidClient__PlayGame ( victim ) ) {
			GetClientAbsOrigin ( victim, flVictimOrigin );
			
			if ( GetClientTeam ( victim ) == explosionTeam )
				continue;
			
			if ( GetVectorDistance ( pos, flVictimOrigin ) <= radius ) {
				flDamageResult = Sine ( ( ( radius - GetVectorDistance ( pos, flVictimOrigin ) ) / radius ) * ( 3.14159 / 2 ) ) * damage;
				SDKHooks_TakeDamage ( victim, attacker, attacker, flDamageResult, DMG_BLAST, weapon, NULL_VECTOR, pos );
			//	loringlib_MakeDamage ( attacker, victim, RoundFloat ( flDamageResult ), weapon, DMG_BLAST );
				
				flTotalDamages += flDamageResult;
			}
		}
	}
	
	return flTotalDamages;
}

/**
 * 허트 포인트를 만듭니다.
 *
 * @param client				클라이언트 인덱스
 * @param target				타겟 인덱스
 * @param dmg					폭발 피해량
 * @param classname
 * @param dmgType
 * @return			포인트 허트를 만들었다면 true아니면 false를 반환합니다.
 * @error			Invalid "point_hurt" entity name.
 */
stock bool loringlib_MakeDamage ( int client, int target, int dmg, const char[] classname = "", int dmgType = DMG_SLASH ) {
	int ent = CreateEntityByName ( "point_hurt" );
//	PrintToChat ( client, "%d Damages!", dmg );
	
	if ( ent != -1 ) {
		if ( target != -1 ) {
			static char targetName[128];
			Format ( targetName, 128, "%d", EntIndexToEntRef ( ent ) );
			DispatchKeyValue ( target, "TargetName", targetName );
			DispatchKeyValue ( ent, "DamageTarget", targetName );
		} else	DispatchKeyValue ( ent, "DamageTarget", "" );
		
		float entfire_DispatchPosition[3];
		loringlib_GetEntityOriginEx ( target, entfire_DispatchPosition );
		
		DispatchKeyValueVector ( ent, "Origin", entfire_DispatchPosition );
		
		static char dmgNumb[8];
		static char dmgtypeTemp[16];
		IntToString ( dmg, dmgNumb, sizeof ( dmgNumb ) );
		IntToString ( dmgType, dmgtypeTemp, sizeof ( dmgtypeTemp ) );
		DispatchKeyValue ( ent, "Damage", dmgNumb );
		DispatchKeyValue ( ent, "classname", classname );
		DispatchKeyValue ( ent, "DamageType", dmgtypeTemp );
		
		DispatchKeyValueFloat ( ent, "DamageRadius", 1.0 );
		
		DispatchSpawn ( ent );
		
		AcceptEntityInput ( ent, "Hurt", client != -1 ? client : 0 );
		AcceptEntityInput ( ent, "kill" );
		
		return true;
	}
	
	else
		return false;
}

/**
 * 범위 데미지를 만듭니다.
 * @note 클라이언트를 중심으로 범위 데미지를 만듭니다.
 *
 * @param client				클라이언트 인덱스
 * @param range					범위
 * @param dmg					폭발 피해량
 * @param classname
 * @param dmgType
 * @param team					데미지를 면할 팀 값, -1일 경우 클라이언트를 제외하고 모두 데미지를 받습니다.
 * @return			포인트 허트를 만들었다면 true아니면 false를 반환합니다.
 * @error			Invalid "point_hurt" entity name.
 */
stock bool loringlib_MakeRangeDamage ( int client, float range = 50.0, int dmg, const char[] classname, int dmgType = DMG_SLASH, int team = -1 ) {
	bool bResult = false;
	
	float flPosition[3];
	GetClientEyePosition ( client, flPosition );
	
	float flTargetPosition[3];
	for ( int target = 1; target <= MaxClients; target ++ ) {
		if ( loringlib_IsValidClient__PlayGame ( target ) ) {
			if ( target == client )
				continue;
			
			if ( team != -1 ? GetClientTeam ( target ) == team : false )
				continue;
			
			GetClientEyePosition ( target, flTargetPosition );
			if ( GetVectorDistance ( flPosition, flTargetPosition ) <= range )
				bResult = loringlib_MakeDamage ( client, target, dmg, classname, dmgType );
		}
	}
	
	return bResult;
}

/**
 * point_hurt를 이용한 불데미지 만들기
 *
 * @param victim				Victim index.
 * @param attacker				Attacker index.
 * @param dmg					Damage scale.
 * @param times					Fire time.
 * @param delay					Damage delay.
 * @error				point_hurt entity invalid.
 */
stock int loringlib_IgniteEntityEx ( int victim, int attacker, int dmg, float times = 1.0, float delay = 1.0, char[] classname ) {
	int entfire = CreateEntityByName ( "point_hurt" );
	
	if ( entfire != -1 ) {
		if ( victim != -1 ) {
			char tarname[32];
			Format ( tarname, sizeof ( tarname ), "%d", EntIndexToEntRef ( victim ) );
			
			DispatchKeyValue ( victim, "TargetName", tarname );
			DispatchKeyValue ( entfire, "DamageTarget", tarname );
		}
		float entfire_DispatchPosition[3];
		GetClientAbsOrigin ( victim, entfire_DispatchPosition );
		
		DispatchKeyValueVector ( entfire, "Origin", entfire_DispatchPosition );
		
		int dmgType = DMG_BURN;
		
		char strnum[16];
		IntToString ( dmg, strnum, sizeof ( strnum ) );
		DispatchKeyValue ( entfire, "Damage", strnum );
		
		IntToString ( dmgType, strnum, sizeof ( strnum ) );
		DispatchKeyValue ( entfire, "DamageType", strnum );
		
		DispatchKeyValueFloat ( entfire, "DamageRadius", 1.0 );
		if ( delay > 0.0 )
			DispatchKeyValueFloat ( entfire, "DamageDelay", delay );	//	delay
		
		DispatchKeyValue ( entfire, "classname", classname );
		
		AcceptEntityInput ( entfire, "TurnOn", attacker != -1 ? attacker : 0 );
		loringlib_ThisKill ( entfire, times );
		
		return entfire;
	}
	
	return -1;
}

/**
 * point_hurt를 이용한 데미지 만들기
 * @note 데미지 관련 이벤트 및 sdkhook에서 사용할 시 무한적으로 반복될 수 있습니다.
 *
 * @param attacker				Attacker index.
 * @param victim				Victim index.
 * @param dmg					Damage value.
 * @param dmgType				Damage type.
 * @param dmgRadius				데미지 거리.
 * @param delay					데미지 딜레이.
 * @param dmgDuration			.0으로 설정 시 한번만 데미지를 입힙니다. 그 이상으로 설정 시 그만큼의 주어진 시간(초) 만큼 데미지를 입힙니다.
 * @param attackerpos			Attacker position.
 * @param index					Damage classname.
 * @param customdmg				1: 엔티티에게 데미지를 주지않음, 0: 모두에게 데미지를 줌.
 * @param remover				1: point_hurt를 그대로 둠, 0: point_hurt를 자동으로 삭제함.
 * @return point_hurt엔티티
 */ 
stock int loringlib_CreateCustomDamage (
 int attacker,
 int victim,
 int dmg,
 int dmgType,
 float dmgRadius,
 float dmgDelay,
 float dmgDuration,
 const float attackpos[3],
 const char[] index,
 bool customdmg = false,
 bool remover = true ) {

	int ent = CreateEntityByName ( "point_hurt" );
	
	if ( ent != -1 ) {
		if ( victim != -1 ) {
			char tarname[32];
			Format ( tarname, sizeof ( tarname ), "%f%f", GetEngineTime (), GetRandomFloat () );
			
			DispatchKeyValue ( victim, "TargetName", tarname );
			DispatchKeyValue ( ent, "DamageTarget", tarname );
		}
		
		DispatchKeyValueVector ( ent, "Origin", attackpos );
		
		char num[32];
		IntToString ( dmg, num, sizeof ( num ) );
		DispatchKeyValue ( ent, "Damage", num );
		
		IntToString ( dmgType, num, sizeof ( num ) );
		DispatchKeyValue ( ent, "DamageType", num );
		
		/*	데미지 범위	*/
		DispatchKeyValueFloat ( ent, "DamageRadius", dmgRadius );
		DispatchKeyValueFloat ( ent, "DamageDelay", dmgDelay );
		
		if ( !StrEqual ( index, "", false ) )
			DispatchKeyValue ( ent, "classname", index );
			
		DispatchSpawn ( ent );
		
		if ( !customdmg ) {
			if ( dmgDuration == 0.0 ) 
				AcceptEntityInput ( ent, "Hurt", attacker != -1 ? attacker : 0 );
			else
				AcceptEntityInput ( ent, "TurnOn", attacker != -1 ? attacker : 0 );
		}
	
		if ( remover ) {
			if ( !customdmg ) {
				if ( dmgDuration == 0.0 )
					AcceptEntityInput ( ent, "Kill" );
					
				else if ( dmgDuration > 0.0 ) {
					char output[256];
					Format ( output, sizeof ( output ), "OnUser1 !self:kill:justkill:%.1f:1", dmgDuration );
					
					SetVariantString ( output );
					
					AcceptEntityInput ( ent, "AddOutput" );
					AcceptEntityInput ( ent, "FireUser1" );
				}
			}
		}
		else {
			if ( !customdmg ) {
				if ( dmgDuration > 0.0 ) {
					char output[256];
					Format ( output, sizeof ( output ), "OnUser1 !self:TurnOff:justTurnOff:%.1:1", dmgDuration );
					
					SetVariantString ( output );
					
					AcceptEntityInput ( ent, "AddOutput" );
					AcceptEntityInput ( ent, "FireUser1" );
				}
			}
		}
		return ent;
	}
	else
		return -1;
}

/**
 * 샷건 전체 데미지 구하기
 * @note SDKHook_TraceAttack* 및 SDKHook_OnTakeDamage* 에서만 구할 수 있습니다.
 *
 * @param victim				Victim index.
 * @param attacker				Attacker index.
 * @param dmg					Hook damages
 * @return		샷건이면 샷건데미지, 아니라면 일반 데미지를 반환합니다.
 */
stock float loringlib_CSGOGetShotgunTotalDamages ( int victim, int attacker, float dmgs ) {
	float totaldamage;
	char weaponidx[32];
	GetClientWeapon ( victim, weaponidx, sizeof ( weaponidx ) );
	
	if ( StrEqual ( weaponidx, "weapon_nova", false ) ||
		StrEqual ( weaponidx, "weapon_xm1014", false ) ||
		StrEqual ( weaponidx, "weapon_sawedoff", false ) ||
		StrEqual ( weaponidx, "weapon_mag7", false ) ) {
		totaldamage += dmgs;
		
		return	totaldamage;
	}
	else
		return dmgs;
}

/**
 * 특정 클래스 이름을 가진 엔티티를 모두 삭제합니다.
 *
 * @param classname				클래스 이름
 * @return				엔티티를 삭제했을 경우 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_RemoveEntityByName ( char[] classname ) {
	static char temp[64];
	bool result = false;
	for ( int i = GetMaxEntities (); i <= GetMaxEntities (); i ++ ) {
		if ( IsValidEdict ( i ) ) {
			GetEdictClassname ( i, temp, sizeof ( temp ) );
			if ( StrEqual ( temp, classname, false ) ) {
				RemoveEdict ( i );
				result = true;
			}
		}
	}
	
	return result;
}

/**
 * 모든 무기를 삭제합니다.
 *
 * @param client				Client index.
 * @noreturn
 */
stock void loringlib_KillWeaponSlot ( int client ) {
	if ( GetPlayerWeaponSlot ( client, CS_SLOT_PRIMARY ) != -1 )
		RemovePlayerItem ( client, GetPlayerWeaponSlot ( client, CS_SLOT_PRIMARY ) );
		
	if ( GetPlayerWeaponSlot ( client, CS_SLOT_SECONDARY ) != -1 )
		RemovePlayerItem ( client, GetPlayerWeaponSlot ( client, CS_SLOT_SECONDARY ) );
			
	if ( GetPlayerWeaponSlot ( client, CS_SLOT_KNIFE ) != -1 )
		RemovePlayerItem ( client, GetPlayerWeaponSlot ( client, CS_SLOT_KNIFE ) );
	
	/* broken */
	for ( int i = 0; i < 7; i ++ )
		if ( GetPlayerWeaponSlot ( client, CS_SLOT_GRENADE ) != -1 )
			RemovePlayerItem ( client, GetPlayerWeaponSlot ( client, CS_SLOT_GRENADE ) );
			
	if ( GetPlayerWeaponSlot ( client, CS_SLOT_C4 ) != -1 )
		RemovePlayerItem ( client, GetPlayerWeaponSlot ( client, CS_SLOT_C4 ) );
}

/**
 * 해당 슬롯의 무기를 제거합니다.
 *
 * @param client				Client index.
 * @param weaponSlot			Slot index (mod specific).
 * @noreturn
 */
stock void loringlib_RemoveWeaponSlot ( int client, int weaponSlot ) {
	if ( GetPlayerWeaponSlot ( client, weaponSlot ) != -1 )
		RemovePlayerItem ( client, GetPlayerWeaponSlot ( client, weaponSlot ) );
}

/**
 * 타이머를 없앱니다.
 *
 * @param handler				타이머 핸들러
 * @error		타이머는 이미 null값을 가짐.
 */
stock void loringlib_KillTimer ( Handle handler ) {
	if ( handler != null )
		KillTimer ( handler );
	handler = null;
}

/**
 * Death notice를 표시합니다.
 *
 * @param target				타겟 인덱스
 * @param attacker				어텍커 인덱스
 * @param weapon				무기 이름
 * @param headshot				헤드샷 여부
 * @param add_action			킬 수, 사망 수 채크
 * @return		표시했다면 true, 아니면 false를 반환합니다.
 * @error				player_death이벤트가 존제하지 않음.
 */
stock bool loringlib_CreateFakeCallDeathEvent ( int target, int attacker, char[] weapon = "trigger", bool headshot = false, bool add_action = false ) {
	Event __handler = CreateEvent ( "player_death" );
	
	if ( __handler == null )
		return false;
	
	__handler.SetInt ( "userid", GetClientUserId ( target ) );
	__handler.SetInt ( "attacker", GetClientUserId ( attacker ) );
	__handler.SetString ( "weapon", weapon );
	__handler.SetBool ( "headshot", headshot );
	
	__handler.Fire ();
	
	if ( add_action ) {
		loringlib_AddCSDeathPoints ( target, 1 );
		loringlib_AddCSKillPoints ( attacker, 1 );
		if ( GetEngineVersion () == Engine_CSGO )
			loringlib_AddCSGOScorePoints ( attacker, 2 );
	}
	
	return true;
}

/**
 * 클래스 이름을 정의합니다.
 *
 * @param ent				엔티티
 * @param classname			정의할 클래스 이름
 */
stock void loringlib_SetEntClassname ( int ent, const char[] classname ) {
	DispatchKeyValue ( ent, "classname", classname );
}

/**
 * 엔티티의 이동속도를 설정합니다.
 *
 * @param ent				엔티티
 * @param value				이동속도 값 (Default 1.0)
 */
stock void loringlib_SetEntityLaggedmovement ( int ent, float value ) {
	int	laggedMovementOffs = FindSendPropInfo ( "CBasePlayer", "m_flLaggedMovementValue" );
	SetEntDataFloat ( ent, laggedMovementOffs, value );
}

/**
 * 엔티티의 중력을 설정합니다.
 *
 * @param ent				엔티티
 * @param value				중력 값 (Default 1.0)
 */
stock void loringlib_SetEntityGravity ( int ent, float value ) {
	SetEntPropFloat ( ent, Prop_Data, "m_flGravity", value );
}

/**
 * 엔티티의 최고 속도 값을 설정합니다.
 *
 * @param ent					엔티티
 * @param maxSpeed				최고 속도
 */
stock void loringlib_SetEntityMaxSpeed ( int ent, float maxSpeed = 250.0 ) {
	SetEntPropFloat ( ent, Prop_Send, "m_flMaxspeed", maxSpeed );
}

/**
 * 엔티티의 베이스 벨록시티를 설정합니다.
 *
 * @param ent				엔티티
 * @param vel				Base Velocity
 */
stock void loringlib_SetEntityBaseVelocity ( int ent, const float vel[3] ) {
	SetEntPropVector ( ent, Prop_Send, "m_vecBaseVelocity", vel );
}

/**
 * 엔티티의 벨록시티 값을 설정합니다.
 *
 * @param ent				엔티티
 * @param vel				Velocity Vector
 */
stock void loringlib_SetEntityVelocity ( int ent, const float vel[3] ) {
	SetEntPropFloat ( ent, Prop_Send, "m_vecVelocity[0]", vel[0] );
	SetEntPropFloat ( ent, Prop_Send, "m_vecVelocity[1]", vel[1] );
	SetEntPropFloat ( ent, Prop_Send, "m_vecVelocity[2]", vel[2] );
}

/**
 * 엔티티의 체력을 설정합니다.
 *
 * @param ent				엔티티
 * @param value				체력
 */
stock void loringlib_SetEntityHealth ( int ent, int value ) {
	SetEntProp ( ent, Prop_Send, "m_iHealth", value );
}

/**
 * 엔티티의 최대 체력을 설정합니다.
 *
 * @param ent				엔티티
 * @param value				최대 체력
 */
stock void loringlib_SetEntityMaxHealth ( int ent, int value ) {
	SetEntProp ( ent, Prop_Data, "m_iMaxHealth", value );
}

/**
 * 엔티티의 아머를 설정합니다.
 *
 * @param ent				엔티티
 * @param value				아머
 */
stock void loringlib_SetEntityArmor ( int ent, int value ) {
	SetEntProp ( ent, Prop_Data, "m_ArmorValue", value );
}

/**
 * 엔티티의 달러 값을 설정합니다.
 *
 * @param ent				엔티티
 * @param value				달러
 */
stock void loringlib_SetEntityAccount ( int ent, int value ) {
	SetEntProp ( ent, Prop_Send, "m_iAccount", value );
}

/**
 * Set entity minimum size.
 *
 * @param ent
 * @param value
 */
stock void loringlib_SetEntVectorMins ( int ent, const float value[3] ) {
	SetEntPropVector ( ent, Prop_Send, "m_vecMins", value );
}

/**
 * Set entity maximum size.
 *
 * @param ent
 * @param value
 */
stock void loringlib_SetEntVectorMaxs ( int ent, const float value[3] ) {
	SetEntPropVector ( ent, Prop_Send, "m_vecMaxs", value );
}

/**
 * Get entity minimum mins.
 *
 * @param ent
 * @param value
 */
stock void loringlib_GetEntVectorMins ( int ent, float value[3] ) {
	GetEntPropVector ( ent, Prop_Send, "m_vecMins", value );
}

/**
 * Get entity maximum maxs.
 *
 * @param ent
 * @param value
 */
stock void loringlib_GetEntVectorMaxs ( int ent, float value[3] ) {
	GetEntPropVector ( ent, Prop_Send, "m_vecMaxs", value );
}


/**
 * 엔티티의 팀 값을 설정합니다.
 * @note teamnum:: 1 관전, 2 테러리스트, 3 대테러부대 	
 *
 * @param ent
 * @param teamnum
 */
stock void loringlib_SetEntityTeamNumber ( int ent, int teamnum ) {
	SetEntProp ( ent, Prop_Send, "m_iTeamNum", teamnum );
}

/**
 * 엔티티의 팀 값을 구합니다..
 *
 * @param ent
 * @return teamnumber
 */
stock int loringlib_GetEntityTeamNumber ( int ent ) {
	return GetEntProp ( ent, Prop_Send, "m_iTeamNum" );
}

/**
 * 손 모델을 설정합니다.
 * @note CS:GO와 L4D2만 지원합니다.
 *
 * @param ent
 * @param armspath
 * @return Number of non-null bytes written.
 */
stock int loringlib_SetEntityArmsModel ( int ent, const char[] armspath ) {
	return	SetEntPropString ( ent, Prop_Send, "m_szArmsModel", armspath );
}

/**
 * 헬멧을 설정합니다.
 *
 * @param client
 * @param value
 */
stock void loringlib_SetEntityHelmet ( int client, int value ) {
	SetEntProp ( client, Prop_Send, "m_bHasHelmet", value );
}

/**
 * 헬멧을 구합니다.
 *
 * @param client
 * @return 헬멧이 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasEntityHelmet ( int client ) {
	int helmet = GetEntProp ( client, Prop_Send, "m_bHasHelmet" );
	if ( helmet > 0 )
		return true;
	return false;
}

/**
 * 이동속도 (LaggedMovement)를 구합니다.
 *
 * @param ent
 */
stock float loringlib_GetEntityLaggedmovement ( int ent ) {
	int	laggedMovementOffs = FindSendPropInfo ( "CBasePlayer", "m_flLaggedMovementValue" );
	return GetEntDataFloat ( ent, laggedMovementOffs );
}

/**
 * Active Weapon을 구합니다.
 *
 * @param client
 * @return m_hActiveWeapon
 */
stock int loringlib_GetActiveWeapon ( int client ) {
	return GetEntPropEnt ( client, Prop_Data, "m_hActiveWeapon" );
}

/**
 * clip1을 설정합니다.
 *
 * @param client
 * @param value
 */
stock void loringlib_SetClip1 ( int index, int value ) {
	SetEntProp ( index, Prop_Data, "m_iClip1", value );
}

/**
 * clip1을 설정합니다..
 *
 * @param client
 * @param value
 */
stock void loringlib_SetClip2 ( int index, int value ) {
	SetEntProp ( index, Prop_Data, "m_iClip2", value );
}

/**
 * Ammo 값을 구합니다.
 *
 * @param client			클라이언트
 * @return m_iAmmo
 */
stock int loringlib_GetWeaponAmmo ( int client ) {
	int weapon = GetEntPropEnt ( client, Prop_Data, "m_hActiveWeapon" );
	if ( weapon < 1 )	return -1;
	int ammotype = GetEntProp ( weapon, Prop_Send, "m_iPrimaryAmmoType" );
	if ( ammotype == -1 )	return -1;
	return GetEntProp ( client, Prop_Send, "m_iAmmo", _, ammotype );
}

/**
 * 무기의 Ammo 값을 구합니다.
 *
 * @param client		클라이언트
 * @param weapon		무기
 * @return m_iAmmo
 */
stock int loringlib_GetWeaponAmmo2 ( int client, int weapon ) {
	int ammotype = GetEntProp ( weapon, Prop_Send, "m_iPrimaryAmmoType" );
	if ( ammotype == -1 )	return -1;
	return GetEntProp ( client, Prop_Send, "m_iAmmo", _, ammotype );
}

/**
 * Ammo 값을 설정합니다.
 *
 * @param client			클라이언트
 * @param amount			설정 값
 */
stock void loringlib_SetWeaponAmmo ( int client, int amount ) {
	int weapon = GetEntPropEnt ( client, Prop_Data, "m_hActiveWeapon" );
	if ( weapon < 1 )	return;
	int ammotype = GetEntProp ( weapon, Prop_Send, "m_iPrimaryAmmoType" );
	if ( ammotype == -1 )	return;
	SetEntProp ( client, Prop_Send, "m_iAmmo", amount, _, ammotype );
}

/**
 * Set ammo player weapon.
 *
 * @param client
 * @param index
 * @param primaryAmmo
 * @param secondaryAmmo
 */
stock void loringlib_SetPlayerWeaponAmmoEx ( int client, int index, int primaryAmmo = -1, int secondaryAmmo = -1 ) {
	int offsAmmo = FindDataMapInfo ( client, "m_iAmmo" );
	
	if ( primaryAmmo != -1 ) {
		int offs = offsAmmo + ( loringlib_GetPrimaryAmmoType ( index ) * 4 );
		SetEntData ( client, offs, primaryAmmo, 4, true );
	}
	
	if ( secondaryAmmo != -1 ) {
		int offs = offsAmmo + ( loringlib_GetSecondaryAmmoType ( index ) * 4 );
		SetEntData ( client, offs, secondaryAmmo, 4, true );
	}
}

stock void loringlib_GetPlayerWeaponAmmoEx ( int client, int index, int& primaryAmmo = -1, int& secondaryAmmo = -1 ) {
	int offsAmmo = FindDataMapInfo ( client, "m_iAmmo" );
	
	int offs;
	if ( primaryAmmo != -1 ) {
		offs = offsAmmo + ( loringlib_GetPrimaryAmmoType ( index ) * 4 );
		primaryAmmo = GetEntData ( client, offs, 4 );
	}
	
	if ( secondaryAmmo != -1 ) {
		offs = offsAmmo + ( loringlib_GetSecondaryAmmoType ( index ) * 4 );
		secondaryAmmo = GetEntData ( client, offs, 4 );
	}
}

/**
 * 클라이언트의 무기 총알 인덱스를 설정합니다.
 *
 * @param client
 * @param index
 * @param primaryAmmo
 * @param secondaryAmmo
 * @param primaryClip
 * @param secondaryClip
 * @return 설정을 했다면 true를 반환합니다.
 */
stock bool loringlib_SetWeaponAmmoIndex ( int client, int index, int primaryAmmo = -1, int secondaryAmmo = -1, int primaryClip = -1, int secondaryClip = -1 ) {
	if ( index == -1 )
		return false;
		
	if ( primaryClip != -1 )
		loringlib_SetClip1 ( index, primaryClip );
		
	if ( secondaryClip != -1 )
		loringlib_SetClip2 ( index, secondaryClip );
		
	loringlib_SetPlayerWeaponAmmoEx ( client, index, primaryAmmo, secondaryAmmo );
	
	return true;
}

/**
 * 엔티티의 색상을 설정합니다.
 *
 * @param entity
 * @param r				Red
 * @param g				Green
 * @param b				Blue
 * @param a				Alpha
 */
stock void loringlib_SetEntityRenderColor ( int entity, int r, int g, int b, int a ) {
	SetEntityRenderMode ( entity, RENDER_TRANSCOLOR );
	SetEntityRenderColor ( entity, r, g, b, a );
}

/**
 * 엔티티의 색상을 설정합니다.
 *
 * @param entity
 * @param rgba			색상 값
 */
stock void loringlib_SetEntityRenderColorEx ( int entity, const int rgba[4] ) {
	SetEntityRenderMode ( entity, RENDER_TRANSCOLOR );
	SetEntityRenderColor ( entity, rgba[0], rgba[1], rgba[2], rgba[3] );
}

/**
 * 엔티티의 무적 여부를 설정합니다.
 *
 * @param entity
 * @param god			무적 여부
 */
stock void loringlib_SetEntityTakedamage ( int entity, bool god = true ) {
	if ( god )
		SetEntProp ( entity, Prop_Data, "m_takedamage", DAMAGE_NO, 1 );
		
	else
		SetEntProp ( entity, Prop_Data, "m_takedamage", DAMAGE_YES, 1 );
}

/**
 * 엔티티의 m_takedamage를 설정합니다.
 *
 * @param entity
 * @param value		값
 */
stock void loringlib_SetEntityTakedamageEx ( int entity, int value = DAMAGE_YES ) {
	SetEntProp ( entity, Prop_Data, "m_takedamage", value, 1 );
}

/**
 * 엔티티의 m_takedamage 값을 반환합니다.
 *
 * @param entity
 * @return	m_takedamage
 */
stock int loringlib_GetEntityTakedamage ( int entity ) {
	return GetEntProp ( entity, Prop_Data, "m_takedamage" );
}

/**
 * 엔티티의 모델 경로를 구합니다.
 *
 * @param entity
 * @param modelname
 * @param maxlen
 */
stock void loringlib_GetEntityModel ( int entity, char[] modelname, int maxlen ) {
	GetEntPropString ( entity, Prop_Data, "m_ModelName", modelname, maxlen );
}

/**
 * 엔티티의 속도(Velocity)를 구합니다.
 *
 * @param entity				엔티티 인덱스.
 * @return		Unit/Seconds
 */
stock float loringlib_GetEntitySpeed ( int entity ) {
	float vel[3];
	GetEntPropVector ( entity, Prop_Data, "m_vecVelocity", vel );
	
	return SquareRoot ( vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2] );
}

/**
 * 엔티티의 수평 속도(Velocity)를 구합니다.
 *
 * @param entity				엔티티 인덱스.
 * @return		Horizontal Speed
 */
stock float loringlib_GetEntityHorizontalSpeed ( int entity ) {
	float vel[3];
	GetEntPropVector ( entity, Prop_Data, "m_vecVelocity", vel );
	
	return SquareRoot ( vel[0] * vel[0] + vel[1] * vel[1] );
}


/**
 * 엔티티의 수직 속도(Velocity)를 구합니다.
 *
 * @param entity				엔티티 인덱스.
 * @return		Vertical Speed
 */
stock float loringlib_GetEntityVerticalSpeed ( int entity ) {
	float vel[3];
	GetEntPropVector ( entity, Prop_Data, "m_vecVelocity", vel );
	
	return SquareRoot ( vel[2] * vel[2] );
}

/**
 * 엔티티의 속력을 구합니다.
 *
 * @param ent
 * @return 속력
 */
stock float loringlib_GetEntityVelocity ( int ent ) {
	float	vel[3];
	GetEntPropVector ( ent, Prop_Data, "m_vecVelocity", vel );
	
	return	GetVectorLegnth ( vel );
}

/**
 * CS:GO에서 진짜 AbsOrigin 값을 구합니다.
 * 
 * @param client			클라이언트
 * @param origin			오리진 값
 */
stock void loringlib_GetClientOriginEx ( int client, float origin[3] ) {
	if ( GetEngineVersion () == Engine_CSGO ) {
		GetClientAbsOrigin ( client, origin );
		if ( GetEntityFlags ( client ) & FL_DUCKING )
			origin[2] -= 32.0;
		else
			origin[2] -= 64.0;
	}
	else
		GetClientAbsOrigin ( client, origin );
}

/**
 * 엔티티의 위치를 구합니다.
 *
 * @param ent
 * @param origin
 */
stock void loringlib_GetEntityOriginEx ( int ent, float origin[3] ) {
	GetEntPropVector ( ent, Prop_Send, "m_vecOrigin", origin );
}

/**
 * 엔티티의 바라보는 앵글을 구합니다.
 *
 * @param ent
 * @param angles
 */
stock void loringlib_GetEntityAngle ( int ent, float angles[3] ) {
	GetEntPropVector ( ent, Prop_Data, "m_angRotation", angles );
}

/**
 * 클라이언트의 무기의 인덱스 값을 구합니다.
 *
 * @param client
 * @param classname
 */
stock int loringlib_GetWeapon ( int client, const char[] classname ) {
	int offs = loringlib_GetWeaponOffset ( client ) - 4;
	int index = INVALID_ENT_REFERENCE;
	
	for ( int i = 0; i < CSGO_MAX_WEAPONS; i ++ ) {
		offs += 4;
		index = GetEntDataEnt2 ( client, offs );
		
		if ( !loringlib_IsValidWeapon ( index ) )
			continue;
			
		if ( loringlib_IsClassnameMatches ( index, classname ) )
			return index;
	}
	
	return INVALID_ENT_REFERENCE;
}

/**
 * clip1을 구합니다.
 *
 * @param index				Weapon index
 * @return m_iClip1
 */
stock int loringlib_GetClip1 ( int index ) {
	return GetEntProp ( index, Prop_Send, "m_iClip1" );
}

/**
 * clip2를 구합니다.
 *
 * @param index				Weapon index
 * @return m_iClip2
 */
stock int loringlib_GetClip2 ( int index ) {
	return GetEntProp ( index, Prop_Send, "m_iClip2" );
}

/**
 * 주무기 총알 타입을 구합니다.
 *
 * @param index				Weapon index
 * @return 주무기 총알 타입
 */
stock int loringlib_GetPrimaryAmmoType ( int index ) {
	return GetEntProp ( index, Prop_Data, "m_iPrimaryAmmoType" );
}

/**
 * 보조무기 총알 타입을 구합니다.
 *
 * @param index				Weapon index
 * @return 보조무기 총알 타입
 */
stock int loringlib_GetSecondaryAmmoType ( int index ) {
	return GetEntProp ( index, Prop_Data, "m_iSecondaryAmmoType" );
}

/**
 * Get primary ammo
 *
 * @param client
 * @param index
 * @return primary ammo
 */
stock int loringlib_GetPrimaryAmmo ( int client, int index ) {
	int ammoType = loringlib_GetPrimaryAmmoType ( index );

	if ( ammoType == -1 )
		return -1;
		
	return GetEntProp ( client, Prop_Send, "m_iAmmo", _, ammoType );
}

/**
 * Get secondary ammo
 *
 * @param client
 * @param index
 * @return secondary ammo
 */
stock int loringlib_GetSecondaryAmmo ( int client, int index ) {
	int ammoType = loringlib_GetSecondaryAmmoType ( index );

	if ( ammoType == -1 )
		return -1;
		
	return GetEntProp ( client, Prop_Send, "m_iAmmo", _, ammoType );
}

/**
 * Set primary ammo
 *
 * @param client
 * @param index				무기 인덱스 값
 * @param amount			설정할 총알 값
 */
stock void loringlib_SetPrimaryAmmo ( int client, int index, int amount ) {
	int ammoType = loringlib_GetPrimaryAmmoType ( index );

	if ( ammoType == -1 )
		return;
		
	SetEntProp ( client, Prop_Send, "m_iAmmo", amount, _, ammoType );
}

/**
 * 클라이언트의 무기 오프셋 값을 구합니다.
 *
 * @param client
 * @return 무기 오프셋
 */
stock int loringlib_GetWeaponOffset ( int client ) {
	int offs = -1;
	
	if ( offs == -1 )
		offs = FindDataMapInfo ( client, "m_hMyWeapons" );
		
	return offs;
}

/**
 * 엔티티의 이름을 구합니다.
 *
 * @param ent
 * @param buffer
 * @param maxlen
 */
stock void loringlib_GetEntName ( int ent, char[] buffer, int maxlen ) {
	GetEntPropString ( ent, Prop_Data, "m_iName", buffer, maxlen );
}

/**
 * 엔티티의 부모를 구합니다.
 *
 * @param ent
 * @param buffer
 * @param maxlen
 */
stock loringlib_GetEntParent ( int ent, char[] buffer, int maxlen ) {
	GetEntPropString ( ent, Prop_Data, "m_iParent", buffer, maxlen );
}

/**
 * 엔티티의 해머아이디를 구합니다.
 *
 * @param ent
 */
stock loringlib_GetEntHammerID ( int ent ) {
	return GetEntProp ( ent, Prop_Data, "m_iHammerID" );
}

/**
 * Gets the Classname of an entity.
 * This is like GetEdictClassname(), except it works for ALL
 * entities, not just edicts.
 *
 * @param entity			Entity index.
 * @param buffer			Return/Output buffer.
 * @param size				Max size of buffer.
 * @return					Number of non-null bytes written.
 */
stock int loringlib_GetClassname ( int entity, char[] buffer, int size) {
	return GetEntPropString ( entity, Prop_Data, "m_iClassname", buffer, size );
}

/**
 * 엔티티가 클래스 이름과 일치하는지 채크합니다.
 *
 * @param entity
 * @param classname
 * @param partialMatch		대소문자 구분
 * @return 일치하면 true를 반환합니다.
 */
stock bool loringlib_IsClassnameMatches ( int entity, const char[] classname, bool partialMatch = false ) {
	char classname_[64];
	GetEdictClassname ( entity, classname_, sizeof ( classname_ ) );
	
	if ( partialMatch )
		return ( StrContains ( classname_, classname ) != -1 );
		
	return StrEqual ( classname_, classname );
}

/**
 * 클라이언트가 관리자인지 확인합니다.
 *
 * @param client				Client index.
 * @return			클라이언트가 관리자이면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsClientAdmin ( int client ) {
	AdminId id = GetUserAdmin ( client );
	
	if ( id != INVALID_ADMIN_ID )	return true;
	else	return false;
}

/**
 * 무기가 장전중인지 여부를 구합니다.
 *
 * @param weapon
 * @return 장전중일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponReloading ( int weapon ) {
	return loringlib_IntToBoolean ( GetEntProp ( weapon, Prop_Data, "m_bInReload" ) );
}

/**
 * 무기가 유효한지 채크합니다.
 *
 * @param weapon
 * @return 유효할 경우 true를 반환합니다.
 */
stock int loringlib_IsValidWeapon ( int index ) {
	if ( !IsValidEdict ( index ) )
		return false;
		
	return loringlib_IsClassnameMatches ( index, "weapon_", true );
}

/**
 * Gets the classname and entity index of the current/active weapon of a client.
 *
 * @param client		Client Index.
 * @param buffer		String Buffer to store the weapon's classname.
 * @param size			Max size of String: buffer.
 * @return				Weapon Entity Index on success or INVALID_ENT_REFERENCE otherwise
 */
stock int loringlib_GetActiveWeaponName ( int client, char[] buffer, int size) {
	int weapon = loringlib_GetActiveWeapon ( client );

	if ( weapon == INVALID_ENT_REFERENCE ) {
		buffer[0] = '\0';
		return INVALID_ENT_REFERENCE;
	}

	loringlib_GetClassname ( weapon, buffer, size );

	return weapon;
}

/**
 * Input 'FireUser1'을 이용하여 엔티티 제거.
 *
 * @param ent					Entity index.
 * @param value					Remove time.
 * @return Input FireUser1.
 */
stock bool loringlib_ThisKill ( int ent, float value = 0.0 ) {
	char	buff[64];
	Format ( buff, sizeof ( buff ), "OnUser1 !self:kill::%f:1", value );
	SetVariantString ( buff );

	AcceptEntityInput ( ent, "AddOutput" );
	
	return		AcceptEntityInput ( ent, "FireUser1" );
}

/**
 * Input 'kill'을 이용하여 엔티티 제거.
 * @note 클라이언트 제거를 방지합니다.
 *
 * @param entity				Entity index.
 * @param value					Remove time.
 * @noreturn
 * @error			클라이언트는 삭제할 수 없음.
 */
stock void loringlib_RemoveEntity ( int entity, float value = 0.0 ) {
	if ( value == 0.0 ) {
		if ( IsValidEntity ( entity ) ) {
			char classname[32];
			GetEdictClassname ( entity, classname, sizeof ( classname ) );
			
			if ( !StrEqual ( classname, "player" ) )
				AcceptEntityInput ( entity, "Kill" );
		}
	}
	else if ( value > 0.0 )
		CreateTimer ( value, timer_RemoveEntity, EntIndexToEntRef ( entity ), TIMER_FLAG_NO_MAPCHANGE );
}

public Action timer_RemoveEntity ( Handle timer, int entityRef ) {
	int ent = EntRefToEntIndex ( entityRef );
	if ( ent != INVALID_ENT_REFERENCE )
		loringlib_RemoveEntity ( ent );
	
	return Plugin_Stop;
}

/**
 * entity의 Account를 구합니다.
 *
 * @param ent			Entity index.
 * @return		Entity account values.
 */
stock int loringlib_GetEntityAccount ( int ent ) {
	return GetEntProp ( ent, Prop_Send, "m_iAccount" );
}

/**
 * entity의 Account를 구합니다.
 *
 * @param ent			Entity index.
 * @return		Entity health values.
 */
stock int loringlib_GetEntityHealth ( int ent ) {
	return GetEntProp ( ent, Prop_Data, "m_iHealth" );
}

/**
 * entity의 MaxHealth를 구합니다.
 *
 * @param ent			Entity index.
 * @return		Entity Maxhealth values.
 */
stock int loringlib_GetEntityMaxHealth ( int ent ) {
	return GetEntProp ( ent, Prop_Data, "m_iMaxHealth" );
}

/**
 * entity의 벨록시티 값을 구합니다.
 *
 * @param ent				엔티티 인덱스
 * @return			velocity 값 return.
 * @error		entity또는 BaseVelocity Offset이 유효하지 않음
 */
stock float loringlib_GetEntityBaseVelocity ( int ent ) {
	static float vel[3];
	return GetEntPropVector ( ent, Prop_Send, "m_vecBaseVelocity", vel );
}

/**
 * entity의 fov 값을 설정합니다.
 * 
 * @param	entity			엔티티 인덱스
 * @param	fov				설정할 fov 값
 * @return noreturn
 */
stock void loringlib_SetEntityFov ( int ent, int fov ) {
	SetEntProp ( ent, Prop_Send, "m_iFOV", fov );
}

/**
 * entity의 기본 fov 값을 설정합니다.
 *
 * @param	entity			엔티티 인덱스
 * @param	fov				설정할 fov 값
 * @noreturn
 */
stock void loringlib_SetEntityDefaultFov ( int ent, int fov ) {
	SetEntProp ( ent, Prop_Send, "m_iDefaultFOV", fov );
}

/**
 * entity의 기본 fov 값을 구합니다.
 *
 * @param	entity			엔티티 인덱스
 * @return	Entity Default FOV
 */
stock void loringlib_GetEntityDefaultFov ( int ent ) {
	return GetEntProp ( ent, Prop_Send, "m_iDefaultFOV" );
}

/**
 * entity의 moveparent을 구합니다.
 *
 * @param ent				엔티티 인덱스
 * @return				엔티티의 moveparent 값
 * @error			entity또는 moveparent Offset이 유효하지 않음.
 */
stock int loringlib_GetEntityParent ( int ent ) {
	return GetEntProp ( ent, Prop_Send, "moveparent" );
}

/**
 * entity의 Friction을 구합니다.
 *
 * @param ent				엔티티 인덱스
 * @return				엔티티의 Friction 값
 * @error			entity또는 Friction Offset이 유효하지 않음.
 */
stock float loringlib_GetEntityFriction ( int ent ) {
	return GetEntPropFloat ( ent, Prop_Send, "m_flFriction" );
}

/**
 * entity의 Maxspeed값을 구합니다.
 *
 * @param ent				엔티티 인덱스
 * @return				엔티티의 Maxspeed 값
 * @error			entity또는 Maxspeed Offset이 유효하지 않음.
 */
stock float loringlib_GetEntityMaxSpeed ( int ent ) {
	return GetEntPropFloat ( ent, Prop_Send, "m_flMaxspeed" );
}

/**
 * entity의 Armor값을 구합니다.
 *
 * @param ent				엔티티 인덱스
 * @return				엔티티의 ArmorValue 값
 * @error			entity또는 ArmorValue Offset이 유효하지 않음.
 */
stock int loringlib_GetEntityArmor ( int ent ) {
	return GetEntProp ( ent, Prop_Data, "m_ArmorValue" );
}

/**
 * entity의 주인을 구합니다.
 *
 * @param ent				엔티티 인덱스
 * @return				엔티티 주인 인덱스
 * @error			entity나 Offset또는 Owner가 유효하지 않음.
 */
stock int loringlib_GetEntityOwner ( int ent ) {
	return GetEntPropEnt ( ent, Prop_Send, "m_hOwner" ); 
}

/**
 * entity의 주인을 구합니다.
 *
 * @param ent				엔티티 인덱스
 * @return				엔티티 주인 인덱스
 * @error			entity나 Offset또는 Owner가 유효하지 않음.
 */
stock int loringlib_GetEntityOwner2 ( int ent ) {
	return GetEntPropEnt ( ent, Prop_Send, "m_hOwnerEntity" ); 
}

/**
 * entity의 주인을 설정합니다.
 *
 * @param ent				엔티티 인덱스
 * @param owner				엔티티 주인
 * @error			entity나 Offset또는 Owner가 유효하지 않음.
 */
stock void loringlib_SetEntityOwner ( int ent, int owner ) {
	SetEntPropEnt ( ent, Prop_Send, "m_hOwner", owner ); 
}

/**
 * entity의 주인을 설정합니다.
 *
 * @param ent				엔티티 인덱스
 * @param owner				엔티티 주인
 * @error			entity나 Offset또는 Owner가 유효하지 않음.
 */
stock void loringlib_SetEntityOwner2 ( int ent, int owner ) {
	SetEntPropEnt ( ent, Prop_Send, "m_hOwnerEntity", owner ); 
}

/**
 * entity의 던진 주인을 설정합니다.
 *
 * @param ent				던져진 엔티티 인덱스
 * @param throwner			엔티티 주인
 * @error			entity나 Offset또는 Throwner가 유효하지 않음.
 */
stock int loringlib_SetEntityThrowner ( int ent, int throwner ) {
	SetEntPropEnt ( ent, Prop_Send, "m_hThrower", throwner );
}

/**
 * entity를 던진 주인을 구합니다.
 *
 * @param ent				던져진 엔티티 인덱스
 * @return				던져진 주인 인덱스 값
 * @error			entity나 Offset또는 Throwner가 유효하지 않음.
 */
stock int loringlib_GetEntityThrowner ( int ent ) {
	return GetEntPropEnt ( ent, Prop_Send, "m_hThrower" );
}

/**
 * entity의 collision group을 설정합니다.
 *
 * @param ent			엔티티
 * @param toggle		true = unblocking, false = blocking
 * @return noreturn
 * @error	m_CollisionGroup Offset이 없으면 return합니다.
 */
stock void loringlib_SetEntityNoblock ( int ent, bool toggle = true ) {
	int cBaseEntityCollisionGroup = FindSendPropInfo ( "CBaseEntity", "m_CollisionGroup" );
	if ( cBaseEntityCollisionGroup == -1 )
		return;
		
	if ( toggle )	SetEntData ( ent, cBaseEntityCollisionGroup, 2, 4, true );
	else	SetEntData ( ent, cBaseEntityCollisionGroup, 5, 4, true );
}

enum waterLevel {
	WATER_LEVEL_NOT_IN_WATER = 0,
	WATER_LEVEL_FEET_IN_WATER,
	WATER_LEVEL_WAIST_IN_WATER,
	WATER_LEVEL_HEAD_IN_WATER
};

/**
 * 물 깊이를 구합니다.
 *
 * @param entity			엔티티 인덱스
 * @return				물 깊이 값
 */
stock waterLevel loringlib_GetEntityWaterLevel ( int entity ) {
	return view_as<waterLevel> ( GetEntProp ( entity, Prop_Send, "m_nWaterLevel" ) );
}

/**
 * 클라이언트가 사다리에 있는지 채크합니다.
 *
 * @param client			클라이언트 인덱스
 * @return				사다리에 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsClientOnLadder ( int client ) {
	if ( GetEntityMoveType ( client ) == MOVETYPE_LADDER )
		return true;
		
	else
		return false;
}

/**
 * client의 음성채팅을 차단해제 합니다.
 *
 * @param client				클라이언트 인덱스
 * @noreturn
 */
stock void loringlib_UnmutedClient ( int client ) {
	SetClientListeningFlags ( client, VOICE_NORMAL );
}

/**
 * client가 target의 음성채팅을 개인차단해제 합니다.
 *
 * @param client				클라이언트 인덱스
 * @param target				타겟 인덱스
 * @noreturn
 */
stock void loringlib_PrivateUnmute ( int client, int target ) {
	SetListenOverride ( client, target, Listen_Yes );
}

/**
 * client의 음성채팅을 차단 합니다.
 *
 * @param client				클라이언트 인덱스
 * @noreturn
 */
stock void loringlib_MutedClient ( int client ) {
	SetClientListeningFlags ( client, VOICE_MUTED );
}

/**
 * client가 target의 음성채팅을 개인차단 합니다.
 *
 * @param client				클라이언트 인덱스
 * @param target				타겟 인덱스
 * @noreturn
 */
stock void loringlib_PrivateMute ( int client, int target ) {
	SetListenOverride ( client, target, Listen_No );
}

/**
 * 해당 팀의 인원들을 모두 죽입니다.
 *
 * @param team				Team index.
 * @noreturn
 * @error				잘못된 팀 인덱스
 */
stock void loringlib_ForceSuicideTeam ( int team ) {
	if ( team > 3 || team < 1 ) {
		LogError ( "Invalid team index." );
		return;
	}

	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient__PlayGame ( i ) )
			if ( GetClientTeam ( i ) == team )
				ForcePlayerSuicide ( i );
}

/**
 * 살아있는 클라이언트를 모두 죽입니다.
 * @param lastClient				자살을 제외할 한명의 클라이언트 인덱스.
 * @noreturn
 * @error				Invalid lastClient index.
 */
stock void loringlib_ForceAllSuicide ( int lastClient = -1 ) {
	if ( lastClient == -1 ) {
		for ( int i = 1; i <= MaxClients; i ++ )
			if ( loringlib_IsValidClient__PlayGame ( i ) )
				ForcePlayerSuicide ( i );
	}
	
	else {
		for ( int i = 1; i <= MaxClients; i ++ )
			if ( loringlib_IsValidClient__PlayGame ( i ) )
				if ( lastClient != i )
					ForcePlayerSuicide ( i );
	}
}

/**
 * 달러 량을 덧셈합니다.
 *
 * @param client				Client index.
 * @param addAccount			Add account value.
 */
stock void loringlib_AddEntityAccount ( int client, int addAccount ) {
	loringlib_SetEntityAccount ( client, loringlib_GetEntityAccount ( client ) + addAccount );
}

/**
 * 달러 량을 뺄셈합니다.
 *
 * @param client				Client index.
 * @param subAccount			Subtraction account value.
 *
 * @error						뺄 달러 량이 엔티티의 달러 량 보다 큽니다.
 */
stock void loringlib_SubEntityAccount ( int client, int subAccount ) {
	if ( loringlib_GetEntityAccount ( client ) < subAccount )
		return;
	
	loringlib_SetEntityAccount ( client, loringlib_GetEntityAccount ( client ) - subAccount );
}

/**
 * 허드를 숨깁니다.
 *
 * @param client				Client index.
 * @param flags					Flag to set, use one of the HIDEHUD_ hiding constants.
 * @noreturn
 */
stock void loringlib_HideHUD ( int client, int flags ) {
	SetEntProp ( client, Prop_Send, "m_iHideHUD", flags );
}

stock int loringlib_GetHideHUD ( int client ) {
	return GetEntProp ( client, Prop_Send, "m_iHideHUD" );
}

stock void loringlib_CSGOClientEnemyGlow ( int client, float times ) {
	SetEntPropFloat ( client, Prop_Send, "m_flDetectedByEnemySensorTime", times );
}

stock void loringlib_CSGOClientEnemyGlowKill ( int client ) {
	SetEntPropFloat ( client, Prop_Send, "m_flDetectedByEnemySensorTime", 0.0 );
}

stock void loringlib_AddCSGOScorePoints ( int client, int addv ) {
	CS_SetClientContributionScore ( client, CS_GetClientContributionScore ( client ) + addv );
}

stock int loringlib_GetCSKillPoints ( int client ) {
	return GetEntProp ( client, Prop_Data, "m_iFrags" );
}

stock void loringlib_SetCSKillPoints ( int client, int value ) {
	SetEntProp ( client, Prop_Data, "m_iFrags", value );
}

stock void loringlib_AddCSKillPoints ( int client, int addv ) {
	loringlib_SetCSKillPoints ( client, loringlib_GetCSKillPoints ( client ) + addv );
}

stock int loringlib_GetCSDeathPoints ( int client ) {
	return GetEntProp ( client, Prop_Data, "m_iDeaths" );
}

stock void loringlib_SetCSDeathPoints ( int client, int value ) {
	SetEntProp ( client, Prop_Data, "m_iDeaths", value );
}

stock void loringlib_AddCSDeathPoints ( int client, int addv ) {
	loringlib_SetCSDeathPoints ( client, loringlib_GetCSDeathPoints ( client ) + addv );
}

/**
 * 날짜를 채크합니다.
 *
 * @param dates				날짜 (DD MM)
 * @return		날짜가 맞다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsDates ( const char[] dates ) {
	static char temp[8];
	FormatTime ( temp, sizeof ( temp ), "%m/%d", GetTime () );
	if ( StrContains ( datas, temp ) != -1 && loringlib_GetFirstUnixTime () )
		return true;
		
	else
		return false;
}

/**
 * 날짜를 채크합니다.
 *
 * @param dates				날짜 (YY DD MM)
 * @return		날짜가 맞다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsYearDates ( const char[] dates ) {
	static char temp[8];
	FormatTime ( temp, sizeof ( temp ), "%Y/%m/%d", GetTime () );
	
	else if ( StrContains ( datas, temp ) != -1 && loringlib_GetFirstUnixTime () )
		return true;
		
	else
		return false;
}

/**
 * 1970년인지 채크합니다.
 *
 * @return		1970년 이상이면 true, 이하이면 false를 반환합니다.
 *
 */
stock bool loringlib_GetFirstUnixTime ( /*void*/ ) {
	static char year[4];
	FormatTime ( year, sizeof ( year ), "%Y", GetTime () );
	static int dates;
	dates = StringToInt ( year );
	if ( dates >= 1970 )
		return true;
		
	else
		return false;
}

/**
 * int 값이 Overflow 인지 채크합니다.
 *
 * @param num				정수 값
 * @return		Overflow이면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsOverflow ( int num ) {
	if ( num >= OVERFLOW32 - 1 )
		return true;
		
	else
		return false;
}

/**
 * 클라이언트가 기본 장갑인지 채크합니다.
 * 
 * @param client				Client index.
 * @return						기본 장갑이라면 true 아니면 false를 반환합니다.
 */
stock bool loringlib_HasDefaultArms ( int client ) {
	char modelpath[256];
	GetEntPropString ( client, Prop_Send, "m_szArmsModel", modelpath, sizeof ( modelpath ) );
	
	if ( StrEqual ( modelpath, defaultArms[0] ) ||
	StrEqual ( modelpath, defaultArms[1] ) ||
	StrEqual ( modelpath, defaultArms[2] ) ||
	StrEqual ( modelpath, defaultArms[3] ) ||
	StrEqual ( modelpath, defaultArms[4] ) ||
	StrEqual ( modelpath, defaultArms[5] ) ||
	StrEqual ( modelpath, defaultArms[6] ) ||
	StrEqual ( modelpath, defaultArms[7] ) ||
	StrEqual ( modelpath, defaultArms[8] ) ||
	StrEqual ( modelpath, defaultArms[9] ) ||
	StrEqual ( modelpath, defaultArms[10] ) ||
	StrEqual ( modelpath, defaultArms[11] ) ||
	StrEqual ( modelpath, defaultArms[12] ) ||
	StrEqual ( modelpath, defaultArms[13] ) ||
	StrEqual ( modelpath, defaultArms[14] ) ||
	StrEqual ( modelpath, defaultArms[15] ) ||
	StrEqual ( modelpath, defaultArms[16] ) )
		return true;
		
	return false;
}

/**
 * 거리를 유닛으로 변환합니다.
 *
 * @param distance
 * @param conversion
 * @return units
 */
stock float loringlib_ConvertUnits ( float distance, float conversion ) {
	return distance / conversion;
}

/**
 * env_spritetrail을 생성합니다.
 * @note CS:GO에서는 때때로 작동하지 않을 수 있습니다.
 *
 * @param client				클라이언트 인덱스
 * @param entity				env_spritetrail 인덱스 값
 * @param spritetrail			엔티티 모델 경로
 * @param renderColor			r, g, b, a 색상
 * @param lifeTime				표시 시간
 * @param startWidth			시작 폭
 * @param endWidth				끝 폭
 * @return				엔티티가 만들어졌으면 true, 아니면 false를 반환합니다.
 * @error				엔티티가 유효하지 않거나, 제공되지 않은 엔진입니다.
 */
stock bool loringlib_SetupSpriteTrail ( int client, int entity, const char[] spritetrail, int renderColor[4], float lifeTime, float startWidth, float endWidth ) {
	entity = CreateEntityByName ( "env_spritetrail" );
	if ( entity > 0 &&
		IsValidEntity ( entity ) ) {
		static float origin[3];
		static char id[64];
		static char pos[256];
		static char colors[16];
		static char life[16];
		static char start[16];
		static char end[16];
		GetClientAbsOrigin ( client, origin );
		origin[2] += 10.0;
		
		GetClientAuthId ( client, AuthId_Steam2, id, sizeof ( id ) );
		Format ( pos, sizeof ( pos ), "%f %f %f", origin[0], origin[1], origin[2] );
		Format ( colors, sizeof ( colors ), "%i %i %i %i", renderColor[0], renderColor[1], renderColor[2], renderColor[3] );
		Format ( life, sizeof ( life ), "%f", lifeTime );
		Format ( start, sizeof ( start ), "%f", startWidth );
		Format ( end, sizeof ( end ), "%f", endWidth );
		
		DispatchKeyValue ( entity, "Origin", pos );
		DispatchKeyValue ( entity, "spritename", spritetrail );
		DispatchKeyValue ( entity, "lifetime", life );
		DispatchKeyValue ( entity, "startwidth", start );
		DispatchKeyValue ( entity, "endwidth", end );
		DispatchKeyValue ( entity, "renderamt", "255" );
		DispatchKeyValue ( entity, "rendercolor", colors );
		DispatchKeyValue ( entity, "rendermode", "5" );
		
		DispatchSpawn ( entity );

		SetEntPropFloat ( entity, Prop_Send, "m_flTextureRes", 0.05 );
		SetEntPropFloat ( entity, Prop_Data, "m_flSkyboxScale", 1.0 );
		
		DispatchKeyValue ( client, "targetname", id );
		
		SetVariantString ( id );
		AcceptEntityInput ( entity, "SetParent" );
		
		return true;
	}
	
	else
		return false;
}

/**
 * env_beam을 생성합니다.
 *
 */
stock int loringlib_SetupBeam ( const float start[3], const float end[3], const char[] model, int lifeTime = 0, float size, float startWidth, float endWidth, const int color[3] ) {
	/* 시작 지점 설정 */
	int starter = CreateEntityByName ( "info_target" );
	if ( starter == -1 )
		return -1;
	
	char starterTarget[32];
	Format ( starterTarget, sizeof ( starterTarget ), "info_target_starter_%i", EntIndexToEntRef ( starter ) );
	DispatchKeyValue ( starter, "targetname", starterTarget );
	DispatchKeyValueVector ( starter, "origin", start );
	DispatchSpawn ( starter );
	
	/* 끝 지점 설정 */
	int ender = CreateEntityByName ( "info_target" );
	char enderTarget[32];
	Format ( enderTarget, sizeof ( enderTarget ), "info_target_ender_%i", EntIndexToEntRef ( ender ) );
	DispatchKeyValue ( ender, "targetname", enderTarget );
	DispatchKeyValueVector ( ender, "origin", end );
	DispatchSpawn ( ender );
	
	int entity = CreateEntityByName ( "env_beam" );
	if ( entity == -1 )
		return entity;
		
	char temp[16];
	DispatchKeyValue ( entity, "LightningStart", starterTarget );
	DispatchKeyValue ( entity, "LightningEnd", enderTarget );
	DispatchKeyValue ( entity, "TouchType", "3" );
	Format ( temp, sizeof ( temp ), "%f", size );
	DispatchKeyValue ( entity, "BoltWidth", temp );
	DispatchKeyValue ( entity, "framerate", "1" );
	IntToString ( lifeTime, temp, sizeof ( temp ) );
	DispatchKeyValue ( entity, "life", temp );
	Format ( temp, sizeof ( temp ), "%i %i %i", color[0], color[1], color[2] );
	DispatchKeyValue ( entity, "rendercolor", temp );
	DispatchKeyValue ( entity, "renderamt", "255" );
	DispatchKeyValue ( entity, "spawnflags", "1" );
	DispatchKeyValue ( entity, "HDRColorScale", "1.0" );
	DispatchKeyValue ( entity, "StrikeTime", "1" );
	DispatchKeyValue ( entity, "TextureScroll", "35" );
	DispatchKeyValue ( entity, "texture", model );
	DispatchKeyValue ( entity, "decalname", "env_beam" );
	
	DispatchSpawn ( entity );
	
	PrecacheModel ( model );
	SetEntityModel ( entity, model );
	
	SetEntDataFloat ( entity, FindSendPropInfo ( "CBeam", "m_fWidth" ), startWidth );
	SetEntDataFloat ( entity, FindSendPropInfo ( "CBeam", "m_fEndWidth" ), endWidth );
	AcceptEntityInput ( entity, "TurnOn" );
	ActivateEntity ( entity );
	
	AcceptEntityInput ( starter, "kill" );
	AcceptEntityInput ( ender, "kill" );
	
	return EntIndexToEntRef ( entity );
}

/**
 * 엔티티를 삭제합니다.
 *
 * @param entity				Entity index.
 * @noreturn
 */
stock void loringlib_RemoveSpriteTrail ( int client, int entity ) {
	if ( !loringlib_IsValidClient ( client ) )
		return;
		
	while ( ( entity = FindEntityByClassname ( entity, "env_spritetrail" ) ) != -1 ) {
		if ( IsValidEntity ( entity ) )
			AcceptEntityInput ( entity, "Kill" );
	}
}

/**
 * 타 클라이언트가 클라이언트 거리 안에 있는지 채크합니다.
 *
 * @param client
 * @param another
 * @param origin			Client's Eye positions.
 * @param distance
 * @param nearestDistance				거리를 구합니다.
 * @return 거리안에 있을 경우 true를 반환합니다.
 */
stock bool loringlib_GetNearTrue ( int client, int another, float origin[3], float distance, float &nearestDistance = 0.0 ) {
	if ( loringlib_IsValidClient ( another ) && client != another ) {
		static float eye[3];
		GetClientEyePosition ( another, eye );
		if ( GetVectorDistance ( origin, eye ) <= distance ) {
			static float vec[3], vecang[3];
			MakeVectorFromPoints ( origin, eye, vec );
			GetVectorAngles ( vec, vecang );
			Handle trace = null;
			trace = TR_TraceRayFilterEx ( origin, vecang, MASK_SOLID, RayType_Infinite, loringlib_TraceRayFilter_tarPlayer, client );
			if ( TR_DidHit ( trace ) ) {
				if ( TR_GetEntityIndex ( trace ) == another ) {
					if ( trace != null )
					//	delete trace;
						delete trace;
					//	CloseHandle ( trace );
					return true;
				}
			}
			
			delete trace;
		}
	}
	
	return false;
}

/**
 * loringlib_GetNearTrue () 함수의 거리를 보여줍니다.
 *
 * @param client
 * @param distance
 * @param display_time
 * @param width
 * @param amplitude
 * @param colors			RGBA
 * @param sendToAll
 */
stock void loringlib_DisplayNearTrueTrigger ( int client, float distance, float display_time = 1.5, float width = 10.0, float amplitude = 0.0, const int colors[4], bool sendToAll = true ) {
	if ( loringlib_IsValidClient ( client ) ) {
		float pos[3];
		GetClientAbsOrigin ( client, pos );
		pos[2] += 3.0;
		
		float fix_distance = distance + 150.0;	//	fixed
		TE_SetupBeamRingPoint ( pos, fix_distance - 5.0, fix_distance, PrecacheModel ( "materials/sprites/laserbeam.vmt" ), 0, 1, 1, display_time, width, amplitude, colors, 1, 0 );
		if ( sendToAll )
			TE_SendToAll ();
		else
			TE_SendToClient ( client );
	}
}

/**
 * 특정 클라이언트에게 blinding합니다.
 *
 * @param client				클라이언트 인덱스
 * @param duration				지속 시간
 * @param holdTimes				유지 시간
 * @param rgba					Red, Green, Blue, Alpha 인덱스 값
 * @return			클라이언트에게 fade메세지를 전했다면 true, 아니면 false를 반환합니다.
 * @note rgba에서 alpha값이 0일 경우 페이드가 삭제됨.
 * @error		Invalid client index.
 */
stock bool loringlib_ShowFadeUserMessage ( int client, int duration, int holdTimes, int rgba[4] ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	int flags;
	if ( rgba[3] == 0 )
		flags = ( 0x0001 | 0x0010 );
	else
		flags = ( 0x0002 | 0x0008 );
	Handle message = StartMessageOne ( "Fade", client );
	if ( GetUserMessageType () == UM_Protobuf ) {
		Protobuf pb = UserMessageToProtobuf ( message );
		pb.SetInt ( "duration", duration );
		pb.SetInt ( "hold_time", holdTimes );
		pb.SetInt ( "flags", flags );
		pb.SetColor ( "clr", rgba );
	}
	
	else {
		BfWrite bf = UserMessageToBfWrite ( message );
		bf.WriteShort ( duration );
		bf.WriteShort ( holdTimes );
		bf.WriteShort ( flags );
		bf.WriteByte ( rgba[0] );
		bf.WriteByte ( rgba[1] );
		bf.WriteByte ( rgba[2] );
		bf.WriteByte ( rgba[3] );
	}
	
	EndMessage ();
	return true;
}

#define FFADE_IN 		0x0001        // Just here so we don't pass 0 into the function
#define FFADE_OUT		0x0002        // Fade out (not in)
#define FFADE_MODULATE	0x0004        // Modulate (don't blend)
#define FFADE_STAYOUT	0x0008        // ignores the duration, stays faded out until new ScreenFade message received
#define FFADE_AUTO		0x0009
#define FFADE_PURGE		0x0010        // Purges all other fades, replacing them with this one

/**
 * 특정 클라이언트에게 blinding합니다.
 *
 * @param client				클라이언트 인덱스, 0일 경우 모두에게 표시합니다.
 * @param duration				지속 시간
 * @param holdTimes				유지 시간
 * @param rgba					Red, Green, Blue, Alpha 인덱스 값
 * @param flags					플레그 값
 * @error		Invalid client index.
 */
stock bool loringlib_ShowFadeUserMessageEx ( int client, int duration, int holdTimes = -1, int flags, const int rgba[4] = { 0, 0, 0, 255 } ) {
	Handle userMessage = StartMessageOne ( "Fade", client, USERMSG_RELIABLE );
	if ( userMessage == null )
		return false;
	
	if ( GetFeatureStatus ( FeatureType_Native, "GetUserMessageType" ) == FeatureStatus_Available &&
		GetUserMessageType () == UM_Protobuf ) {
		Protobuf pb = UserMessageToProtobuf ( userMessage );
		
		pb.SetInt ( "duration", duration );
		pb.SetInt ( "hold_time", holdTimes );
		pb.SetInt ( "flags", flags );
		pb.SetColor ( "clr", rgba );
	}
	else {
		BfWrite bf = UserMessageToBfWrite ( userMessage );
		
		bf.WriteShort ( duration );
		bf.WriteShort ( holdTimes );
		bf.WriteShort ( flags );
		bf.WriteByte ( rgba[0] );
		bf.WriteByte ( rgba[1] );
		bf.WriteByte ( rgba[2] );
		bf.WriteByte ( rgba[3] );
	}
	
	EndMessage ();
	return true;
} 

stock void loringlib_VoteMessage ( int client, char[] disp, char[] details ) {
	Handle userMessage = StartMessageOne ( "VotePass", client, USERMSG_RELIABLE | USERMSG_BLOCKHOOKS );
	if ( GetUserMessageType () == UM_Protobuf ) {
		Protobuf pb = UserMessageToProtobuf ( userMessage );
		if ( pb != null ) {
			pb.SetInt ( "team", GetClientTeam ( client ) );
			pb.SetInt ( "vote_type", 0 );
			pb.SetString ( "disp_str", disp );
			pb.SetString ( "details_str", details );
			EndMessage ();
		}
		else
			PrintToChat ( client, "Protobuf is null." );
	}
}

/**
 * 클라이언트에게 KeyHintText메세지를 보냅니다.
 *
 * @param client				클라이언트 인덱스
 * @param format
 * @param ...
 * @error				클라이언트가 유효하지 않습니다.
 */
stock void loringlib_KeyHintText ( int client, const char[] format, any ... ) {
	if ( !loringlib_IsValidClient ( client ) )
		return;
	
	static char buffer[256];
	VFormat ( buffer, sizeof ( buffer ), format, 3 );
	
	Handle msg = StartMessageOne ( "KeyHintText", client );
	BfWrite bf = UserMessageToBfWrite ( msg );
	bf.WriteByte ( 1 );
	bf.WriteString ( buffer );
	EndMessage ();
}

/**
 * 모두에게 SayText2를 보냅니다.
 *
 * @param owner				SayText2를 보내는 클라이언트
 * @param format
 * @param ...
 */
stock loringlib_SayText2ToAll ( int client, const char[] format, any ... ) {
	if ( !loringlib_IsValidClient ( client ) )
		return;
		
	static char buffer[256];
	VFormat ( buffer, sizeof ( buffer ), format, 3 );
	
	Handle msg = StartMessageAll ( "SayText2" );
	if ( msg != null ) {
		BfWrite bf = UserMessageToBfWrite ( msg );
		bf.WriteByte ( client );
		bf.WriteByte ( true );
		bf.WriteString ( buffer );
	}
	
	EndMessage ();
}

/**
 * Send SayText2.
 *
 * @param author
 * @param target
 * @param wantsToChat
 * @param buffer
 * @param any
 * @return no
 */
stock void loringlib_SayText2 ( int author, int target = 0, bool wantsToChat = false, const char[] buffer, any ... ) {
	char temp[192];
	VFormat ( temp, sizeof ( temp ), buffer, 5 );
	StrCat ( temp, sizeof ( temp ), "\n" );
	
	Handle msg = StartMessageOne ( "SayText2", target, USERMSG_RELIABLE | USERMSG_BLOCKHOOKS );
	if ( GetFeatureStatus ( FeatureType_Native, "GetUserMessageType" ) == FeatureStatus_Available &&
		GetUserMessageType () == UM_Protobuf ) {
		Protobuf pb = UserMessageToProtobuf ( msg );
		if ( pb != null ) {
			pb.SetInt ( "ent_idx", author );
			pb.SetBool ( "chat", wantsToChat );
			
			pb.SetString ( "msg_name", temp );
			pb.AddString ( "params", "" );
			pb.AddString ( "params", "" );
			pb.AddString ( "params", "" );
			pb.AddString ( "params", "" );
		}
	}
	
	else {
		BfWrite bf = UserMessageToBfWrite ( msg );
		bf.WriteByte ( author );
		bf.WriteByte ( wantsToChat );
		bf.WriteString ( temp );
	}
	
	EndMessage ();
}

/**
 * Send KeyHintText.
 *
 * @param client			Client index.
 * @param buffer			Text buffer.
 * @param any
 * @return no
 */
stock void loringlib_PrintKeyHintTextToClient ( int client, const char[] buffer, any ... ) {
	Handle msg = StartMessageOne ( "KeyHintText", client );
	if ( msg == null )
		return;
		
	char buff[1024];
	SetGlobalTransTarget ( client );
	VFormat ( buff, sizeof ( buff ), buffer, 3 );
	if ( GetUserMessageType () == UM_Protobuf ) {
		Protobuf pb = UserMessageToProtobuf ( msg );
		pb.AddString ( "hints", buff );
	}
	
	else {
		BfWrite bf = UserMessageToBfWrite ( msg );
		bf.WriteByte ( 1 );
		bf.WriteString ( buff );
	}
	
	EndMessage ();
}

/**
 * 라운드 종료 페널에 메시지를 띄웁니다.
 *
 * @param client
 * @param message
 * @param ...
 */
stock void loringlib_PrintWinPanelMessage ( int client, const char[] message, any ... ) {
	Event hEvent = CreateEvent ( "cs_win_panel_round" );
	
	char buff[1024];
	SetGlobalTransTarget ( client );
	VFormat ( buff, sizeof buff, message, 3 );
	
	hEvent.SetString ( "funfact_token", message );
	hEvent.FireToClient ( client );
	hEvent.Cancel ();
}

stock void loringlib_PrintWinPanelMessageAll ( const char[] message, any ... ) {
	char buff[1024];
	VFormat ( buff, sizeof buff, message, 2 );
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && !IsFakeClient ( i ) ) {
			SetGlobalTransTarget ( i );
			loringlib_PrintWinPanelMessage ( i, buff );
		}
	}
}

#define HUD_PRINTNOTIFY			1	/**< 알림 메세지로 표시 */
#define HUD_PRINTCONSOLE		2	/**< 콘솔 메세지로 표시 */
#define HUD_PRINTTALK			3	/**< 채팅 메세지로 표시 */
#define HUD_PRINTCENTER			4	/**< 중간 메세지로 표시 */

/**
 * 벨브 번역 문구를 표시합니다.
 * @note message 파라메터는 무조건 '#'으로 시작해야합니다. 예) #vote_failed
 *
 * @param clients		All player index.
 * @param numClients	Client numbers.
 * @param msgDest		Message display type.
 * @param message		Translation tag.
 * @param param1
 * @param param2
 * @param param3
 * @param param4
 * @return noreturn
 */
stock void loringlib_PrintValveTranslationMessage ( int[] clients, int numClients, int msgDest, const char[] message, const char[] param1 = "", const char[] param2 = "", const char[] param3 = "", const char[] param4 = "" ) {
	Handle msg = StartMessage ( "TextMsg", clients, numClients, USERMSG_RELIABLE );
	if ( msg == null )
		return;
		
	if ( GetUserMessageType () == UM_Protobuf ) {
		Protobuf pb = UserMessageToProtobuf ( msg );
		pb.SetInt ( "msg_dest", msgDest );
		pb.AddString ( "params", message );
		
		pb.AddString ( "params", param1 );
		pb.AddString ( "params", param2 );
		pb.AddString ( "params", param3 );
		pb.AddString ( "params", param4 );
	}
	
	else {
		BfWrite bf = UserMessageToBfWrite ( msg );
		bf.WriteByte ( msgDest );
		bf.WriteString ( message );
		
		bf.WriteString ( param1 );
		bf.WriteString ( param2 );
		bf.WriteString ( param3 );
		bf.WriteString ( param4 );
	}
	
	EndMessage ();
}

/**
 * 벨브 번역 문구를 모두에게 표시합니다.
 * @note message 파라메터는 무조건 '#'으로 시작해야합니다. 예) #vote_failed
 *
 * @param msgDest		Message display type.
 * @param message		Translation tag.
 * @param param1
 * @param param2
 * @param param3
 * @param param4
 * @return noreturn
 */
stock void loringlib_PrintValveTranslationMessageToAll ( int msgDest, const char[] message, const char[] param1 = "", const char[] param2 = "", const char[] param3 = "", const char[] param4 = "" ) {
	int tot = 0;
	int clients[MaxClients];
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
		
		clients[tot++] = i;
	}
	
	loringlib_PrintValveTranslationMessage ( clients, tot, msgDest, message, param1, param2, param3, param4 );
}

/**
 * 벨브 번역 문구를 클라이언트에게 표시합니다.
 * @note message 파라메터는 무조건 '#'으로 시작해야합니다. 예) #vote_failed
 *
 * @param client
 * @param msgDest		Message display type.
 * @param message		Translation tag.
 * @param param1
 * @param param2
 * @param param3
 * @param param4
 * @return noreturn
 */
stock void loringlib_PrintValveTranslationMessageToClient ( int client, int msgDest, const char[] message, const char[] param1 = "", const char[] param2 = "", const char[] param3 = "", const char[] param4 = "" ) {
	int players[1];
	players[0] = client;
	loringlib_PrintValveTranslationMessage ( players, 1, msgDest, message, param1, param2, param3, param4 );
}

/**
 * Send to all KeyHintText.
 *
 * @param buffer			Text buffer.
 * @param any
 * @return no
 */
stock void loringlib_PrintKeyHintTextToAll ( const char[] buffer, any ... ) {
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
			
		char buff[1024];
		VFormat ( buff, sizeof ( buff ), buffer, 2 );
		loringlib_PrintKeyHintTextToClient ( i, buff );
	}
}

/**
 * 전체에게 콘솔 메세지를 보냅니다.
 *
 * @param buffer				Text buffer.
 * @param any					
 * @return no
 */
stock void loringlib_PrintToConsoleAll ( const char[] buffer, any ... ) {
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
			
		char buff[256];
		VFormat ( buff, sizeof ( buff ), buffer, 2 );
		PrintToConsole ( i, buff );
	}
}

/**
 * 클라이언트에게 프로그래스바를 보여줍니다.
 * @note 이제 CS:GO에서는 작동하지 않습니다.
 *
 * @param client			클라이언트 인덱스
 * @param time				시간 (초)
 * @return no return 
 */
stock void loringlib_ShowProgressBar ( int client, int time ) {
	SetEntPropFloat ( client, Prop_Send, "m_flProgressBarStartTime", GetGameTime() );
	SetEntProp ( client, Prop_Send, "m_iProgressBarDuration", time );  
}

 /**
 * 프로그래스바를 삭제합니다.
 * @note 이제 CS:GO에서는 작동하지 않습니다.
 *
 * @param client			클라이언트 인덱스
 * @return no return 
 */
stock void loringlib_RemoveProgressBar ( int client ) {
	SetEntPropFloat ( client, Prop_Send, "m_flProgressBarStartTime", GetGameTime() );
	SetEntProp ( client, Prop_Send, "m_iProgressBarDuration", 0 );  
}

/**
 * 클라이언트의 시점을 흔들리게 합니다.
 *
 * @param client				클라이언트 인덱스
 * @param vec					흔들리게 할 시선 각도
 * @noreturn
 */
stock void loringlib_ShowViewPunch ( int client, float vec[3] ) {
	SetEntPropVector ( client, Prop_Send, "m_viewPunchAngle", vec );
}

/**
 * 클라이언트의 시점(에임)을 흔들리게 합니다.
 *
 * @param client				클라이언트 인덱스
 * @param vec					흔들리게 할 시선 각도
 * @noreturn
 */
stock void loringlib_ShowAimPunch ( int client, float vec[3] ) {
	SetEntPropVector ( client, Prop_Send, "m_aimPunchAngle", vec );
}

/**
 * 클라이언트의 에임 펀치의 속도를 정합니다.
 *
 * @param client				클라이언트 인덱스
 * @param vec					흔들리게 할 시선 각도
 * @noreturn
 */
stock void loringlib_SetAimPunchVel ( int client, float vec[3] ) {
	SetEntPropVector ( client, Prop_Send, "m_aimPunchAngleVel", vec );
}

/**
 * 클라이언트에게 Shake메세지를 보냅니다.
 *
 * @param client				클라이언트 인덱스
 * @param shake					Shaking 진폭
 * @param time					유지 시간
 * @error			Invalid client index.
 */
stock void loringlib_ShowShakeMessage ( int client, float shake, float time ) {
	Handle msg = StartMessageOne ( "Shake", client );
	if ( msg != null ) {
		Protobuf pb = UserMessageToProtobuf ( msg );
		pb.SetInt ( "command", 0 );
		pb.SetFloat ( "local_amplitude", shake );
		pb.SetFloat ( "frequency", 1.0 );
		pb.SetFloat ( "duration", time );
	}
	
	EndMessage ();
}

/**
 * 월드텍스트를 띄웁니다.
 *
 * @param client
 * @param pos
 * @param ang
 * @param size
 * @param color				RGBA
 * @param killTime
 * @param text
 */
stock int loringlib_ShowPointWorldText ( int client, float pos[3], float ang[3], int size, int color[4] = { 255, 255, 255, 255 }, float killTime = 0.0, char[] text ) {
	int entity = CreateEntityByName ( "point_worldtext" );
	if ( entity == -1 )
		return entity;
		
	DispatchKeyValue ( entity, "message", text );
	
	char sizeChar[16];
	char colors[32];
	IntToString ( size, sizeChar, sizeof ( sizeChar ) );
	Format ( colors, sizeof ( colors ), "%d %d %d %d", color[0], color[1], color[2], color[3] );
	DispatchKeyValue ( entity, "textsize", sizeChar );
	DispatchKeyValue ( entity, "color", colors );
	
	DispatchSpawn ( entity );
	
	if ( GetEdictFlags ( entity ) & FL_EDICT_ALWAYS )
		SetEdictFlags ( entity, ( GetEdictFlags ( entity ) ^ FL_EDICT_ALWAYS ) );
		
	loringlib_SetEntityOwner2 ( entity, client );
	
	TeleportEntity ( entity, pos, ang, NULL_VECTOR );
	
	if ( killTime > 0.0 ) {
		CreateTimer ( killTime, timerKillWorldText, EntIndexToEntRef ( entity ) );
	}
	
	return entity;
}

public Action timerKillWorldText ( Handle timer, int ref ) {
	int entity = EntRefToEntIndex ( ref );
	if ( entity == INVALID_ENT_REFERENCE ||
		!IsValidEntity ( entity ) )
		return;
		
	AcceptEntityInput ( entity, "kill" );
}

/**
 * 클라이언트의 닉네임에서 HTML코드를 필터링 합니다.
 * @note CS:GO에서 HintText 및 CenterText에서 HTML코드가 적용되는 것을 방지합니다.
 *
 * @param client				클라이언트 인덱스
 * @param nickname				필터링된 닉네임
 * @param maximum				char 최대 크기
 * @error			Invalid client index.
 */
stock void loringlib_RemoveNicknameHTMLCode ( int client, const char[] nickname, int maximum ) {
	char temp[32];
	GetClientName ( client, temp, sizeof ( temp ) );
	
	ReplaceString ( temp, sizeof ( temp ), "&", "&amp;", false );
	
	ReplaceString ( temp, sizeof ( temp ), "<", "&lt;", false );
	ReplaceString ( temp, sizeof ( temp ), ">", "&gt;", false );
	
	Format ( nickname, maximum, temp );
}

/*
 * Gets the owner (usually a client) of the weapon
 *
 * @param weapon		Weapon Entity.
 * @return				Owner of the weapon or INVALID_ENT_REFERENCE if the weapon has no owner.
 */
stock int loringlib_GetWeaponOwner ( int weapon ) {
	return GetEntPropEnt ( weapon, Prop_Data, "m_hOwner" );
}

/**
 * Get model index and prevent server from crash
 *
 * @param client				클라이언트 인덱스
 * @param index					인덱스
 * @return	index
 */
stock int loringlib_GetViewModelIndex ( int client, int index ) {
	int owner;
	while ( ( index = loringlib_FindEntityByClassnameEx ( index, "predicted_viewmodel" ) ) != -1 ) {
		owner = GetEntPropEnt ( index, Prop_Send, "m_hOwner" );
		if ( owner != client )
			continue;
			
		return EntIndexToEntRef ( index );
	}
	
	return INVALID_ENT_REFERENCE;
}

/**
 * Get entity name.
 *
 * @param startEnt
 * @param classname
 */
stock int loringlib_FindEntityByClassnameEx ( int startEnt, char[] classname ) {
	while ( startEnt > -1 &&
		!IsValidEntity ( startEnt ) )
		startEnt --;
	
	return FindEntityByClassname ( startEnt, classname );
}

/**
 * Get percentage.
 *
 * @param normal		일부 값
 * @param total			전체 값
 * @return percentage
 */
public float loringlib_GetPercentage ( int normal, int total ) {
	return ( float ( normal ) / float ( total ) * 100.0 );
}

/**
 * Get percentage (float type).
 *
 * @param normal		일부 값
 * @param total			전체 값
 * @return percentage
 */
public float loringlib_GetFloatPercentage ( float normal, float total ) {
	return ( normal / total * 100.0 );
}

/**
 * 닉네임으로 클라이언트 인덱스 값을 찾습니다.
 * @note 정확한 값을 찾아오지 않습니다, 되도록이면 loringlib_FindTarget을 사용해 주세요.
 *
 * @param name
 * @param equal_check			닉네임이 전부일치일 경우 true, 부분일치일 경우 false.
 * @param uppercase				대소문자 구분, 대문자 true, 소문자 false.
 * @return	Client index
 */
stock int loringlib_GetIndexByClientName ( char[] name, bool equal_check, bool uppercase ) {
	static char temp[32];
	int result = -1;
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) ) {
			GetClientName ( i, temp, sizeof ( temp ) );
			if ( equal_check ? ( StrEqual ( temp, name, uppercase ) ) : ( StrContains ( temp, name, uppercase ) != -1 ) )
				result = i;
		}
	}
	
	return result;
}

/**
 * 스팀 고유번호로 클라이언트 인덱스 값을 찾습니다.
 *
 * @param steam32				스팀 고유번호 (SteamID32)
 * @return			Client index
 */
stock int loringlib_GetIndexBySteamID ( const char[] steam32 ) {
	static char temp[32];
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient ( i ) )
			continue;
			
		GetClientAuthId ( i, AuthId_Steam2, temp, sizeof ( temp ) );
		if ( StrEqual ( steam32, temp, false ) )
			return i;
	}
	
	return -1;
}

/**
 * IsStringNumeric?
 *
 * @param buffer
 * @param maxlen
 * @return		문자 모두가 숫자라면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsStringNumeric ( char[] buffer, int maxlen ) {
	for ( int i = 0; i < maxlen; i ++ ) {
		if ( StrEqual ( buffer[i], "" ) )
			continue;
			
		if ( !IsCharNumeric ( buffer[i] ) )
			return false;
	}
	
	return true;
}

/**
 * 콤마 추가
 * 
 * @param buffer
 * @param maxlen
 * @param position
 */
stock void loringlib_AddCommaToString ( char[] buffer, int maxlen, int position ) {
	static char temp[32];
	FormatEx ( temp, position + 1, "%s", buffer ), Format ( temp, sizeof ( temp ), "%s,", temp ), Format ( temp, sizeof ( temp ), "%s%s", temp, buffer[position] ), FormatEx ( buffer, maxlen, "%s", temp );
}

/**
 * 숫자 포멧
 * 
 * @param number
 * @param buffer
 * @param maxlen
 */
stock void loringlib_NumberFormat ( int number, char[] buffer, int maxlen ) {
	bool negative = number < 0 ? true : false;
	if ( negative )
		number *= -1;
	FormatEx ( buffer, maxlen, "%d", number );
	for ( int i = strlen ( buffer ) - 3; i > 0; i -= 3 )
		loringlib_AddCommaToString ( buffer, maxlen, i );
	if ( negative )
		Format ( buffer, maxlen, "-%s", buffer );
}

/**
 * Boolean 값을 Integer 값으로 바꿉니다.
 * @param target
 * @return target 값이 false이면 0, true이면 1을 반환합니다.
 */
stock int loringlib_BooleanToInt ( bool target ) {
	return target ? 1 : 0;
}

/**
 * Integer 값을 Boolean 값으로 바꿉니다.
 * @param target
 * @return target 값이 1이면 true, 0이면 false를 반환합니다.
 */
stock bool loringlib_IntToBoolean ( int target ) {
	return target > 0 ? true : false;
}

/**
 * Boolean 값을 String 값으로 바꿉니다.
 *
 * @param target
 * @param trueAlias
 * @param falseAlias
 * @noreturn
 */
stock void loringlib_BooleanToString ( bool target, char[] trueAlias, char[] falseAlias, char[] str, int strlen ) {
	Format ( str, strlen, target ? trueAlias : falseAlias );
}

/**
 * 확률 계산
 * 
 * @param percentage
 * @note		확률 값이 0.0 이하거나, 100.0 이상이면 false를 반환합니다.
 * @return		확률안에 들어있으면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsFloatProbability ( float percentage ) {
	if ( percentage < 0.0 || percentage > 100.0 )
		return false;
	float randam = GetRandomFloat ( 0.000000, 1.000000 );
	float probability = percentage / 100.0;
	
	if ( randam <= probability )
		return true;
	else
		return false;
}

/**
 * 확률 계산
 * 
 * @param percentage
 * @note		확률 값이 0.0 이하거나, 100.0 이상이면 false를 반환합니다.
 * @return		확률안에 들어있으면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsFloatChance ( float percentage ) {
	return loringlib_IsFloatProbability ( percentage );
}

/**
 * 확률 계산 (Integer)
 *
 * @param percentage
 * @return 확률안에 들어있으면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_IsIntegerChance ( int percentage ) {
	if ( percentage <= 0 )
		return false;
	else if ( percentage >= 100 )
		return true;
	
	int randam = GetRandomInt ( 1, 100 );
	if ( randam <= percentage )
		return true;
	return false;
}

/**
 * Set integer colors.
 * 
 * @param colors
 * @param red
 * @param green
 * @param blue
 * @param alpha
 * @noreturn
 */
stock void loringlib_SetColors ( int colors[4], int red, int green, int blue, int alpha ) {
	colors[0] = red;
	colors[1] = green;
	colors[2] = blue;
	colors[3] = alpha;
}

/**
 * Set float vectors.
 *
 * @param vec
 * @param x
 * @param z
 * @param y
 * @noreturn
 */
stock void loringlib_SetVectors ( float vec[3], float x, float z, float y ) {
	vec[0] = x;
	vec[1] = z;
	vec[2] = y;
}

/**
 * 들고 있는 무기인지 채크합니다.
 *
 * @param client
 * @param weaponname
 * @return 무기가 맞다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponName ( int client, char[] weaponname ) {
	if ( !loringlib_IsValidClient__PlayGame  ( client ) )
		return false;
		
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrEqual ( weapon, weaponname ) )
		return true;
	
	return false;
}

/**
 * 플레이어가 투척무기를 들고 있을 때를 채크합니다.
 *
 * @param client
 * @return 투척무기를 들고 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponGrenade ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	if ( !IsPlayerAlive ( client ) )
		return false;
		
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrContains ( weapon, "grenade", false ) != -1 ||
		StrEqual ( weapon, "weapon_flashbang" ) ||
		StrEqual ( weapon, "weapon_decoy" ) ||
		StrEqual ( weapon, "weapon_molotov" ) )
		return true;
		
	return false;
}

/**
 * 플레이어가 권총을 들고 있을 때를 채크합니다.
 *
 * @param client
 * @return 권총을 들고 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponPistol ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	if ( !IsPlayerAlive ( client ) )
		return false;
		
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrEqual ( weapon, "weapon_glock" ) ||
		StrEqual ( weapon, "weapon_hkp2000" ) ||
		StrEqual ( weapon, "weapon_usp_silencer" ) ||
		StrEqual ( weapon, "weapon_usp" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_p250" ) ||
		StrEqual ( weapon, "weapon_p228" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_fiveseven" ) ||
		StrEqual ( weapon, "weapon_deagle" ) ||
		StrEqual ( weapon, "weapon_revolver" ) ||
		StrEqual ( weapon, "weapon_cz75a" ) ||
		StrEqual ( weapon, "weapon_elite" ) )
		return true;
		
	return false;
}

/**
 * 플레이어가 샷건을 들고 있을 때를 채크합니다.
 *
 * @param client
 * @return 샷건을 들고 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponShotgun ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	if ( !IsPlayerAlive ( client ) )
		return false;
	
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrEqual ( weapon, "weapon_nova" ) ||
		StrEqual ( weapon, "weapon_m3" ) ||
		StrEqual ( weapon, "weapon_xm1014" ) ||
		StrEqual ( weapon, "weapon_mag7" ) )
		return true;
	
	return false;
}

/**
 * 플레이어가 중화기를 들고 있을 때를 채크합니다.
 *
 * @param client
 * @return 중화기를 들고 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponHeavy ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	if ( !IsPlayerAlive ( client ) )
		return false;
		
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrEqual ( weapon, "weapon_nova" ) ||
		StrEqual ( weapon, "weapon_xm1014" ) ||
		StrEqual ( weapon, "weapon_sawedoff" ) ||
		StrEqual ( weapon, "weapon_m3" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_mag7" ) ||
		StrEqual ( weapon, "weapon_m249" ) ||
		StrEqual ( weapon, "weapon_negev" ) )
		return true;
		
	return false;
}

/**
 * 플레이어가 기관단총 들고 있을 때를 채크합니다.
 *
 * @param client
 * @return 기관단총 들고 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponSMGs ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	if ( !IsPlayerAlive ( client ) )
		return false;
		
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrEqual ( weapon, "weapon_mp9" ) ||
		StrEqual ( weapon, "weapon_mp7" ) ||
		StrEqual ( weapon, "weapon_ump45" ) ||
		StrEqual ( weapon, "weapon_tmp" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_mp5sd" ) ||
		StrEqual ( weapon, "weapon_mp5navy" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_p90" ) ||
		StrEqual ( weapon, "weapon_bizon" ) )
		return true;
		
	return false;
}

/**
 * 플레이어가 돌격소총을 들고 있을 때를 채크합니다.
 *
 * @param client
 * @return 돌격소총을 들고 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponARs ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	if ( !IsPlayerAlive ( client ) )
		return false;
		
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrEqual ( weapon, "weapon_famas" ) ||
		StrEqual ( weapon, "weapon_galilar" ) ||
		StrEqual ( weapon, "weapon_galil" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_ak47" ) ||
		StrEqual ( weapon, "weapon_m4a1" ) ||
		StrEqual ( weapon, "weapon_m4a1_silencer" ) ||
		StrEqual ( weapon, "weapon_sg552" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_sg556" ) ||
		StrEqual ( weapon, "weapon_aug" ) )
		return true;
		
	return false;
}

/**
 * 플레이어가 저격소총을 들고 있을 때를 채크합니다.
 *
 * @param client
 * @return 저격소총을 들고 있다면 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_HasWeaponSRs ( int client ) {
	if ( !loringlib_IsValidClient ( client ) )
		return false;
	
	if ( !IsPlayerAlive ( client ) )
		return false;
		
	static char weapon[32];
	GetClientWeapon ( client, weapon, sizeof ( weapon ) );
	if ( StrEqual ( weapon, "weapon_scout" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_ssg08" ) ||
		StrEqual ( weapon, "weapon_awp" ) ||
		StrEqual ( weapon, "weapon_sg550" ) ||	//	CS:S
		StrEqual ( weapon, "weapon_scar20" ) ||
		StrEqual ( weapon, "weapon_g3sg1" ) )
		return true;
		
	return false;
}

/**
 * 무기 이름이 권총일 경우를 채크합니다.
 *
 * @param weapon
 * @return 권총일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponPistol ( char[] weapon ) {
	if ( StrContains ( weapon, "glock" ) != -1 ||
		StrContains ( weapon, "hkp2000" ) != -1 ||
		StrContains ( weapon, "usp_silencer" ) != -1 ||
		StrContains ( weapon, "p250" ) != -1 ||
		StrContains ( weapon, "fiveseven" ) != -1 ||
		StrContains ( weapon, "deagle" ) != -1 ||
		StrContains ( weapon, "elite" ) != -1 ||
		StrContains ( weapon, "revolver" ) != -1 ||
		StrContains ( weapon, "cz75a" ) != -1 )
		return true;
	return false;
}

/**
 * 무기 이름이 샷건일 경우를 채크합니다.
 *
 * @param weapon
 * @return 샷건일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponShotgun ( char[] weapon ) {
	if ( StrContains ( weapon, "nova" ) != -1 ||
		StrContains ( weapon, "m3" ) != -1 ||
		StrContains ( weapon, "xm1014" ) != -1 ||
		StrContains ( weapon, "sawedoff" ) != -1 ||
		StrContains ( weapon, "mag7" ) != -1 )
		return true;
	return false;
}

/**
 * 무기 이름이 중화기일 경우를 채크합니다.
 *
 * @param weapon
 * @return 중화기일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponMGs ( char[] weapon ) {
	if ( StrContains ( weapon, "m249" ) != -1 ||
		StrContains ( weapon, "negev" ) != -1 )
		return true;
	return false;
}

/**
 * 무기 이름이 해비류 무기일 경우를 채크합니다.
 *
 * @param weapon
 * @return 해비류 무기일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponHeavy ( char[] weapon ) {
	if ( loringlib_IsWeaponShotgun ( weapon ) ||
		loringlib_IsWeaponMGs ( weapon ) )
		return true;
	return false;
}

/**
 * 무기 이름이 SMG일 경우를 채크합니다.
 *
 * @param weapon
 * @return SMG일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponSMGs ( char[] weapon ) {
	if ( StrContains ( weapon, "mp9" ) != -1 ||
		StrContains ( weapon, "mp7" ) != -1 ||
		StrContains ( weapon, "mp5sd" ) != -1 ||
		StrContains ( weapon, "ump45" ) != -1 ||
		StrContains ( weapon, "mac10" ) != -1 ||
		StrContains ( weapon, "p90" ) != -1 ||
		StrContains ( weapon, "bizon" ) != -1 )
		return true;
	return false;
}

/**
 * 무기 이름이 AR일 경우를 채크합니다.
 *
 * @param weapon
 * @return AR일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponARs ( char[] weapon ) {
	if ( StrContains ( weapon, "famas" ) != -1 ||
		StrContains ( weapon, "galil" ) != -1 ||
		StrContains ( weapon, "m4a1" ) != -1 ||
		StrContains ( weapon, "ak47" ) != -1 ||
		StrContains ( weapon, "sg552" ) != -1 ||
		StrContains ( weapon, "sg553" ) != -1 ||
		StrContains ( weapon, "sg556" ) != -1 ||
		StrContains ( weapon, "aug" ) != -1 )
		return true;
	return false;
}

/**
 * 무기 이름이 SR일 경우를 채크합니다.
 *
 * @param weapon
 * @return SR일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponSRs ( char[] weapon ) {
	if ( StrContains ( weapon, "ssg08" ) != -1 ||
		StrContains ( weapon, "awp" ) != -1 ||
		StrContains ( weapon, "scout" ) != -1 ||
		StrContains ( weapon, "g3sg1" ) != -1 ||
		StrContains ( weapon, "scar20" ) != -1 ||
		StrContains ( weapon, "sg550" ) != -1 )
		return true;
	return false;
}

/**
 * 무기 이름이 Sniper일 경우를 채크합니다.
 *
 * @param weapon
 * @return Sniper일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponSniper ( char[] weapon ) {
	if ( StrContains ( weapon, "awp" ) != -1 ||
		StrContains ( weapon, "scout" ) != -1 ||
		StrContains ( weapon, "ssg08" ) != -1 )
		return true;
	return false;
}

/**
 * 무기 이름이 Auto-Sniper일 경우를 채크합니다.
 *
 * @param weapon
 * @return Auto-Sniper일 경우 true를 반환합니다.
 */
stock bool loringlib_IsWeaponAutoSniper ( char[] weapon ) {
	if ( StrContains ( weapon, "g3sg1" ) != -1 ||
		StrContains ( weapon, "scar20" ) != -1 ||
		StrContains ( weapon, "sg550" ) != -1 )
		return true;
	return false;
}

/**
 * databases.cfg에 db정보를 삽입합니다.
 *
 * @param section		이름
 * @param driver		데이터베이스 드라이버 명
 * @param host			호스트 아이피
 * @param port			아이피 포트
 * @param db_name		데이터베이스 명
 * @param user			데이터베이스 유저 ID
 * @param pass			데이터베이스 비밀번호
 * @return 삽입 성공 시 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_SQL_CreateKeyValue ( char[] section, char[] driver, char[] host, char[] port, char[] db_name, char[] user, char[] pass ) {
	KeyValues kv = new KeyValues ( "Databases" );
	static char cfg_path[256];
	BuildPath ( Path_SM, cfg_path, sizeof ( cfg_path ), "configs/databases.cfg" );
	if ( !kv.ImportFromFile ( cfg_path ) ) {
		delete kv;
		return false;
	}
	
	if ( kv.JumpToKey ( section, true ) ) {
		kv.SetString ( "driver", driver );
		kv.SetString ( "host", host );
		kv.SetString ( "port", port );
		kv.SetString ( "database", db_name );
		kv.SetString ( "user", user );
		kv.SetString ( "pass", pass );
		kv.Rewind ();
		kv.ExportToFile ( cfg_path );
		delete kv;
		return true;
	}
	
	delete kv;
	return false;
}

/**
 * databases.cfg에 있는 db정보를 삭제합니다.
 *
 * @section			삭제할 db 이름
 * @return		삭제 성공 시 true, 아니면 false를 반환합니다.
 */
stock bool loringlib_SQL_DeleteKeyValue ( char[] section ) {
	KeyValues kv = new KeyValues ( "Databases" );
	static char cfg_path[256];
	BuildPath ( Path_SM, cfg_path, sizeof ( cfg_path ), "configs/databases.cfg" );
	if ( !kv.ImportFromFile ( cfg_path ) ) {
		delete kv;
		return false;
	}
	
	if ( kv.JumpToKey ( section, true ) ) {
		kv.DeleteKey ( section );
		kv.Rewind ();
		kv.ExportToFile ( cfg_path );
		delete kv;
		return true;
	}
	
	delete kv;
	return false;
}

/**
 * 엔티티가 끼여있는지 채크합니다.
 *
 * @param entity
 * @return 끼어있지 않다면 -1을 반환합니다.
 */
stock int loringlib_IsClientStuck ( int entity ) {
	float vecMin[3], vecMax[3], vecOrigin[3];
	
	loringlib_GetEntVectorMins ( entity, vecMin );
	loringlib_GetEntVectorMaxs ( entity, vecMax );
	
	loringlib_GetEntityOriginEx ( entity, vecOrigin );
	
	TR_TraceHullFilter ( vecOrigin, vecOrigin, vecMin, vecMax, MASK_SOLID, loringlib_FilterWorldAndEntity );
	return TR_GetEntityIndex ();
}

stock int loringlib_IsEntityStuck ( int entity ) {
	return loringlib_IsClientStuck ( entity );
}

/**
 * 센터에 가까운 엔티티를 구합니다.
 *
 * @param center
 * @param clientsOnly			true일 경우 클라이언트만 찾습니다.
 * @param ignoreEntity
 */
stock int loringlib_GetClosest ( float center[3], bool clientsOnly = false, int ignoreEntity = -1 ) {
	float edictOrigin[3];
	float smallestDistance = 0.0;
	int closestEdict = -1;
	
	int maxEntities;
	
	if ( clientsOnly )
		maxEntities = MaxClients;
	else
		maxEntities = GetMaxEntities ();
	
	for ( int edict = 1; edict <= maxEntities; edict ++ ) {
		if ( !IsValidEdict ( edict ) )
			continue;
		
		if ( ignoreEntity >= 0 && edict == ignoreEntity )
			continue;
		
		if ( GetEntSendPropOffs ( edict, "m_vecOrigin" ) == -1 )
			continue;
		
		loringlib_GetEntityOriginEx ( edict, edictOrigin );
		
		float edictDistance = GetVectorDistance ( center, edictOrigin, true );
		
		if ( edictDistance < smallestDistance || smallestDistance == 0.0 ) {
			smallestDistance = edictDistance;
			closestEdict = edict;
		}
	}
	
	return closestEdict;
}

/**
 * 가까운 에딕트를 찾습니다.
 *
 * @param edict			에딕트 인덱스
 * @param clientsOnly	클라이언트만 찾으려면 true로 합니다.
 * @return				가까운 에딕트 없을 경우 -1
 */
stock int loringlib_GetClosestToEdict ( int edict, bool clientsOnly = false ) {
	float origin[3];
	if ( GetEntSendPropOffs ( edict, "m_vecOrigin" ) == -1 )
		return -1;
	
	loringlib_GetEntityOriginEx ( edict, origin );
	return loringlib_GetClosest ( origin, clientsOnly, edict );
}

/**
 * 클라이언트에서 가까운 클라이언트를 찾습니다.
 *
 * @param client
 * @param distance
 * @param targetDistance			클라이언트와 타겟과의 거리
 * @return 가까운 타겟 인덱스
 */
stock int loringlib_GetNearestClient ( int client, float distance, float &targetDistance = 0.0 ) {
	int target = -1;
	float clientOrigin[3], targetOrigin[3];
	
	GetClientEyePosition ( client, clientOrigin );
	
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( !loringlib_IsValidClient__PlayGame ( i ) )
			continue;
		
		GetClientEyePosition ( i, targetOrigin );
		
		float dist = GetVectorDistance ( clientOrigin, targetOrigin );
		
		if ( dist <= distance ) {
			if ( targetDistance == 0.0 ) {
				targetDistance = dist;
				target = i;
			}
			
			else if ( targetDistance > dist ) {
				targetDistance = dist;
				target = i;
			}
		}
	}
	
	if ( targetDistance == 0.0 )
		return -1;
	
	return target;
}

/**
 * 거리에 가까운 클라이언트 중 한명을 구합니다.
 *
 * @param client		중심 클라이언트
 * @param distance		거리
 * @return	nearby to one client from distance.
 */
stock int loringlib_GetClientNearbyTarget ( int client, float distance = 50.0 ) {
	if ( loringlib_IsValidClient__PlayGame ( client ) ) {
		float pos[3];
		GetClientEyePosition ( client, pos );
		for ( int i = 1; i <= MaxClients; i ++ ) {
			if ( loringlib_IsValidClient__PlayGame ( i ) ) {
				if ( loringlib_GetNearTrue ( client, i, pos, distance ) )
					return i;
			}
		}
	}
	
	return -1;
}

/**
 * 거리에 가까운 클라이언트 중 한명의 적을 구합니다.
 *
 * @param client		중심 클라이언트
 * @param distance		거리
 * @return	가까운 적군 클라이언트 값을 반환합니다.
 */
stock int loringlib_IsClientNearbyEnemy ( int client, float distance = 50.0 ) {
	if ( loringlib_IsValidClient__PlayGame ( client ) ) {
		float pos[3];
		GetClientEyePosition ( client, pos );
		for ( int i = 1; i <= MaxClients; i ++ ) {
			if ( loringlib_IsValidClient__PlayGame ( i ) ) {
				if ( GetClientTeam ( i ) != GetClientTeam ( client ) && GetClientTeam ( i ) != CS_TEAM_SPECTATOR )
					if ( loringlib_GetNearTrue ( client, i, pos, distance ) )
						return i;
			}
		}
	}
	
	return -1;
}

/**
 * 거리에 가까운 클라이언트 중 한명의 적을 구합니다.
 *
 * @param client		중심 클라이언트
 * @param distance		거리
 * @return	거리 내에 적이 있다면 적 중 한명의 인덱스를 반환합니다.
 */
stock int loringlib_GetClientNearbyEnemy ( int client, float distance = 50.0 ) {
	if ( loringlib_IsValidClient__PlayGame ( client ) ) {
		float pos[3];
		GetClientEyePosition ( client, pos );
		for ( int i = 1; i <= MaxClients; i ++ ) {
			if ( loringlib_IsValidClient__PlayGame ( i ) ) {
				if ( GetClientTeam ( i ) != GetClientTeam ( client ) && GetClientTeam ( i ) != CS_TEAM_SPECTATOR )
					if ( loringlib_GetNearTrue ( client, i, pos, distance ) )
						return i;
			}
		}
	}
	
	return -1;
}

/**
 * 유저 아이디로 클라이언트를 찾습니다.
 *
 * @param userid
 * @return Client index.
 */
stock int loringlib_FindUserId ( int userid, bool alive = false ) {
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient ( i ) )
			if ( alive ? IsPlayerAlive ( i ) : true )
				if ( GetClientOfUserId ( userid ) == i )
					return i;
	
	return -1;
}

/**
 * 닉네임으로 클라이언트를 찾습니다.
 *
 * @param username
 * @param equals
 * @param uppercase
 * @param checkBot				봇 채크
 *
 * @return 클라이언트 값. 없으면 -1을 반환합니다.
 */
stock int loringlib_FindTarget ( char[] username, bool equals = false, bool uppercase = false, bool checkBot = false ) {
	static int result;
	result = -1;
	static char tempUsername[32];
	for ( int target = 1; target <= MaxClients; target ++ ) {
		if ( loringlib_IsValidClient ( target ) ) {
			if ( !checkBot ? !IsFakeClient ( target ) : true ) {
				GetClientName ( target, tempUsername, sizeof ( tempUsername ) );
				if ( equals ? StrEqual ( tempUsername, username, uppercase ) : ( StrContains ( tempUsername, username, uppercase ) != -1 ) )
					result = target;
			}
		}
	}
	
	return result;
}

/**
 * 틱레이트를 구합니다.
 * @return tickrates
 */
stock float loringlib_GetTickrates () {
	return 1.0 / GetTickInterval ();
}

/**
 * 클라이언트를 타겟에게 바라보게 합니다.
 *
 * @param client
 * @param target
 */
stock void loringlib_LookAtClientToTarget ( int client, int target ){ 
    float angles[3], clientEyes[3], targetEyes[3], resultant[3];
    GetClientEyePosition ( client, clientEyes );
    GetClientEyePosition ( target, targetEyes );
    MakeVectorFromPoints ( targetEyes, clientEyes, resultant );
    GetVectorAngles ( resultant, angles );
    if ( angles[0] >= 270 ) {
        angles[0] -= 270;
        angles[0] = ( 90-angles[0] );
    } else {
        if ( angles[0] <= 90 ) {
            angles[0] *= -1;
        }
    }
    angles[1] -= 180;
    TeleportEntity ( client, NULL_VECTOR, angles, NULL_VECTOR );
}

stock void loringlib_GetClientLookAtTargetAngles ( int client, int target, float angles[3] ) {
    float clientEyes[3], targetEyes[3], resultant[3];
    GetClientEyePosition ( client, clientEyes );
    GetClientEyePosition ( target, targetEyes );
    MakeVectorFromPoints ( targetEyes, clientEyes, resultant );
    GetVectorAngles ( resultant, angles );
    if ( angles[0] >= 270 ) {
        angles[0] -= 270;
        angles[0] = ( 90-angles[0] );
    } else {
        if ( angles[0] <= 90 ) {
            angles[0] *= -1;
        }
    }
    angles[1] -= 180;
}

stock void loringlib_GetEntityLookAtTargetAngles ( int entity, int target, float angles[3] ) {
    float entityEyes[3], targetEyes[3], resultant[3];
    loringlib_GetEntityAngle ( entity, entityEyes );
    loringlib_GetEntityAngle ( target, targetEyes );
    MakeVectorFromPoints ( targetEyes, entityEyes, resultant );
    GetVectorAngles ( resultant, angles );
    if ( angles[0] >= 270 ) {
        angles[0] -= 270;
        angles[0] = ( 90-angles[0] );
    } else {
        if ( angles[0] <= 90 ) {
            angles[0] *= -1;
        }
    }
    angles[1] -= 180;
}

/**
 * 엔티티를 타겟에게 바라보게 합니다.
 *
 * @param client
 * @param target
 */
stock void loringlib_LookAtEntityToTarget ( int entity, int target ){ 
	float angles[3], entityEyes[3], targetEyes[3], resultant[3];
	loringlib_GetEntityRotation ( entity, entityEyes );
	GetClientEyePosition ( target, targetEyes );
	MakeVectorFromPoints ( targetEyes, entityEyes, resultant );
	GetVectorAngles ( resultant, angles );
	if ( angles[0] >= 270 ) {
		angles[0] -= 270;
		angles[0] = ( 90-angles[0] );
	} else {
	if ( angles[0] <= 90 ) {
			angles[0] *= -1;
		}
	}
	angles[1] -= 180;
	TeleportEntity ( entity, NULL_VECTOR, angles, NULL_VECTOR );
}

/**
 * 엔티티의 바라보는 앵글을 구합니다.
 *
 * @param entity
 * @param angles
 */
stock void loringlib_GetEntityRotation ( int entity, float angles[3] ) {
	loringlib_GetEntityAngle ( entity, angles );
}

/**
 * 타겟이 앵글과 거리 안에 있는지 채크합니다.
 *
 * @param client					클라이언트 인덱스 (꼭 클라이언트가 아니여도 됨.)
 * @param target					타겟 인덱스 (무조건 클라이언트를 타겟으로 합니다.)
 * @param angle						타겟이 보이는 각도
 * @param distance					타겟과의 거리
 * @param heightcheck				높이 채크
 * @param negativeangle				No description.
 * @return 타겟이 앵글안에 보이고, 거리 안에 있을 경우 true를 반환합니다.
 */
stock bool loringlib_IsTargetInSightRange (int client, int target, float angle = 90.0, float distance = 0.0, bool heightcheck = true, bool negativeangle = false)
{
	if (angle > 360.0)
		angle = 360.0;
	
	if (angle < 0.0)
		return false;
	
	float clientpos[3];
	float targetpos[3];
	float anglevector[3];
	float targetvector[3];
	float resultangle;
	float resultdistance;
	
	loringlib_GetEntityRotation ( client, anglevector );
	anglevector[0] = anglevector[2] = 0.0;
	GetAngleVectors ( anglevector, anglevector, NULL_VECTOR, NULL_VECTOR );
	NormalizeVector ( anglevector, anglevector );
	if ( negativeangle )
		NegateVector ( anglevector );
	
	loringlib_GetEntityOriginEx ( client, clientpos );
	loringlib_GetEntityOriginEx ( target, targetpos );
	
	if ( heightcheck && distance > 0 )
		resultdistance = GetVectorDistance ( clientpos, targetpos );
	
	clientpos[2] = targetpos[2] = 0.0;
	MakeVectorFromPoints ( clientpos, targetpos, targetvector );
	NormalizeVector ( targetvector, targetvector );
	
	resultangle = RadToDeg ( ArcCosine ( GetVectorDotProduct ( targetvector, anglevector ) ) );
	
	if ( resultangle <= angle / 2 ) {
		if ( distance > 0 ) {
			if ( !heightcheck )
				resultdistance = GetVectorDistance ( clientpos, targetpos );
			
			if ( distance >= resultdistance )
				return true;
				
			else return false;
		}
		
		else return true;
	}
	
	return false;
}

/**
 * 타겟이 앵글과 거리 안에 있는지 채크합니다.
 *
 * @param pos						시작 위치
 * @param ang						시작 앵글
 * @param target
 * @param angle						타겟이 보이는 각도
 * @param distance					타겟과의 거리
 * @param heightcheck				높이 채크
 * @param negativeangle				No description.
 * @return 타겟이 앵글안에 보이고, 거리 안에 있을 경우 true를 반환합니다.
 */
stock bool loringlib_IsTargetInSightRange2 ( float pos[3], float ang[3], int target, float angle = 90.0, float distance = 0.0, bool heightcheck = true, bool negativeangle = false)
{
	if ( angle > 360.0 )
		angle = 360.0;
	
	if ( angle < 0.0 )
		return false;
	
	float targetpos[3];
	float targetvector[3];
	float resultangle;
	float resultdistance;
	
	ang[0] = ang[2] = 0.0;
	GetAngleVectors ( ang, ang, NULL_VECTOR, NULL_VECTOR );
	NormalizeVector ( ang, ang );
	if ( negativeangle )
		NegateVector ( ang );
	
	loringlib_GetEntityOriginEx ( target, targetpos );
	
	if ( heightcheck && distance > 0 )
		resultdistance = GetVectorDistance ( pos, targetpos );
	
	pos[2] = targetpos[2] = 0.0;
	MakeVectorFromPoints ( pos, targetpos, targetvector );
	NormalizeVector ( targetvector, targetvector );
	
	resultangle = RadToDeg ( ArcCosine ( GetVectorDotProduct ( targetvector, ang ) ) );
	
	if ( resultangle <= angle / 2 ) {
		if ( distance > 0 ) {
			if ( !heightcheck )
				resultdistance = GetVectorDistance ( pos, targetpos );
			
			if ( distance >= resultdistance )
				return true;
				
			else return false;
		}
		
		else return true;
	}
	
	return false;
}

/**
 * 클라이언트에게 라디오를 보냅니다.
 *
 * @param client
 * @param target			타겟 인덱스 값
 * @param sound
 * @param pitch				라디오 소리 피치
 * @param showTime			라디오 마크 표시 시간
 */
stock void loringlib_SendRawAudioToClient ( int client, int target, const char[] sound, int pitch = 100, float showTime = 1.0 ) {
	Handle message = StartMessageOne ( "RawAudio", target );
	BfWrite bf = UserMessageToBfWrite ( message );
	bf.WriteByte ( pitch );
	bf.WriteByte ( client );
	bf.WriteFloat ( showTime );
	bf.WriteString ( sound );
	EndMessage ();
}

/**
 * 설정된 팀에게 라디오를 보냅니다.
 *
 * @param client
 * @param team				라디오가 표시 될 팀 값
 * @param sound
 * @param pitch				라디오 소리 피치
 * @param showTime			라디오 마크 표시 시간
 */
stock void loringlib_SendRawAudioToTeam ( int client, int team, const char[] sound, int pitch = 100, float showTime = 1.0 ) {
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) && GetClientTeam ( i ) == team ) {
			loringlib_SendRawAudioToClient ( client, i, sound, pitch, showTime );
		}
	}
}

/**
 * 모든 클라이언트에게 라디오를 보냅니다.
 *
 * @param client
 * @param sound
 * @param pitch				라디오 소리 피치
 * @param showTime			라디오 마크 표시 시간
 */
stock void loringlib_SendRawAudioToAll ( int client, const char[] sound, int pitch = 100, float showTime = 1.0 ) {
	for ( int i = 1; i <= MaxClients; i ++ ) {
		if ( loringlib_IsValidClient ( i ) ) {
			loringlib_SendRawAudioToClient ( client, i, sound, pitch, showTime );
		}
	}
}

/**
 * 플레이어의 맵 위치 이름을 구합니다.
 *
 * @param client
 * @param buffer
 * @param buffsize
 */
stock void loringlib_GetPlayerLastPlaceName ( int client, char[] buffer, int buffsize ) {
	GetEntPropString ( client, Prop_Data, "m_szLastPlaceName", buffer, buffsize );
}

/**
 * 타겟을 클라이언트의 반대 방향으로 날립니다.
 *
 * @param client
 * @param target
 * @param scale				날라가는 힘
 * @param blockFly			
 */
stock void loringlib_KnockbackToClient ( int client, int target, float scale = 100.0, bool blockFly = false ) {
	float tempVectors[3];
	float clientEyePosition[3], targetEyePosition[3];
	float velocity[3], resultVelocity[3];
	
	GetClientEyePosition ( client, clientEyePosition );
	GetClientEyePosition ( target, targetEyePosition );
	
	if ( blockFly ) {
		clientEyePosition[2] = 0.0;
		targetEyePosition[2] = 0.0;
	}
	
	MakeVectorFromPoints ( clientEyePosition, targetEyePosition, tempVectors );
	NormalizeVector ( tempVectors, tempVectors );
	
	ScaleVector ( tempVectors, scale );
	GetEntPropVector ( target, Prop_Data, "m_vecVelocity", velocity );
	AddVectors ( velocity, tempVectors, resultVelocity );
	
	TeleportEntity ( target, NULL_VECTOR, NULL_VECTOR, resultVelocity );
}

/**
 * 팀 전체 인원의 체력을 구합니다.
 *
 * @param team
 * @return 팀 전체 인원 체력
 */
stock int loringlib_GetTeamTotalHealth ( int team ) {
	int result = 0;
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient__PlayGame ( i ) )
			if ( team == GetClientTeam ( i ) )
				result += loringlib_GetEntityHealth ( i );
	return result;
}

/**
 * 클라이언트 전체의 체력을 구합니다.
 *
 * @return 클라이언트 전체 체력
 */
stock int loringlib_GetClientsTotalHealth () {
	int result = 0;
	for ( int i = 1; i <= MaxClients; i ++ )
		if ( loringlib_IsValidClient__PlayGame ( i ) )
			result += loringlib_GetEntityHealth ( i );
	return result;
}

/**
 * 클라이언트를 스폰으로 이동시킵니다.
 *
 * @param client
 * @return 이동 했다면 true를 반환합니다.
 */
stock bool loringlib_CS_TeleportToSpawn ( int client ) {
	bool bResult = false;
	
	if ( !IsPlayerAlive ( client ) )
		return bResult;
	
	char szClassname[64];
	switch ( GetClientTeam ( client ) ) {
		case CS_TEAM_CT:	strcopy ( szClassname, sizeof szClassname, "info_player_terrorist" );
		case CS_TEAM_T:		strcopy ( szClassname, sizeof szClassname, "info_player_counterterrorist" );
		default:	return bResult;
	}
	
	int iEnt = -1;
	ArrayList hArray = new ArrayList ();
	
	while ( ( iEnt = FindEntityByClassname ( iEnt, szClassname ) ) != -1 ) {
		if ( !bResult )
			bResult = true;
		
		hArray.Push ( iEnt );
	}
	
	iEnt = hArray.Get ( GetRandomInt ( 0, hArray.Length - 1 ) );
	delete hArray;
	
	float flOrigin[3], flRotate[3];
	GetEntPropVector ( iEnt, Prop_Send, "m_vecOrigin", flOrigin );
	GetEntPropVector ( iEnt, Prop_Send, "m_angRotation", flRotate );
	
	TeleportEntity ( client, flOrigin, flRotate, NULL_VECTOR );
	
	return bResult;
}

stock bool loringlib_TF2_TeleportToSpawn ( int client ) {
	bool bResult = false;

	if ( !IsPlayerAlive ( client ) )
		return bResult;

	int iEnt = -1;
	ArrayList hArray = new ArrayList ();
	
	while ( ( iEnt = FindEntityByClassname ( iEnt, "info_player_teamspawn" ) ) != -1 ) {
		if ( GetEntProp ( iEnt, Prop_Send, "m_iTeamNum" ) == GetClientTeam ( client ) ) {
			if ( !bResult )
				bResult = true;
			
			hArray.Push ( iEnt );
		}
	}
	
	iEnt = hArray.Get ( GetRandomInt ( 0, hArray.Length - 1 ) );
	delete hArray;
	
	float flOrigin[3], flRotate[3];
	GetEntPropVector ( iEnt, Prop_Send, "m_vecOrigin", flOrigin );
	GetEntPropVector ( iEnt, Prop_Send, "m_angRotation", flRotate );
	
	TeleportEntity ( client, flOrigin, flRotate, NULL_VECTOR );
	
	return bResult;
}

/**
 * 클라이언트의 옵저버 모드를 구합니다.
 *
 * @param client
 * @return 옵저버 모드
 */
stock int loringlib_GetClientObserverMode ( int client ) {
	return GetEntProp ( client, Prop_Send, "m_iObserverMode" );
}

/**
 * 클라이언트의 옵저버 타겟을 구합니다.
 *
 * @param client
 * @return 옵저버 타겟
 */
stock int loringlib_GetClientObserverTarget ( int client ) {
	return GetEntPropEnt ( client, Prop_Send, "m_hObserverTarget" );
}

/**
 * origin에서 앞쪽으로 units 만큼 이동합니다.
 *
 * @param origin
 * @param angles
 * @param units
 * @param output
 */
stock void loringlib_AddInFrontOf ( float origin[3], float angles[3], float units, float output[3] ) {
	float flAngVectors[3];
	flAngVectors = angles;
	GetAngleVectors ( flAngVectors, flAngVectors, NULL_VECTOR, NULL_VECTOR );
	for ( int i; i < 3; i ++ )
		output[i] = origin[i] + ( flAngVectors[i] * units );
}






















































































































/**
 * 필터링 방식 모음 입니다.
 */
stock	bool loringlib_TraceRayFilter_tarNotPlayer ( int ent, int mask, any data ) {
	if ( !loringlib_IsValidClient__PlayGame ( ent ) )	return true;
	else	return false;
}

stock	bool loringlib_TraceRayFilter_tarNotPlayer2 ( int ent, int mask ) {
	return	!( 1 <= ent <= MaxClients );
}

stock	bool loringlib_TraceRayFilter_tarNotPlayer3 ( int ent, int mask, any data ) {
	return ent > MaxClients;
}

stock	bool loringlib_TraceRayFilter_tarPlayer ( int ent, int mask, any data ) {
	return ent > 0 && ent <= MaxClients && ent != data;
}

stock bool loringlib_FilterWorldAndEntity ( int entity, int mask, any data ) {
	return ( ( entity < 1 || entity > MaxClients ) && entity != data );
}

