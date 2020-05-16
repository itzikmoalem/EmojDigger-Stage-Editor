# EmojDigger | Stage-Editor
With this project, you can edit stages to "EmojDigger" game project. 
Created with SFML library.

<a href="https://ibb.co/zx12G8W"><img src="https://i.ibb.co/NCXNZ1g/Untitled-sff1.jpg" alt="Untitled-sff1" border="0"></a>

Me and my partner worte 4 classes 
(CPP + Header files) :

<b>Rectangle</b> - The base class for Board and Menu classes.

<b>Menu</b> - This class is inherited from the Rectangle class, In this class we made sure to create all the functions needed for menu effects and operation.

<b>Controller</b> - A class that manages the user interface and is responsible for the "window" loop, in this class we also print the board.

<b>Board</b> - This class inherits from the Rectangle class. In this class, all objects are added or removed (by the user) in every moment, this class keep another options like opening an existing stage or creating a new one.


