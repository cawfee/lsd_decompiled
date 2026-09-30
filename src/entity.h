#ifndef LSD_ENTITY_H
#define LSD_ENTITY_H

#include "effect.h"
#include "common.h"
#include "base_class.h"

typedef struct dream_sys dream_sys_t;

/* Notify codes raised by entity behaviours (base_class_notify). */
typedef enum {
    ENTITY_NOTIFY_DETACH = 1,      /* base_class cleanup: detach from sender */
    ENTITY_NOTIFY_TRIGGERED = 9,   /* interaction fired (entity_set_triggered) */
    ENTITY_NOTIFY_LINK = 10,       /* request a dynamic link (dream_session case 10) */
    ENTITY_NOTIFY_LINK_VIDEO = 11, /* link that also plays an event video */
    ENTITY_NOTIFY_LINK_END = 12,   /* request day end / link (dream_session case 12) */
} entity_notify_t;


/* entity_vtable is a superset of actor_vtable:
 *   slots 0x004..0x140   inherited base_class -> transform -> scene_node -> actor methods
 *   slot  0x008/0x00C    overridden by entity_construct/entity_cleanup
 *   slots 0x144..0x180   entity-specific (distance, dream effects, link/trigger
 *                        and per-frame behaviour control).  See g_ENTITY_TABLE.
 * Slots still named UnkNN are inherited and not yet understood. */
