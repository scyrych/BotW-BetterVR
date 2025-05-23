[BetterVR_WeaponHands_V208]
moduleMatches = 0x6267BFD0

.origin = codecave

0x1046CF88 = Camera__sInstance:
0x03191B70 = Camera__getLookAtCamera:

changeWeaponMtx:
lwz r3, 0x58(r1) ; the actor we hackily put on the stack

mflr r0
stwu r1, -0x50(r1)
stw r0, 0x54(r1)

stw r3, 0x1C(r1)
mr r3, r31

stw r3, 0x08(r1)
stw r4, 0x0C(r1)
stw r5, 0x10(r1)
stw r6, 0x14(r1)
stw r7, 0x18(r1)
stw r8, 0x20(r1)
stw r9, 0x24(r1)
stw r10, 0x28(r1)

; get camera from global camera instance
lis r3, Camera__getLookAtCamera@ha
addi r3, r3, Camera__getLookAtCamera@l
mtctr r3
lis r3, Camera__sInstance@ha
lwz r3, Camera__sInstance@l(r3)
bctrl ; bl Camera__getLookAtCamera
mr. r10, r3 ; move camera to r10
beq noChangeWeaponMtx

; call C++ code to change the weapon mtx to the hand mtx
lwz r3, 0x1C(r1) ; the source actor
lwz r4, 0x18(r31) ; the char array of the weapon name
lwz r5, 0x10(r1) ; the target MTX
addi r6, r29, 0x34 ; the gsysModel->mtx, maybe used for the location?
addi r7, r31, 0x3C ; the mtx of the item supposedly
lwz r8, 0x0C(r1) ; the target actor
bl import.coreinit.hook_ChangeWeaponMtx

cmpwi r9, 0
beq noChangeWeaponMtx

lwz r3, 0x6C(r31)
li r5, 3
;stw r5, 0x6C(r31)


noChangeWeaponMtx:
lwz r3, 0x08(r1)
lwz r4, 0x0C(r1)
lwz r5, 0x10(r1)
lwz r6, 0x14(r1)
lwz r7, 0x18(r1)
lwz r8, 0x20(r1)
lwz r9, 0x24(r1)
lwz r10, 0x28(r1)

lwz r0, 0x54(r1)
mtlr r0
addi r1, r1, 0x50

blr

; 0x03125438 = li r5, 3 ; this forces all weapons to be static

0x0312587C = bla changeWeaponMtx

; we want to preserve r7 since we need it later
;0x0312584C = lwz r10, 0x24(r29)
;0x03125854 = lwzx r10, r6, r10

; increase stack size
0x0312575C = stwu r1, -0x54(r1)
0x03125898 = addi r1, r1, 0x54
0x03125900 = addi r1, r1, 0x54
0x03125924 = addi r1, r1, 0x54

; store r7 on the stack
storeR7OnStack:
stw r3, 0x58(r1) ; store result of the function
mr. r7, r3
blr

0x0312577C = bla storeR7OnStack
