#ifndef AUTONOMOUS_HPP
#define AUTONOMOUS_HPP

#include <map>
#include "main.h"

extern void tuneAngularPID();

extern void tuneLateralPID();

extern void autonomousRunner();

enum AutonTypes { BP, BN, RP, RN, TA, TL };
const std::map<AutonTypes, std::string> autonTypeString = {
	{BP, "BP"}, {BN, "BN"}, {RP, "RP"}, {RN, "RN"}, {TA, "TA"}, {TL, "TL"},
};

#endif	// AUTONOMOUS_HPP
