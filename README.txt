                   .:                     :,                                          
,:::::::: ::`      :::                   :::                                          
,:::::::: ::`      :::                   :::                                          
.,,:::,,, ::`.:,   ... .. .:,     .:. ..`... ..`   ..   .:,    .. ::  .::,     .:,`   
   ,::    :::::::  ::, :::::::  `:::::::.,:: :::  ::: .::::::  ::::: ::::::  .::::::  
   ,::    :::::::: ::, :::::::: ::::::::.,:: :::  ::: :::,:::, ::::: ::::::, :::::::: 
   ,::    :::  ::: ::, :::  :::`::.  :::.,::  ::,`::`:::   ::: :::  `::,`   :::   ::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  :::::: ::::::::: ::`   :::::: ::::::::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  .::::: ::::::::: ::`    ::::::::::::::: 
   ,::    ::.  ::: ::, ::`  ::: ::: `:::.,::   ::::  :::`  ,,, ::`  .::  :::.::.  ,,, 
   ,::    ::.  ::: ::, ::`  ::: ::::::::.,::   ::::   :::::::` ::`   ::::::: :::::::. 
   ,::    ::.  ::: ::, ::`  :::  :::::::`,::    ::.    :::::`  ::`   ::::::   :::::.  
                                ::,  ,::                               ``             
                                ::::::::                                              
                                 ::::::                                               
                                  `,,`


http://www.thingiverse.com/thing:53321
Dual Axis Solar Tracker by OpenSourceClassroom is licensed under the Creative Commons - Attribution - Share Alike license.
http://creativecommons.org/licenses/by-sa/3.0/

# Summary

If you have made this thing, PLEASE take pictures and post!  Thanks.  

This is a simplified dual axis tracker for small solar projects.  Notice that the weight of the tracker is NOT putting pressure on the servo motors.  The pitch gear is nestled inside the bracket which reduces wobbliness and makes the installation look professional.  For the horizontal gear system it just made sense to attach the entire panel mount directly on the gear.  It makes for a really solid structure.  This was my first attempt at a project like this. Let me know how it works out if you build one...  Enjoy!  
Here are video links:  
http://www.youtube.com/watch?v=sbksReSEpJc  
http://www.youtube.com/watch?v=HqACH3WS-w8  
Here is a simiar project with no printed parts:  
http://www.instructables.com/id/Arduino-Solar-Tracker/  


# Instructions

You need:  Arduino Uno, (2) SG90 Micro servo motors, (4) LDRs, breadboard, wires, rainbow ribbon cable for LDRs, 4" long 1/4" bolt and nut.  
Print all parts.  
Attach horizontal servo motor to tracker base before attaching the horizontal gear or you will have trouble with tool access to get the motor mounted.  The vertical servo gear should be ok to assemble first due to the smaller size.  To mount the gears to the servo motors, I cut tiny brass nails just a bit smaller than the thickness of the gears and made little groves on the nail to give a rough surface for the plastic to bond to.  I then used a soldering iron to heat the nail and fuse it through the white servo gear attachment and then into the plastic gear.  Makes for a nice, clean installation.  Just make sure that your gear is exactly centered when you mount it to the servo.  
Attach motors, gears, and panel mount.  
Hook up wires according to schematic.  
Load program into Arduino and test it out.  
Depending on the light that you use to move your tracker around, you might need to change the resistor size on breadboard (they should all be equal value, higher value resistors for less light).