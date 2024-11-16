#!/bin/bash

pros_path="$HOME/Folders/CustomPrograms/pros-cli-linux/pros"

$pros_path -- c --no-analytics upgrade
$pros_path -- build-compile-commands --no-analytics all
$pros_path -- build --no-analytics all
sudo "$pros_path" --no-analytics -- upload
