#!/bin/bash
set -e
uploadCommand="pros --no-analytics -- upload"
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	uploadCommand="sudo pros --no-analytics -- upload"
fi

preRunCommands() {
	pros -- c --no-analytics upgrade
	pros -- build-compile-commands --no-analytics
	pros -- build --no-analytics
	eval "$uploadCommand"
}

runCommands() {
	#	sed -i "s/*slot*/\"slot\": $1,/" ./project.pros
	sed -i "/slot/c\      \"slot\": $1" ./project.pros
	#	sed -i "s/*project_name*/\"project_name\": \"$3\",/" ./project.pros
	sed -i "/project_name/c\   \"project_name\": \"$3\"," ./project.pros
	sed -i "s/*AutonTypes autonType*/AutonTypes autonType = $2;/" ./src/autonomous/autonomous.cpp
	preRunCommands
}

runCommands 1 "BP" "BP1965M"
runCommands 2 "BN" "BN1965M"
runCommands 3 "RP" "RP1965M"
runCommands 4 "RN" "RN1965M"
runCommands 5 "TA" "TA"
runCommands 6 "TL" "TL"
