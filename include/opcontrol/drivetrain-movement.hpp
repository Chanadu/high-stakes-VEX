#ifndef _DRIVE_TRAIN_MOVEMENT_HPP_
#define _DRIVE_TRAIN_MOVEMENT_HPP_

#include "../main.h"
#include "../utils/config-enums.hpp"

extern void drivetrainMovementController(int& i);

extern void tankControl();
extern void singleStickArcadeControl();
extern void doubleStickArcadeControl();
extern void singleStickCurvatureControl();
extern void doubleStickCurvatureControl();

#endif	// _DRIVE_TRAIN_MOVEMENT_HPP_
