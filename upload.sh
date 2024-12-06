#!/bin/bash

uploadCommand="pros --no-analytics -- upload"
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	uploadCommand="sudo pros --no-analytics -- upload"
fi

runCommands() {
	pros -- c --no-analytics upgrade
	pros -- build-compile-commands --no-analytics
	pros -- build --no-analytics
	eval "$uploadCommand"
}

AutonTypes autonType = TL
sed -i 's/"slot": 4/"slot": 1/' ./project.pros
sed -i 's/AutonTypes autonType = TL/AutonTypes autonType = RA/' ./src/autonomous/autonomous.cpp
bool flip = false
sed -i 's/bool flip = true/bool flip = false/' ./src/autonomous/autonomous.cpp
sed -i 's/"project_name": "TL"/"project_name": "1965M"/' ./project.pros

runCommands

sed -i 's/"slot": 1/"slot": 2/' ./project.pros
#sed -i 's/RA/RA/' ./src/autonomous/autonomous.cpp
sed -i 's/bool flip = false/bool flip = true/' ./src/autonomous/autonomous.cpp
sed -i 's/"project_name": "1965M"/"project_name": "FLIPPED 1965M"/' ./project.pros

runCommands

sed -i 's/"slot": 2/"slot": 3/' ./project.pros
sed -i 's/AutonTypes autonType = RA/AutonTypes autonType = TA/' ./src/autonomous/autonomous.cpp
#sed -i 's/bool flip = false/bool flip = true/' ./src/autonomous/autonomous.cpp
sed -i 's/"project_name": "FLIPPED 1965M"/"project_name": "TA"/' ./project.pros

runCommands

sed -i 's/"slot": 3/"slot": 4/' ./project.pros
sed -i 's/AutonTypes autonType = TA/AutonTypes autonType = TL/' ./src/autonomous/autonomous.cpp
#sed -i 's/bool flip = false/bool flip = true/' ./src/autonomous/autonomous.cpp
sed -i 's/"project_name": "TA"/"project_name": "TL"/' ./project.pros

runCommands
