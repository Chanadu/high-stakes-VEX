#!/bin/bash

pros_path="$HOME/Folders/CustomPrograms/pros-cli-linux/pros"

$pros_path -- build-compile-commands all
$pros_path -- build all
sudo $pros_path -- upload