typedef struct entity_vtable {
    /* 0x000 80089ad4 */ u32 type_id;
    /* 0x004 80089ad8 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 80089adc */ entity_t *(*entity_construct)(entity_t *, s32, s32, s32);
    /* 0x00C 80089ae0 */ void (*entity_cleanup)(entity_t *);
    /* 0x010 80089ae4 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 80089ae8 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 80089aec */ void (*DetachAll)(base_class_t *);
    /* 0x01C 80089af0 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 80089af4 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 80089af8 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 80089afc */ void (*ClearParents)(base_class_t *);
    /* 0x02C 80089b00 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 80089b04 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 80089b08 */ void (*Nop)(base_class_t *);
    /* 0x038 80089b0c */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 80089b10 */ s32 dummy1;
    /* 0x040 80089b14 */ void (*Unk15)(entity_t *);
    /* 0x044 80089b18 */ void (*Unk16)(void *, s32, s32 *);
    /* 0x048 80089b1c */ void (*Unk17)(void *, s32, s32 *);
    /* 0x04C 80089b20 */ void (*Unk18)(entity_t *, s32, s32, s32, s32);
    /* 0x050 80089b24 */ void (*Unk19)(entity_t *);
    /* 0x054 80089b28 */ void (*Unk20)(void *);
    /* 0x058 80089b2c */ void (*Unk21)(void *);
    /* 0x05C 80089b30 */ void (*Unk22)(void *);
    /* 0x060 80089b34 */ void (*Unk23)(void *, s32);
    /* 0x064 80089b38 */ void (*Unk24)(void *);
    /* 0x068 80089b3c */ void (*Unk25)(void *);
    /* 0x06C 80089b40 */ void (*Unk26)(void *);
    /* 0x070 80089b44 */ void (*Unk27)(void *, s32);
    /* 0x074 80089b48 */ void (*Unk28)(void *);
    /* 0x078 80089b4c */ void (*Unk29)(void *);
    /* 0x07C 80089b50 */ void (*Unk30)(void *);
    /* 0x080 80089b54 */ void (*Unk31)(void *);
    /* 0x084 80089b58 */ void (*Unk32)(void *);
    /* 0x088 80089b5c */ void (*Unk33)(void *);
    /* 0x08C 80089b60 */ void (*Unk34)(void *);
    /* 0x090 80089b64 */ void (*Unk35)(void *);
    /* 0x094 80089b68 */ void (*Unk36)(void *);
    /* 0x098 80089b6c */ void (*Unk37)(entity_t *, s32, s32);
    /* 0x09C 80089b70 */ void (*Unk38)(void *);
    /* 0x0A0 80089b74 */ void (*Unk39)(void *);
    /* 0x0A4 80089b78 */ void (*Unk40)(void *);
    /* 0x0A8 80089b7c */ void (*Unk41)(void *);
    /* 0x0AC 80089b80 */ void (*Unk42)(void *);
    /* 0x0B0 80089b84 */ s32 dummy2;
    /* 0x0B4 80089b88 */ void (*Unk44)(void *);
    /* 0x0B8 80089b8c */ void (*Unk45)(void *, s32);
    /* 0x0BC 80089b90 */ void (*Unk46)(void *, s32 *);
    /* 0x0C0 80089b94 */ void (*Unk47)(void *);
    /* 0x0C4 80089b98 */ void (*Unk48)(void *, s32, s32);
    /* 0x0C8 80089b9c */ void (*Unk49)(void *, s32, s32);
    /* 0x0CC 80089ba0 */ void (*Unk50)(void *, s32, s32);
    /* 0x0D0 80089ba4 */ void (*Unk51)(void *, s32, s32);
    /* 0x0D4 80089ba8 */ void (*Unk52)(void *);
    /* 0x0D8 80089bac */ void (*Unk53)(void *);
    /* 0x0DC 80089bb0 */ void (*Unk54)(entity_t *, s32, s32);
    /* 0x0E0 80089bb4 */ void (*Unk55)(entity_t *, s32, s32);
    /* 0x0E4 80089bb8 */ void (*Unk56)(void *);
    /* 0x0E8 80089bbc */ void (*Unk57)(void *);
    /* 0x0EC 80089bc0 */ void (*Unk58)(void *);
    /* 0x0F0 80089bc4 */ void (*Unk59)(void *);
    /* 0x0F4 80089bc8 */ void (*Unk60)(void *);
    /* 0x0F8 80089bcc */ void (*Unk61)(void *);
    /* 0x0FC 80089bd0 */ void (*Unk62)(void *);
    /* 0x100 80089bd4 */ void (*Unk63)(void *);
    /* 0x104 80089bd8 */ void (*Unk64)(void *);
    /* 0x108 80089bdc */ void (*Unk65)(void *);
    /* 0x10C 80089be0 */ void (*Unk66)(void *, s32);
    /* 0x110 80089be4 */ void (*Unk67)(void *);
    /* 0x114 80089be8 */ void (*Unk68)(void *);
    /* 0x118 80089bec */ void (*Unk69)(void *);
    /* 0x11C 80089bf0 */ void (*Unk70)(entity_t *);
    /* 0x120 80089bf4 */ void (*Unk71)(void *);
    /* 0x124 80089bf8 */ void (*Unk72)(void *);
    /* 0x128 80089bfc */ void (*set_motion)(void *, s32);
    /* 0x12C 80089c00 */ void (*Unk74)(void *);
    /* 0x130 80089c04 */ void (*Unk75)(void *);
    /* 0x134 80089c08 */ s32 (*tick_anim)(void *, s32, s32);
    /* 0x138 80089c0c */ void (*set_motion_blend)(void *, s32, s32);
    /* 0x13C 80089c10 */ void (*Unk78)(void *);
    /* 0x140 80089c14 */ void (*Unk79)(void *);
    /* 0x144 80089c18 */ s32 (*entity_get_distance)(entity_t *, void *);
    /* 0x148 80089c1c */ s32 (*entity_get_trigger_ratio)(entity_t *);
    /* 0x14C 80089c20 */ s8 *(*entity_get_mood_effect)(entity_t *);
    /* 0x150 80089c24 */ s32 (*entity_get_unlock_effect)(entity_t *);
    /* 0x154 80089c28 */ s32 (*entity_get_link_stage)(entity_t *);
    /* 0x158 80089c2c */ s32 (*entity_get_event_video)(entity_t *);
    /* 0x15C 80089c30 */ void (*entity_enable_link)(entity_t *);
    /* 0x160 80089c34 */ void (*entity_disable_link)(entity_t *);
    /* 0x164 80089c38 */ void (*entity_set_triggered)(entity_t *, s32);
    /* 0x168 80089c3c */ void (*entity_start_behaviour)(entity_t *);
    /* 0x16C 80089c40 */ void (*entity_stop_behaviour)(entity_t *);
    /* 0x170 80089c44 */ s32 (*entity_check_interaction)(entity_t *);
    /* 0x174 80089c48 */ s32 (*entity_check_interaction_range)(entity_t *);
    /* 0x178 80089c4c */ s32 (*entity_check_interaction_angle)(entity_t *);
    /* 0x17C 80089c50 */ s32 (*entity_check_link_trigger)(entity_t *);
    /* 0x180 80089c54 */ s32 (*entity_check_link_proximity)(const entity_t *);
} entity_vtable_t;

