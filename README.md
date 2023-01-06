05 Jan 2023: This variant code was tested on a BMW 2018 540i G30 cluster. 

Working items: Gauges, headlights, turn indicators. This is still a work in progress project.

For people who aren't finding it difficult, you can use x-loader software to flash the hex files in firmware folder directly to arduino:

1. Put the "ets2-telemetry-udp.dll" file inside your game directory/bin/win_x64/plugins. 
It would look like this for example: D:\Games\American Truck Simulator\bin\win_x64\plugins

2. Flash the corresponding firmware (.hex file) via X-loader to arduino. There are two files each for the Arduino Mega 2560 & UNO each. You need to choose the file for CS Pin depending on the type of can bus shield you have. For Seeed Studios it's CS 9 generally.

3. Open telemetry-client.exe app. Select your arduino's port. Then click connect. Next launch your ETS/ATS game. 
Once you are all teh way in and see you are ready to drive, 
minimize the game and in the telemetry-client app select the game you want from drop down menu. Then click connect.Now resume game and enjoy!

## Gameplay demo
[(https://youtube.com/shorts/gNk2IcqHBqA?feature=share)]

If you are interested to play with the code you can take a look at the below video on how to flash the original code via MS VSCode:


## Uploading original code
[(https://youtu.be/80r-yTnWmj0)]

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# E90 Dashboard ETS2 [original code]

Euro Truck Simulator 2 telemetry on the BMW E90 instrument cluster

## Using
 - [ETS2 Telemetry client app](https://github.com/Marcin648/e90-dashboard-ets2/releases/download/v0.1.0/telemetry-client.exe)
 - [ETS2 Telemetry UDP](https://github.com/Marcin648/ets2-telemetry-udp)
 - [Arduino Mega 2560 Rev3](https://store.arduino.cc/arduino-mega-2560-rev3)
 - [CAN-BUS Shield V2.0](http://wiki.seeedstudio.com/CAN-BUS_Shield_V2.0/)
 - [Python 3](https://www.python.org/)
 - [BMW Can-bus Codes](http://www.loopybunny.co.uk/CarPC/k_can.html)

## Video
[![Watch the video](https://img.youtube.com/vi/5KFK7mTA3D0/maxresdefault.jpg)](https://youtu.be/5KFK7mTA3D0)
