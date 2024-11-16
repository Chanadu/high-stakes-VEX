#ifndef DRIVE_TRAIN_MOVEMENT_HPP
#define DRIVE_TRAIN_MOVEMENT_HPP

extern void drivetrainMovementController(short& lineNumber);

extern void tankControl();
extern void singleStickArcadeControl();
extern void doubleStickArcadeControl();
extern void singleStickCurvatureControl();
extern void doubleStickCurvatureControl();

#endif	// DRIVE_TRAIN_MOVEMENT_HPP
