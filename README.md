# 2021-Current
Our Robot Code for 2021 using multi-project gradle with WML, CJ-Vision &amp; Wayfinder Libraries

#### Current build status:
[![Build Status](https://dev.azure.com/ConnorBuchel0890/CurtinFRC/_apis/build/status/CurtinFRC.2021-GameChangers?branchName=master)](https://dev.azure.com/ConnorBuchel0890/CurtinFRC/_build/latest?definitionId=15&branchName=master)

## Installing Code
#### 1. Download latest WPILib from releases [https://github.com/wpilibsuite/allwpilib/releases]
  - Downlad based on your operating system. https://docs.wpilib.org/en/stable/docs/getting-started/getting-started-frc-control-system/wpilib-setup.html

#### 2. run `git clone ${link} --recursive` when cloning (clones code with submodules)

#### 3. Build Code `./gradlew build` Successful if installed correctly
  - On windows use `gradlew build`. 
  - For linux and macOS you might need to run `sudo chmod +x gradlew` to be able to use the command

## Developing
  - Code for robot goes in `4788/src/main`

  - Code for coprocessor goes in `Coproc/src/main`


## Documentation

#### @TODO (Put your docs/info on what your code does. e.g)

  - Drivebase
```
Uses XboxControllers on USB ports 0 and 1. Control Left and Right power via tankdrive with a maxspeed of 80% etc.... 
```