typedef struct entity {
    /* 0x00 */ entity_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Transform;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_InteractionTimer;
    /* 0x28 */ s32 m_FrameOffsetX;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_State;
    /* 0x48 */ s32 m_Unk17;
    /* 0x4C */ struct entity *m_LinkTarget;
    /* 0x50 */ s32 m_EffectColor;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ void *m_Helper;
    /* 0x5C */ s32 m_Unk22;
    /* 0x60 */ s32 m_Unk23;
    /* 0x64 */ s32 m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
    /* 0x70 */ struct entity **m_Unk27;
    /* 0x74 */ s32 m_Unk28;
    /* 0x78 */ s32 m_Unk29;
    /* 0x7C */ s32 m_Variant;
    /* 0x80 */ s32 m_Duration;
    /* 0x84 */ s32 m_Frame;
    /* 0x88 */ s32 m_AnimCursor;
    /* 0x8C */ s32 m_ModelLoaded;
    /* 0x90 */ s32 m_AnimPlaying;
    /* 0x94 */ dream_sys_t *m_DreamSys;
    /* 0x98 */ s32 m_EntityID;
    /* 0x9C */ s32 m_EntityContext;
    /* 0xA0 */ s32 m_Unk39;
    /* 0xA4 */ s32 m_Unk40;
    /* 0xA8 */ s32 m_Unk41;
    /* 0xAC */ s32 m_Unk42;
    /* 0xB0 */ s32 m_ProximityScale;
    /* 0xB4 */ s32 m_Unk44;
    /* 0xB8 */ s32 m_Unk45;
    /* 0xBC */ s32 m_Unk46;
    /* 0xC0 */ s32 m_Unk47;
    /* 0xC4 */ s32 m_Unk48;
    /* 0xC8 */ s32 m_Unk49;
    /* 0xCC */ s32 m_Unk50;
    /* 0xD0 */ s32 m_Unk51;
    /* 0xD4 */ s32 m_Unk52;
    /* 0xD8 */ s32 m_Unk53;
    /* 0xDC */ s32 m_Unk54;
    /* 0xE0 */ s32 m_Unk55;
    /* 0xE4 */ s32 m_Unk56;
    /* 0xE8 */ s32 m_Unk57;
    /* 0xEC */ s32 m_Unk58;
    /* 0xF0 */ s32 m_LinkEnabled;
    /* 0xF4 */ s32 m_Triggered;
    /* 0xF8 */ s32 m_BehaviourActive;
    /* 0xFC */ s32 m_Tick;
    /* 0x100 */ effect_t *m_Effect;
    /* 0x104 */ base_class_t *m_Unk64;
} entity_t;

typedef struct {
    /* 0x00 */ s8 mood_effect[2];
    /* 0x02 */ s8 unlock;
    /* 0x03 */ s8 behaviour;
    /* 0x04 */ s8 interaction_type;
    /* 0x05 */ s8 interaction_range;
    /* 0x06 */ s8 interaction_angle;
    /* 0x07 */ s8 link_stage;
    /* 0x08 */ s8 event_video_id;
    /* 0x09 */ s8 interaction_param;
    /* 0x0A */ s8 proximity;
    /* 0x0B */ s8 link_flag;

    /* 0x0C */ void (*behaviour_fn)(entity_t *This, s32 *arg1);
} entity_prop_t;

/* Per-object effect driver registered with sound_entity_init
 * (src/sound.c) and updated once per frame by sound_entity_update.
 * The behaviour function (g_ENTITY_TABLE[].behaviour_fn) is invoked as
 * callback(owner, &context) and writes effect ids into the three slots. */
typedef struct {
    /* 0x00 */ s32 handle;   /* effect/sound handle, -1 when free */
    /* 0x04 */ s32 id;       /* effect id chosen by the behaviour */
    /* 0x08 */ s32 param;    /* effect parameter chosen by the behaviour */
    /* 0x0C */ s32 period;   /* reset to 0x7F by sound_entity_update */
    /* 0x10 */ s32 counter;  /* reset to 0x40 by sound_entity_update */
} entity_effect_slot_t;

typedef struct {
    /* 0x00 */ s32 state;    /* 0 disables updates; set to entity id + 1 */
    /* 0x04 */ s32 tick;     /* frame counter, incremented each update */
    /* 0x08 */ void *owner;  /* object passed as the callback's first arg */
    /* 0x0C */ void (*callback)(void *, s32 *);
    /* 0x10 */ s32 motion;   /* current motion/pose id */
    /* 0x14 */ s32 divisor;  /* period used by sound_entity_update */
    /* 0x18 */ entity_effect_slot_t slots[3];
} entity_context_t;

entity_t *entity_create(s32 Unk1, s32 Unk2, s32 Unk3);
entity_vtable_t *entity_get_vtable();

#endif // LSD_ENTITY_H