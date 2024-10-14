# ScifiShooter

This is a 3D shooter game created in Unreal Engine 5 as part of the Unreal Engine 5 C++ Developer: Learn C++ & Make Video Games course.
The game features a level with enemies looking for the player to kill.

Here are some specific things I developed from scratch while making this game:
- player movement
- animation: locomotion-based blending.
- shooting system with line tracing, vfx, sfx.
- health, damage system
- enemy AI using UE5 Nav mesh for movement, Behavior Tree with Blackboard, and custom Services and Tasks.
- HUD with a simple health bar, crosshair and win/lose messages.

# Demo
[<img src=".github/demo/ScifiShooterThumbnail.png">](https://youtu.be/6Yv0Ppb8wQY)

# Getting started
*Updated to the Unreal Engine 5.4.3.*
*Note: Unfortunately, I can not push some of the assets used in this project because of GitHub storage limits. So if you want to work with this repo, contact me.*
1. `git clone https://github.com/denyskryvytskyi/ScifiShooter`
2. Right-click the `ScifiShooter.uproject` file and select `Generate Visual Studio project files`
3. Build project in Visual Studio (`Development Editor` configuration to run in Editor)
4. Run `ScifiShooter.uproject`
