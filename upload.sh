#!/bin/bash

pros_path="$HOME/Folders/CustomPrograms/pros-cli-linux/pros"

$pros_path -- c --no-analytics upgrade
$pros_path -- build-compile-commands --no-analytics
$pros_path -- build --no-analytics
sudo "$pros_path" --no-analytics -- upload
